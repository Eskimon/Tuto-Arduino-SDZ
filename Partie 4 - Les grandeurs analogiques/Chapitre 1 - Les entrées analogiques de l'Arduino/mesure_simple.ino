const int potar = 0; // le potentiomètre, branché sur la broche analogique 0
int valeurLue; //variable pour stocker la valeur lue après conversion
float tension; //on convertit cette valeur en une tension

void setup()
{
	//on se contente de démarrer la liaison série
	Serial.begin(9600);
}

void loop()
{
 	//on convertit en nombre binaire la tension lue en sortie du potentiomètre
	valeurLue = analogRead(potar);

	//on traduit la valeur brute en tension (produit en croix)
	tension = valeurLue * 5.0 / 1024;

        //on affiche la valeur lue sur la liaison série
	Serial.print("valeurLue = ");
	Serial.println(valeurLue);
	
	//on affiche la tension calculée
	Serial.print("Tension = ");
	Serial.print(tension,2);
	Serial.println(" V");
	
	Serial.println(); //on saute une ligne entre deux affichages
	delay(500); //on attend une demi-seconde pour que l'affichage ne soit pas trop rapide
}
