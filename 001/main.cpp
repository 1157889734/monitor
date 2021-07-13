#include "widget.h"
#include <QApplication>
#include <glib.h>
#include <gst/gst.h>
#include <gst/video/videooverlay.h>

#include <QApplication>
#include <QTimer>
#include <QWidget>
#include <QDebug>

#if 0
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    Widget w;
    w.show();

    return a.exec();
}
#endif

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
//  if (!g_thread_supported ())
//    g_thread_init (NULL);

  gst_init (&argc, &argv);
  QApplication app(argc, argv);
  app.connect(&app, SIGNAL(lastWindowClosed()), &app, SLOT(quit ()));
#if 1
  gchar *urlVedio1 = "rtsp://admin:admin123@168.168.102.20";
#if 0

  GstElement *pipeline = gst_pipeline_new ("xvoverlay");

  GstElement *appSrc = gst_element_factory_make ("rtspsrc", NULL);
  GstElement *waySink = gst_element_factory_make("waylandsink",NULL);

  gst_bin_add_many (GST_BIN (pipeline), appSrc, waySink, NULL);

  g_object_set (appSrc, "location", urlVedio1,"latency" , 300,  NULL);

  gst_element_link (appSrc, waySink);

  // prepare the pipeline
#endif

#if 1
  GstElement *pipeline = gst_pipeline_new ("xvoverlay");
  GstElement *appSrc = gst_element_factory_make ("rtspsrc", NULL);
  GstElement *rtpDepay = gst_element_factory_make("rtph264depay",NULL);
  GstElement *rtph265Parse = gst_element_factory_make("h264parse",NULL);
  GstElement *vpuDecode = gst_element_factory_make("mppvideodec",NULL);
  GstElement *waySink = gst_element_factory_make("waylandsink",NULL);

  //GstElement *sink = gst_element_factory_make ("xvimagesink", NULL);

  if( !pipeline || !appSrc || !rtpDepay || !rtph265Parse || !vpuDecode  || !waySink )
  {
      g_printerr ("One of the elements wasn't created... Exiting\n");
      return -1;
  }

  g_object_set (appSrc, "location", urlVedio1,"latency" , 300,  NULL);

  gst_bin_add_many (GST_BIN (pipeline), appSrc, rtpDepay, rtph265Parse, vpuDecode, waySink, NULL);

  if (!gst_element_link_many (rtpDepay, rtph265Parse, vpuDecode, waySink, NULL))
  {
      g_warning ("Linking part (A)-1 Fail...");
      return -1;
  }
  // gst_element_link (appSrc, waySink);

  if(! g_signal_connect (appSrc, "pad-added", G_CALLBACK (on_pad_added), rtpDepay))
  {
      g_warning ("Linking part (1) with part (A)-1 Fail...");
  }
#endif
//  gst_bin_add_many (GST_BIN (pipeline), src, sink, NULL);
//  gst_element_link (src, sink);

  // prepare the ui

  Widget window;
  //window.resize(960, 800);
  window.setGeometry(10,10,960,600);
  //window.setWindowTitle("test1111111111111");
  window.show();

  WId xwinid = window.winId();
  qDebug()<<"get***"<<xwinid;
  //gst_video_overlay_expose(GST_VIDEO_OVERLAY(waySink));
  //gst_video_overlay_set_window_handle (GST_VIDEO_OVERLAY (waySink), guintptr(xwinid));

  if(! gst_video_overlay_set_render_rectangle (GST_VIDEO_OVERLAY (waySink),100,100,600,600))
  {
      g_warning ("gst_video_overlay_set_render_rectangle Fail...");

  }

  // run the pipeline

  GstStateChangeReturn sret = gst_element_set_state (pipeline,
      GST_STATE_PLAYING);
  if (sret == GST_STATE_CHANGE_FAILURE) {
    gst_element_set_state (pipeline, GST_STATE_NULL);
    gst_object_unref (pipeline);
    // Exit application
    QTimer::singleShot(0, QApplication::activeWindow(), SLOT(quit()));
  }

  int ret = app.exec();

  window.hide();
  gst_element_set_state (pipeline, GST_STATE_NULL);
  gst_object_unref (pipeline);
#endif


  return ret;
}
