#include "Conference.h"

Conference::~Conference() {
}

void Conference::SetType(int _type) {

	type = _type;

}

int Conference::GetType() {
	return type;
}

bool Conference::IsError() {
	return this->error;
}

void Conference::SetError(bool _error)
{
	this->error = _error;
}
