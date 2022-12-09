#include "Singleton.h"

Singleton* Singleton::instance = nullptr;;

Singleton::Singleton() {
  data["passenger_delivered"] = 0.0;
  data["distance_traveled"] = 0.0;
  data["time"] = 0.0; 
}

void Singleton::AddPassenger() {
  data["passenger_delivered"] += 1;
  cout << "Add one passenger!" << endl;
  cout << "passenger_delivered: " << data["passenger_delivered"] << endl;
}

void Singleton::AddDistance(double d) {
  data["distance_traveled"] += d;
  cout << "distance: " << data["distance_traveled"] << endl;
  }

void Singleton::AddTime(double t) { 
  data["time"] += t; 
  cout << "time: " << data["time"] << endl;
}

void Singleton::write2CSV() { 
    cout << "Writing to CSV..." << endl;
    std::ofstream myfile;
    myfile.open ("data.csv");
    myfile << "drone, num of passengers dilevered, traveling distance, traveling time\n";
    myfile << "drone1, ";
    myfile << to_string(data["passenger_delivered"]) + ", ";
    myfile << to_string(data["distance_traveled"]) + ", ";
    myfile << to_string(data["time"]) + "\n";
    myfile.close();
}

// static method
Singleton *Singleton::GetInstance(){
  if (instance == nullptr) {
    instance = new Singleton();
  }
  return instance;
}