#pragma once
#include <iostream>
#include <string>


class Cesar
{
private:
	int decalage;
public:
	Cesar(void);
	void setD(int);
	void chiffrer(std::string, std::string);
	void dechiffrer(std::string, std::string);
};

