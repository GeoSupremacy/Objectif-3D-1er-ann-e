#include "Player.h"
#include"Map.h"
#include"Mob.h"
#include <string>
#include "Case.h"
#include "MapLoader.h"
#include"Utils.h"

int main()
{
	Player* _player = new Player(Utils::UserChoise<std::string>("enter you name"));

	Mob* _mob1 = new Mob("BobLeMob", new Vector2(7, 7));

	// Mob* _mob2 = new Mob("Mob", new Vector2(4, 4));

	

	MapLoader _loader = MapLoader();
	_loader.Load();
	if (_loader.IsEmpty()) return -5;
	_loader.DisplayMapName();

	Map map = _loader.GetMap(Utils::UserChoise<int>("Choose map: "));
	if (!map.IsValid()) return -4;
	{
		map->SetPlayer(_player);
		map->SetMobs(_mob1);
	}

	while (!map.GetPlayer()->Position()->Equals(map.Exit()->Position()))
	{
		if (map->GetPlayer()->GetPosition()->Equals(map->GetMob()->GetPosition()))
		{
			std::cout << "Bonsoir, je suis BobLeMob HAHA !" << std::endl;
		}

		map->GetPlayer()->Move();

		map->SetMobs(_mob1);
		map->GetMob()->Move();

		system("cls");
		map.Display();
		map.GetPlayer()->Move();
	}
	system("cls");
	Utils::Log(map.GetPlayer()->Name() + "find exit!");
	return 0;
} 