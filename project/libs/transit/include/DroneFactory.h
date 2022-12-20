#ifndef DRONE_FACTORY_H_
#define DRONE_FACTORY_H_

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Drone.h"

#include <vector>
/**
* @brief The class inherite from IEntityFactory. It is responsible for create drone
*/
class DroneFactory : public IEntityFactory {
  public:
    /**
     * @brief Destructor
     */
    virtual ~DroneFactory() {}
    /**
     * @brief Create drone
     * @param entity The model and infomation of drone0 
     */
    IEntity* CreateEntity(JsonObject& entity);
};

#endif