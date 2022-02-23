#include "golwindow.h"
#include "ui_golwindow.h"

GOLwindow::GOLwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GOLwindow)
{
    ui->setupUi(this);
}

GOLwindow::~GOLwindow()
{
    delete ui;
}

void GOLwindow::on_playButton_clicked()
{
    ui->openGLWidget->toggleHold();
}

void GOLwindow::on_openGLWidget_aboutToCompose()
{

}
