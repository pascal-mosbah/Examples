#include <iostream>
#include <iomanip>

int main(){
	for (int i = 1;i < 10;++i){
		for (int j = 1;j < 10; ++j){
			std::cout<< i <<" * "<<j<<" = "<<std::setw(2)<<i*j<<std::endl;
		}
	}
}
