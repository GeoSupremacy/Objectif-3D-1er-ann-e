#pragma once
#include <string>

class FileStream;
class File
{
private:
	std::string path = "";

#pragma constructeur
public:
	File() = default;
	File(const std::string& _path);
	File(const File& _copy);
	
public:
	static bool Exist(const std::string& _path);
	static FileStream* Create(const std::string& _path);
};

