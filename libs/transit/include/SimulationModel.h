#ifndef SIMULATION_MODEL_H_
#define SIMULATION_MODEL_H_

#include "CompositeFactory.h"
#include "IController.h"
#include "IEntity.h"
#include "Singleton.h"
#include "graph.h"
using namespace routing;

//--------------------  Model ----------------------------

/// Simulation Model handling the transit simulation.  The model can communicate
/// with the controller.
class SimulationModel {
 public:
  SimulationModel(IController& controller);
  // ~SimulationModel() {
  //   Singleton* s = Singleton::GetInstance();
  //   s->write2CSV();
  // };

  void SetGraph(const IGraph* graph) { this->graph = graph; }

  /// Creates an simulation entity
  void CreateEntity(JsonObject& entity);

  /// Schedules a trip for an object in the scene
  void ScheduleTrip(JsonObject& details);

  /// Updates the simulation
  void Update(double dt);

  // Adds a new entity type
  void AddFactory(IEntityFactory* factory);

  // Shows the battery level of Drone
  float ShowBattery();

  // Shows times and distances
  std::vector<double> ShowOthers();

  // download csv
  void DownloadCSV() {
    Singleton* s = Singleton::GetInstance();
    s->write2CSV();
  }

 protected:
  IController& controller;
  std::vector<IEntity*> entities;
  std::vector<IEntity*> scheduler;
  const IGraph* graph;
  CompositeFactory* compFactory;
};

#endif
