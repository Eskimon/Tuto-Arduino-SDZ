//les broches du décodeur 7 segments
const int bit_A = 2;
const int bit_B = 3;
const int bit_C = 4;
const int bit_D = 5;
//les broches des transistors pour l'afficheur des dizaines et celui des unités
const int alim_dizaine = 6;
const int alim_unite = 7;

void setup()
{
	//Les broches sont toutes des sorties
	pinMode(bit_A, OUTPUT);
	pinMode(bit_B, OUTPUT);
	pinMode(bit_C, OUTPUT);
	pinMode(bit_D, OUTPUT);
	pinMode(alim_dizaine, OUTPUT);
	pinMode(alim_unite, OUTPUT);
	
	//Les broches sont toutes mise à l'état bas
	digitalWrite(bit_A, LOW);
	digitalWrite(bit_B, LOW);
	digitalWrite(bit_C, LOW);
	digitalWrite(bit_D, LOW);
	digitalWrite(alim_dizaine, LOW);
	digitalWrite(alim_unite, LOW);
}

void loop()
{
	char i = 0;
	for(i = 0; i<100; i++)
	{
		afficher_nombre(i);
	}
}

//fonction permettant d'afficher un nombre
void afficher_nombre(char nombre)
{
	long temps;
	char unite = 0, dizaine = 0;
	if(nombre > 9)
		dizaine = nombre / 10; //on recupere les dizaines
	unite = nombre - (dizaine*10); //on recupere les unités
	temps = millis(); //on recupere le temps courant
	while((millis()-temps) < 500) //tant qu'on a pas affiché ce chiffre pendant au moins 500 millisecondes
	{
		//on affiche le nombre
		//d'abord les dizaines pendant 20 ms
		digitalWrite(alim_dizaine, HIGH);
		digitalWrite(alim_unite, LOW);
		afficher(dizaine);
                delay(10);
		//puis les unités pendant 20 ms
		digitalWrite(alim_unite, HIGH);
                digitalWrite(alim_dizaine, LOW);
		afficher(unite);
                delay(10);
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


