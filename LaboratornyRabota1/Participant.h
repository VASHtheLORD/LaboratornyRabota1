#pragma once
#include "Conference.h"

class Participant :public Conference {
	std::string FIO;
	std::string organization;
	std::string report;
	std::string annotation;
public:
	Participant();
	Participant(std::ifstream& fin);
	~Participant();
	void edit();
	void save(std::ofstream& fout);
	void show(std::ostream& out);
};