#pragma once
#include "Conference.h"

class Program :public Conference {
	std::string day;
	std::string name;
	std::string time;

public:
	
	Program();
	Program(std::ifstream& fin);
	~Program();
	void edit();
	void save(std::ofstream& fout);
	void show(std::ostream& out);
};