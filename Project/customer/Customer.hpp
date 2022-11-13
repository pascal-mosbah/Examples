#pragma once
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#ifdef _WIN32
#include <SDKDDKVer.h>
#endif

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/serialization/vector.hpp>


struct Customer {
  Customer();
  Customer(const int &number, std::string &&name,
           std::vector<int> &&account_numbers);
  int number_ = 0;
  std::string name_;
  std::vector<int> account_numbers_;
  friend std::ostream &operator<<(std::ostream &os, const Customer &customer);
  template <class Archive>
     void serialize(Archive &ar, unsigned int version)
     {
          ar & name_ & number_ & account_numbers_;
     }
};