#include <Windows.h>
#include "Object.h"


#define UPROPERTY()
#define UFUNCTION()




class A
{
private:
	std::string name = "";
public:
	int age = 10;
public:
	A()
	{
		REGISTER_FIELD("name", name, "private");
	}
};

int main()
{
	

	return 0;
}

