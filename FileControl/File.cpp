#include "File.h"
#include "DateTime.h"
#include "Command.h"


#pragma region Node
Node* File::CreateNode(const std::string& _commande, const std::string& _description)
{
	Node * _temp = new Node;
	_temp->description = _description;
	_temp->commande = _commande;
	_temp->nextList = nullptr;
	return _temp;
}
#pragma endregion Node
#pragma region C/D

File::File() : header(nullptr), count(0) {}
File::~File()
{
	Node* del = header;
	while (header) {
		header = header->nextList;
		delete del;
		del = header;
	}
}
#pragma endregion C/D
#pragma region Methode
#pragma region UseNode
void File::Insert(int _pos, const std::string& _commande, const std::string& _description)
{
	
	Node * _new = CreateNode(_commande,_description);

	
	if (count == 0) {
		_new->nextList = header;
		header = _new;
	}
	
	else {
		Node* _currentList = header;
		for (int i = 1; i < count; i++) {
			_currentList = _currentList->nextList;
		}
		_new->nextList = _currentList->nextList;
		_currentList->nextList = _new;
	}
	count++;
}
std::string& File::GetDescription(int _pos) const
{
	
	 if (_pos == 0) {
		return header->description;
	}
	else {
		Node * _current = header;
		for (int i = 0; i < _pos; i++) {
			_current = _current->nextList;
		}
		return _current->description;
	}
}
void File::Delete(int _pos)
{
	if (_pos == 0) {
		Node * del = header;
		header = header->nextList;
		delete del;
	}
	else {
		Node* _current = header;
		for (int i = 0; i < _pos - 1; i++) {
			_current = _current->nextList;
		}
		Node * _del = _current->nextList;
		_current->nextList = _current->nextList->nextList;
		delete _del;
	}
	count--;
}
void File::DisplayCommande() const
{
	if (count == 0) {
		std::cout << "The list is empty!" << std::endl;
		return;
	}
	Node * _current = header;

	while (_current !=0) {
		std::cout << _current->commande <<"         "<< _current->description << std::endl;
		_current = _current->nextList;
	}
}
#pragma endregion UseNode
std::string File::Current()
{
	return currentFile = "C:/User/benoit";

}
void File::Display()
{
	Current();
	std::cout << currentFile << ">";
	std::cin >> firstCommand; std::cin >> secondCommand;
	std::cout << std::endl;
	Command(firstCommand, secondCommand);
}
void File::Command(std::string _firstCommand, std::string _secondCommand)
{
	if (_firstCommand == "cd" )
	{
		if (_firstCommand == "cd" && _secondCommand =="help")
		{
			std::cout << "hi" << std::endl;
		}
	}
	else if(_firstCommand == "cls")
	{
		system("cls");
	}
	else if (_firstCommand == "drives")
	{
		
	}
	else if (_firstCommand == "exit")
	{
		isLoop = false;
	}
	else if (_firstCommand == "help")
	{
		if (_firstCommand == "help cd")
			GetDescription(0);
		std::cout << "----------HELP----------" << std::endl;
		DisplayCommande();
		std::cout << "------------------------" << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
	}
	else if (_firstCommand == "tasklist")
	{
	}
	else if (_firstCommand == "time")
	{
		system("date/t");
		system("time/t");
	}
	else if (_firstCommand == "tree")
	{
	}
	else if (_firstCommand == "type")
	{
		Read(currentFile);
	}
}
void File::CMDEXE()
{
	Init();
	while (isLoop)
	{
		Display();
	}
}
void File::Init()
{
	Insert(0,"cd","Displays the name of or changes the current directory.");
	Insert(1,"cls", "Clears the screen.");
	Insert(2,"drives", "Displays all drives in the computer.");
	Insert(3,"echo", "Displays messages, or turns command_echoing on or offy.");
	Insert(4,"exit ", "Quits the CMD.EXE program (command interpreter)");
	Insert(5,"help ", "Provides Help information for Windows commands");
	Insert(6,"tasklist ", "Displays all currently running tasks including services.");
	Insert(7,"time","Displays the system time.");
	Insert(8,"tree", "Graphically displays the directory structure of a drive or path.");
	Insert(9,"type", "Displays the contents of a text file.");
}
void File::Read(std::string _currentFile)
{
	std::ifstream _monFlux(_currentFile);
	if (_monFlux)
	{
		std::string line;
		printf("Line by line\n");
		while (getline(_monFlux, line))
			std::cout << line << std::endl;
		printf("Word by word\n");
		_monFlux.clear();

		_monFlux.seekg(0, std::ios::beg);
		std::string word;
		while (_monFlux >> word)
			std::cout << word << std::endl;
		printf("Character by character\n");
		_monFlux.clear();
		_monFlux.seekg(0, std::ios::beg);
		char c;
		while (_monFlux.get(c))
		{
			std::cout << c << std::endl;
			int position = _monFlux.tellg();
		}
	}
	else
		std::cout << "Unable to open the file" << std::endl;
}
#pragma endregion Methode