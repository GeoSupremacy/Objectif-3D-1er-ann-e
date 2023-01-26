#include <vector>
template <typename T>
class Singleton
{
private:
	static inline Singleton* instance = nullptr;
	std::vector<T> singleton = std::vector<T>();
public:
	Singleton() = default;
	static Singleton* Instance()
	{

	}
};

