#include "Dog_and_cat.hpp"

Quadrupede::Quadrupede(const std::string &in_nom) : nom(in_nom)
{
    std::cout << " Naissance du quadripede : " << get_nom() << std::endl;
}

const std::string &Quadrupede::get_nom()
{
    return nom;
}

void Quadrupede::set_nom(const std::string &name)
{
    this->nom = name;
}

void Quadrupede::speak()
{
    std::cout << "Le quadripede " << nom << " ne dit rien !" << std::endl;
};

Quadrupede::~Quadrupede(){
       std::cout << "Le quadrupede " << nom << " n'existe plus" << std::endl;
}

void Chat::speak()
{
    std::cout << "Le chat " << get_nom() << " dit Miaou !" << std::endl;
};

void Chien::speak()
{
    std::cout << "Le chien " << get_nom() << " dit Ouaf !" << std::endl;
};

Chat::Chat(const std::string &nom) : Quadrupede(nom)
{
    std::cout << " Naissance du chat : " << get_nom() << std::endl;
}

Chien::Chien(const std::string &nom) : Quadrupede(nom)
{
    std::cout << " Naissance du chien : " << get_nom() << std::endl;
}

Chien::~Chien()
{
    std::cout << "Le chien " << Quadrupede::get_nom() << " n'existe plus" << std::endl;
}

Chat::~Chat()
{
    std::cout << "Le chat " << get_nom() << " n'existe plus" << std::endl;
}