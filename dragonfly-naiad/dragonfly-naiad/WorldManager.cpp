//
// Dragonfly WorldManager.cpp - Harrison March
//

//Engine Includes
#include "WorldManager.h"
#include "ObjectListIterator.h"

df::WorldManager::WorldManager(){
	updates = ObjectList();
	deletions = ObjectList();
}

df::WorldManager &df::WorldManager::getInstance(){
	static df::WorldManager w_mInstance;
	return w_mInstance;
}

int df::WorldManager::startUp(){
	Manager::startUp();
	return 0;
}

void df::WorldManager::shutDown(){
	ObjectList ol = updates;
	ObjectListIterator li(&ol);
	for (li.first(); !li.isDone(); li.next()) {
		updates.remove(li.currentObject());
	}
	Manager::shutDown();
}

int df::WorldManager::insertObject(df::Object *p_o){
	return updates.insert(p_o);
}

int df::WorldManager::removeObject(df::Object *p_o){
	return updates.remove(p_o);
}

ObjectList df::WorldManager::getAllObjects(void) const{
	return updates;
}

void df::WorldManager::update(){
	ObjectListIterator li(&deletions);
	for (li.first(); !li.isDone(); li.next()) {
		updates.remove(li.currentObject());
	}
	deletions.clear();
}

int df::WorldManager::markForDelete(df::Object *p_o){

	ObjectListIterator li(&deletions);
	while (!li.isDone()){
		if (li.currentObject() == p_o)
			return 0;
		li.next();
	}

	deletions.insert(p_o);
	return 0;
}