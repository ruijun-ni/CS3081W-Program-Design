#include "StationFactory.h"

IEntity* StationFactory::CreateEntity(JsonObject& entity){
  std::string type = entity["type"];
  if(type.compare("Station") == 0){
    std::cout << "Station Created" << std::endl;
    return new Station(entity);
  }
  return nullptr;
}