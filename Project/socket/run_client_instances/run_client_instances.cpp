#include <cstdlib>
#include <string>
#include <random>
#include <chrono>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

using std::default_random_engine;
using std::random_device;
using std::uniform_int_distribution;

using std::string;
using std::to_string;

random_device rd;
default_random_engine generator(rd());
uniform_int_distribution<int> distribution(100, 800);

string add_plane()
{
     return "AF" + to_string(distribution(generator));
}

int main()
{
     int count = 0;
     unsigned int seconds = 3;
     while (true && count < 10)
     {
#ifdef _WIN32
          string command{"start ..\\bin\\socket_example_client " + add_plane()};
          system(command.c_str());
          Sleep(seconds * 1000);
#else
          string command{"../bin/socket_example_client " + add_plane() + "&"};
          system(command.c_str());
          sleep(seconds);
#endif
          ++count;
     }
#ifdef _WIN32
     string command{"start ..\\bin\\socket_example_client 0"};
#else
     string command{"../bin/socket_example_client 0"};
#endif
     system(command.c_str());
}