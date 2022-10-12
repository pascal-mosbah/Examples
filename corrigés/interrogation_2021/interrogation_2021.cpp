// interrogation_2021: This file contains the 'main' function. Program execution begins and ends there.
//
//
//
#include <iostream>

class Mon_vecteur {
	int size_ = 0;
	float* tab_;
public:
	Mon_vecteur(const int& size);
	int get_size() const;
	float & operator()(const int& ind); //retourne le ième élément de tab_
	float  operator*(Mon_vecteur& v);   //produit scalaire de 2 vecteurs
	Mon_vecteur &operator*=(const float& val); // produit d'un vecteur par un scalaire
	friend std::ostream& operator<<(std::ostream& os, Mon_vecteur& v);
	~Mon_vecteur();
};

Mon_vecteur::Mon_vecteur(const int& size) : size_(size), tab_(new float[size]) {
}

int Mon_vecteur::get_size() const {
	return size_;
}

float & Mon_vecteur::operator() (const int& i) {
	return tab_[i];
}

float Mon_vecteur::operator*(Mon_vecteur& v) {
	float sum = 0;
	for (size_t i = 0; i < size_; ++i) {
		sum += this->tab_[i] * v(i);
	}
	return sum;
}

Mon_vecteur& Mon_vecteur::operator*=(const float &val) {
	for (size_t i = 0; i < size_; ++i) {
		tab_[i] *= val;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, Mon_vecteur& v) {
        for (size_t i = 0; i < v.get_size(); ++i) {
                os << v(i) << ", ";
        }
        return os;
}

Mon_vecteur::~Mon_vecteur(){
	delete [] tab_;
}


int main() {

	constexpr int size = 3;
	Mon_vecteur v1(size);
	Mon_vecteur v2(size);
	for (int i = 0; i < v1.get_size(); ++i) {
		v1(i) = static_cast<float>(i);
		v2(i) = static_cast<float>(i+1);
	}
	std::cout <<"get_size :"<< v1.get_size() << std::endl;
	std::cout <<"V1 : "<< v1 << " V2 : "<< v2 << std::endl;
	std::cout <<"V1*V2 : " << v1 * v2 << std::endl;
	v2 *= 2.;
	std::cout <<"V2*2 : "<< v2 << std::endl;
}
