#ifndef CELEBRATION_DECORATOR_H_
#define CELEBRATION_DECORATOR_H_

#include <vector>

#include "IStrategy.h"
/**
* @brief The class inherite from IStrategy. It is responsible for celebration behavior
*/
class CelebrationDecorator : public IStrategy {
 public:
  /**
   * @brief Constructor
   * @param strategy The moving strategy
   */
  CelebrationDecorator(IStrategy *strategy_) {
    strategy = strategy_;
    time = 0;
  }

  /**
   * @brief Move the entity
   * @param entity Entity that need to move
   * @param dt Delta time
   */
  void Move(IEntity *entity, double dt);

  /**
   * @brief Check if the strategy is complete
   * @return True if compelte, false otherwise
   */
  bool IsCompleted();
  
  /**
   * @brief Get the strategy
   * @return The strategy of CelebrationDecorator
   */
  IStrategy *getStrategy() { return strategy; }

 protected:
  IStrategy *strategy; //!< Strategy that moves drone and robot
  float time; //<! The time that perform celebration behavior
};  // close class

#endif  // CELEBRATION_DECORATOR_H_