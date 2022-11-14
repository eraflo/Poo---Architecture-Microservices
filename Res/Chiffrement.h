#pragma once
#include <iostream>
#include <string>
#include "Cesar.h"
#include "XOR.h"

class Chiffrement
{
private:
	int mode;
	std::string filenameInput;
	std::string filenameOutput;
	Cesar* cesar;
	XOR* xr;
public:
	Chiffrement(void);
	int getMode(void);
	void setMode(int);
	void setFile(std::string, std::string);
	void chiffrer(void);
	void dechiffrer(void);
};

