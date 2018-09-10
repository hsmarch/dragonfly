//
// Dragonfly Object.cpp - Harrison March
//

//Engine Includes
#include "Object.h"
#include "WorldManager.h"
#include "GameManager.h"
#include "LogManager.h"


df::Object::Object(){
	id = 0;
	type = "Object";
	pos = Vector();
	df::WorldManager &w_mngr = df::WorldManager::getInstance();
	w_mngr.insertObject(this);

}

df::Object::~Object(){
	df::WorldManager &w_mngr = df::WorldManager::getInstance();
	w_mngr.removeObject(this);
}

int df::Object::EventHandler(const df::Event *p_e){
	return 0;
}

void df::Object::setId(int new_id){
	id = new_id;
}

int df::Object::getId() const{
	return id;
}

void df::Object::setType(std::string new_type){
	type = new_type;
}

std::string df::Object::getType() const{
	return type;
}

void df::Object::setPosition(Vector new_pos){
	pos = new_pos;
}
Vector df::Object::getPosition() const{
	return pos;
}