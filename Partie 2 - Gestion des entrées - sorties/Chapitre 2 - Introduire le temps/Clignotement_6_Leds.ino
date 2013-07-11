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
 
void loop()
{
   digitalWrite(L1, LOW);  //allumer les LED
   digitalWrite(L2, LOW);
   digitalWrite(L3, LOW);
   digitalWrite(L4, LOW);
   digitalWrite(L5, LOW);
   digitalWrite(L6, LOW);
    
   delay(1500);             //attente du programme de 1,5 secondes
 
   digitalWrite(L1, HIGH);   //on éteint les LED
   digitalWrite(L2, HIGH);
   digitalWrite(L3, HIGH);
   digitalWrite(L4, HIGH);
   digitalWrite(L5, HIGH);
   digitalWrite(L6, HIGH);
 
   delay(4320);             //attente du programme de 4,32 secondes
}
