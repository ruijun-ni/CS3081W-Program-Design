#ifndef SINGLETON_H_
#define SINGLETON_H_

#include <iostream>
#include <unordered_map>
#include <fstream>
using namespace std;

class Singleton {
 private:
  unordered_map<string, double> data;
  static Singleton* instance;

 public:
  Singleton();
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