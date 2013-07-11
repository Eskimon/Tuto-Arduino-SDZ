const int bouton = 2; //le bouton est connecté à la broche 2 de la carte Adruino
const int led = 13; //la LED à la broche 13

int etatBouton; //variable qui enregistre l'état du bouton

void setup()
{
   pinMode(led, OUTPUT); //la led est une sortie
   pinMode(bouton, INPUT); //le bouton est une entrée
   etatBouton = HIGH; //on initialise l'état du bouton comme "relaché"
}

void loop()
{
   etatBouton = digitalRead(bouton); //Rappel : bouton = 2
   
   if(etatBouton == HIGH) //test si le bouton a un niveau logique HAUT
   {
       digitalWrite(led,HIGH); //la LED reste éteinte
   }
   else  //test si le bouton a un niveau logique différent de HAUT (donc BAS)
   {
       digitalWrite(led,LOW); //le bouton est appuyé, la LED est allumée
   }
}
