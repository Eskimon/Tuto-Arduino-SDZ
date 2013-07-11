// on garde le même début que le programme précédent
 
const int L1 = 2; //broche 2 du micro-contrôleur se nomme maintenant : L1
const int L2 = 3; //broche 3 du micro-contrôleur se nomme maintenant : L2
const int L3 = 4; // ...
const int L4 = 5;
const int L5 = 6;
const int L6 = 7;
 
void setup()
{
   pinMode(L1, OUTPUT); //L1 est une broche de sortie
   pinMode(L2, OUTPUT); //L2 est une broche de sortie
   pinMode(L3, OUTPUT); // ...
   pinMode(L4, OUTPUT);
   pinMode(L5, OUTPUT);
   pinMode(L6, OUTPUT);
}
 
// on change simplement l’intérieur de la boucle pour atteindre notre objectif
 
void loop() //la fonction loop() exécute le code qui suit en le répétant en boucle
{
   digitalWrite(L1, LOW);   //allumer L1
   delay(1000);             //attendre 1 seconde
   digitalWrite(L1, HIGH);  //on éteint L1
   digitalWrite(L2, LOW);   //on allume L2 en même temps que l'on éteint L1
   delay(1000);             //on attend 1 seconde
   digitalWrite(L2, HIGH);  //on éteint L2 et 
   digitalWrite(L3, LOW);   //on allume immédiatement L3
   delay(1000);             // ...
   digitalWrite(L3, HIGH);
   digitalWrite(L4, LOW);
   delay(1000);  
   digitalWrite(L4, HIGH);
   digitalWrite(L5, LOW);
   delay(1000);  
   digitalWrite(L5, HIGH);
   digitalWrite(L6, LOW);
   delay(1000);     
   digitalWrite(L6, HIGH);
}
