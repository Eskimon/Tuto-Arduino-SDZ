#define VERT 0
#define ORANGE 1
#define ROUGE 2

int etat = 0; //stock l'état de la situation (vert (0), orange(1), rouge(2))
char mot[20]; //le mot lu
//numéro des broches utilisées
int btn_SOS = 2;
int btn_OK = 3;
int leds[3] = {10,11,12}; //tableau de 3 éléments contenant les numéros de broches des leds

void setup()
{
	Serial.begin(9600); //On démarre la voie série avec une vitesse de 9600 bits/seconde
	
	//reglage des entrées/sorties
	//les entrées (2*boutons)
	pinMode(btn_SOS, INPUT);
	pinMode(btn_OK, INPUT);
	//les sorties (3*leds) éteintes
        int i = 0;
        for(i=0; i<3; i++)
        {
               pinMode(leds[i], OUTPUT);
               digitalWrite(leds[i], HIGH);
        }
}

void loop()
{
	//on regarde si le bouton SOS est appuyé
	if(digitalRead(btn_SOS) == LOW)
	{
		//si oui, on émet l'alerte
		alerte();
	}

	//puis on continu en vérifiant la présence de caractère sur la voie série
	//s'il y a des données dispos sur la voie série (Serial.available() renvoi un nombre supérieur à 0)
	if(Serial.available())
	{
		//alors on va lire le contenu de la réception
		lireVoieSerie();
		etat = comparerMot(mot);
	}
	//Puis on met à jour l'état des leds
	allumerDrapeau(etat);
}

//lit un mot sur la voie série (lit jusqu'à rencontrer le caractère '\n')
void lireVoieSerie(void)
{
	int i = 0;
	//on lit les caractères tant qu'il y en a
	//OU si jamais le nombre de caractère lus atteint 19 (limite du tableau stockant le mot - 1 caractère)
	while(Serial.available()>0 && i<19)
	{
            mot[i] = Serial.read(); //on enregistre le caractère lu
            delay(10); //laisse un peu de temps entre chaque acces a la memoire
            i++; //on passe à l'indice suivant
	}
        mot[i-2] = '\0'; //on supprime le caractère "entrée" et on le remplace par celui de fin de chaine
}

//lit un mot sur la voie série (lit jusqu'à rencontrer le caractère '\n')
//Allume un des trois drapeaux
//paramètres : le numéro du drapeau à allumer
//note : si le paramètre est -1, on se contente de tout éteindre
void allumerDrapeau(int numLed)
{
	int i=0;
	//On commence par éteindre les trois leds
	for(i=0; i<3; i++)
	{
		digitalWrite(leds[i], HIGH);
	}
	//puis on allume une seule led si besoin
	if(numLed != -1)
	{
		digitalWrite(leds[numLed], LOW);
	}
}

//Eteinds les leds et fais clignoter la led rouge en attendant l'appui du bouton "sauveteur"
void alerte(void)
{
	long temps = millis();
	bool clignotant = false;
	allumerDrapeau(-1);
	//tant que le bouton de sauveteur n'est pas appuyé on clignote
	while(digitalRead(btn_OK) != LOW)
	{
		//Si il s'est écoulé 250 ms ou plus depuis la dernière fois
		if(millis() - temps > 250)
		{
			//on change l'état de la led rouge
			clignotant = !clignotant;
			digitalWrite(leds[ROUGE], clignotant);
			temps = millis(); //on se rappel de la date de dernier passage
		}
	}
}

int comparerMot(char mot[])
{
	//on compare les mots "VERT" (surveillant, calme)
	if(strcmp(mot, "surveillant") == 0)
	{	
		return VERT;
	}
	if(strcmp(mot, "calme") == 0)
	{	
		return VERT;
	}
	//on compare les mots "ORANGE" (vague)
	if(strcmp(mot, "vague") == 0)
	{	
		return ORANGE;
	}
	//on compare les mots "ROUGE" (meduse, tempete, requin)
	if(strcmp(mot, "meduse") == 0)
	{	
		return ROUGE;
	}
	if(strcmp(mot, "tempete") == 0)
	{	
		return ROUGE;
	}
	if(strcmp(mot, "requin") == 0)
	{	
		return ROUGE;
	}
	
	//si on a rien reconnu on renvoi ORANGE
	return ORANGE;
}

