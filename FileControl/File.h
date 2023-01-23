#pragma once
#include "Node.h"

#include <string>
#include <filesystem>
#include <fstream>
#include <string>
#include <sstream>


class File
{
#pragma region Node
private:
	Node* header;
	int count;
	Node* CreateNode(const std::string& _commande, const std::string& _description);
#pragma endregion Node
private:
	std::string currentFile = "";
	std::string firstCommand, secondCommand;
	bool isLoop = true;
#pragma region C/D
public:
	File();
	~File();
#pragma endregion C/D
#pragma region Methode
#pragma region UseNode
public:
	void Insert(int _pos, const std::string& _commande,const std::string& _description);
	std::string& GetDescription(int _pos) const;
	void Delete(int _pos);
	void DisplayCommande() const;
#pragma endregion UseNode
public:
	std::string Current();
	void Display();
	void Command(std::string _firstCommand, std::string _secondCommand);
	void CMDEXE();
	void Init();
	void Read(std::string _currentFile);
#pragma endregion Methode

};





	

