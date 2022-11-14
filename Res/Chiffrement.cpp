#include <iostream>
#include <string>
#include "Chiffrement.h"

Chiffrement::Chiffrement(void)
{
	XOR* xr = new XOR();
	Cesar* cesar = new Cesar();
	this->mode = 0;
	this->cesar = cesar;
	this->xr = xr;
}

int Chiffrement::getMode(void)
{
	return this->mode;
}

void Chiffrement::setMode(int mode)
{
	this->mode = mode;
}

void Chiffrement::setFile(std::string fileI, std::string fileO)
{
	this->filenameInput = fileI;
	this->filenameOutput = fileO;
}

void Chiffrement::chiffrer(void)
{
	char carac;
	switch (this->mode)
	{
	case 1:
		int a;
		std::cout << "Quel est le décalage : ";
		std::cin >> a;
		std::cout << std::endl;
		if (a > 0 && a < 128)
		{
			this->cesar->setD(a);
			this->cesar->chiffrer(this->filenameInput, this->filenameOutput);
		}
		break;
	case 2:
		std::cout << "Quel est le caractère de cryptage : ";
		std::cin >> carac;
		std::cout << std::endl;
		this->xr->chiffrer(this->filenameInput, this->filenameOutput, carac);
		break;
	case 3:
		int b;
		std::cout << "Quel est le décalage : ";
		std::cin >> b;
		std::cout << std::endl;
		if (b > 0 && b < 128)
		{
			std::cout << "Quel est le caractère de cryptage : ";
			std::cin >> carac;
			std::cout << std::endl;
			this->cesar->setD(b);
			this->cesar->chiffrer(this->filenameInput, this->filenameOutput);
			this->xr->chiffrer(this->filenameOutput, this->filenameOutput, carac);
		}
		break;
	default:
		break;
	}
}

void Chiffrement::dechiffrer(void)
{
	char carac;
	switch (this->mode)
	{
	case 1:
		int c;
		std::cout << "Quel était le décalage : ";
		std::cin >> c;
		std::cout << std::endl;
		if (c > 0 && c < 128)
		{
			this->cesar->setD(c);
			this->cesar->dechiffrer(this->filenameInput, this->filenameOutput);
		}
		break;
	case 2:
		std::cout << "Quel était le caractère de cryptage : ";
		std::cin >> carac;
		std::cout << std::endl;
		this->xr->dechiffrer(this->filenameInput, this->filenameOutput, carac);
		break;
	case 3:
		int d;
		std::cout << "Quel était le décalage : ";
		std::cin >> d;
		std::cout << std::endl;
		if (d > 0 && d < 128)
		{
			std::cout << "Quel est le caractère de cryptage : ";
			std::cin >> carac;
			std::cout << std::endl;
			this->cesar->setD(d);
			this->xr->dechiffrer(this->filenameInput, this->filenameOutput, carac);
			this->cesar->dechiffrer(this->filenameOutput, this->filenameOutput);
		}
		break;
	default:
		break;
	}
}