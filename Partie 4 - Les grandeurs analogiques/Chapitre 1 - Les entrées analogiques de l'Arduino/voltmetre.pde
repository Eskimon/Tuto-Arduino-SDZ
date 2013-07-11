//les broches du décodeur 7 segments
const int bit_A = 2;
const int bit_B = 3;
const int bit_C = 4;
const int bit_D = 5;
//les broches des transistors pour l'afficheur des dizaines et celui des unités
const int alim_dizaine = 6;
const int alim_unite = 7;
//la broche du potar
const int potar = 0;

float tension = 0.0; //tension mise en forme
int val = 0; //tension brute lue (0 à 1023)
bool afficheur = false;
long temps;

void setup()
{
	//Les broches sont toutes des sorties (sauf les boutons)
	pinMode(bit_A, OUTPUT);
	pinMode(bit_B, OUTPUT);
	pinMode(bit_C, OUTPUT);
	pinMode(bit_D, OUTPUT);
	pinMode(alim_dizaine, OUTPUT);
	pinMode(alim_unite, OUTPUT);
	
	//Les broches sont toutes mise à l'état bas (sauf led rouge éteinte)
	digitalWrite(bit_A, LOW);
	digitalWrite(bit_B, LOW);
	digitalWrite(bit_C, LOW);
	digitalWrite(bit_D, LOW);
	digitalWrite(alim_dizaine, LOW);
	digitalWrite(alim_unite, LOW);
	temps = millis(); //enregistre "l'heure"
}

void loop()
{
	//on fait la lecture analogique
	val = analogRead(potar);
	//mise en forme de la valeur lue
	tension = val * 5; //simple relation de trois pour la conversion ( *5/1023)
	tension = tension / 1023;
	//à ce stade on a une valeur de type 3.452 Volts... que l'on va multiplier par 10 pour l'affichage avec les vieilles fonctions
	tension = tension*10;
	
	//si ca fait plus de 10 ms qu'on affiche, on change de 7 segments
	if((millis() - temps) > 10)
	{
		//on inverse la valeur de "afficheur" pour changer d'afficheur (unité ou dizaine)
		afficheur = !afficheur;
		//on affiche
		afficher_nombre(tension, afficheur);
		temps = millis(); //on met à jour le temps
	}
}

//fonction permettant d'afficher un nombre
void afficher_nombre(float nombre, bool afficheur)
{
	long temps;
	char unite = 0, dizaine = 0;
	if(nombre > 9)
		dizaine = nombre / 10; //on recupere les dizaines
	unite = nombre - (dizaine*10); //on recupere les unités
	
	if(afficheur)
	{
		//on affiche les dizaines
		digitalWrite(alim_unite, LOW);
		digitalWrite(alim_dizaine, HIGH);
		afficher(dizaine);
	}
	else
	{
		//on affiche les unités
		digitalWrite(alim_dizaine, LOW);
		digitalWrite(alim_unite, HIGH);
		afficher(unite);
	}
}

//fonction écriveant sur un seul afficheur
void afficher(char chiffre)
{
   	//on commence par écrire 0, donc tout à l'état bas
	digitalWrite(bit_A, LOW);
	digitalWrite(bit_B, LOW);
	digitalWrite(bit_C, LOW);
	digitalWrite(bit_D, LOW);

	if(chiffre >= 8)
	{
		digitalWrite(bit_D, HIGH);
		chiffre = chiffre - 8;
	}
	if(chiffre >= 4)
	{
		digitalWrite(bit_C, HIGH);
		chiffre = chiffre - 4;
	}
	if(chiffre >= 2)
	{
		digitalWrite(bit_B, HIGH);
		chiffre = chiffre - 2;
	}
	if(chiffre >= 1)
	{
		digitalWrite(bit_A, HIGH);
		chiffre = chiffre - 1;
	}
	//Et voilà !!
}


