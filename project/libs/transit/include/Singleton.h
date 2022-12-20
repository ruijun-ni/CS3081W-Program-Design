#ifndef SINGLETON_H_
#define SINGLETON_H_

#include <fstream>
#include <iostream>
#include <unordered_map>
using namespace std;

/**
 * @brief Use for Singleton pattern aiming to collect drone's traveling data
 */
class Singleton {
 private:
  unordered_map<string, double> data;  //!< the collected data
  static Singleton* instance;          //!< the instance of Singleton

  /**
   * @brief constructor
   */
  Singleton();

 public:
  /**
   * @brief destructor
   */
  ~Singleton();

  /**
   * @brief Collect number of scheduled passengers.
   */
  void AddPassenger();

  /**
   * @brief Collect trip distance of drone.
   * @param d Distance to be added
   */
  void AddTripDistance(double d);

  /**
   * @brief Collect total distance of drone.
   * @param d Distance to be added
   */
  void AddTotalDistance(double d);

  /**
   * @brief Collect total time of drone.
   * @param t Time to be added
   */
  void AddTotalTime(double t);

  /**
   * @brief Collect trip time of drone.
   * @param t Time to be added
   */
  void AddTripTime(double t);

  /**
   * @brief Write CSV file based on collected data.
   */
  void write2CSV();

  /**
   * @brief Get the same instance of Singleton
   * @return the Singleton instance
   */
  static Singleton* GetInstance();

  /**
   * @brief Clear the collected distance.
   */
  void ClearDistance();

  /**
   * @brief Clear the collected time.
   */
  void ClearTime();

  /**
   * @brief Get the total distance.
   * @return the collected total distance.
   */
  double GetTotalDistance();

  /**
   * @brief Get the trip distance.
   * @return the collected trip distance.
   */
  double GetTripDistance();

  /**
   * @brief Get the total time.
   * @return the total time
   */
  double GetTotalTime();

  /**
   * @brief Get the trip time.
   * @return the collected trip time
   */
  double GetTripTime();
};

#endif  // SINGLETON_H_