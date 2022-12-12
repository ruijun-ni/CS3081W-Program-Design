
#ifndef STATION_FACTORY_H_
#define STATION_FACTORY_H_

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Station.h"

#include <vector>

class StationFactory : public IEntityFactory {
  public:
    virtual ~StationFactory() {}
    IEntity* CreateEntity(JsonObject& entity);
};

#endif