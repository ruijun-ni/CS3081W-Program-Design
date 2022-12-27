#define _USE_MATH_DEFINES
#include "robot.h"

#include <cmath>

Robot::Robot(const std::string& name, float radius)
    : name(name), angle(0.0), radius(radius) {
  pos = std::vector<double>(2);
  pos[0] = radius * std::cos(angle);
  pos[1] = radius * std::sin(angle);
}

void Robot::Update(double dt) {
  angle += dt;
  pos[0] = radius * std::cos(angle);
  pos[1] = radius * std::sin(angle);
}
