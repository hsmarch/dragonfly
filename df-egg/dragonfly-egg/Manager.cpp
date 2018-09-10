//
// Dragonfly Manager.cpp - Harrison March
//

//Engine Includes
#include "Manager.h"

df::Manager::Manager() {
	this->type = "Manager";
}

df::Manager::~Manager() {

}

int df::Manager::startUp() {
	is_started = true;
	return 0;
}

void df::Manager::shutDown() {
	is_started = false;
	return;
}

bool df::Manager::isStarted() const{
	return is_started;
}

void df::Manager::setType(std::string type) {
	this->type = type;
}

std::string df::Manager::getType() {
	return type;
}