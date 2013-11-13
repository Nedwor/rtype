#include "ObjectsManager.h"


ObjectsManager::ObjectsManager(void)
{
}


ObjectsManager::~ObjectsManager(void)
{
}

void	ObjectsManager::createObject(int index, bool active)
{
}

//Object*	ObjectsManager::getObjectToUpdate(int pos)
{
}

//Object*	ObjectsManager::getObjectToDraw(int pos)
{
}

bool	ObjectsManager::updateState()
{
	if (this->_state == END)
		this->_state = START;
	else if (this->_state == START)
		this->_state = UPDATING
	else
		this->_state = END;
}