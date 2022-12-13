#ifndef ROBOT_FACTORY_H_
#define ROBOT_FACTORY_H_

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Robot.h"

#include <vector>
/**
* @brief This class is responsible for creating robot entity
**/
class RobotFactory : public IEntityFactory {
  public:
    /**
     * @brief It creates Entity
     * @param entity Json object that contain robot model and infomation
     */
    IEntity* CreateEntity(JsonObject& entity);
};

#endif