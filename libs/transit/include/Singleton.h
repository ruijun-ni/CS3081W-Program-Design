#ifndef SINGLETON_H_
#define SINGLETON_H_

#include <iostream>
#include <unordered_map>
using namespace std;

class Singleton {
 private:
  unordered_map<string, double> data;
  static Singleton* instance;

 public:
  Singleton();
  ~Singleton();
  void AddPassenger();
  void AddDistance(double d);
  void AddTime(double t);
  static Singleton* GetInstance();
};

#endif  // SINGLETON_H_