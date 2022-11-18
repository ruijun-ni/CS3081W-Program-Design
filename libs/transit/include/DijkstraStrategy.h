#ifndef Dijkstra_STRATEGY_H_
#define Dijkstra_STRATEGY_H_

/**
 * include
 */
#include "math/vector3.h"
#include <vector>
#include "IStrategy.h"
#include "IEntity.h"
/**
 * @brief this class inhertis from the IStrategy class and is responsible for generating the beeline that the drone will take.
 */
class DijkstraStrategy : public IStrategy {
public:
    DijkstraStrategy(Vector3 position, Vector3 destination, const IGraph* graph);
    ~DijkstraStrategy();
    void Move(IEntity* entity, double dt);
    bool IsCompleted();

private:
    std::vector<std::vector<float>> path;
    int currentIndex;
    int maxIndex;
}; //end class
#endif // Dijkstra_STRATEGY_H_