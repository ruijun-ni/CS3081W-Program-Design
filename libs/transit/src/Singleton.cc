#include "Singleton.h"

Singleton* Singleton::instance = nullptr;
;

Singleton::Singleton() {
  std::ofstream myfile;
  myfile.open("data.csv", std::ios_base::trunc);
  myfile << "Drone No., Passengers Delivered, Distance Traveled, Distance "
            "Traveled (trips only), Total Time, Time Elapsed (trips only)\n";
  data["passenger_delivered"] = 0.0;
  data["distance_traveled"] = 0.0;
  data["trip_distance"] = 0.0;
  data["time_elapsed"] = 0.0;
  data["trip_time"] = 0.0;
}

void Singleton::AddPassenger() {
  data["passenger_delivered"] += 1;
  cout << "Add one passenger!" << endl;
  cout << "passenger_delivered: " << data["passenger_delivered"] << endl;
}

void Singleton::AddTripDistance(double d) { data["trip_distance"] += d; }

void Singleton::AddTotalDistance(double d) { data["distance_traveled"] += d; }

void Singleton::AddTotalTime(double t) { data["time_elapsed"] += t; }

void Singleton::AddTripTime(double t) { data["trip_time"] += t; }

void Singleton::write2CSV() {
  cout << "Writing to CSV..." << endl;
  std::ofstream myfile;
  myfile.open("data.csv", std::ios_base::app);
  myfile << "drone1, ";
  myfile << to_string(data["passenger_delivered"]) + ", ";
  myfile << to_string(data["distance_traveled"]) + ", ";
  myfile << to_string(data["trip_distance"]) + ", ";
  myfile << to_string(data["time_elapsed"]) + ", ";
  myfile << to_string(data["trip_time"]) + "\n";
  myfile.close();
}

void Singleton::ClearDistance() {
  data["distance_traveled"] = 0.0;
  data["trip_distance"] = 0.0;
}

void Singleton::ClearTime() {
  data["time_elapsed"] = 0.0;
  data["trip_time"] = 0.0;
}

double Singleton::GetTotalDistance() {
  return data["distance_traveled"];
}

double Singleton::GetTripDistance() {
  return data["trip_distance"];
}

double Singleton::GetTotalTime() {
  return data["time_elapsed"];
}

double Singleton::GetTripTime() {
  return data["trip_time"];
}

// static method
Singleton* Singleton::GetInstance() {
  if (instance == nullptr) {
    instance = new Singleton();
  }
  return instance;
}