#include <iostream>
#include<string>
#include<vector>
#include<map>
#include "TranslateManager.h"
#include "Language.h"
#include "Utile.h"
#include "StringUtile.h"
int main()
{
   // std::string _str = "sfdgfdg dhry htdyt ";
    setlocale(LC_ALL, "");
    TranslateManager manager = TranslateManager();
    Utile::Log(manager.GetMessage("fr", "salut"));
    Utile::Log(manager.GetMessage("en", "hello"));
  

   /* FileStream _stream = File::Create("C:\\Users\\GUIC1203\\source\\repos\\New folder\\Text.txt");

    _stream->Writer()->Write("Test");

    std::vector<std::string> _allLines = _stream->Reader()->GetAllLines();
    for (int i = 0; i < _allLines.size(); i++)
        Utile::Log(_allLines[i]);
    _stream->Close();*/
    
    /* FileReader file = FileReader("C:\\Users\\GUIC1203\\source\\repos\\New folder\\Text.txt");
        std::vector<std::string> _allLines = file.GetAllLines();
    for (int i = 0; i < _allLines.size(); i++)
        Utile::Log(_allLines[i]);

    */
    /*
    if (Directory::Exist(Enviromnent::CurrentDirectory()))
    {

                                                                    C:\Users\GUIC1203\source\repos\New folder\Text.txt
        Utile::Log("exist !");
    }
    Directory::Create(Path::GetPath("C:\\Test"));
    if (!Directory::Exist("C:\\Test"))
    {
        Utile::Log("test doesn't exist !");
    }
    else
    {
        Utile::Log("test exist !");
    }

        if (Directory::Delete("C:\\Test"))
        {
            Utile::Log("test deleted !");
        }
        */
        //Directory d = Directory(Enviromnent::CurrentDirectory());

      /* std::string _path = "C:\\Test";
       std::string _path1 = "Traduction";
       std::string _fullPath = Path::Combine(_path, _path1);

       //StringUtile::Replace(_path, "\\", "/"); // "/"->totoTest
       Utile::Log(_fullPath);*/
   
}

