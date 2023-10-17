#include "keeper.h"
#include <iostream>
#include <string>

Keeper::Keeper() {
	this->data = nullptr;
	this->size = 0;
}

Keeper::~Keeper() {
	delete[] data;
}

int Keeper::GetSize() {
	return size;
}

void Keeper::add() {
	int type;
	try {
		std::cout << "Choose class members of this conference\n    1.Speaker\n    2.Administrator\n    3. Program\nYour choose ";
		std::cin >> type;
		if (type > 3 || type < 1) {
			throw (std::string)"Wrong choice! ";
		}
		Conference** tmp = new Conference * [size + 1];
		for (int i = 0; i < size; i++) {
			tmp[i] = data[i];
		}
		switch (type)
		{
		case 1:
			tmp[size] = new Participant;
			break;
		case 2:
			tmp[size] = new Administrator;
			break;
		case 3:
			tmp[size] = new Program;
			break;
		default:
			break;
		}
		if (tmp[size]->IsError()) {
			std::cout << "Ooooops! ";
			system("pause");
			return;
		}
		size++;
		if (data) {
			delete[] data;
		}
		data = tmp;
		std::cout << "That's done! ";
		system("pause");
	}
	catch (std::string err) {
		std::cout << "Error " + err;
		system("pause");

	}
}

void Keeper::add(int _type, std::ifstream& fin) {
	Conference** tmp = new Conference * [size + 1];
	for (int i=0; i < size; i++) {
		tmp[i] = data[i];
	}
	switch (_type) {
	case 1:
		tmp[size] = new Participant(fin);
		break;
	case 2:
		tmp[size] = new Administrator(fin);
		break;
	case 3:
		tmp[size] = new Program(fin);
		break;
	default:
		break;
	}
	size++;
	if (data) {
		delete[] data;
	}
	data = tmp;
}

void Keeper::edit() {
	int c;
	if (!size) {
		std::cout << "Empty!!! ";
		system("pause");
		return;
	}
	try {
		for (int i = 0; i < size; i++) {
			std::cout << "[" << i << "]";
			switch (data[i]->GetType()) {
			case 1:
				std::cout << "Participant ";
				break;
			case 2:
				std::cout << "Administrator ";
				break;
			case 3:
				std::cout << "Program ";
				break;
			default:
				break;
			}
		}
		std::cout << "Choose group to change: ";
		std::cin >> c;
		if (c < 0 || c>size-1) {
			throw (std::string)"Wrong index! ";

		}
		data[c]->edit();
		if (data[c]->IsError()) {
			std::cout << "Element empty ";
		}
		else {
			std::cout << "That's done! ";
		}
		system("pause");
	}
	catch (std::string err) {
		std::cout << "Error " + err;
		system("pause");
	}
}

void Keeper::del() {
	int c;
	if (!size) {
		std::cout << "Empty!!! ";
		system("pause");
		return;
	}
	try {
		for (int i = 0; i < size; i++) {
			std::cout << "[" <<  i <<"]" << std::endl;
			switch (data[i]->GetType()){
			case 1:
				std::cout << "Participant ";
				break;
			case 2:
				std::cout << "Administrator ";
				break;
			case 3:
				std::cout << "Program ";
				break;
			default:
				break;
			}
		}
		std::cout << "Choose element for remove: ";
		std::cin >> c;
		if (c<0 || c>size - 1) {
			throw (std::string)"Wrong index!!! ";
		}
		if (size == 1) {
			delete[] data;
			data = nullptr;
			std::cout << "That's done ";
			size--;
			system("pause");
			return;

		}
		Conference** tmp = new Conference * [size - 1];
		int j = 0;
		for (int i = 0; i < size; i++) {
			if (c == i) {
				continue;
			}
			tmp[j] = data[i];
			
		}
		delete[] data;
		data = tmp;
		size--;
		std::cout << "That's done! ";
		system("pause");
	}
	catch (std::string err) {
		std::cout << "Error " + err;
		system("pause");
	}
}


void Keeper::save()
{
	std::ofstream fout("aaa.txt");
	for (int i = 0; i < size; i++)
	{
		data[i]->save(fout);
	}
	fout.close();
	std::cout << "Save complete! " << std::endl;
	system("pause");
}


void Keeper::load()
{
	std::ifstream fin("aaa.txt");
	if (fin.fail())
	{
		std::cout << "File is empty " << std::endl;
		system("pause");
		return;
	}
	int type = 0;
	while (fin)
	{
		fin >> type;
		if (fin.peek() == -1)
		{
			break;
		}
		add(type, fin);
	}
	fin.close();
	std::cout << "Load complete!!! " <<std::endl;
	system("pause");
}

std::ostream& operator<<(std::ostream& out, Keeper& obj)
{
	if (!obj.size)
	{
		std::cout << "Empty." << std::endl;
		system("pause");
		return out;
	}
	for (int i = 0; i < obj.size; i++)
	{
		obj.data[i]->show(out);
	}
	system("pause");
	return out;
}