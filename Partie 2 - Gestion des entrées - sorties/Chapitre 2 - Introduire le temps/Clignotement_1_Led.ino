const int led_rouge = 2;       //définition de la broche 2 de la carte en tant que variable
 
void setup()                   //fonction d'initialisation de la carte
{
   pinMode(led_rouge, OUTPUT); //initialisation de la broche 2 comme étant une sortie
}
 
void loop()                    //fonction principale, elle se répète (s’exécute) à l'infini
{
   digitalWrite(led_rouge, LOW);    // allume la LED
   delay(600);                      // fait une pause de 600 milli-seconde
   digitalWrite(led_rouge, HIGH);     // éteint la LED
   delay(40);                      // fait une pause de 40 milli-seconde
}
