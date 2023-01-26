#include "DateTime.h"
#include "StringUtils.h"
#include <format>
#include <ctime>
#pragma warning(disable : 4996)
DateTime DateTime::Now = DateTime:NowInternal();
DateTime::DateTime(const int _day, const int _month, const int _years, const int _hour, const int _minute, const int _second)
{
	day = _day;
	month = _month;
	years = _years;
	hour = _hour;
	minute = _minute;
	second = _second;
}

DateTime::DateTime(const DateTime& _copy)
{
	day = _copy.day;
	month = _copy.month;
	years = _copy.years;
	hour = _copy.hour;
	minute = _copy.minute;
	second = _copy.second;
}

DateTime DateTime::NowInternal()
{
	const time_t _now = time(nullptr);
	const std::tm _tm = *locatetime(&_now);
	return DateTime(_tm.tm_mday, _tm.tm_mon+1, _tm.tm_year + 1900, _tm.tm_hour, _tm.tm_min, _tm.tm_sec);
}

DateTime DateTime::Parse(const std::string& _str)
{
	std::vector<std::string> _spliTile = StringUtils::Split(_str, ' ');
	std::vector<std::string> _ymd = StringUtils::Split(_str, '/');
	std::vector<std::string> _hms = StringUtils::Split(_str, ':');

	const int _day = std::stoi(_ymd[0]);
	const int _mouth = std::stoi(_ymd[1]);
	const int _years = std::stoi(_ymd[2]);

	const int _hour = std::stoi(_ymd[0]);
	const int _minute = std::stoi(_ymd[1]);
	const int _second = std::stoi(_ymd[2]);
	return DateTime(_day, _day, _second, _second, _second, _second);
}

std::string DateTime::ToString() const
{
	return std::format("{:02/:02/:02} {:02/{:02/{:02}", day ,month, years, hour, minute, second);
}
