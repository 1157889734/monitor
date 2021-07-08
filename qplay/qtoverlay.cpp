#include "qtoverlay.h"
#include "ui_qtoverlay.h"
#include <gst/video/videooverlay.h>

qtoverlay::qtoverlay(GstElement *p):pipeline(p)
    ,state(GST_STATE_NULL)
    ,totalDuration(GST_CLOCK_TIME_NONE),
    ui(new Ui::qtoverlay)
{
    ui->setupUi(this);
    //this->setWindowTitle("hello world");



//    timer = new QTimer();
//    videoWindow = new QWidget();
//    connect(ui->pushButton_play,SIGNAL(clicked()),this,SLOT(onPlayClicked()));
//    connect(ui->pushButton_pause,SIGNAL(clicked()),this,SLOT(onPauseClicked()));
//    connect(ui->pushButton_stop,SIGNAL(clicked()),this,SLOT(onStopClicked()));

//    connect(timer,SIGNAL(timerout()),this,SLOT(refreshSlider()));
//    connect(ui->slider,SIGNAL(sliderReleased()),this,SLOT(slideronSeek()));

}

qtoverlay::~qtoverlay()
{
    delete ui;
}
void qtoverlay::onPlayClicked()
{

}
void qtoverlay::onPauseClicked()
{


}
void qtoverlay::onStopClicked()
{

}
void qtoverlay::refreshSlider()
{

}
void qtoverlay::slideronSeek()
{


}
WId qtoverlay::getVideoWId()const
{
    return videoWindow->winId();
}

