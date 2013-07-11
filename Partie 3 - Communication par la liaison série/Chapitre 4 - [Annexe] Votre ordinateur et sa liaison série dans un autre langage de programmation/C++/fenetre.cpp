#include "fenetre.h"
#include "ui_fenetre.h"

Fenetre::Fenetre(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Fenetre)
{
    ui->setupUi(this);

    QextSerialEnumerator enumerateur;
    QList<QextPortInfo> ports = enumerateur.getPorts();

    //on parcourt la liste des ports
    for(int i=0; i<ports.size(); i++)
        //Si le port ne s'appelle pas "ttyS..", on l'ajoute au combobox
        //if(!ports.at(i).portName.contains("ttyS"))
            ui->ComboPort->addItem(ports.at(i).physName);

    //Si la liste est vide, le bouton est disable
    if(ui->ComboPort->currentText() == "")
        ui->btnConnection->setEnabled(false);

    //On remplit le combo des vitesses avec quelques vitesses communes
    ui->comboVitesse->addItem("300");
    ui->comboVitesse->addItem("1200");
    ui->comboVitesse->addItem("2400");
    ui->comboVitesse->addItem("4800");
    ui->comboVitesse->addItem("9600");
    ui->comboVitesse->addItem("14400");
    ui->comboVitesse->addItem("19200");
    ui->comboVitesse->addItem("38400");
    ui->comboVitesse->addItem("57600");
    ui->comboVitesse->addItem("115200");

    //on sélectionne par défaut la vitesse 9600
    ui->comboVitesse->setCurrentIndex(4);
}

Fenetre::~Fenetre() {
    if(port != NULL && port->isOpen())
        port->close();
    delete port;
    delete ui;
}

//Slot pour le click sur le bouton de connection
void Fenetre::on_btnConnection_clicked() {
    //deux cas de figures à gérer, soit on coche, soit on décoche

    //on coche -> connection
    if(ui->btnConnection->isChecked()) {
        //on essaie de faire la connection avec la carte Arduino
        //on commence par créer l'objet port série
        port = new QextSerialPort();
        //on règle le port utilisé (sélectionné dans la liste déroulante)
        port->setPortName(ui->ComboPort->currentText());
        //on règle la vitesse utilisée
        port->setBaudRate(getBaudRateFromString(ui->comboVitesse->currentText()));
        //quelques règlages pour que tout marche bien
        port->setParity(PAR_NONE);//parité
        port->setStopBits(STOP_1);//nombre de bits de stop
        port->setDataBits(DATA_8);//nombre de bits de données
        port->setFlowControl(FLOW_OFF);//pas de controle de flux
        //on démarre !
        port->open(QextSerialPort::ReadWrite);
        if(!port->isOpen())
            qDebug() << "Probème d'ouverture du port";
        //change le message du bouton
        ui->btnConnection->setText("Deconnecter");

        //on fait la connection pour pouvoir obtenir les évènements
        connect(port,SIGNAL(readyRead()), this, SLOT(readData()));
        connect(ui->boxEmission,SIGNAL(textChanged()),this,SLOT(sendData()));
    }
    else {
        //on se déconnecte de la carte Arduino
        port->close();
        //puis on détruit l'objet port série devenu inutile
        delete port;
        ui->btnConnection->setText("Connecter");
    }
}

void Fenetre::sendData() {
    QString caractere = ui->boxEmission->toPlainText().right(1); //On récupère le dernier caractère tapé
    if(port != NULL) //si le port est instancié (donc ouvert a priori)
        port->write(caractere.toAscii());
}

void Fenetre::readData() {
    QByteArray array = port->readAll();
    ui->boxReception->insertPlainText(array);
}

BaudRateType Fenetre::getBaudRateFromString(QString baudRate) {
    int vitesse = baudRate.toInt();
    switch(vitesse) {
        case(300):return BAUD300;
        case(1200):return BAUD1200;
        case(2400):return BAUD2400;
        case(4800):return BAUD4800;
        case(9600):return BAUD9600;
        case(14400):return BAUD14400;
        case(19200):return BAUD19200;
        case(38400):return BAUD38400;
        case(57600):return BAUD57600;
        case(115200):return BAUD115200;
        default:return BAUD9600;
    }
}
