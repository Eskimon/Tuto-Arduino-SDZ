const int led_rouge = 2;   //définition de la broche 2 de la carte en tant que variable
 
void setup()          //fonction d'initialisation de la carte
{
   pinMode(led_rouge, OUTPUT); //initialisation de la broche 2 comme étant une sortie
}
 
void loop()           //fonction principale, elle se répète (s’exécute) à l'infini
{
   digitalWrite(led_rouge, LOW); // écriture en sortie (broche 2) d'un état BAS
}
