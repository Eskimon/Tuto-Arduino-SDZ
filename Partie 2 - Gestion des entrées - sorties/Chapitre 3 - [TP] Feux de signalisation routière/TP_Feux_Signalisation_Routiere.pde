//définition des broches
const int led_rouge_feux_1 = 2; 
const int led_jaune_feux_1 = 3; 
const int led_verte_feux_1 = 4;

const int led_rouge_feux_2 = 5;
const int led_jaune_feux_2 = 6;
const int led_verte_feux_2 = 7;

void setup()
{
   //initialisation en sortie de toutes les broches
   pinMode(led_rouge_feux_1, OUTPUT); 
   pinMode(led_jaune_feux_1, OUTPUT); 
   pinMode(led_verte_feux_1, OUTPUT); 
   pinMode(led_rouge_feux_2, OUTPUT);
   pinMode(led_jaune_feux_2, OUTPUT);
   pinMode(led_verte_feux_2, OUTPUT);

   //on initialise toutes les LED éteintes au début du programme (sauf les deux feux rouges)
   digitalWrite(led_rouge_feux_1, LOW);
   digitalWrite(led_jaune_feux_1, HIGH);
   digitalWrite(led_verte_feux_1, HIGH);
   digitalWrite(led_rouge_feux_2, LOW);
   digitalWrite(led_jaune_feux_2, HIGH);
   digitalWrite(led_verte_feux_2, HIGH);
}

void loop()
{
   // première séquence 
   digitalWrite(led_rouge_feux_1, HIGH); 
   digitalWrite(led_verte_feux_1, LOW);

   delay(3000);

   // deuxième séquence
   digitalWrite(led_verte_feux_1, HIGH); 
   digitalWrite(led_jaune_feux_1, LOW);
   
   delay(1000);

   // troisième séquence
   digitalWrite(led_jaune_feux_1, HIGH); 
   digitalWrite(led_rouge_feux_1, LOW);

   delay(1000);

/* ---------- deuxième partie du programme, on s'occupe du feux numéro 2 ---------- */
   
   // première séquence
   digitalWrite(led_rouge_feux_2, HIGH); 
   digitalWrite(led_verte_feux_2, LOW);

   delay(3000);

   // deuxième séquence
   digitalWrite(led_verte_feux_2, HIGH);
   digitalWrite(led_jaune_feux_2, LOW);
   
   delay(1000);

   // deuxième séquence
   digitalWrite(led_jaune_feux_2, HIGH); 
   digitalWrite(led_rouge_feux_2, LOW);
   
   delay(1000);

/* --------------- le programme va reboucler et revenir au début ------------------ */
}
