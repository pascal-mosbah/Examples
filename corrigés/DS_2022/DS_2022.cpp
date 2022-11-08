#include <cmath>
#include <string>
#include <iostream>

using namespace std;

void pointer_to_pointer_allocation()
{
    int **mat = NULL;

    float rand_limit = 100.f;

    const size_t size = 5;
    // allocate for a square matrix whitout checking

    mat = new int *[size];

    for (int i = 0; i < size; ++i)
    {
        mat[i] = new int[size];
    }
    srand((unsigned)time(NULL));
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            mat[i][j] = (int)(rand() * rand_limit / (float)RAND_MAX + 1);
        }
    }
    for (int i = 0; i < size; ++i)
    {
        delete[] mat[i];
    }
    delete[] mat;
}

class Suite
{
public: // private not required since constant cannot be modified and no interface seems to be usefull in this case
    const float raison_;
    const float premier_terme_;
    Suite(const float &premier_terme, const float &raison) : raison_(raison), premier_terme_(premier_terme) {}
    virtual float calcul_terme_pour_n(const unsigned &n) = 0;
    virtual float calcul_somme_pour_n(const unsigned &n) = 0;
    friend ostream &operator<<(ostream &os, const Suite &other);
};

ostream &operator<<(ostream &os, const Suite &other)
{
    os << "premier terme : " << other.premier_terme_ << ", Raison : " << other.raison_;
    return os;
}

class Suite_arithmetique : public Suite
{
    float test1;

public:
    Suite_arithmetique(const float &premier_terme, const float &raison) : Suite(premier_terme, raison) {}
    float calcul_terme_pour_n(const unsigned &n)
    {
        float val = premier_terme_;

        for (unsigned i = 1; i < n; ++i)
        {
            val += raison_;
        }
        return premier_terme_ + n * raison_;
    }

    float calcul_somme_pour_n(const unsigned &n)
    {
        float sum = premier_terme_;

        for (unsigned i = 1; i <= n; ++i)
        {
            sum += calcul_terme_pour_n(i);
        }
        return (n + 1) * (premier_terme_ + calcul_terme_pour_n(n)) / 2.f;
    }
};

class Suite_geometrique : public Suite
{
public:
    Suite_geometrique(const float &premier_terme, const float &raison) : Suite(premier_terme, raison) {}
    float calcul_terme_pour_n(const unsigned &n)
    {
        return premier_terme_ * powf(raison_, static_cast<float>(n));
    }
    float calcul_somme_pour_n(const unsigned &n)
    {
        float sum = premier_terme_;
        for (unsigned i = 1; i <= n; ++i)
        {
            sum += calcul_terme_pour_n(i);
        }
        return sum;
    }
};

class A
{
public:
    virtual void f() const = 0;
};
class B : public A
{
    int n;

public:
    B(int p = 1) : n(p) {}
    void f() const { std::cout << "B" << n; }
};
class C : public A
{
    int n;

public:
    C(int p = 2) : n(p) {}
    void f() const { std::cout << "C" << n; }
};
void print(const A *a) { a->f(); }
void print(const B &a) { a.f(); }
void print(const C &a) { a.f(); }

int main()
{
    const unsigned size = 2;
    auto *sa = new Suite_arithmetique(1, 1);
    auto *sg = new Suite_geometrique(1, 2);

    Suite *tab[size] = {sa, sg};

    for (unsigned i = 0; i < size; ++i)
    {
        cout << "calcul_terme_pour_n : " << tab[i]->calcul_terme_pour_n(5) << endl;
        cout << "calcul_somme_pour_n : " << tab[i]->calcul_somme_pour_n(5) << endl;
        cout << *(tab[i]) << endl;
    }

    B b(3);
    C c;
    A *ab = &b;
    A *ac = &c;
    print(ab);
    print(ac);
    print(b);
    print(c);
    cout << endl;
    return EXIT_SUCCESS;
}
