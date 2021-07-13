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
 // GstElement *pipeline = gst_parse_launch ("playbin uri=file:///apink.webm", NULL);
  GstElement *pipeline = gst_parse_launch(" gst-lauch-1.0 filesrc location=apink.mp4 ! qtdemux ! queue ! h264parse ! mppvideodec ! waylandsink", NULL);
  // prepare the ui
  PlayerWindow *window = new PlayerWindow(pipeline);
  window->resize(600,500);

  QWidget  xwindow;
  xwindow.resize(300,200);
  xwindow.setWindowTitle("Qt demo");
  xwindow.show();

//  guintptr window_handle;
//  window_handle = (guintptr)(xwindow.winId());
//  gst_video_overlay_set_window_handle(GST_VIDEO_OVERLAY(pipeline),window_handle);

//

  //WId xwind = xwindow.winId();
  // seg window id to gstreamer
  //GstElement *vsink = gst_element_factory_make ("waylandsink", "vsink");
//  GstElement *sink = gst_bin_get_by_name( GST_BIN( pipeline ), "mysink" );
 // gst_bin_add_many( GST_BIN( pipeline ), vsink, nullptr );

  WId xwinid = window->getVideoWId();
  gst_video_overlay_set_window_handle (GST_VIDEO_OVERLAY (pipeline), xwinid);
//  g_object_set(GST_OBJECT(pipeline), "video-sink", vsink, NULL);

  //QApplication::syncX();
  //gst_x_overlay_set_xwindow_id(, window_handle);

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
    QTimer::singleShot(0, QApplication::activeWindow(), SLOT(quit()));
  }

  int ret = app.exec();

  window->hide();
  gst_element_set_state (pipeline, GST_STATE_NULL);
  gst_object_unref (pipeline);

  return ret;
}
