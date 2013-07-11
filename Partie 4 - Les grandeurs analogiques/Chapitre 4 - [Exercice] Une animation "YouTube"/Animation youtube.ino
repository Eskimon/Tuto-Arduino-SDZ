const int LED[6] = {3,5,6,9,10,11}; //sortie LEDs
const char pwm[6] = {255,210,160,200,220,240}; //niveaux de luminosité utilisé
const int potar = 0; //potentiometre sur la broche 0

void setup()
{
	pinMode(potar, INPUT);
	for(int i=0; i<6; i++)
		pinMode(LED[i], OUTPUT);
}

void loop()
{
	for(int i=0; i<6; i++) //étape de l'animation
	{
		for(int n=0; n<6; n++) //mise à jour des LEDs
		{
			analogWrite(LED[n], pwm[(n+i)%6]);
		}
		int temps = analogRead(potar);
		delay(temps/6 + 20); //tmax = 190ms, tmin = 20ms
	}
}
