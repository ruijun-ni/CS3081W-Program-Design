#ifndef SIMULATION_MODEL_H_
#define SIMULATION_MODEL_H_

#include "IController.h"
#include "Drone.h"
#include "IEntity.h"
#include "graph.h"
#include "Robot.h"
using namespace routing;

/// @brief Simulation Model handling the transit simulation. The model can communicate with the controller.
//--------------------  Model ----------------------------

/// Simulation Model handling the transit simulation.  The model can communicate
/// with the controller.
class SimulationModel {
 public:
 /**
   * @brief constructor
   * @param controller SimulationModel are created with the controller
   */
  SimulationModel(IController& controller);

  /**
   * @brief Set graph of SimulationModel.
   * @param graph new graph
   */
  void SetGraph(const IGraph* graph) { this->graph = graph; }

  /**
   * @brief Creates an simulation entity.
   * @param entity new entity
   */
  void CreateEntity(JsonObject& entity);

  /**
   * @brief Schedules a trip for an object in the scene.
   * @param details the JsonObject object of details to be scheduled
   */
  void ScheduleTrip(JsonObject& details);

  /**
   * @brief Updates the simulation model with the delta time.
   * @param dt the delta time
   */
  void Update(double dt);

 protected:
  IController& controller;  //!< the controller the model used
  std::vector<IEntity*> entities;  //!< entities in the model
  std::vector<IEntity*> scheduler;  //!< scheduler in the model
  const IGraph* graph;  //!< graph in the model
};

#endif
