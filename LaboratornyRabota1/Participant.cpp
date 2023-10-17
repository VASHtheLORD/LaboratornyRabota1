#include "Participant.h"

Participant::Participant() {
	std::cout << "Append of participant ";
	try {
		SetType(1);
		std::cout << "Enter FIO: ";
		std::cin.ignore(256, '\n');
		getline(std::cin, FIO);
		if (FIO == "") {
			throw (std::string)"FIO can not be empty ";
		}
		std::cout << "Enter University or Organization: ";
		//std::cin.ignore(256, '\n');
		getline(std::cin, organization);
		if (organization == "") {
			throw (std::string)"Organization can not be empty ";
		}
		std::cout << "Enter your report: \n";	
		//std::cin.ignore(256, '\n');
		getline(std::cin, report);
		if (report == "") {
			throw (std::string)"Report can not be empty ";
		}
		//std::cin.ignore(256, '\n');
		std::cout << "Enter your annotation: \n";
		getline(std::cin, annotation);
		if (annotation == "") {
			throw (std::string)"Annotation can not be empty ";
		}
		SetError(false);
	}
	catch (std::string err) {
		std::cout << "Error " + err;
		SetError(true);
	}
}

Participant::Participant(std::ifstream& fin) {
	SetType(1);
	fin.ignore(256, '\n');
	getline(fin, FIO);
	//fin.ignore(256, '\n');
	getline(fin, organization);
	//fin.ignore(256, '\n');
	getline(fin, report);
	//fin.ignore(256, '\n');
	getline(fin, annotation);
}

Participant::~Participant() {
	std::cout << "BAAAAAAAAAAAAAAAAAAM ";
}

void Participant::edit() {
	try {
		int c, iTemp; 
		std::string stringTemp;
		std::cout << "Choose attribute to change: \n1. FIO\n2. Organization\n3. Report\n4. Annotation\nYour choice: ";
		std::cin>> c;
		if (c < 1 || c >4) {
			throw (std::string)"Wrong index! ";
		}
		std::cout << "Original value: ";
		switch (c) {
		case 1:
			std::cout << FIO;
			std::cout << "New value: ";
			std::cin.ignore(256, '\n');
			getline(std::cin, stringTemp);
			if (stringTemp == "") {
				throw(std::string)"FIO can not be empty ";
			}
			FIO = stringTemp;
			break;
		case 2:
			std::cout << organization;
			std::cout << "New value: ";
			std::cin.ignore(256, '\n');
			getline(std::cin, stringTemp);
			if (stringTemp == "") {
				throw(std::string)"Organization can not be empty ";
			}
			organization = stringTemp;
			break;
		case 3:
			std::cout << report;
			std::cout << "New value: ";
			std::cin.ignore(256, '\n');
			getline(std::cin, stringTemp);
			if (stringTemp == "") {
				throw(std::string)"Report can not be empty ";
			}
			report = stringTemp;
			break;
		case 4:
			std::cout << annotation;
			std::cout << "New value: ";
			std::cin.ignore(256, '\n');
			getline(std::cin, stringTemp);
			if (stringTemp == "") {
				throw(std::string)"Annotation can not be empty ";
			}
			annotation = stringTemp;
			break;
		default:
			break;
		}
		SetError(false);
	}
	catch (std::string err) {
		std::cout << "Error " + err;
		SetError(true);
	}
}

void Participant::save(std::ofstream &fout) {
	fout << GetType() << std::endl
		<< this->FIO << std::endl
		<< this->organization << std::endl
		<< this->report << std::endl
		<< this->annotation << std::endl;
}

void Participant::show(std::ostream & out) {
	out << "Participant: " << std::endl
		<< "FIO: " << FIO << std::endl
		<< "Organization " << organization << std::endl
		<< "Report\n" << report << std::endl
		<< "Annotation\n" << annotation << std::endl;
}