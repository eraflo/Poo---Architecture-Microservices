#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <random>
#include "Cesar.h"


Cesar::Cesar(void)
{
	this->decalage = 5;
}

void Cesar::setD(int d)
{
	this->decalage = d;
}

void Cesar::chiffrer(std::string fileInput, std::string fileOutput)
{
	std::ifstream fichierI(fileInput.c_str(), std::ios::in);
	std::string texte;

	if (fichierI)
	{
		std::string ligne;
		fichierI.seekg(0, std::ios::beg);

		while (std::getline(fichierI, ligne))
		{
			for (int i = 0; i < ligne.size(); i++) {
				int val = int(ligne[i]);
				val += this->decalage;
				char newC = val;
				texte += newC;
			}
		}
		fichierI.close();
	}
	std::ofstream fichierO(fileOutput.c_str(), std::ios::out | std::ios::trunc);

	if (fichierO)
	{
		fichierO << texte;
		fichierO.close();
	}

}


void Cesar::dechiffrer(std::string fileInput, std::string fileOutput)
{
	std::ifstream fichierI(fileInput.c_str(), std::ios::in | std::ios::binary);
	std::string texteF;

	if (fichierI)
	{
		fichierI.seekg(0, std::ios::beg);
		std::string c;
		while (std::getline(fichierI, c))
		{
			for (int i = 0; i < c.size(); i++) {
				int val = int(c[i]);
				val -= this->decalage;
				char newC = val;
				texteF += newC;
			}
		}
	}
	std::ofstream fichierO(fileOutput.c_str(), std::ios::out | std::ios::trunc);

	if (fichierO)
	{
		fichierO << texteF;
		fichierO.close();
	}
}
