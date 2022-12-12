#ifndef STATION_H
#define STATION_H

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"
#include "util/json.h"

class Station : public IEntity {
 public:
  Station(JsonObject& obj);

  ~Station() override = default;

  JsonObject GetDetails() const override;

  Vector3 GetPosition() const { return position; }

  Vector3 GetDirection() const { return direction; }

  Vector3 GetDestination() const { return destination; }

  float GetSpeed() const { return speed; }

  void SetPosition(Vector3 pos_) { position = pos_; }

  void SetDirection(Vector3 dir_) { direction = dir_; }

  void SetDestination(Vector3 des_) { destination = des_; }

  // void Rotate(double angle);

  // void Update(double dt, std::vector<IEntity*> scheduler);

  float Random(float Min, float Max);

  void SetNewDestination();

 private:
  JsonObject details;
  Vector3 position;

  Vector3 direction;
  Vector3 destination;
  IStrategy* strategy = NULL;
  float speed;
};

#endif  // STATION_H