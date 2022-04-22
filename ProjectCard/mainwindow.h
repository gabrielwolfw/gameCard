#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QTimer>
#include <QTime>
#include <QMessageBox>
#include <QVector>
#include <QHash>
#include <QString>
#include <random>



#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QTimer *timer = new QTimer();
    QTime time;
    int matchesLeft;
    QMessageBox mgBox;
    QVector <QString> cards{"card_1","card_2","card_3","card_4","card_5","card_6",
                            "card_7","card_8","card_9","card_10","card_11","card_12"};
    int score;
    QHash<QString,QString> allocate;
    bool active_Game;
    QPushButton* pastCard;
    QPushButton* actualCard;






private slots:
    void updateStatus();
    void updateTimer();
    void Result();
    void restartGame();
    void matchedCard();
    void shuffleCards();
    void allocateCard();
    void showCard();
    void parcialResult();
    void restartCards();




private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
