#include "mainwindow.h"
#include "./ui_mainwindow.h"


//Author: Kevin Gabriel Lobo Juárez
//
//Date:01/04/22
//
//
//
//
//
//
//

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(timer, SIGNAL(timeout()),this, SLOT(updateStatus()));

    connect(ui->card_1, SIGNAL(clicked()),this, SLOT(matchedCard()));
    connect(ui->card_2, SIGNAL(clicked()),this, SLOT(matchedCard()));
    connect(ui->card_3, SIGNAL(clicked()),this, SLOT(matchedCard()));
    connect(ui->card_4, SIGNAL(clicked()),this, SLOT(matchedCard()));
    connect(ui->card_5, SIGNAL(clicked()),this, SLOT(matchedCard()));
    connect(ui->card_6, SIGNAL(clicked()),this, SLOT(matchedCard()));
    connect(ui->card_7, SIGNAL(clicked()),this, SLOT(matchedCard()));
    connect(ui->card_8, SIGNAL(clicked()),this, SLOT(matchedCard()));
    connect(ui->card_9, SIGNAL(clicked()),this, SLOT(matchedCard()));
    connect(ui->card_10, SIGNAL(clicked()),this, SLOT(matchedCard()));
    connect(ui->card_11, SIGNAL(clicked()),this, SLOT(matchedCard()));
    connect(ui->card_12, SIGNAL(clicked()),this, SLOT(matchedCard()));
    restartGame();

}



void MainWindow:: restartGame(){
    active_Game = false;
    score = 0;
    ui->points_number->setText(QString::number(score));

    matchesLeft = 6;
    time.setHMS(0,1,0);
    ui->temporizador->setText(time.toString("m:ss"));
    timer->start(1000);
    shuffleCards();
    allocateCard();
    ui->frame->setEnabled(true);
    QList<QPushButton*> buttons = ui->centralwidget->findChildren<QPushButton*>();
    //Recorrer la lista
    foreach(QPushButton* i, buttons){
        i->setEnabled(true);
        i->setStyleSheet("#"+ i->objectName()+"{}");
    }
}





void MainWindow:: matchedCard(){
    actualCard = qobject_cast<QPushButton*>(sender());
    showCard();
    actualCard->setEnabled(false);
    //it determinates if a card has been selected or not

    if (!active_Game){
        pastCard = actualCard;
        active_Game = true;
    }
    else{
        parcialResult(); //it defines if there's a win while the game is running
        active_Game = false;

    }
}
void MainWindow:: Result(){
    mgBox.setWindowTitle("Finished Session");
    mgBox.setIcon(QMessageBox:: Information);
    mgBox.setStandardButtons(QMessageBox::Yes);
    mgBox.addButton(QMessageBox::No);
    mgBox.setDefaultButton(QMessageBox:: Yes);

    if (matchesLeft == 0){
        timer->stop();
        ui->frame->setEnabled(false);
        mgBox.setText("Congrats!Total Points:"+ QString::number(score) + "\n Do you want to try again?");
        if (QMessageBox::Yes ==mgBox.exec()){
            restartGame();

        }else{
            QCoreApplication:: quit();

        }
    }else{
        if (time.toString()=="00:00:00"){
        }
    }
}

//Terminar en la madrugada 10:51 pm 04/04/2022
void MainWindow:: parcialResult(){
    if (allocate[actualCard->objectName()] == allocate[pastCard->objectName()]){
        score += 2 ;
        ui->points_number->setText(QString::number(score));
        matchesLeft--;
        Result();
    }else{
        ui->points_number->setText(QString::number(score));
        ui->frame->setEnabled(false);
        QTimer::singleShot(1000,this,SLOT(restartCards()));
    }
}
void MainWindow:: restartCards(){
    actualCard->setStyleSheet("#" + actualCard->objectName()+"{}");
    pastCard->setStyleSheet("#" + pastCard->objectName()+"{}");
    actualCard->setEnabled(true);
    pastCard->setEnabled(true);
    ui->frame->setEnabled(true);

}






//It shows image's card
void MainWindow:: showCard(){
    QString card_name = actualCard->objectName();
    QString img = allocate[card_name];
    actualCard->setStyleSheet("#" + card_name + "{background-image: url(:/CardImages/"+img+")}" );
}


//timer -> function to control time


void MainWindow:: updateTimer(){
    time = time.addSecs(-1);
    ui->temporizador->setText(time.toString("m:ss"));
}
void MainWindow:: updateStatus(){
    updateTimer();
    Result();
}


//This function shuffle all the cards in the game
void MainWindow::shuffleCards(){
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(cards.begin(), cards.end(),std::default_random_engine(seed));

}

void MainWindow::allocateCard(){
    auto iterator = cards.begin();
    for (int i = 6; i <= 6; i++) {
        QString file_name = "0"+ QString::number(i)+".png";
        allocate[(*iterator)] = file_name;
        iterator++;
        allocate[(*iterator)] = file_name;
        iterator++;
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

