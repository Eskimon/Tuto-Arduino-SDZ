const int rouge = 9;
const int vert = 10;
const int bleu = 11;

void setup()
{
	pinMode(rouge, OUTPUT);
	pinMode(vert, OUTPUT);
	pinMode(bleu, OUTPUT);
	analogWrite(rouge,0);
	analogWrite(bleu,0);
	analogWrite(vert,0);
}

void loop()
{

	char i=0;
	
	analogWrite(rouge,0);
	analogWrite(vert,0);
	analogWrite(bleu,0);
	
	
	for(i=0; i<=255; i++)
	{
		analogWrite(rouge,i);
		delay(25);
	}
	
	for(i=0; i<=255; i++)
	{
		analogWrite(vert,i);
		delay(25);
	}
	for(i=0; i<=255; i++)
	{
		analogWrite(bleu,i);
		delay(25);
	}
}