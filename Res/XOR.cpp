#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include "XOR.h"

XOR::XOR(void)
{

}



void XOR::chiffrer(std::string fileInput, std::string fileOutput, char carac)
{
	std::ifstream fichierI(fileInput.c_str(), std::ios::in);
	std::string texte;


	if (fichierI)
	{
		std::string ligne;
		fichierI.seekg(0, std::ios::beg);
		 
		while (std::getline(fichierI, ligne)) 
		{
			char caractere;
			for (int i = 0; i < ligne.size(); i++) {
				caractere = (char)(ligne[i] ^ carac);
				texte += caractere;
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


void XOR::dechiffrer(std::string fileInput, std::string fileOutput, char carac)
{
	std::ifstream fichierI(fileInput.c_str(), std::ios::in | std::ios::binary);
	std::string texteF;

	if (fichierI)
	{
		fichierI.seekg(0, std::ios::beg);
		std::string c;
		while (std::getline(fichierI, c))
		{
			char caractere;
			for (int i = 0; i < c.size(); i++)
			{
				caractere = (char)(c[i] ^ carac);
				texteF += caractere;
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