#pragma once
class ObjectsManager
{
	State				_state;
	IMutex				_mutex;
	ManageSound			_sound;
	ManageSprite		_sprite;
	std::list<Objects*>	_toUpdate;
	std::list<Objects*>	_toDraw;
	std::list<Objects*>	_waiting;
public:
	ObjectsManager(void);
	~ObjectsManager(void);
	void	createObject(int index, bool active);
	Object*	getObjectToUpdate(int pos);
	Object* getObjectToDraw(int pos);
	bool	updateState();
};

