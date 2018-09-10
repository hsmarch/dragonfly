#ifndef __WORLDMANAGER_H__
#define __WORLDMANAGER_H__

//Engine Includes
#include "Manager.h"
#include "ObjectList.h"

namespace df{

	class WorldManager : public df::Manager {
	private:
		WorldManager();
		WorldManager(WorldManager const&);
		void operator=(WorldManager const&);

		ObjectList updates;
		ObjectList deletions;

	public:

		static WorldManager &getInstance();

		int startUp();

		void shutDown();

		int insertObject(Object *p_o);

		int removeObject(Object *p_o);

		ObjectList getAllObjects(void) const;

		void update();

		int markForDelete(Object *p_o);

	};

}

#endif