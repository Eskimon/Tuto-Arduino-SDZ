//tableau regroupant les broches des leds
const int leds[10] = {2,3,4,5,6,7,8,9,10,11};
//la broche du potar
const int potar = 0;
int tension = 0; //tension brute lue (0 à 1023)

void setup()
{
	char i = 0;
	//on initialise les leds
	for(i=0; i<10; i++)
	{
		//Les LEDs sont toutes des sorties
		pinMode(leds[i], OUTPUT);
		//Les LEDs seront toutes éteintes (donc état haut)
		digitalWrite(leds[i], HIGH);
	}
}

void loop()
{
	tension = analogRead(potar);
	afficher(tension);
}

void afficher(int valeur)
{
	int i=0;
	for(i=0; i<10; i++)
	{
		if(valeur <= (i*100))
			digitalWrite(leds[i], HIGH);
		else
			digitalWrite(leds[i], LOW);
	}
}