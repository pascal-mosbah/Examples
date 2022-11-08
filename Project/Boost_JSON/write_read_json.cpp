#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using boost::property_tree::ptree;
using boost::property_tree::read_json;
using boost::property_tree::write_json;

struct Customer {
  Customer(const int &number, std::string &&name,
           // std::vector<std::pair<std::string, int>>&& account_numbers)
           std::vector<int> &&account_numbers)
      : number_(number), name_(name), account_numbers_(account_numbers) {}
  int number_ = 0;
  std::string name_;
  std::vector<int> account_numbers_;
};

std::ostream &operator<<(std::ostream &os, const Customer &customer) {
  os << "Name " << customer.name_ << std::endl;
  os << "Number " << customer.number_ << std::endl;
  for (auto &account : customer.account_numbers_) {
    std::cout << "Account_Number : " << account << std::endl;
  }
  return os;
}

enum class Account_type { Checking, Savings };

struct Account {
  int number;
  Account_type account_type;
};

ptree get_a_ptree_from_a_customer(const Customer &customer) {
  ptree pt;
  ptree account_numbers;

  pt.put("Number", customer.number_);
  pt.put("Name", customer.name_);

  for (auto &account_number : customer.account_numbers_) {
    ptree dummy_tree;
    //   dummy_tree.put(account_number.first, account_number.second);
    dummy_tree.put_value(account_number);
    account_numbers.push_back({"", dummy_tree});
  }
  pt.add_child("Account_numbers", account_numbers);
  return pt;
}

Customer get_a_customer_from_a_ptree(ptree &pt) {

  int number = pt.get<int>("Number", 0);

  std::string name = pt.get<std::string>("Name");
  std::vector<int> account_numbers;

  for (ptree::value_type &account_number : pt.get_child("Account_numbers")) {
    account_numbers.push_back(account_number.second.get_value<int>());
  }

  Customer customer(number, std::move(name), std::move(account_numbers));
  return customer;
}

int main(int argc, char **argv) {
  ptree pt_write;
  ptree pt_accounts;

  try {
    Customer customer1(1001, "Tartempion1",
                       //    { {"Epargne", 10000}, {"Courant", 10001} });
                       {10000, 10001});

    Customer customer2(1002, "Tartempion2",
                       //      { {"Epargne", 10002}, {"Courant", 10003} });
                       {10002, 10003});

    pt_accounts.push_back({"", get_a_ptree_from_a_customer(customer1)});
    pt_accounts.push_back({"", get_a_ptree_from_a_customer(customer2)});
    pt_write.add_child("Customers", pt_accounts);

    std::ofstream file_out("example_write_read.json");
    write_json(file_out, pt_write);
    file_out.close();

    std::ifstream file_in("example_write_read.json");
    read_json(file_in, pt_write);
    file_in.close();

    for (ptree::value_type &customer : pt_write.get_child("Customers")) {
      auto custom = get_a_customer_from_a_ptree(customer.second);

      std::cout << custom << std::endl;
    }
  } catch (std::exception &e) {
    // Other errors
  }
}
