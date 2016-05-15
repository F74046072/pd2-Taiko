#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    ui->graphicsView->setGeometry(0,0,800,600);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setScene(scene);

    music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/music/openmusic.mp3"));
    don = new QMediaPlayer();
    don->setMedia(QUrl("qrc:/music/don.mp3"));
    ka = new QMediaPlayer();
    ka->setMedia(QUrl("qrc:/music/ka.mp3"));

    ui->startbtn->setGeometry(80,500,200,50);
    ui->exitbtn->setGeometry(520,500,200,50);
    ui->againbtn->setGeometry(550,500,200,50);

    ui->loading->setGeometry(550,500,300,100);
    ui->counter->setGeometry(50,50,100,50);
    ui->score->setGeometry(550,50,100,50);
    ui->counterLCD->setGeometry(150,50,100,50);
    ui->scoreLCD->setGeometry(650,50,100,50);

    ui->combobar->setGeometry(30,330,200,80);
    ui->combo10num0->setGeometry(40,300,60,100);
    ui->combo10num1->setGeometry(40,300,60,100);
    ui->combo10num2->setGeometry(40,300,60,100);
    ui->combo10num3->setGeometry(40,300,60,100);
    ui->combo10num4->setGeometry(40,300,60,100);
    ui->combo10num5->setGeometry(40,300,60,100);
    ui->combo10num6->setGeometry(40,300,60,100);
    ui->combo10num7->setGeometry(40,300,60,100);
    ui->combo10num8->setGeometry(40,300,60,100);
    ui->combo10num9->setGeometry(40,300,60,100);
    ui->combo1num0->setGeometry(100,300,60,100);
    ui->combo1num1->setGeometry(100,300,60,100);
    ui->combo1num2->setGeometry(100,300,60,100);
    ui->combo1num3->setGeometry(100,300,60,100);
    ui->combo1num4->setGeometry(100,300,60,100);
    ui->combo1num5->setGeometry(100,300,60,100);
    ui->combo1num6->setGeometry(100,300,60,100);
    ui->combo1num7->setGeometry(100,300,60,100);
    ui->combo1num8->setGeometry(100,300,60,100);
    ui->combo1num9->setGeometry(100,300,60,100);

    ui->good->setGeometry(25,150,150,150);
    ui->ok->setGeometry(25,150,150,150);
    ui->miss->setGeometry(25,150,150,150);
    ui->goodicon->setGeometry(75,110,50,50);
    ui->okicon->setGeometry(75,110,50,50);
    ui->missicon->setGeometry(55,110,90,50);

    ui->finalscoreTXT->setGeometry(450,0,300,100);
    ui->finalscore->setGeometry(550,80,80,100);
    ui->highscoreTXT->setGeometry(50,0,300,100);
    ui->highscore->setGeometry(150,80,80,100);
    ui->comboTXT->setGeometry(250,80,300,100);
    ui->combo->setGeometry(350,160,80,100);

    ui->result->setGeometry(450,280,100,125);
    ui->resultsuccess->setGeometry(570,280,60,60);
    ui->resultfail->setGeometry(570,340,60,60);
    ui->goodTXT->setGeometry(650,250,50,50);
    ui->resultgood->setGeometry(700,250,50,50);
    ui->okTXT->setGeometry(650,300,50,50);
    ui->resultok->setGeometry(700,300,50,50);

    ui->loading->hide();
    ui->againbtn->hide();
    ui->counter->hide();
    ui->score->hide();
    ui->counterLCD->hide();
    ui->scoreLCD->hide();

    ui->combobar->hide();
    ui->combo10num0->hide();
    ui->combo10num1->hide();
    ui->combo10num2->hide();
    ui->combo10num3->hide();
    ui->combo10num4->hide();
    ui->combo10num5->hide();
    ui->combo10num6->hide();
    ui->combo10num7->hide();
    ui->combo10num8->hide();
    ui->combo10num9->hide();
    ui->combo1num0->hide();
    ui->combo1num1->hide();
    ui->combo1num2->hide();
    ui->combo1num3->hide();
    ui->combo1num4->hide();
    ui->combo1num5->hide();
    ui->combo1num6->hide();
    ui->combo1num7->hide();
    ui->combo1num8->hide();
    ui->combo1num9->hide();

    ui->good->hide();
    ui->ok->hide();
    ui->miss->hide();
    ui->goodicon->hide();
    ui->okicon->hide();
    ui->missicon->hide();

    ui->finalscoreTXT->hide();
    ui->finalscore->hide();
    ui->highscoreTXT->hide();
    ui->highscore->hide();
    ui->comboTXT->hide();
    ui->combo->hide();

    ui->result->hide();
    ui->resultsuccess->hide();
    ui->resultfail->hide();
    ui->goodTXT->hide();
    ui->resultgood->hide();
    ui->okTXT->hide();
    ui->resultok->hide();

    highscore=0;
    open();
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::open(){
    QImage bg;
    bg.load(":/img/openbg.jpg");
    scene->setBackgroundBrush(bg);
    music->play();
}

void MainWindow::game(){
    QImage bg;
    bg.load(":/img/gamebg.png");
    scene->setBackgroundBrush(bg);
    music->play();

    time=30;
    score=0;
    combo=0;
    maxcombo=0;
    success=0;
    fail=0;
    good=0;
    ok=0;

    ui->counter->show();
    ui->score->show();
    ui->counterLCD->show();
    ui->counterLCD->display(time);
    ui->scoreLCD->show();
    ui->scoreLCD->display(score);
    ui->combobar->show();

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timeElapse()));
    timer->start(1000);
}

void MainWindow::gameover(){
    QImage bg;
    bg.load(":/img/gameover.png");
    scene->setBackgroundBrush(bg);
    music->stop();
    music->setMedia(QUrl("qrc:/music/overmusic.mp3"));
    music->play();

    if(score>highscore) highscore=score;
    ui->againbtn->show();
    ui->finalscoreTXT->show();
    ui->finalscore->setText(QString::number(score));
    ui->finalscore->show();
    ui->highscoreTXT->show();
    ui->highscore->setText(QString::number(highscore));
    ui->highscore->show();
    ui->comboTXT->show();
    ui->combo->setText(QString::number(maxcombo));
    ui->combo->show();

    ui->result->show();
    ui->resultsuccess->setText(QString::number(success));
    ui->resultsuccess->show();
    ui->resultfail->setText(QString::number(fail));
    ui->resultfail->show();
    ui->goodTXT->show();
    ui->resultgood->setText(QString::number(good));
    ui->resultgood->show();
    ui->okTXT->show();
    ui->resultok->setText(QString::number(ok));
    ui->resultok->show();
}

void MainWindow::timeElapse(){
    if(time>0) time--;
    ui->counterLCD->display(time);
    if(time>4){
        makedrum();
        int randtime=200+rand()%200;
        QTimer::singleShot(randtime, this, SLOT(makedrum()));
        int randtime2=600+rand()%200;;
        QTimer::singleShot(randtime2, this, SLOT(makedrum()));
    }

    if(time==0){
        ui->counter->hide();
        ui->score->hide();
        ui->counterLCD->hide();
        ui->scoreLCD->hide();
        ui->combobar->hide();

        timer->stop();
        gameover();
    }
}

void MainWindow::makedrum(){
    Drum *drum = new Drum();
    drum->setFlag(QGraphicsItem::ItemIsFocusable);
    scene->addItem(drum);
}

void MainWindow::scoreplus(){
    score++;
    ui->scoreLCD->display(score);   
    success++;

    combo++;
    if(combo>maxcombo) maxcombo=combo;
    if(combo<10){
        switch(combo){
            case 0:ui->combo1num0->show(); break;
            case 1:ui->combo1num1->show(); break;
            case 2:ui->combo1num2->show(); break;
            case 3:ui->combo1num3->show(); break;
            case 4:ui->combo1num4->show(); break;
            case 5:ui->combo1num5->show(); break;
            case 6:ui->combo1num6->show(); break;
            case 7:ui->combo1num7->show(); break;
            case 8:ui->combo1num8->show(); break;
            case 9:ui->combo1num9->show(); break;
        }
        QTimer::singleShot(150, this, SLOT(del()));
    }
    else if(combo>10){
        int combo10=combo/10;
        int combo1=combo%10;
        switch(combo10){
            case 0:ui->combo10num0->show(); break;
            case 1:ui->combo10num1->show(); break;
            case 2:ui->combo10num2->show(); break;
            case 3:ui->combo10num3->show(); break;
            case 4:ui->combo10num4->show(); break;
            case 5:ui->combo10num5->show(); break;
            case 6:ui->combo10num6->show(); break;
            case 7:ui->combo10num7->show(); break;
            case 8:ui->combo10num8->show(); break;
            case 9:ui->combo10num9->show(); break;
        }
        switch(combo1){
            case 0:ui->combo1num0->show(); break;
            case 1:ui->combo1num1->show(); break;
            case 2:ui->combo1num2->show(); break;
            case 3:ui->combo1num3->show(); break;
            case 4:ui->combo1num4->show(); break;
            case 5:ui->combo1num5->show(); break;
            case 6:ui->combo1num6->show(); break;
            case 7:ui->combo1num7->show(); break;
            case 8:ui->combo1num8->show(); break;
            case 9:ui->combo1num9->show(); break;
        }
        QTimer::singleShot(150, this, SLOT(del()));
    }
}

void MainWindow::goodshow(){
    ui->good->show();
    ui->goodicon->show();
    good++;
    QTimer::singleShot(150, this, SLOT(del()));
}

void MainWindow::okshow(){
    ui->ok->show();
    ui->okicon->show();
    ok++;
    QTimer::singleShot(150, this, SLOT(del()));
}

void MainWindow::missshow(){
    ui->miss->show();
    ui->missicon->show();
    combo=0;
    fail++;
    QTimer::singleShot(150, this, SLOT(del()));
}

void MainWindow::del(){
    ui->good->hide();
    ui->ok->hide();
    ui->miss->hide();
    ui->goodicon->hide();
    ui->okicon->hide();
    ui->missicon->hide();
    ui->combo10num0->hide();
    ui->combo10num1->hide();
    ui->combo10num2->hide();
    ui->combo10num3->hide();
    ui->combo10num4->hide();
    ui->combo10num5->hide();
    ui->combo10num6->hide();
    ui->combo10num7->hide();
    ui->combo10num8->hide();
    ui->combo10num9->hide();
    ui->combo1num0->hide();
    ui->combo1num1->hide();
    ui->combo1num2->hide();
    ui->combo1num3->hide();
    ui->combo1num4->hide();
    ui->combo1num5->hide();
    ui->combo1num6->hide();
    ui->combo1num7->hide();
    ui->combo1num8->hide();
    ui->combo1num9->hide();
}

void MainWindow::waiting(){
    ui->loading->hide();
    ChooseMusic *chm = new ChooseMusic;
    chm->setWindowTitle("選擇曲目");
    chm->setFixedSize(600,400);
    chm->show();
}

void MainWindow::on_startbtn_clicked(){
    QImage bg;
    bg.load(":/img/tutorial.png");
    scene->setBackgroundBrush(bg);

    ui->loading->show();
    ui->startbtn->hide();
    ui->exitbtn->hide();   
    QTimer::singleShot(3000, this, SLOT(waiting()));
}

void MainWindow::on_exitbtn_clicked(){
    close();
}

void MainWindow::on_againbtn_clicked(){
    music->stop();
    ui->finalscoreTXT->hide();
    ui->finalscore->hide();
    ui->highscoreTXT->hide();
    ui->highscore->hide();
    ui->comboTXT->hide();
    ui->combo->hide();

    ui->result->hide();
    ui->resultsuccess->hide();
    ui->resultfail->hide();
    ui->goodTXT->hide();
    ui->resultgood->hide();
    ui->okTXT->hide();
    ui->resultok->hide();

    ui->againbtn->hide();
    waiting();
}

void MainWindow::keyPressEvent(QKeyEvent *keyevent){
    if(keyevent->key()==Qt::Key_F){
        don->play();
    }
    if(keyevent->key()==Qt::Key_J){
        ka->play();
    }
}
