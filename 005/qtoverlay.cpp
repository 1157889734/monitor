#include <gst/video/videooverlay.h>
#include <QApplication>
#include "qtoverlay.h"
#include <gst/gst.h>


PlayerWindow::PlayerWindow(GstElement *p)
    :pipeline(p)
    ,state(GST_STATE_NULL)
    ,totalDuration(GST_CLOCK_TIME_NONE)
{
    playBt = new QPushButton("Play");
    pauseBt = new QPushButton("Pause");
    stopBt = new QPushButton("Stop");
    videoWindow = new QWidget();
    slider = new QSlider(Qt::Horizontal);
    timer = new QTimer();

    connect(playBt, SIGNAL(clicked()), this, SLOT(onPlayClicked()));
    connect(pauseBt, SIGNAL(clicked()), this, SLOT(onPauseClicked()));
    connect(stopBt, SIGNAL(clicked()), this, SLOT(onStopClicked()));
    connect(slider, SIGNAL(sliderReleased()), this, SLOT(onSeek()));

    buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(playBt);
    buttonLayout->addWidget(pauseBt);
    buttonLayout->addWidget(stopBt);
    buttonLayout->addWidget(slider);

    playerLayout = new QVBoxLayout;
    playerLayout->addWidget(videoWindow);
    playerLayout->addLayout(buttonLayout);

    this->setLayout(playerLayout);

    connect(timer, SIGNAL(timeout()), this, SLOT(refreshSlider()));
    connect(this, SIGNAL(sigAlbum(QString)), this, SLOT(onAlbumAvaiable(QString)));
    connect(this, SIGNAL(sigState(GstState)), this, SLOT(onState(GstState)));
    connect(this, SIGNAL(sigEos()), this, SLOT(onEos()));
}

WId PlayerWindow::getVideoWId() const {
    return videoWindow->winId();
}

void PlayerWindow::onPlayClicked() {
    GstState st = GST_STATE_NULL;
    gst_element_get_state (pipeline, &st, NULL, GST_CLOCK_TIME_NONE);
    if (st < GST_STATE_PAUSED) {
        // Pipeline stopped, we need set overlay again
        GstElement *vsink = gst_element_factory_make ("waylandsink", "vsink");
        g_object_set(GST_OBJECT(pipeline), "video-sink", vsink, NULL);
        WId xwinid = getVideoWId();
        gst_video_overlay_set_window_handle (GST_VIDEO_OVERLAY (vsink), xwinid);
    }
    gst_element_set_state (pipeline, GST_STATE_PLAYING);
}

void PlayerWindow::onPauseClicked() {
    gst_element_set_state (pipeline, GST_STATE_PAUSED);
}

void PlayerWindow::onStopClicked() {
    gst_element_set_state (pipeline, GST_STATE_NULL);
}

void PlayerWindow::onAlbumAvaiable(const QString &album) {
    setWindowTitle(album);
}

void PlayerWindow::onState(GstState st) {
    if (state != st) {
        state = st;
        if (state == GST_STATE_PLAYING){
            timer->start(1000);
        }
        if (state < GST_STATE_PAUSED){
            timer->stop();
        }
    }
}

void PlayerWindow::refreshSlider() {
    gint64 current = GST_CLOCK_TIME_NONE;
    if (state == GST_STATE_PLAYING) {
        if (!GST_CLOCK_TIME_IS_VALID(totalDuration)) {
            if (gst_element_query_duration (pipeline, GST_FORMAT_TIME, &totalDuration)) {
                slider->setRange(0, totalDuration/GST_SECOND);
            }
        }
        if (gst_element_query_position (pipeline, GST_FORMAT_TIME, &current)) {
            g_print("%ld / %ld\n", current/GST_SECOND, totalDuration/GST_SECOND);
            slider->setValue(current/GST_SECOND);
        }
    }
}

void PlayerWindow::onSeek() {
    gint64 pos = slider->sliderPosition();
    g_print("seek: %ld\n", pos);
    gst_element_seek_simple (pipeline, GST_FORMAT_TIME, GST_SEEK_FLAG_FLUSH ,
                  pos * GST_SECOND);
}

void PlayerWindow::onEos() {
    gst_element_set_state (pipeline, GST_STATE_NULL);
}

gboolean PlayerWindow::postGstMessage(GstBus * bus, GstMessage * message, gpointer user_data) {
    PlayerWindow *pw = NULL;
    if (user_data) {
        pw = reinterpret_cast<PlayerWindow*>(user_data);
    }
    switch (GST_MESSAGE_TYPE(message)) {
        case GST_MESSAGE_STATE_CHANGED: {
            GstState old_state, new_state, pending_state;
            gst_message_parse_state_changed (message, &old_state, &new_state, &pending_state);
            pw->sigState(new_state);
            break;
        }
        case GST_MESSAGE_TAG: {
            GstTagList *tags = NULL;
            gst_message_parse_tag(message, &tags);
            gchar *album= NULL;
            if (gst_tag_list_get_string(tags, GST_TAG_ALBUM, &album)) {
                pw->sigAlbum(album);
                g_free(album);
            }
            gst_tag_list_unref(tags);
            break;
        }
        case GST_MESSAGE_EOS: {
            pw->sigEos();
            break;
        }
        default:
            break;
    }
    return TRUE;
}


