#pragma once
#include<fstream>
#include <string>
#include <vector>
class FileReader
{
public:
	std::string path = "";
	std::ifstream stream = std::ifstream();

	FileReader() = default;
	FileReader(const std::string& _path) ;
	FileReader(const FileReader& _copy);

public:
	bool IsOpen() const;
	void Close();
	std::vector<std::string>GetAllLines();

};

