#include "Singleton.h"

Singleton* Singleton::instance = nullptr;
;

Singleton::Singleton() {
  std::ofstream myfile;
  myfile.open("data.csv", std::ios_base::trunc);
  myfile << "Drone No., Passengers Delivered, Distance Traveled, Distance "
            "Traveled (trips only), Time Elapsed\n";
  data["passenger_delivered"] = 0.0;
  data["distance_traveled"] = 0.0;
  data["trip_distance"] = 0.0;
  data["time_elapsed"] = 0.0;
}

void Singleton::AddPassenger() {
  data["passenger_delivered"] += 1;
  cout << "Add one passenger!" << endl;
  cout << "passenger_delivered: " << data["passenger_delivered"] << endl;
}

void Singleton::AddTripDistance(double d) { data["trip_distance"] += d; }

void Singleton::AddTotalDistance(double d) { data["distance_traveled"] += d; }

void Singleton::AddTime(double t) { data["time_elapsed"] += t; }

void Singleton::write2CSV() {
  cout << "Writing to CSV..." << endl;
  std::ofstream myfile;
  myfile.open("data.csv", std::ios_base::app);
  myfile << "drone1, ";
  myfile << to_string(data["passenger_delivered"]) + ", ";
  myfile << to_string(data["distance_traveled"]) + ", ";
  myfile << to_string(data["trip_distance"]) + ", ";
  myfile << to_string(data["time_elapsed"]) + "\n";
  myfile.close();
}

void Singleton::ClearDistance() {
  data["distance_traveled"] = 0.0;
  data["trip_distance"] = 0.0;
}

void Singleton::ClearTime() { data["time_elapsed"] = 0.0; }

// static method
Singleton* Singleton::GetInstance() {
  if (instance == nullptr) {
    instance = new Singleton();
  }
  return instance;
}