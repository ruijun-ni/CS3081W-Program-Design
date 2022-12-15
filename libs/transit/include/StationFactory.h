
#ifndef STATION_FACTORY_H_
#define STATION_FACTORY_H_

#include <vector>

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Station.h"
/**
 * @brief The class inherite from IEntityFactory. It is responsible for create
 *station
 **/
class StationFactory : public IEntityFactory {
 public:
  /**
   * @brief Destructor
   **/
  virtual ~StationFactory() {}
  /**
   * @brief Create station
   * @param entity The model and infomation of station
   */
  IEntity* CreateEntity(JsonObject& entity);
};

#endif