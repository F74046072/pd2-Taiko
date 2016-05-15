#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Drum.h"
#include "choosemusic.h"
#include "stdlib.h"
#include <QMainWindow>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QKeyEvent>
#include <QTimer>

namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QGraphicsScene *scene;
    QMediaPlayer *music;
    QMediaPlayer *don;
    QMediaPlayer *ka;
    QTimer *timer;
    void open();
    void game();
    void gameover();
    void scoreplus();
    void goodshow();
    void okshow();
    void missshow();
    void keyPressEvent(QKeyEvent *keyevent);
private slots:
    void on_startbtn_clicked();
    void on_exitbtn_clicked();
    void on_againbtn_clicked();
    void makedrum();
    void timeElapse();
    void waiting();
    void del();
private:  
    Ui::MainWindow *ui;
    int time;
    int combo;
    int maxcombo;
    int goodcount;
    int okcount;
    int misscount;
    int score;
    int highscore;
    int success;
    int fail;
    int good;
    int ok;
};

#endif // MAINWINDOW_H
