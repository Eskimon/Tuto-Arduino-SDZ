#include <LiquidCrystal.h> //on inclut la librairie

// initialise l'écran avec les bonnes broches
// ATTENTION, REMPLACER LES NOMBRES PAR VOS BRANCHEMENTS À VOUS !
LiquidCrystal lcd(8,9,4,5,6,7);

int heures,minutes,secondes;
char message[16] = "";

void setup()
{  
  lcd.begin(16, 2); // règle la taille du LCD : 16 colonnes et 2 lignes

  //changer les valeurs pour démarrer à l'heure souhaitée !
  heures = 0;
  minutes = 0;
  secondes = 0;
}

void loop()
{
  //on commence par gérer le temps qui passe...
  if(secondes == 60) //une minutes est atteinte ?
  {
    secondes = 0; //on recompte à partir de 0
    minutes++; 
  }
  if(minutes == 60) //une heure est atteinte ?
  {
    minutes = 0;
    heures++;
  }
  if(heures == 24) //une journée est atteinte ?
  {
    heures = 0; 
  }
  
  //met le message dans la chaine à transmettre
  sprintf(message,"Il est %2d:%2d:%2d",heures,minutes,secondes);

  lcd.home();           //met le curseur en position (0;0) sur l'écran
  
  lcd.write(message);   //envoi le message sur l'écran
  
  delay(1000);          //attend une seconde
  //une seconde s'écoule...
  secondes++;
}
