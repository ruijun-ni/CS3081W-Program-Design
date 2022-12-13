#ifndef Dijkstra_STRATEGY_H_
#define Dijkstra_STRATEGY_H_


#include "math/vector3.h"
#include <vector>
#include "IStrategy.h"
#include "IEntity.h"
#include "Singleton.h"
/**
 * @brief this class inhertis from the IStrategy class and is responsible for generating the dijkstra that the drone will take.
 */
class DijkstraStrategy : public IStrategy {
public:
    /**
     * @brief Constructor
     * @param position The position of the robot
     * @param destination The destination of robot want to go
     * @param graph The graph want to set
     */
    DijkstraStrategy(Vector3 position, Vector3 destination, const IGraph* graph);

    /**
     * @brief Destructor
     */  
    ~DijkstraStrategy();

    /**
     * @brief Entity's move function
     * @param entity The entity want to move
]    * @param dt The delta time
     */
    void Move(IEntity* entity, double dt);

    /**
     * @brief If the strategy is completed
     */  
    bool IsCompleted();

private:
    std::vector<std::vector<float>> path; //!< the vector save move path
    int currentIndex; //!< the current number of positions
    int maxIndex; //!< total number of positions
}; //end class
#endif // Dijkstra_STRATEGY_H_