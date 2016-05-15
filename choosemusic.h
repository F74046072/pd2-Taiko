#ifndef CHOOSEMUSIC_H
#define CHOOSEMUSIC_H

#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class ChooseMusic;
}

class ChooseMusic : public QDialog
{
    Q_OBJECT

public:
    explicit ChooseMusic(QWidget *parent = 0);
    ~ChooseMusic();

private slots:
    void on_music1_clicked();
    void on_music2_clicked();
    void on_music3_clicked();
    void on_music4_clicked();
    void on_music5_clicked();

private:
    Ui::ChooseMusic *ui;
};

#endif // CHOOSEMUSIC_H
