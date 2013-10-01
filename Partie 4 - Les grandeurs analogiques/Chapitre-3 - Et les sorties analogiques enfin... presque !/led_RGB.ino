//définition des broches utilisée (vous êtes libre de les changer)
const int led_verte = 9;
const int led_bleue = 10;
const int led_rouge = 11;

int compteur_defilement = 0; //variable permettant de changer de couleur


void setup()
{
   //définition des broches en sortie
   pinMode(led_rouge, OUTPUT);
   pinMode(led_verte, OUTPUT);
   pinMode(led_bleue, OUTPUT);
}

void loop()
{
   couleur(compteur_defilement); //appel de la fonction d'affichage
   compteur_defilement++; //incrémentation de la couleur à afficher
   if(compteur_defilement > 6) compteur_defilement = 0; //si le compteur dépasse 6 couleurs

   delay(500);
}

void couleur(int numeroCouleur)
{
   switch(numeroCouleur)
   {
      case 0 : //rouge
         analogWrite(led_rouge, 0); //rapport cyclique au minimum pour une meilleure luminosité de la LED
                                    //qui je le rappel est commandée en "inverse"
                                    //(0 -> LED allumée ; 255 -> LED éteinte)
         analogWrite(led_verte, 255);
         analogWrite(led_bleue, 255);
         break;
      case 1 : //vert
         analogWrite(led_rouge, 255);
         analogWrite(led_verte, 0);
         analogWrite(led_bleue, 255);
         break;
      case 2 : //bleu
         analogWrite(led_rouge, 255);
         analogWrite(led_verte, 255);
         analogWrite(led_bleue, 0);
         break;
      case 3 : //jaune
         analogWrite(led_rouge, 0);
         analogWrite(led_verte, 0);
         analogWrite(led_bleue, 255);
         break;
      case 4 : //violet
         analogWrite(led_rouge, 0);
         analogWrite(led_verte, 255);
         analogWrite(led_bleue, 0);
         break;
      case 5 : //bleu ciel
         analogWrite(led_rouge, 255);
         analogWrite(led_verte, 0);
         analogWrite(led_bleue, 0);
         break;
      case 6 : //blanc
         analogWrite(led_rouge, 0);
         analogWrite(led_verte, 0);
         analogWrite(led_bleue, 0);
         break;
      default : //"noir"
         analogWrite(led_rouge, 255);
         analogWrite(led_verte, 255);
         analogWrite(led_bleue, 255);
         break;
   }
}
