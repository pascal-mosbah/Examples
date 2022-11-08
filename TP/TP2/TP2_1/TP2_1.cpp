/*
#include <iostream.h>
#define multiplier (x,y) (x * y)
int main(void)
{
	int a;
	int b;
	cout << "Entrez une valeur :" << endl;
	cin << a;
	cout << "Entrez une autre valeur :" << endl;
	cin << b;
	cout << multiplier (a+1, b+1) << endl;
}
*/

#include <iostream>
#define multiplier(x,y) ((x) * (y))

using namespace std;
int main(void)
{
	int a;
	int b;
	cout << "Entrez une valeur :" << endl;
	cin >> a;
	cout << "Entrez une autre valeur :" << endl;
	cin >> b;
	cout << multiplier (a+1, b+1) << endl;
}


