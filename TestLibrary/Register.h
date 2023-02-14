#pragma once

enum Mask
{Private, Public, Protected, Statique};
class RegisterO
{
public:
	
	int variable =0;
	//template <typename T>
	void Register(int _variable);
};

/*template<typename T>
inline void RegisterO::Register(T& _variable)
{
	if (_variable == <public>)
	{
		std::cout << " public" << std::endl;
	}
}*/
