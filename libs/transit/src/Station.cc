#include "Station.h"

Station::Station(JsonObject &obj) : details(obj) {
  JsonArray pos(obj["position"]);
  position = {pos[0], pos[1], pos[2]};
}

JsonObject Station::GetDetails() const { return details; }