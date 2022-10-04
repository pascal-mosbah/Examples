#pragma once
#include <iostream>
#include <string>

class Quadrupede
{
private:
    std::string nom;

public:
    Quadrupede(const std::string &name);
    Quadrupede() = delete;
    void set_nom(const std::string &name);
    const std::string &get_nom();
    virtual void speak();
    virtual ~Quadrupede();
};

class Chat : public Quadrupede
{
    public:
    Chat(const std::string &name);
    void speak();
    ~Chat();
};

class Chien : public Quadrupede
{
    public:
    Chien(const std::string &name);
    void speak();
    ~Chien();
};