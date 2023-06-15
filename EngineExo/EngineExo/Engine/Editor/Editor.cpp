#include "Editor.h"
#include "../Manager/EventSystem/EventSystem.h"
#include "../PrimaryType/Double/Double.h"
#include "../PrimaryType/Boolean/Boolean.h"
#include "../PrimaryType/Integer/Integer.h"
#include "../PrimaryType/List/IList.h"
#include "../UI/Toggle/Toggle.h"
#include "../UI/TextField/TextField.h"


#pragma region constructor
Engine::Editor::Editor::Editor(Object* _object) : super()
{
    currentObjectEdit = _object;
}
Engine::Editor::Editor::Editor(const Editor& _copy) : super(_copy)
{
    currentObjectEdit = _copy.currentObjectEdit;
}
#pragma endregion constructor
#pragma region method
Engine::Editor::EValueType Engine::Editor::Editor::GetValueType(Object* _object)
{
    if (dynamic_cast<PrimaryType::String*>(_object)) return EValueType::String;
    if (dynamic_cast<PrimaryType::Integer*>(_object)) return EValueType::Int;
    if (dynamic_cast<PrimaryType::Boolean*>(_object)) return EValueType::Bool;
    if (dynamic_cast<PrimaryType::Float*>(_object)) return EValueType::Float;
    if (dynamic_cast<PrimaryType::Double*>(_object)) return EValueType::Double;
    if (dynamic_cast<PrimaryType::IList*>(_object)) return EValueType::List;
    if (dynamic_cast<PrimaryType::Vector2*>(_object)) return EValueType::Vector;

    return EValueType::Object;
}
void Engine::Editor::Editor::DisplayProperties(const Reflection::FieldInfo* _filedInfo)
{
}
void Engine::Editor::Editor::CreteToggleProperty(Engine::Reflection::FieldInfo* _field)
{
    PrimaryType::Boolean* _value = dynamic_cast<PrimaryType::Boolean*>(_field->ReflectedObject());
    UI::Toggle* _toggle = new UI::Toggle(*_value);
    _toggle->SetPosition(currentPosition);
    elements.push_back(_toggle);
    currentPosition.y += _toggle->Shape()->getGlobalBounds().height;
}
void Engine::Editor::Editor::SetObjectEdit(Object* _object)
{
    for (UI::UIElement* _element : elements)
    {
        Manager::EventSystem::Instance()->UnRegister(_element);
        delete _element;
    }
    elements.clear();
    currentPosition = initialPosition;
    currentObjectEdit = _object;
}
void Engine::Editor::Editor::SetPosition(PrimaryType::Vector2* _position)
{
    currentPosition = _position;
    initialPosition = _position;
}
void Engine::Editor::Editor::InspectorGUI()
{
    if (currentObjectEdit == nullptr) return;
    currentPosition.y += 30;
    std::vector<Reflection::FieldInfo*> _allfields = currentObjectEdit->Fields();
    for (Reflection::FieldInfo* _field : _allfields)
    {
        switch (GetValueType(_field->ReflecTedObject()))
        {
        case EValueType::Int: break;
        case EValueType::Float:break;
        case EValueType::Double: break;
        case EValueType::Bool:
        {
            CreteToggleProperty(_field);
            break;
        }
        case EValueType::String:
        {
            PrimaryType::String* _value = dynamic_cast<PrimaryType::String*>(_field->ReflecTedObject());
            UI::TextField* _textFields = new  UI::TextField(_value->ToString(), PrimaryType::Vector2(200, 20));
            currentPosition.y += _textFields->Shape()->getGlobalBounds().height;
            elements.push_back(_textFields);
            break;
        }
        case EValueType::List:
        {
            PrimaryType::IList* _list = dynamic_cast<PrimaryType::IList*>(_field->ReflectedObject());
            for (size_t i = 0; i < _list->Count(); i++)
            {
                std::vector<Reflection::FieldInfo*> _otherFields = _list->operator[](i)->Fields();
                DisplayProperties(_otherFields);
            }
            break;
        }
        case EValueType::Vector: break;
        case EValueType::Object: break;
        default: break;
        }
    }
}
Engine::Object* Engine::Editor::Editor::ObjectEdit()
{
    return currentObjectEdit;
}
std::vector<Engine::UI::UIElement> Engine::Editor::Editor::Elements() const
{
    return std::vector<UI::UIElement>();
}
#pragma endregion method

