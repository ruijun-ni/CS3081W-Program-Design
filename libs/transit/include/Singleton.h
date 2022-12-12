#ifndef SINGLETON_H_
#define SINGLETON_H_

#include <fstream>
#include <iostream>
#include <unordered_map>
using namespace std;

class Singleton {
 private:
  unordered_map<string, double> data;
  static Singleton* instance;
  Singleton();

 public:
  ~Singleton();
  void AddPassenger();
  void AddTripDistance(double d);
  void AddTotalDistance(double d);
  void AddTotalTime(double t);
  void AddTripTime(double t);
  void write2CSV();
  static Singleton* GetInstance();
  void ClearDistance();
  void ClearTime();
  double GetTotalDistance();
  double GetTripDistance();
  double GetTotalTime();
  double GetTripTime();
};

#endif  // SINGLETON_H_