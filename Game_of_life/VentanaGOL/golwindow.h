#ifndef GOLWINDOW_H
#define GOLWINDOW_H

#include <QMainWindow>

namespace Ui {
class GOLwindow;
}

class GOLwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GOLwindow(QWidget *parent = 0);
    ~GOLwindow();

private slots:
    void on_playButton_clicked();

    void on_openGLWidget_aboutToCompose();

private:
    Ui::GOLwindow *ui;
};

#endif // GOLWINDOW_H
