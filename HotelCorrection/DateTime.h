#include "Object.h"
class DateTime : public Object
{
private:
	int day = 0;
	int month = 0;
	int years = 0;
	int hour = 0;
	int minute = 0;
	int second = 0;
public:
	DateTime() = default;
	DateTime(const int _day,const int _month = 0,const int _years = 0,const int _hour = 0,const int _minute = 0,const int _second = 0);
	DateTime(const DateTime& _copy);
private:
	static DateTime NowInternal();
public:
	static DateTime Parse(const std::string& _str);
public:
	 std::string ToString() const override;
public:
};

