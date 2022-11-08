#include "some_defines.hpp"

#include <thread>
#include <mutex>
#include <optional>
#include <random>

using std::ref;



std::mutex airport_mutex;
std::mutex waiting_planes_mutex;

void Airport::add_a_plane(Plane &plane)
{
	airport_mutex.lock();
	planes.push_back(plane);
	airport_mutex.unlock();
}

optional<Plane> Waiting_planes::get_a_plane()
{
	if (is_a_plane_available())
	{
		waiting_planes_mutex.lock();
		auto plane = planes.front();
		planes.pop();
		waiting_planes_mutex.unlock();
		return plane;
	}
	return nullopt;
}

void Waiting_planes::add_a_plane(Plane &plane)
{
	waiting_planes_mutex.lock();
	planes.push(plane);
	waiting_planes_mutex.unlock();
}

void add_plane_sometimes(Waiting_planes &waiting_planes, bool &stop_thread)
{
	random_device rd;
	default_random_engine generator(rd());
	uniform_int_distribution<int> distribution(100, 800);

	while (!stop_thread)
	{
		std::this_thread::sleep_for(3s);
		Plane plane;
		plane.identification_ = "AF" + to_string(distribution(generator));
		waiting_planes.add_a_plane(plane);
	}
}

void airport_control(Airport &airport, Waiting_planes &waiting_planes, bool &stop_thread)
{
	while (!stop_thread)
	{
		while (waiting_planes.is_a_plane_available())
		{
			if (auto plane = waiting_planes.get_a_plane())
			{
				cout << "Add a plane " << plane.value().identification_ << endl;
				airport.add_a_plane(*plane);
			}
		}
	}
}

int main()
{
	//	vector<Plane> planes;
	Airport airport;
	Waiting_planes waiting_planes;
	bool stop_thread = false;

	std::thread airport_thread(airport_control, std::ref(airport), std::ref(waiting_planes), std::ref(stop_thread));
	std::thread add_plane(add_plane_sometimes, std::ref(waiting_planes), ref(stop_thread));

	while (true)
	{
		string name;
		cin >> name;
		if (name == "0")
		{
			stop_thread = true;
			break;
		}
		Plane plane;
		plane.identification_ = name;

		waiting_planes.add_a_plane(plane);
	}

// No required here	if (airport_thread.joinable())
	{
		airport_thread.join();
	}

// No required here	if (add_plane.joinable())
	{
		add_plane.join();
	}

	cout << airport;

	std::cout << "Finish\n";

	return 0;
}
