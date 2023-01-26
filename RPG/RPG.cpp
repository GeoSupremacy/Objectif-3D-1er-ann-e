#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "List.h"

class BlockChaine
{
    private:
        int* intArray = nullptr;
        int sizeArray;
    public:
        BlockChaine(int* _intArray, int _sizeArray);

        int getView();

        void Knowing();
        void Add(int _add);
        void Clear();
        
};

BlockChaine::BlockChaine(int* _intArray, int _sizeArray)
{
    intArray = _intArray;
    sizeArray = _sizeArray;
}

void BlockChaine::Knowing()
{
    int _i;
    std::cout << "choose occurrence: " << std::endl;
    std::cin >> _i;
    if (intArray[_i - 1] == 0)
    {
        std::cout << "valeur before: " << std::endl;
        std::cout << "valeur after: " << intArray[_i + 1] << std::endl;
    }
    if (intArray[_i + 1] == 0)
    {
        std::cout << "valeur before: " << intArray[_i - 1] << std::endl;
        std::cout << "valeur after: "  << std::endl;
    }
    else 
    {
        std::cout << "valeur before: " << &intArray[_i - 1] << std::endl;
        std::cout << "valeur after: " << &intArray[_i + 1] << std::endl;
    }
}
void BlockChaine::Clear()
{
    sizeArray = 0;
    delete[] intArray;
}
void BlockChaine::Add(int _add)
{
    int* _tmp = intArray;
    
    for (size_t i = 0; i < sizeArray; i++)
    {
        sizeArray++;

    }

    intArray = new int[sizeArray];
    
    for (size_t i = 0; i < sizeArray; i++) //(sizeArray-1) c'est pour l'occurence Au début il n'y a rien mais avt on a ajouter une ocurence
    {

        intArray[i] = _tmp[i]; // La nouvel table prend l'ancien mais avec ses caractéristiques
        intArray[i] = _add;
         
    }
    
}
int BlockChaine::getView()
{
    int p = intArray[1] = 5;
    return p;
}

int main()
{
    /*List list = List();
    for (int i = 0; i < 10: i++)
        list.AddFirst(i);*/
    List list = List{ 0,12,2,3,4,5,6,7,8,9 };
    List ListAdd(12, 500);
    list.Display();

   // std::cout << list.Contain(5) << std::endl;
   // std::cout << list.Contain(11) << std::endl;

    list.Clear();
    list.AddFirst(1);
    list.Display();
    BlockChaine v1(nullptr, 0);
    v1.Add(5);
    v1.Add(6);
    v1.Add(7);
    v1.Knowing();
    std::cout << v1.getView() <<std::endl;
    void Clear();
   



   /* List list = List();
    list.AddFirst(0);
    list.Display();
    std::vector<int>tab = std::vector<int>();
    tab.push_back();
    tab.push_emplace();
    tab.size();
    tab.erase(tab.begin() + 5);
    tab[0] = 5;
    std::cout << tab[0];*/
   /* std::ifstream stream("level0.scene");
    if (!stream.is_open()) return -2;
    std::string _str = "";
    std::string _result = "";
    while (std::getline(stream, _str))
    {
        _result += _str + "\n";
    }
    std::cout << _result << std::endl;*/
}