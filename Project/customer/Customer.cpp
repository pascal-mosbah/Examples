#include "Customer.hpp"

Customer::Customer(){}

Customer::Customer(const int &number, std::string &&name,
           std::vector<int> &&account_numbers)
      : number_(number), name_(name), account_numbers_(account_numbers) {}

std::ostream &operator<<(std::ostream &os, const Customer &customer) {
  os << "Name " << customer.name_ << std::endl;
  os << "Number " << customer.number_ << std::endl;
  for (auto &account : customer.account_numbers_) {
    std::cout << "Account_Number : " << account << std::endl;
  }
  return os;
}