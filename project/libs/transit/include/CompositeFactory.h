#ifndef COMPOSITE_FACTORY_H_
#define COMPOSITE_FACTORY_H_

#include "IEntityFactory.h"
/**
* @brief The class inherite from IEntityFactory. It is responsible for store factories for entities.
**/
class CompositeFactory : public IEntityFactory {
 public:
  /**
   * @brief Constructor
   * @param entity Json object that contain entity model and infomation
   */
  IEntity* CreateEntity(JsonObject& entity);
  /**
   * @brief Add factory of different entities
   * @param factoryEntity Factory of a entity
   */
  void AddFactory(IEntityFactory* factoryEntity);

  /**
   * @brief Destructor
   */
  virtual ~CompositeFactory();

 private:
  std::vector<IEntityFactory*> componentFactories; //<! The factory of component
};

#endif