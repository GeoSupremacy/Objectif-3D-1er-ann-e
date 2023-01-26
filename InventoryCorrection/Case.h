#include "MapDataBase.h"
#include "Vector2.h"
class Case
{
private:
	char caseValue = MapDataBase::Wall;
	Vector2* position = nullptr;
public:
	Case() = default;
	Case(const char _value, Vector2* _position);
	Case(const Case& _copy);
	virtual ~Case();
public :
	bool IsWall() const;
	bool HasMob() const;
	bool IsEnter() const;
	bool IsExit() const;
	const char CaseValue() const;
	Vector2* Position() const;

};

