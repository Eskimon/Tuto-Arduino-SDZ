int carlu; //stock le caractère lu sur la voie série

void setup()
{
    Serial.begin(9600);
}

void loop()
{
   //on commence par vérifier si un caractère est disponible dans le buffer
   if(Serial.available() > 0)
   {
      carlu = Serial.read(); //lecture du premier caractère disponible
		
      if(carlu >= 'a' && carlu <= 'z') //Est-ce que c'est un caractère minuscule ?
      {
         carlu = carlu - 'a'; //on garde juste le "numéro de lettre"
         carlu = carlu + 'A'; //on passe en majuscule
      }
      else if(carlu >= 'A' && carlu <= 'Z') //Est-ce que c'est un caractère MAJUSCULE ?
      {
         carlu = carlu - 'A'; //on garde juste le "numéro de lettre"
         carlu = carlu + 'a'; //on passe en minuscule
      }
      //ni l'un ni l'autre on renvoie en tant que BYTE ou alors on renvoie le caractère modifié
      Serial.write(carlu);
   }
}
