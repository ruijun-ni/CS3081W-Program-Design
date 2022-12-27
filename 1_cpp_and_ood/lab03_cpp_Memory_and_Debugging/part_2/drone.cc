#define _USE_MATH_DEFINES
#include "drone.h"

#include <cmath>

Drone::Drone(const std::string& name) : name(name) {
  // Drones have 3 components x,y,z
  position = std::vector<double>(3);
  velocity = std::vector<double>(3);
}

Drone::~Drone() {
  // Delete dynamically allocated variables
  // delete velocity;
}

void Drone::SetVelocity(std::vector<double> velocity) {
  // Copy the velocity data into the member variable array.
  for(int i = 0; i < velocity.size(); i++){
    this->velocity[i] = velocity[i];
  }
}

void Drone::Update(double dt) {
  // Updates the drone position based on velocity and change in time
  for (int i = 0; i < 3; i++) {
    position[i] = position[i] + velocity[i] * dt;
  }
}

void Drone::Rotate(double angle) {
  // Rotates the drone by changing the velocity by a
  // specified angle.
  double x = velocity[0];
  double y = velocity[1];
  velocity[0] = x * std::cos(angle) - y * std::sin(angle);
  velocity[1] = x * std::sin(angle) + y * std::cos(angle);
}