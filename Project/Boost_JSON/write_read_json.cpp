#include "Customer_for_JSON.hpp"

int main(int argc, char **argv)
{
  ptree pt_write;
  ptree pt_accounts;

  try
  {
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

    for (ptree::value_type &customer : pt_write.get_child("Customers"))
    {
      auto custom = get_a_customer_from_a_ptree(customer.second);

      std::cout << custom << std::endl;
    }
  }
  catch (std::exception &e)
  {
    // Other errors
    std::cout << "Error :" << e.what() << std::endl;
  }
}
