#ifndef _QTOVERLAY_
#define _QTOVERLAY_

#include <gst/gst.h>

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSlider>
#include <QTimer>

class PlayerWindow : public QWidget
{
    Q_OBJECT
public:
  PlayerWindow(GstElement *p);

  WId getVideoWId() const ;
  static gboolean postGstMessage(GstBus * bus, GstMessage * message, gpointer user_data);

private slots:
  void onPlayClicked() ;
  void onPauseClicked() ;
  void onStopClicked() ;
  void onAlbumAvaiable(const QString &album);
  void onState(GstState st);
  void refreshSlider();
  void onSeek();
  void onEos();

signals:
  void sigAlbum(const QString &album);
  void sigState(GstState st);
  void sigEos();

private:
  GstElement *pipeline;
  QPushButton *playBt;
  QPushButton *pauseBt;
  QPushButton *stopBt;
  QWidget *videoWindow;
  QSlider *slider;
  QHBoxLayout *buttonLayout;
  QVBoxLayout *playerLayout;
  QTimer *timer;

  GstState state;
  gint64 totalDuration;
};

#endif
