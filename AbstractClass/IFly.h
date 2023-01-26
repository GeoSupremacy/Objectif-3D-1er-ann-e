#ifdef _WIN32|| _WIN64
__interface IFly
{
public:
	
	 void Fly();
	 float Speed();
};
#elif __APPLE__|| __linux__  
__interface IFly
{
public:
	virtual ~IFLy() = default;
	virtual void Fly() = 0;
	virtual float Speed() = 0;
};
#endif
