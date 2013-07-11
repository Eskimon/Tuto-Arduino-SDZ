#ifndef FENETRE_H
#define FENETRE_H

#include <QWidget>
#include <QDebug>
#include <QString>
#include <qextserialport.h>
#include <qextserialenumerator.h>

namespace Ui {
class Fenetre;
}

class Fenetre : public QWidget
{
    Q_OBJECT
    
public:
    explicit Fenetre(QWidget *parent = 0);
    ~Fenetre();

private:
    Ui::Fenetre * ui;
    QextSerialPort * port;

    BaudRateType getBaudRateFromString(QString baudRate);

private slots:
    void on_btnConnection_clicked();
    void readData();
    void sendData();
};

#endif // FENETRE_H
