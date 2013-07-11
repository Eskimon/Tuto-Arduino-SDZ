#include <LiquidCrystal.h> //on inclut la librairie

//les branchements
const int boutonGauche = 11; //le bouton de gauche
const int boutonDroite = 12; //le bouton de droite
const int potentiometreGauche = 0; //le potentiomètre de gauche sur l'entrée analogique 0
const int potentiometreDroite = 1; //le potentiomètre de droite sur l'entrée analogique 1
const int ledAlarme = 2; //la LED est branché sur la sortie 2

// initialise l'écran avec les bonne broche
// ATTENTION, REMPLACER LES NOMBRES PAR VOS BRANCHEMENTS À VOUS !
LiquidCrystal lcd(8,9,4,5,6,7);

char messageHaut[16] = ""; //Message sur la ligne du dessus
char messageBas[16] = ""; //Message sur la ligne du dessous

unsigned long temps = 0; //pour garder une trace du temps qui s'écoule et gérer les séquences
boolean ecran = LOW; //pour savoir si on affiche les boutons ou les conversions

int etatGauche = LOW; //état du bouton de gauche
int etatDroite = LOW; //état du bouton de droite
int niveauGauche = 0; //conversion du potentiomètre de gauche
int niveauDroite = 0; //conversion du potentiomètre de droite

//les memes variables mais "old" servant de mémoire pour constater un changement
int etatGauche_old = LOW; //état du bouton de gauche
int etatDroite_old = LOW; //état du bouton de droite
int niveauGauche_old = 0; //conversion du potentiomètre de gauche
int niveauDroite_old = 0; //conversion du potentiomètre de droite

//------------------------------------------------------------------------------

void setup() {
  //réglage des entrées/sorties
  pinMode(boutonGauche, INPUT);
  pinMode(boutonDroite, INPUT);
  pinMode(ledAlarme, OUTPUT);

  //paramétrage du LCD
  lcd.begin(16, 2); // règle la  taille du LCD
  lcd.noBlink(); //pas de clignotement
  lcd.noCursor(); //pas de curseur
  lcd.noAutoscroll(); //pas de défilement
}

void loop() {

  recupererDonnees(); //commence par récupérer les données des boutons et capteurs

  if(ecran) //quel écran affiche t'on ? (bouton ou potentiomètre ?)
  {
    if(boutonsChanged()) //si un bouton a changé d'état
      updateEcran();
  }   
  else
  {
    if(potarChanged()) //si un potentiomètre a changé d'état
      updateEcran();
  }

  if(niveauDroite > niveauGauche)
    digitalWrite(ledAlarme, LOW); //RAPPEL : piloté à l'état bas donc on allume !
  else
    digitalWrite(ledAlarme, HIGH);

  if(millis() - temps > 5000) //si ca fait 5s qu'on affiche la même donnée
  {
    ecran = ~ecran;
    lcd.clear();
    updateEcran();
    temps = millis();
  }
}

//------------------------------------------------------------------------------

void recupererDonnees()
{
  //efface les anciens avec les "nouveaux anciens"
  etatGauche_old = etatGauche;
  etatDroite_old = etatDroite;
  niveauGauche_old = niveauGauche;
  niveauDroite_old = niveauDroite;

  etatGauche = digitalRead(boutonGauche);
  etatDroite = digitalRead(boutonDroite); 
  niveauGauche = analogRead(potentiometreGauche);
  niveauDroite = analogRead(potentiometreDroite);
  
  delay(1); //pour s'assurer que les conversions analogiques sont terminées avant de passer à la suite
}

boolean boutonsChanged()
{
  if(etatGauche_old != etatGauche || etatDroite_old != etatDroite)
    return true;
  else
    return false;
}

boolean potarChanged()
{
  //si un potentiomètre affiche une différence entre ces deux valeurs de plus de 2 unités, alors on met à jour
  if(abs(niveauGauche_old-niveauGauche) > 2 || abs(niveauDroite_old-niveauDroite) > 2)
    return true;
  else
    return false;
}

void updateEcran()
{
  if(ecran)
  {
    //prépare les chaines à mettre sur l'écran
    if(etatGauche)
      sprintf(messageHaut,"Bouton G : ON");
    else
      sprintf(messageHaut,"Bouton G : OFF");
    if(etatDroite)
      sprintf(messageBas,"Bouton D : ON");
    else
      sprintf(messageBas,"Bouton D : OFF");
  }
  else
  {
     //prépare les chaines à mettre sur l'écran
    sprintf(messageHaut,"gauche = %4d", niveauGauche);
    sprintf(messageBas,"droite = %4d", niveauDroite);
  }
  
  //on envoie le texte
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(messageHaut);
  lcd.setCursor(0,1);
  lcd.print(messageBas);
}
