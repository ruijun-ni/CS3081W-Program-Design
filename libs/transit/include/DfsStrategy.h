#ifndef DFS_STRATEGY_H_
#define DFS_STRATEGY_H_

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
class DfsStrategy : public IStrategy {
public:
    DfsStrategy(Vector3 position, Vector3 destination, const IGraph* graph);
    ~DfsStrategy();
    void Move(IEntity* entity, double dt);
    bool IsCompleted();

private:
    std::vector<std::vector<float>> path;
    int currentIndex;
    int maxIndex;
}; //end class
#endif // DFS_STRATEGY_H_