#include "Ihm.h"

void Ihm::run(void)
{
	Chiffrement chiffrement;
	bool choix = true;
	int mode;
	int crypt;
	std::string fileI;
	std::string fileO;
	while (choix)
	{
		std::cout << "Choisissez votre mode de chiffrement (Cesar = 1, XOR = 2, Cesar+XOR = 3) : ";
		std::cin >> mode;
		if (mode == 1 || mode == 2 || mode == 3)
		{
			chiffrement.setMode(mode);
			std::cout << std::endl;
			std::cout << "Voulez-vous crypter ou décrypter (0 ou 1) : ";
			std::cin >> crypt;
			std::cout << std::endl;
			if (crypt == 0)
			{
				std::cout << "Quel est le fichier à crypter ? : ";
				std::cin >> fileI;
				std::cout << std::endl;
				std::cout << "Quel est le nom du fichier de sortie : ";
				std::cin >> fileO;
				std::cout << std::endl;
				chiffrement.setFile(fileI, fileO);
				chiffrement.chiffrer();
			}
			else if (crypt == 1)
			{
				std::cout << "Quel est le fichier à décrypter ? : ";
				std::cin >> fileI;
				std::cout << std::endl;
				std::cout << "Quel est le nom du fichier de sortie : ";
				std::cin >> fileO;
				std::cout << std::endl;
				chiffrement.setFile(fileI, fileO);
				chiffrement.dechiffrer();
			}
			else
			{
				std::cout << "Cette option n'est pas valide." << std::endl;
			}
		}
		else
		{
			std::cout << "Ce mode n'est pas valide." << std::endl;
		}
	}
}
