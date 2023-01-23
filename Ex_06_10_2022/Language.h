#include<string>
class Language
{
private:
	int  sizeline = 0; 
	int  sizeColumn = 0;
	std::string* table = nullptr;
public:
	Language() = default;
	Language(int const _size, std::string* _table) ;
	void InsertLanguage(std::string _fr, std::string _lang);
};

