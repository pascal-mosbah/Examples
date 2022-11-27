#include "Customer_for_JSON.hpp"

ptree get_a_ptree_from_a_customer(const Customer &customer)
{
  ptree pt;
  ptree account_numbers;

  pt.put("Number", customer.number_);
  pt.put("Name", customer.name_);

  for (auto &account_number : customer.account_numbers_)
  {
    ptree dummy_tree;
    //   dummy_tree.put(account_number.first, account_number.second);
    dummy_tree.put_value(account_number);
    account_numbers.push_back({"", dummy_tree});
  }
  pt.add_child("Account_numbers", account_numbers);
  return pt;
}

Customer get_a_customer_from_a_ptree(ptree &pt)
{

  int number = pt.get<int>("Number", 0);

  std::string name = pt.get<std::string>("Name");
  std::vector<int> account_numbers;

  for (ptree::value_type &account_number : pt.get_child("Account_numbers"))
  {
    account_numbers.push_back(account_number.second.get_value<int>());
  }

  Customer customer(number, std::move(name), std::move(account_numbers));
  return customer;
}
