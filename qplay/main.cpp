#include "qtoverlay.h"
#include <QApplication>
#include <gst/gst.h>
#include <gst/video/videooverlay.h>
#include <QDebug>
#include <QWidget>

typedef struct _CustomData {
  GstElement *pipeline;
  GstElement *appSrc;
  GstElement *rtpDepay;

  GstElement *qdemux;
  GstElement *queue;

  GstElement *rtph265Parse;
  GstElement *vpuDecode;
  GstElement *imxShowG2d;
  GstElement *waySink;


  GMainLoop *loop;
  GstBus *bus;
} CustomData;

static gboolean bus_call (GstBus *bus, GstMessage *msg, gpointer data)
{
    GMainLoop *loop = (GMainLoop *) data;
    switch (GST_MESSAGE_TYPE (msg)) {
    case GST_MESSAGE_EOS:
        g_print ("Stream Ends\n");
        g_main_loop_quit (loop);
        break;
    case GST_MESSAGE_ERROR: {
        gchar  *debug;
        GError *error;
        gst_message_parse_error (msg, &error, &debug);
        g_free (debug);
        g_printerr ("Error: %s\n", error->message);
        g_error_free (error);
        g_main_loop_quit (loop);
        break;
    }
    default:
        break;
    }
    return TRUE;
}

/* Dynamically link */
static void on_pad_added (GstElement *element, GstPad *pad, gpointer data)
{
    GstPad *sinkpad;
    GstPadLinkReturn ret;
    GstElement *decoder = (GstElement *) data;
    /* We can now link this pad with the rtsp-decoder sink pad */
    g_print ("Dynamic pad created, linking source/demuxer\n");
    sinkpad = gst_element_get_static_pad (decoder, "sink");

    /* If our converter is already linked, we have nothing to do here */
    if (gst_pad_is_linked (sinkpad)) {
        g_print("*** We are already linked ***\n");
        gst_object_unref (sinkpad);
        return;
    } else {
        g_print("proceeding to linking ...\n");
    }
    ret = gst_pad_link (pad, sinkpad);

    if (GST_PAD_LINK_FAILED (ret)) {
        //failed
        g_print("failed to link dynamically\n");
    } else {
        //pass
        g_print("dynamically link successful\n");
    }

    gst_object_unref (sinkpad);
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.connect(&a, SIGNAL(lastWindowClosed()), &a, SLOT(quit ()));
    CustomData data;
    gchar *urlVedio1 = "rtsp://admin:admin123@168.168.102.20";
    /* Initialize GStreamer */
    gst_init (&argc, &argv);
    /* Create the empty pipeline */
    data.pipeline = gst_pipeline_new ("decode_pipe");
    if (!data.pipeline)
    {
        g_printerr ("pipeline created error.\n");
        return -1;
    }
    /* Create the elements */
    data.appSrc = gst_element_factory_make ("rtspsrc", "rtspsrc0");
    data.rtpDepay = gst_element_factory_make ("rtph264depay", "rtph264depay0");	/* H265 */
    data.rtph265Parse = gst_element_factory_make ("h264parse", "h264parse0");;
    data.vpuDecode = gst_element_factory_make ("mppvideodec", "vpudec0");
    //Video Sink
    data.waySink = gst_element_factory_make ("waylandsink", "waylandsink0");
    /* Make sure: Every elements was created ok */
    if( !data.pipeline || !data.appSrc || !data.rtpDepay || !data.rtph265Parse || !data.vpuDecode  || !data.waySink )
    {
        g_printerr ("One of the elements wasn't created... Exiting\n");
        return -1;
    }
    /* element属性设置 */
    g_object_set (data.appSrc, "location", urlVedio1,"latency" , 300,  NULL);
    /* Add Elements to the Bin */
    gst_bin_add_many (GST_BIN (data.pipeline), data.appSrc, data.rtpDepay, data.rtph265Parse, data.vpuDecode, data.waySink, NULL);
    /* Link confirmation */
    if (!gst_element_link_many (data.rtpDepay, data.rtph265Parse, data.vpuDecode, data.waySink, NULL))
    {
        g_warning ("Linking part (A)-1 Fail...");
        return -1;
    }
    if(! g_signal_connect (data.appSrc, "pad-added", G_CALLBACK (on_pad_added), data.rtpDepay))
    {
        g_warning ("Linking part (1) with part (A)-1 Fail...");
    }
    qtoverlay *window = new qtoverlay(data.pipeline);
    window->setWindowTitle("hello video");
    window->resize(1200, 960);
    window->show();

    guintptr window_handle;
    window_handle = (guintptr)(window->winId());
    qDebug()<<"****window_handle"<<window_handle;
    gst_video_overlay_set_window_handle(GST_VIDEO_OVERLAY(data.pipeline),window_handle);


    data.loop = g_main_loop_new (NULL, FALSE);
    data.bus = gst_pipeline_get_bus (GST_PIPELINE (data.pipeline));
    gst_bus_add_watch (data.bus, bus_call, data.loop);
    gst_object_unref (data.bus);


    /* Run the pipeline */
    gst_element_set_state (data.pipeline, GST_STATE_PLAYING);
    g_main_loop_run (data.loop);

    /* Free resources */
    g_main_loop_unref (data.loop);
    gst_object_unref (data.bus);
     int ret = a.exec();

     window->hide();
    gst_element_set_state (data.pipeline, GST_STATE_NULL);
    gst_object_unref (GST_OBJECT (data.pipeline));

#if 0

    GstElement *pipeline;
    GstBus *bus;
    GstMessage *msg;

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
