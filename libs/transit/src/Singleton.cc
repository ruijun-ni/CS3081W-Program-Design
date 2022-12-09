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

// static method
Singleton *Singleton::GetInstance(){
  if (instance == nullptr) {
    instance = new Singleton();
  }
  return instance;
}