
#include "Object.h"
#include <string>

class IGame : public Object
{
public:
	virtual ~IGame() = default;
	virtual void OnStart() = 0;
	virtual void OnUpdate() = 0;
	virtual void OnEnd() = 0;
	virtual void DisplayMenu() = 0;
	virtual std::string GameName() = 0;
	virtual std::string GamDescription() = 0;
};