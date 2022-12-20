#ifndef I_ENTITY_FACTORY_H_
#define I_ENTITY_FACTORY_H_

#include "util/json.h"

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Drone.h"
/**
* @brief This class is responsible for creating entity
**/
class IEntityFactory {
  public:
    /**
     * @brief Constructor
     */
    virtual ~IEntityFactory() {}
    /**
     * @brief Virtual function. It creates Entity
     * @param entity Json object that contain entity model and infomation
     */
    virtual IEntity* CreateEntity(JsonObject& entity) = 0;
};

#endif