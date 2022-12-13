#ifndef BEELINE_H_
#define BEELINE_H_


#include "math/vector3.h"
#include <vector>
#include "IStrategy.h"
#include "IEntity.h"
#include "Singleton.h"
/**
 * @brief this class inhertis from the IStrategy class and is responsible for generating the beeline that the drone will take.
 */
class BeelineStrategy : public IStrategy {
public:
    /**
     * @brief Constructor
     * @param position The position of the robot
     * @param destination The destination of robot want to go
     */
    BeelineStrategy(Vector3 position, Vector3 destination);

    /**
     * @brief Destructor
     */  
    ~BeelineStrategy();

    /**
     * @brief Entity's move function
     * @param entity The entity want to move
     * @param dt The delta time
     */
    void Move(IEntity* entity, double dt);

    /**
     * @brief If the strategy is completed
     */  
    bool IsCompleted();

private:
    Vector3 position; //!< the position of the robot
    Vector3 destination; //!< the destination of the robot
}; //end class
#endif // BEELINE_H_