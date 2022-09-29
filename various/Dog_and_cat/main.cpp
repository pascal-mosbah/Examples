#include "Dog_and_cat.hpp"

int main()
{
    const unsigned n = 5;
    auto chat1 = new Chat("Chat1");
    auto chat2 = new Chat("Chat2");
    auto chien1 = new Chien("Chien1");
    auto chien2 = new Chien("Chien2");
    auto quadripede = new Quadrupede("Quatre Pattes");

    std::cout << std::endl;
    Chat chat3("Chat3");

    Quadrupede *quadrupedes[n];

    quadrupedes[0] = chat1;
    quadrupedes[1] = chien1;
    quadrupedes[2] = chat2;
    quadrupedes[3] = chien2;
    quadrupedes[4] = quadripede;

    std::cout << std::endl;

    for (unsigned i = 0; i < n; ++i)
    {
        quadrupedes[i]->speak();
    }

    std::cout << std::endl;

    for (unsigned i = 0; i < n; ++i)
    {
        delete quadrupedes[i]; // Must be explicitly deleted
    }

    std::cout << std::endl;
    //chat3 is implicitly deleted not a pointer
}