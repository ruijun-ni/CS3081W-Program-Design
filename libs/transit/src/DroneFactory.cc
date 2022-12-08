#include "DroneFactory.h"
#include "BatteryDecorator.h"

IEntity* DroneFactory::CreateEntity(JsonObject& entity){
  std::string type = entity["type"];
  if(type.compare("drone") == 0){
    std::cout << "Drone Created" << std::endl;

    IEntity* drone = new Drone(entity);
    IEntity* battery = new BatteryDecorator(drone);
    return battery;
  }
  return nullptr;
}