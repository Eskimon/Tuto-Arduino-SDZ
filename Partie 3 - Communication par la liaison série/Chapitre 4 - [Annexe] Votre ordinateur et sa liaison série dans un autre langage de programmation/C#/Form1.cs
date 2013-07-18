using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO.Ports;

namespace SdZSerialArduino
{
    public partial class Form1 : Form
    {
        SerialPort port;

        //une déléguée pour pouvoir mettre à jour le texte de la boite de réception de manière "thread-safe"
        delegate void SetTextCallback(string text);

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //on commence par lister les voies séries présentes
            String[] ports = SerialPort.GetPortNames(); //fonction statique
            //on ajoute les ports au combo box
            foreach (String s in ports)
                comboPort.Items.Add(s);

            //on ajoute les vitesses au combo des vitesses
            comboVitesse.Items.Add("300");
            comboVitesse.Items.Add("1200");
            comboVitesse.Items.Add("2400");
            comboVitesse.Items.Add("4800");
            comboVitesse.Items.Add("9600");
            comboVitesse.Items.Add("14400");
            comboVitesse.Items.Add("19200");
            comboVitesse.Items.Add("38400");
            comboVitesse.Items.Add("57600");
            comboVitesse.Items.Add("115200");
        }

        private void btnConnexion_Click(object sender, EventArgs e)
        {
            //on gère la connexion/déconnexion
            if (btnConnexion.Text == "Connecter") //alors on connecte
            {
                //crée un nouvel objet voie série
                port = new SerialPort();
                //règle la voie série
                port.BaudRate = int.Parse(comboVitesse.SelectedItem.ToString()); //parse en int le combo des vitesses
                port.DataBits = 8;
                port.StopBits = StopBits.One;
                port.Parity = Parity.None;
                port.PortName = comboPort.SelectedItem.ToString(); //récupère le nom sélectionné

                //ajoute un gestionnaire de réception pour la réception de donnée sur la voie série
                port.DataReceived += new SerialDataReceivedEventHandler(DataReceivedHandler);

                port.Open(); //ouvre la voie série

                btnConnexion.Text = "Deconnecter";
            }
            else //sinon on déconnecte
            {
                port.Close(); //ferme la voie série
                btnConnexion.Text = "Connecter";
            }
        }

        private void boxEmission_TextChanged(object sender, EventArgs e)
        {
            //met le dernier caractère dans un tableau avec une seule case le contenant
            char[] car = new char[] { boxEmission.Text[boxEmission.TextLength - 1] };
            if (port != null && port.IsOpen) //on s'assure que le port est existant et ouvert
                port.Write(car, 0, 1); //envoie le tableau de caractère, depuis la position 0, et envoie 1 seul élément
        }

        //gestionnaire de la réception de caractère
        private void DataReceivedHandler(object sender, SerialDataReceivedEventArgs e)
        {
            String texte = port.ReadExisting();
            SetText(texte);
        }
        
        private void SetText(string text)
        {
            if (boxReception.InvokeRequired)
            {
                SetTextCallback d = new SetTextCallback(SetText);
                boxReception.Invoke(d, new object[] { text });
            }
            else
                boxReception.Text += text;
        }
    }
}
