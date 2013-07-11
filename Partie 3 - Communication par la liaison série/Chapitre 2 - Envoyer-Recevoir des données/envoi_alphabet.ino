void setup()
{
   Serial.begin(9600);

   Serial.println(65, BIN); //envoie la valeur 1000001
   Serial.println(65, DEC); //envoie la valeur 65
   Serial.println(65, OCT); //envoie la valeur 101 (ce n'est pas du binaire !)
   Serial.println(65, HEX); //envoie la valeur 41
}

void loop()
{
	char i = 0;
	char lettre = 'a'; // ou 'A' pour envoyer en majuscule

	Serial.println("------  L'alphabet des Zéros  ------"); //petit message d'accueil

	//on commence les envois
	for(i=0; i<26; i++)
	{
		Serial.print(lettre); //on envoie la lettre
		lettre = lettre + 1; //on passe à la lettre suivante
		delay(250); //on attend 250ms avant de réenvoyer
	}
	Serial.println(""); //on fait un retour à la ligne

	delay(5000); //on attend 5 secondes avant de renvoyer l'alphabet
}
