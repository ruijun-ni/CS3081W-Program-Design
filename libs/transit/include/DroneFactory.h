#ifndef DRONE_FACTORY_H_
#define DRONE_FACTORY_H_

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Drone.h"

#include <vector>

class DroneFactory : public IEntityFactory {
  public:
    virtual ~DroneFactory() {}
    IEntity* CreateEntity(JsonObject& entity);
};

#endif