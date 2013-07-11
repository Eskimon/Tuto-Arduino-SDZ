#define VERT 0
#define ORANGE 1
#define ROUGE 2

int etat = 0; //stock l'état de la situation (vert = 0, orange = 1, rouge = 2)
char mot[20]; //le mot lu sur la liaison série

//numéro des broches utilisées
const int btn_SOS = 2;
const int btn_OK = 3;
const int leds[3] = {11,12,13}; //tableau de 3 éléments contenant les numéros de broches des LED


void setup()
{
	Serial.begin(9600); //On démarre la voie série avec une vitesse de 9600 bits/seconde
	
	//réglage des entrées/sorties
	//les entrées (2 boutons)
	pinMode(btn_SOS, INPUT);
	pinMode(btn_OK, INPUT);

	//les sorties (3 LED) éteintes
        for(int i=0; i<3; i++)
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
		//si oui, on émet l'alerte en appelant la fonction prévue à cet effet
		alerte();
	}

	//puis on continu en vérifiant la présence de caractère sur la liaison série
	//s'il y a des données disponibles sur la liaison série (Serial.available() renvoi un nombre supérieur à 0)
	if(Serial.available())
	{
		//alors on va lire le contenu de la réception
		lireVoieSerie();
                //on entre dans une variable la valeur retournée par la fonction comparerMot()
		etat = comparerMot(mot);
	}
	//Puis on met à jour l'état des LED
	allumerDrapeau(etat);
}


//lit un mot sur la liaison série (lit jusqu'à rencontrer le caractère '\n')
void lireVoieSerie(void)
{
	int i = 0; //variable locale pour l'incrémentation des données du tableau

	//on lit les caractères tant qu'il y en a
	//OU si jamais le nombre de caractères lus atteint 19 (limite du tableau stockant le mot - 1 caractère)
	while(Serial.available() > 0 && i <= 19)
	{
            mot[i] = Serial.read(); //on enregistre le caractère lu
            delay(10); //laisse un peu de temps entre chaque accès a la mémoire
            i++; //on passe à l'indice suivant
	}
        mot[i] = '\0'; //on supprime le caractère '\n' et on le remplace par celui de fin de chaine '\0'
}


/*
Rappel du fonctionnement du code qui précède celui-ci : 
>lit un mot sur la voie série (lit jusqu'à rencontrer le caractère '\n')
Fonction allumerDrapeau() :
>Allume un des trois drapeaux
>paramètre : le numéro du drapeau à allumer (note : si le paramètre est -1, on éteint toutes les LED)
*/

void allumerDrapeau(int numLed)
{
	//On commence par éteindre les trois LED
	for(int j=0; j<3; j++)
	{
		digitalWrite(leds[j], HIGH);
	}
	//puis on allume une seule LED si besoin
	if(numLed != -1)
	{
		digitalWrite(leds[numLed], LOW);
	}

/* Note : vous pourrez améliorer cette fonction en
          vérifiant par exemple que le paramètre ne
          dépasse pas le nombre présent de LED
*/
}


//Éteint les LED et fais clignoter la LED rouge en attendant l'appui du bouton "sauveteur"

void alerte(void)
{
	long temps = millis();
	boolean clignotant = false;
	allumerDrapeau(-1); //on éteint toutes les LED

	//tant que le bouton de sauveteur n'est pas appuyé on fait clignoté la LED rouge
	while(digitalRead(btn_OK) != LOW)
	{
		//S'il s'est écoulé 250 ms ou plus depuis la dernière vérification
		if(millis() - temps > 250)
		{
			//on change l'état de la LED rouge
			clignotant = !clignotant; //si clignotant était FALSE, il devient TRUE et inversement
			digitalWrite(leds[ROUGE], clignotant); //la LEd est allumée au gré de la variable clignotant
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
