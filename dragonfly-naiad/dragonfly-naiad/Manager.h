#ifndef __MANAGER_H__
#define __MANAGER_H__

//System Includes
#include <string>

namespace df
{
	class Manager
	{
	private:
		std::string type;
		bool is_started;

	protected:
		void setType(std::string type);

	public:
		Manager();
		virtual ~Manager();


		std::string getType();
		virtual int startUp();
		virtual void shutDown();

		bool isStarted() const;
	};
}

#endif
