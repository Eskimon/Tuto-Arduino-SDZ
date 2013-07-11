bool afficheur = false; //variable pour le choix de l'afficheur

// --- setup() ---

void loop()
{
	//gestion du rafraichissement
	//si ça fait plus de 10 ms qu'on affiche, on change de 7 segments (alternance unité <-> dizaine)
	if((millis() - temps) > 10)
	{
		//on inverse la valeur de "afficheur" pour changer d'afficheur (unité ou dizaine)
		afficheur = !afficheur;
		//on affiche la valeur sur l'afficheur
		//afficheur : true->dizaines, false->unités
		afficher_nombre(valeur, afficheur);
		temps = millis(); //on met à jour le temps
	}
	
	//ici, on peut traiter les évènements (bouton...)
}

//fonction permettant d'afficher un nombre
//elle affiche soit les dizaines soit les unités
void afficher_nombre(char nombre, bool afficheur)
{
	char unite = 0, dizaine = 0;
	if(nombre > 9)
		dizaine = nombre / 10; //on recupere les dizaines
	unite = nombre - (dizaine*10); //on recupere les unités
	
	//si "
	if(afficheur)
	{
		//on affiche les dizaines
		digitalWrite(alim_unite, LOW);
		afficher(dizaine);
		digitalWrite(alim_dizaine, HIGH);
	}
	else // égal à : else if(!afficheur)
	{
		//on affiche les unités
		digitalWrite(alim_dizaine, LOW);
		afficher(unite);
		digitalWrite(alim_unite, HIGH);
	}
}

//fonction écrivant sur un seul afficheur
void afficher(char chiffre)
{
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
}
