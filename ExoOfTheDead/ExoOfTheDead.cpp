#include <iostream>
#include <string>


std::string dict = "zxcdgefef6545rgeh";
std::string text = "l like to cheat";
std::string key = "iw3";

std::string InToOut(std::string  _entry)
{
    std::string tab = "";
    for (int i = 0; i < _entry.size(); i++)
    {
        for (int x = 0; x < dict.size(); x++)
        {
            if (_entry[i] == dict[i])
            {
                tab += text[i];
            }
        }
    }
        return tab;
}
int main()
{
    for (char c : key)
        std::cout << text[dict.find(c)];

}

