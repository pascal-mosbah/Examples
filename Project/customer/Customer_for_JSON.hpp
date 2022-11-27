#pragma once

#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <fstream>

#ifdef _WIN32
#include <SDKDDKVer.h>
#endif

#include "Customer.hpp"

using boost::property_tree::ptree;
using boost::property_tree::read_json;
using boost::property_tree::write_json;

enum class Account_type
{
  Checking,
  Savings
};

struct Account
{
  int number;
  Account_type account_type;
};

ptree get_a_ptree_from_a_customer(const Customer &customer);

Customer get_a_customer_from_a_ptree(ptree &pt);
