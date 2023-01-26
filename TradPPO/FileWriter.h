#include <string>
#include <fstream>

class FileWriter
{
#pragma
private:
	std::string path = "";
	std::ofstream stream = std::ofstream();
public:
	FileWriter() = default;
	FileWriter(const std::string& _path);
	FileWriter(const FileWriter& _copy);
public:
	bool IsOpen() const;
	void Write(const std::string& _value);
	void Clear();
	void Close();
};

