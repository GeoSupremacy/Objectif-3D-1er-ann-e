#include <iostream>

const int sizeTab = 4;
int oneTab[sizeTab] = { 1,2,3,4 };
int twoTab[4][4] = {
   { 1,2,3,4 },
   { 1,2,3,4 },
   { 1,2,3,4 },
   { 1,2,3,4 }
};
std::string students[5][2][5][2] = {
    { "Jean", "Student","oi","oi","m","Jean", "Student","oi","oi","m","y","t","e"},

    {"Hao", "Doe","m","Jean", "Student","oi","oi","m","y","t","e"},

    { "Jean", "Student","m","Jean", "Student","oi","oi","m","y","t","e"  },
    { "Jean", "Student" ,"m","Jean", "Student","oi","oi","m","y","t","e" },
    {"Hao", "Doe","m","Jean", "Student","oi","oi","m","y","t","e"},

};
int main()
{
    
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int O = 0; O < 5; O++)
            {
                for (int T = 0; T < 2; T++)
                {
                    std::string _student = "";
                    _student += " " + students[i][j][0][T];
                    std::cout << _student;
                }
                
            }
        }
        std::cout <<  std::endl;
    }
}
