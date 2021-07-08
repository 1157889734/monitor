#ifndef QTOVERLAY_H
#define QTOVERLAY_H

#include <QWidget>
#include <QTimer>

#include <gst/gst.h>
#include <QPushButton>
#include <QSlider>

namespace Ui {
class qtoverlay;
}

class qtoverlay : public QWidget
{
    Q_OBJECT

public:
    explicit qtoverlay(GstElement *p =nullptr);
    ~qtoverlay();

    static gboolean postGstMessage(GstBus * bus, GstMessage * message, gpointer user_data);


private:
    Ui::qtoverlay *ui;
    GstState state;
    gint64 totalDuration;
    GstElement *pipeline;
    QWidget *videoWindow;


signals:
  void sigAlbum(const QString &album);
  void sigState(GstState st);
  void sigEos();


public:
    QTimer *timer;
    WId getVideoWId() const ;


public slots:
    void onPlayClicked();
    void onPauseClicked() ;
    void onStopClicked() ;
    void refreshSlider();
    void slideronSeek();


};

#endif // QTOVERLAY_H
