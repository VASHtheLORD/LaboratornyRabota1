#pragma once
#include <iostream>
#include <fstream>
#include <string>

class Conference {
	int type;
	bool error;
public:
	virtual ~Conference() = 0;
	void SetType(int _type);
	int GetType();
	bool IsError();
	void SetError(bool _error);
	virtual void save(std::ofstream& fout) = 0;
	virtual void edit() = 0;
	virtual void show(std::ostream& out) = 0;
};