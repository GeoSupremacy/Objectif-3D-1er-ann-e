#include <vector>
#include <string>
class Case;
class Player;
class Vector2;
class Mob;

class Map
{
private:
	std::vector<Case*> cases = std::vector<Case*>();
	std::string mapName = "default name";
	std::string mapPath = "";
	Case* enter = nullptr;
	Case* exit = nullptr;
	Mob* mobs = nullptr;;
	Player* player = nullptr;
public:
	Map() = default;
	Map(const std::string& _mapPath);
	Map(const Map& _copy);
	~Map();
private:
	void Init();
public:
	void Display();
	bool IsValid() const;
	Case* GetCaseAtPosition(const Vector2& _psition);
	void SetPlayer(Player* _player);
	void SetMob(Mob* _mob);
	Player* GetPlayer() const;
	Mob* GetMob() const;
	Case* Enter() const;
	Case* Exit()const;
	std::string MapsName() const;
};

