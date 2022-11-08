#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <random>
#include <chrono>

#include <optional>

using std::string;
using std::to_string;
using std::vector;
using std::queue;
using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::optional;
using std::nullopt;
using std::random_device;
using std::default_random_engine;
using std::uniform_int_distribution;
using namespace std::chrono_literals;

struct Plane
{
     Plane();
	Plane(const string &identification);
	string identification_;
};

class Airport
{
	vector<Plane> planes;

public:
	void add_a_plane(Plane &plane);
	friend ostream &operator<<(ostream &os, const Airport &airport);
};

class Waiting_planes
{
	queue<Plane> planes;

public:
	void add_a_plane(Plane &plane);
	bool is_a_plane_available();

	optional<Plane> get_a_plane();
};

struct Plane_wrapping : Plane
{
     Plane_wrapping();

     Plane_wrapping(const string &identification);

     template <class Archive>
     void serialize(
         Archive &ar,
         unsigned int version)
     {
          ar &identification_;
     }
};
