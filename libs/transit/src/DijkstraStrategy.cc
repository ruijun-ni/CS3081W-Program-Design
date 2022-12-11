#include "DijkstraStrategy.h"
#include "routing/dijkstra.h"
#include "routing_api.h"
#include "graph.h"
using namespace routing;

DijkstraStrategy::DijkstraStrategy(Vector3 position, Vector3 destination, const IGraph* graph) {
    this->graph = graph;

    std::vector<float> positionV;
    positionV.push_back(position.x);
    positionV.push_back(position.y);
    positionV.push_back(position.z);
    
    std::vector<float> destinationV;
    destinationV.push_back(destination.x);
    destinationV.push_back(destination.y);
    destinationV.push_back(destination.z);

    std::vector<float> start = graph->NearestNode(positionV, EuclideanDistance())->GetPosition();
    std::vector<float> end = graph->NearestNode(destinationV, EuclideanDistance())->GetPosition();
    
    path = graph->GetPath(start, end, Dijkstra::Default());

    distance = 0;
    for (int i = 1; i < path.size(); i++) {
        float prev_x = path[i - 1][0];
        float prev_z = path[i - 1][1];
        float prev_y = path[i - 1][2];
        
        float curr_x = path[i][0];
        float curr_z = path[i][1];
        float curr_y = path[i][2];

        this->distance += sqrt(pow(prev_x - curr_x, 2) + pow(prev_y - curr_y, 2) +
                pow(prev_z - curr_z, 2));
    }
    std::cout << "The total distance for Dijkstra route is " << distance << std::endl;
    currentIndex = 0;
    maxIndex = path.size()-1;
}

bool DijkstraStrategy::IsCompleted(){
    return currentIndex == maxIndex;
}

void DijkstraStrategy::Move(IEntity* entity, double dt){
    Vector3 currentPos = entity->GetPosition();
    Vector3 destination = Vector3(path[currentIndex].at(0), path[currentIndex].at(1), path[currentIndex].at(2));
    Vector3 direction = (destination - currentPos).Unit();
    float speed = entity->GetSpeed(); 
    currentPos = currentPos + direction * speed * dt;
    entity->SetPosition(currentPos);
    entity->SetDirection(direction);
<<<<<<< HEAD

    // if (currPath = 0) {
    //     currPath = destination.Distance(currentPos);
    // }
    // else {
    //     currPath = currPath - destination.Distance(currentPos);
    // }
=======
    // update the battery status
    float update_battery = entity->GetBattery() - destination.Distance(currentPos) * 0.0125;
>>>>>>> 0aa63a0bd86ba4bea7c6f76d4fed7ca0e1a3e02f

    if((destination - currentPos).Magnitude()<1.0){
        currentIndex++;
    }
}