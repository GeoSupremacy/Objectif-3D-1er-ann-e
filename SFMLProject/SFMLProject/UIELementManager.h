#pragma once
#include "Singleton.h"
#include <vector>


class FB_UIElement;

class UIElementManager : public Singleton<UIElementManager>
{
#pragma region f/p
private:
	std::vector<FB_UIElement*> elements = std::vector<FB_UIElement*>();
#pragma endregion f/p
#pragma region constructor/destructor
public:

#pragma endregion constructor/destructor
#pragma region methods
public:
	void Register(FB_UIElement* _elements);
	void UnRegister(FB_UIElement* _elements);
	void Update();
#pragma endregion methods
#pragma region override
public:
	virtual void OnDestroy() override;
#pragma endregion override

};

