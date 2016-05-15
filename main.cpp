#include "mainwindow.h"
#include <QApplication>
MainWindow *m;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    m = new MainWindow;
    m->setFixedSize(800,600);
    m->setWindowTitle("太鼓達人");
    m->show();

    return a.exec();
}
