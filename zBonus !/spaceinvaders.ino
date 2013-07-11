#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

//Partie gauche de l'invader bras baissé
byte invader_low_left[8] = {
  B00100,
  B00010,
  B00111,
  B01101,
  B11111,
  B10111,
  B10100,
  B00010
};
//Partie droite de l'invader bras baissé
byte invader_low_right[8] = {
  B00100,
  B01000,
  B11100,
  B10110,
  B11111,
  B11101,
  B00101,
  B01000
};
//Partie gauche de l'invader bras levé
byte invader_high_left[8] = {
  B00100,
  B10010,
  B10111,
  B11101,
  B11111,
  B01111,
  B00100,
  B01000
};
//Partie droite de l'invader bras levé
byte invader_high_right[8] = {
  B00100,
  B01001,
  B11101,
  B10111,
  B11111,
  B11110,
  B00100,
  B00010
};

void setup() {
  randomSeed(analogRead(0)); //initialise l'aléatoire avec une lecture analogique 
  lcd.createChar(0, invader_low_left); //apprend le caractère à l'écran LCD
  lcd.createChar(1, invader_low_right); //apprend le caractère à l'écran LCD
  lcd.createChar(2, invader_high_left); //apprend le caractère à l'écran LCD
  lcd.createChar(3, invader_high_right); //apprend le caractère à l'écran LCD
  lcd.begin(16, 2);

  lcd.write("Salut les zeros!");
  delay(2000);
  lcd.clear();
}

void loop() {
  char colonne = random(0, 2);
  char ligne = random(0, 15);
  drawInvader(colonne, ligne, 0);
  delay(800);
  drawInvader(colonne, ligne, 1);
  delay(800);
  lcd.clear();
}

void drawInvader(char colonne, char ligne, char etat)
{
  lcd.clear(); //efface l'écran
  lcd.setCursor(ligne,colonne); //se place au bon pixel
  lcd.write((uint8_t) (0+etat*2)); //affiche la moitié gauche 
  lcd.write((uint8_t) (1+etat*2)); //affiche la moitié droite
}

