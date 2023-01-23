#include <iostream>
#include <sstream>
#include<string>

int countWords(std::string _str)
{
    // Breaking input into word
    // using string stream

    // Used for breaking words
    std::stringstream s(_str);

    // To store individual words
    std::string word;

    int count = 0;
    while (s >> word)
        count++; // count if word after space
    return count;
}
int main()
{

    std::string txt = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::cout << "The length of the txt string is: " << txt.length();
    std::cout << "The length of the txt string is: " << txt.size();
    return 0;
}
#pragma region
/*
* 
    std::string vlt;
    std::string _str = "Hello World";
    auto _find =_str.find(5);
    std::cout << _str.find(5) << std::endl;
* ---------------------------------------------------------------
*  int vl = 3;
    std::vector<int>vc = { 8, 9, 3, 2, 4 };
    auto rslt = std::find(vc.begin(), vc.end(), vl);
    if (rslt != end(vc))
        std::cout << "Elements_present_in_Vector " << vl << std::endl;
    vl = 18;
    rslt = find(vc.begin(), vc.end(), vl);
    if (rslt == end(vc))
        std::cout << "Element_not_present_in_Vector " << vl << std::endl;
* -----------------------------------------------------------
float a = 12;
    float* pf = &a;
    char* ch = reinterpret_cast<char*>(pf);
    std::cout << a << std::endl;
    std::cout <<"ce qui pointe vers a "<< *pf << std::endl;
    std::cout <<"ce qui pointe vers a "<< *ch << std::endl;
    std::cout <<"l'adresse ou je pointe & "<< &pf << std::endl;
    std::cout <<" l'adresse ou je pointe & "<< &ch << std::endl;
    std::cout << "l'adresse ou je pointe " << pf << std::endl;
    std::cout << " l'adresse ou je pointe " << ch << std::endl;
   // int b = *reinterpret_cast<int*>(&a);

   // std::cout << b << std::endl;
    std::cout << a << std::endl;
    */
#pragma endregion 