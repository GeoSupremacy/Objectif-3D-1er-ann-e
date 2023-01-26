#include <vector>
#include <string>

class Map;

class MapLoader
{
private:
	std::vector<Map*> maps = std::vector<Map*>();
	int count = 0;
public:
	MapLoader() = default;
	MapLoader(const MapLoader& _copy);
	~MapLoader();
public: //methode
	void Load();
	int Count() const;
	bool IsEmpty() const;
	std::vector<std::string>MapsName() const;
	Map& GetMap(const int _indx) const;
	void DisplayMapName();

};

