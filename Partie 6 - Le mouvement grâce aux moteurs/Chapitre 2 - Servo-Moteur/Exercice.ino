#include <Servo.h> //On oublie pas d'ajouter la bibliothèque !

const int potar = 0; //notre potentiomètre
Servo monServo;

void setup()
{
   monServo.attach(2); //on déclare le servo sur la broche 2 (éventuellement réglé les bornes)
   Serial.begin(9600); //on oublie pas de démarrer la voie série
}

void loop()
{
   int val = analogRead(potar); //on lit la valeur du potentiomètre
   int angle = val / 5.7; //on convertit la valeur lue en angle compris dans l’intervalle [0;180]
   monServo.write(angle); //on met à jour l'angle sur le servo
   Serial.println(angle); //on renvoi l'angle par la voie série pour superviser
   delay(100); //un petit temps de pause
}
