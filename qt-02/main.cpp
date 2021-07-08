#include "qtoverlay.h"
#include <QApplication>
#include <gst/gst.h>
#include <gst/video/videooverlay.h>


int main(int argc, char *argv[])
{
  gst_init (&argc, &argv);
  QApplication app(argc, argv);
  app.connect(&app, SIGNAL(lastWindowClosed()), &app, SLOT(quit ()));

  // prepare the pipeline
//  GstElement *pipeline = gst_parse_launch ("playbin uri=file://apink.webm", NULL);
  GstElement *pipeline = gst_parse_launch("gst-launch-1.0 filesrc location=apink.mp4 ! qtdemux ! queue ! h264parse ! mppvideodec ! waylandsink",
                NULL);
  // prepare the ui
  PlayerWindow *window = new PlayerWindow(pipeline);
  window->resize(300,300);
  window->show();

  // seg window id to gstreamer
  GstElement *vsink = gst_element_factory_make ("ximagesink", "vsink");
  WId xwinid = window->getVideoWId();
  gst_video_overlay_set_window_handle (GST_VIDEO_OVERLAY (vsink), xwinid);
  g_object_set(GST_OBJECT(pipeline), "video-sink", vsink, NULL);

  // connect to interesting signals
  GstBus *bus = gst_element_get_bus(pipeline);
  gst_bus_add_watch(bus, &PlayerWindow::postGstMessage, window);
  gst_object_unref(bus);

  // run the pipeline
  GstStateChangeReturn sret = gst_element_set_state (pipeline, GST_STATE_PLAYING);
  if (sret == GST_STATE_CHANGE_FAILURE) {
    gst_element_set_state (pipeline, GST_STATE_NULL);
    gst_object_unref (pipeline);
    // Exit application
    //QTimer::singleShot(, QApplication::activeWindow(), SLOT(quit()));
  }

  int ret = app.exec();

  window->hide();
  gst_element_set_state (pipeline, GST_STATE_NULL);
  gst_object_unref (pipeline);

  return ret;
}
