#pragma warning(disable: 4996)
#include <string>
#include <vector>//

class String
{
private:
    const char* value = "";
    int mLength = 0;
public:
    String(const char* _value);
    String(const String& _copy);
    ~String();
public:
    String ToLower()const;
    String ToUpper()const;
    bool Contains(const String& _str)const;
    std::vector<String> Split(const char _c);
    String Replace(const char _old, const char _new);
    int LastIndexof(const char _c);
    int FirstIndexof(const char _c);
    String Join(const std::vector<String>& _values);
    String Trim();
    String SubString(const int _begin, const int _endl) const;
    String SubString(const int _begin) const;
    int Countof(const char _c);
    static bool IsNullOrEmpty(const String& _str);
public:
    String& operator +=(const char _c);
    String& operator+=(const String& _str);
    String operator+(const String& _c);
    operator const char* ();
   
};

typedef;
