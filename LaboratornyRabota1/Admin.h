#pragma once
#include "Conference.h"

class Administrator :public Conference {
	std::string FIO;
	std::string position;
	std::string responsibility;
public:
	Administrator();
	Administrator(std::ifstream& fin);
	~Administrator();
	void edit();
	void save(std::ofstream& fout);
	void show(std::ostream& out);
};