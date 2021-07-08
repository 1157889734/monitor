#include "qtoverlay.h"
#include <QApplication>
#include <gst/gst.h>
#include <gst/video/videooverlay.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    gst_init (&argc, &argv);

    GstElement *pipeline;
    GstBus *bus;
    GstMessage *msg;

#if 1
    /* Build the pipeline */
    pipeline = gst_parse_launch("gst-launch-1.0 filesrc location=11.mp4 ! qtdemux ! queue ! h264parse ! mppvideodec ! waylandsink",
                  NULL);

    qtoverlay *window = new qtoverlay(pipeline);
    window->resize(600, 300);
    window->show();

    GstElement *vsink = gst_element_factory_make ("ximagesink", "vsink");
    WId xwinid = window->getVideoWId();
    gst_video_overlay_set_window_handle (GST_VIDEO_OVERLAY (vsink), xwinid);
    g_object_set(GST_OBJECT(pipeline), "video-sink", vsink, NULL);


    /* Wait until error or EOS */
    bus = gst_element_get_bus (pipeline);
    msg = gst_bus_timed_pop_filtered (bus, GST_CLOCK_TIME_NONE,
        GST_MESSAGE_ERROR);

    /* Start playing */
    gst_element_set_state (pipeline, GST_STATE_PLAYING);

    g_main_loop_run(g_main_loop_new(NULL, FALSE));

    /* Free resources */
    if (msg != NULL)
      gst_message_unref (msg);
    gst_object_unref (bus);
    gst_element_set_state (pipeline, GST_STATE_NULL);
    gst_object_unref (pipeline);




#endif

#if 0
    pipeline = gst_parse_launch("gst-launch-1.0 filesrc location=22.mp4 ! qtdemux ! queue ! h264parse ! mppvideodec ! waylandsink",
                  NULL);

    qtoverlay *playWindow = new qtoverlay(pipeline);
    playWindow->resize(900,600);
    playWindow->show();

    GstElement *vsink = gst_element_factory_make ("waylandsink", "vsink");

    WId xwind = playWindow->getVideoWId();
    gst_video_overlay_set_window_handle(GST_VIDEO_OVERLAY (vsink),xwind);
    g_object_set(GST_OBJECT(pipeline), "video-sink", vsink, NULL);

    GstStateChangeReturn sret = gst_element_set_state (pipeline, GST_STATE_PLAYING);
    if (sret == GST_STATE_CHANGE_FAILURE) {
      gst_element_set_state (pipeline, GST_STATE_NULL);
      gst_object_unref (pipeline);
      // Exit application
      //QTimer::singleShot(0, QApplication::activeWindow(), SLOT(quit()));
    }

    g_main_loop_run(g_main_loop_new(NULL, FALSE));

    /* Wait until error or EOS */
    bus = gst_element_get_bus (pipeline);
    msg = gst_bus_timed_pop_filtered (bus, GST_CLOCK_TIME_NONE,
    GST_MESSAGE_ERROR);
    if (msg != NULL)
        gst_message_unref (msg);
    gst_object_unref (bus);
    gst_element_set_state (pipeline, GST_STATE_NULL);
    gst_object_unref (pipeline);
#endif
//    qtoverlay w;
//    w.show();

    return a.exec();
}
