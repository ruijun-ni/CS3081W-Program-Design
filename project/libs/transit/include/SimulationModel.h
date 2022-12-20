#ifndef SIMULATION_MODEL_H_
#define SIMULATION_MODEL_H_

#include "CompositeFactory.h"
#include "IController.h"
#include "IEntity.h"
#include "Singleton.h"
#include "graph.h"
using namespace routing;

//--------------------  Model ----------------------------
/**
 * @brief Simulation Model handling the transit simulation. The model can communicate
 * with the controller.
 */
class SimulationModel {
 public:
  /**
   * @brief Constructor
   * @param controller SimulationModel are created with the controller
   */
  SimulationModel(IController& controller);

  /**
   * @brief Set graph of SimulationModel.
   * @param graph The graph going to be set
   */
  void SetGraph(const IGraph* graph) { this->graph = graph; }

  /**
   * @brief Creates an simulation entity.
   * @param entity The entity going to be set
   */
  void CreateEntity(JsonObject& entity);

  /**
   * @brief Schedules a trip for an object in the scene.
   * @param details The JsonObject object of details to be scheduled
   */
  void ScheduleTrip(JsonObject& details);

  /**
   * @brief Updates the simulation model with the delta time.
   * @param dt The delta time
   */
  void Update(double dt);

  /**
   * @brief Add factory of IEntity.
   * @param dt The delta time
   * @param scheduler The scheduler of drone
   */
  void AddFactory(IEntityFactory* factory);

  /**
   * @brief Shows the battery level of Drone
   */
  float ShowBattery();

  /**
   * @brief Shows times and distances
   */
  std::vector<double> ShowOthers();

  /**
   * @brief Download csv
   */
  void DownloadCSV() {
    Singleton* s = Singleton::GetInstance();
    s->write2CSV();
  }

 protected:
  IController& controller;          //!< The controller the model used
  std::vector<IEntity*> entities;   //!< Entities in the model
  std::vector<IEntity*> scheduler;  //!< Scheduler in the model
  const IGraph* graph;              //!< Graph in the model
  CompositeFactory* compFactory;    //!< The compositeFactory
};

#endif
