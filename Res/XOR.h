#pragma once
#include <iostream>
#include <string>
#include <fstream>


class XOR
{
public:
	XOR(void);
	void chiffrer(std::string, std::string, char);
	void dechiffrer(std::string, std::string, char);
};

