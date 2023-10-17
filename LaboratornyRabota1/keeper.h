#pragma once
#include "Participant.h"
#include "Admin.h"
#include "Program.h"
#include <fstream>
class Keeper {	
	Conference** data;
	int size;

public:
	Keeper();
	~Keeper();
	int GetSize();
	void edit();
	void add();
	void add(int _type, std::ifstream& fin);
	void del();
	void save();
	void load();
	friend std::ostream& operator << (std::ostream& out, Keeper& obj);
};