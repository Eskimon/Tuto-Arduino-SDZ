#!/usr/bin/python3
# -*-coding:Utf-8 -*

from serial import Serial
import time

port = Serial('/dev/ttyACM0', 9600)

port.open()
time.sleep(5) #dors 5 secondes pour être sur que le reset de Arduino est passé

if (port.isOpen()): #test que le port est ouvert
	chaine = input("Que voulez vous transformer ? ")
	port.write(bytes(chaine, 'UTF-8'))
	while(port.inWaiting() == 0):
	#on attend 0.5 seconde pour que les données arrive
		time.sleep(0.5)
		
	#si on arrive là, des données sont arrivées
	while(port.inWaiting() != 0):
		car = port.read() #on lit un caractère
		print(car) #on l'affiche
else:
	print ("Le port n'a pas pu être ouvert !")
