#include <LiquidCrystal.h> //on inclut la librairie

// initialise l'écran avec les bonnes broches
// ATTENTION, REMPLACER LES NOMBRES PAR VOS BRANCHEMENTS À VOUS !
LiquidCrystal lcd(8,9,4,5,6,7);

//notre nouveau caractère
byte smiley[8] = {
  B00000,
  B10001,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000,
};

void setup()
{
  lcd.createChar(0, smiley); //apprend le caractère à l'écran LCD
  lcd.begin(16, 2);
  lcd.write((uint8_t) 0); //affiche le caractère de l'adresse 0
}
