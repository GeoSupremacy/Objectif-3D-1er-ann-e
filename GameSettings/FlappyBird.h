#include <windows.h>
class FlappyBird
{

private:
	static inline HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	static inline COORD cursorPosition = {};
	char bird[2][6] = { '/','-','-','o','\\',' ',
					   '|','_','_','_',' ','>' };
public:
	FlappyBird() = default;
public:
	void DrawBird();
	void SetCursorPosition(const int _x, const int _y);
};

