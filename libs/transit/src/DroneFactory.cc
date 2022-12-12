#include "DroneFactory.h"
#include "BatteryDecorator.h"

IEntity* DroneFactory::CreateEntity(JsonObject& entity){
  std::string type = entity["type"];
  if(type.compare("drone") == 0){
    std::cout << "Drone Created" << std::endl;
    Drone* DroneA = new Drone(entity);
    BatteryDecorator* battery = new BatteryDecorator(DroneA);
    return battery;
  }
  return nullptr;
}