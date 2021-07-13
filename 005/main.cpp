#include "qtoverlay.h"
#include <QApplication>
#include <gst/video/videooverlay.h>
#if 0
static GstBusSyncReply
create_window (GstBus * bus, GstMessage * message, GstPipeline * pipeline)
{
 // ignore anything but 'prepare-xwindow-id' element messages
 if (GST_MESSAGE_TYPE (message) != GST_MESSAGE_ELEMENT)
   return GST_BUS_PASS;

 if (!gst_structure_has_name (message->structure, "prepare-xwindow-id"))
   return GST_BUS_PASS;

 win = XCreateSimpleWindow (disp, root, 0, 0, 320, 240, 0, 0, 0);

 XSetWindowBackgroundPixmap (disp, win, None);

 XMapRaised (disp, win);

 XSync (disp, FALSE);

 gst_x_overlay_set_window_handle (GST_X_OVERLAY (GST_MESSAGE_SRC (message)),
     win);

 gst_message_unref (message);

 return GST_BUS_DROP;
}
#endif
int main(int argc, char *argv[])
{
  gst_init (&argc, &argv);
  QApplication app(argc, argv);
  app.connect(&app, SIGNAL(lastWindowClosed()), &app, SLOT(quit ()));

  // prepare the pipeline
  GstElement *pipeline = gst_parse_launch ("playbin uri=file:///userdata/11.mp4", NULL);
  GstElement *vsink = gst_element_factory_make ("waylandsink", "vsink");


//   gst_bin_add_many (GST_BIN (pipeline), vsink, NULL);
  // prepare the ui
  PlayerWindow *window = new PlayerWindow(pipeline);
  window->setGeometry(10,30,960,600);
  window->setWindowTitle("qtoverlay");
//  window->resize(900, 600);
  window->show();


// GstBus *testbus = gst_pipeline_get_bus (GST_PIPELINE (pipeline));
//  gst_bus_set_sync_handler (testbus, (GstBusSyncHandler) create_window, pipeline,
//        NULL);
  // seg window id to gstreamer


  WId xwinid = window->getVideoWId();
//  gst_video_overlay_set_window_handle (GST_VIDEO_OVERLAY (vsink), xwinid);
  g_object_set(GST_OBJECT(pipeline), "video-sink", vsink, NULL);

//    gst_video_overlay_expose(GST_VIDEO_OVERLAY (vsink));
//    gst_video_overlay_prepare_window_handle(GST_VIDEO_OVERLAY (vsink));
  if(! gst_video_overlay_set_render_rectangle (GST_VIDEO_OVERLAY (vsink),10,40,900,600))
  {
      g_warning ("gst_video_overlay_set_render_rectangle Fail...");

  }
    gst_video_overlay_expose(GST_VIDEO_OVERLAY(vsink));

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
