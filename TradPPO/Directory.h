#pragma once
#include <string>
class Directory
{
#pragma region
private:
	std::string name ="";
	std::string path ="";
#pragma variable
public:
	Directory() = default;
	Directory(const std::string& _path);
	
public:
	std::string Name() const;
	std::string Path() const;
	
public:
	static Directory* Create(const std::string& _path);
	static bool Exist(const std::string& _path);
	static bool Delete(const std::string& _path);
};

