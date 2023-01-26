#include "Entity.h"


class Mob : public Entity
{

public:
	Mob() = default;
	Mob(const std::string& _name, Vector2* _position = new Vector2(0, 0), const float _maxLife = 100.0f, const float _maxMana = 100.0f);
	Mob(const Mob& _copy);
	~Mob();
public:
	void Move() override;
	
};

