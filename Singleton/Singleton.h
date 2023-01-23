#pragma once
class Singleton
{
#pragma region f/p
private:
	static inline Singleton* instance = nullptr;
#pragma endregion f/p
#pragma region constructor/destructor
private:
	Singleton() = default;
	Singleton(const Singleton& obj) = delete;
public:
	~Singleton();
#pragma endregion constructor/destructor
#pragma region methods
public:
	static Singleton* OnDestroy(){
		if (instance == nullptr)instance = new Singleton();
		return instance;
	}
#pragma endregion methods
};

