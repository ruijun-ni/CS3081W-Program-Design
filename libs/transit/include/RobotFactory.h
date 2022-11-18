#ifndef ROBOT_FACTORY_H_
#define ROBOT_FACTORY_H_

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Robot.h"

#include <vector>

class RobotFactory : public IEntityFactory {
  public:
    IEntity* CreateEntity(JsonObject& entity);
};

#endif