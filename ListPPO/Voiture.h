#pragma once
#include <iostream>
#include <string>
class Voiture
{
private:
    std::string marque,
        modele,
        couleur;
    int an;
public:
    //constructeur
    Voiture(std::string mp, std::string md, std::string c, int a)
    {
        marque = mp;
        modele = md;
        couleur = c;
        an = a;
    };
    //Getters
    std::string getMarque()
    {
        return this->marque;
    }
    std::string getModele()
    {
        return this->modele;
    }
    std::string getCouleur()
    {
        return couleur;
    }
    int getAn()
    {
        return this->an;
    }

    //Setters
    void setCouleur(std::string c)
    {
        couleur = c;
    }

    //Methode
    void afficher()
    {
        std::cout << "Marque: " << this->marque << std::endl;
        std::cout << "Model: " << this->modele << std::endl;
        std::cout << "Couleur: " << this->couleur << std::endl;
        std::cout << "Anne: " << this->an << std::endl;

    }

    friend short comparer(const Voiture& v1, const Voiture& v2)
    {
        if (v1.an > v2.an)
            return v1.an;
        else
            return v2.an;
    }
};



