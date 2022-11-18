#ifndef COMPOSITE_FACTORY_H_
#define COMPOSITE_FACTORY_H_

#include "IEntityFactory.h"

class CompositeFactory : public IEntityFactory {
  public:

    IEntity* CreateEntity(JsonObject& entity);

    void AddFactory(IEntityFactory* factoryEntity);
    
    virtual ~CompositeFactory();

  private:
    std::vector<IEntityFactory*> componentFactories;
};

#endif