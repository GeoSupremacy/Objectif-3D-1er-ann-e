#include "Map.h"
#include "Map.h"
#include"Case.h"
#include"Path.h"
#include"Environment.h"
#include"File.h"
#include"Player.h"
#include"Mob.h"//
#include"Vector2.h"
#include"Utils.h"
#include"MapLoader.h"
#include<iostream>
#include<string>

Map::Map(const std::string& _mapPath)
{
	mapPath = _mapPath;
	mapName = Path::GetFileNameWithoutExtension(mapPath);
	Init();
	
}



Map::Map(const Map& _copy)
{
	mapName = _copy.mapName;
	mapPath = _copy.mapPath;
	cases = _copy.cases;
	mobs = _copy.mobs;//
	Init();
}

Map::~Map()
{
	cases.clear();
}

void Map::Init()
{

	int count = 0;//
	
	std::vector<std::string> _lines = File::GetAllLines(mapPath);
	const size_t _size = _lines.size();
	for (size_t y = 0; y < _size; y++)
	{
		const std::string _line = _lines[y];
		const size_t _lenght = _line.length();
			for (size_t x = 0; x < _lenght; x++)
			{
				Vector2* _position = new Vector2(x, y);
				Case* _case = new Case(_line[x], _position);
				if (_case->IsEnter()) 
				{
					enter = _case;
					
				}
			}
			cases.push_back(new Case('\n', new Vector2(-1, -1)));

	}
}

void Map::Display()
{
	const size_t _size = cases.size();
	for (size_t i = 0; i < _size; i++)
	{
		if (player->Position()->Equals(cases[i]->Position()))
				std::cout << MapDataBase::Player;
		else if (cases[i]->Position()->Equals(mobs->Position())) // Test si la case est un mob //
		{
			
			std::cout << MapDataBase::Mob; // Afficher Mob //
		}
		else
			std::cout << cases[i]->CaseValue();
	}
}

bool Map::IsValid() const
{
	return enter != nullptr && exit != nullptr;
	return player;
}

Case* Map::GetCaseAtPosition(const Vector2& _position)
{
	const size_t _size = cases.size();
	for (size_t i = 0; i < _size; i++)
	{
		if (cases[i]->Position()->Equals(&_position))
			return cases[i];
	}
	return nullptr;
}

void Map::SetPlayer(Player* _player)
{
	player = _player;
	player->Position()->Set(*enter->Position());
	player->SetMap(this);
}

void Map::SetMob(Mob* _mob)
{
	mobs = _mob; 
	mobs->SetMap(this);
}


Player* Map::GetPlayer() const
{
	return player;
}

Mob* Map::GetMob() const
{
	return mobs;
}

Case* Map::Enter() const
{
	return enter;
}

Case* Map::Exit() const
{
	return exit;
}
std::string Map::MapsName() const
{
	return mapName;
}
