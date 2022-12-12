#include "DijkstraStrategy.h"

#include "Singleton.h"
#include "graph.h"
#include "routing/dijkstra.h"
#include "routing_api.h"

using namespace routing;

DijkstraStrategy::DijkstraStrategy(Vector3 position, Vector3 destination,
                                   const IGraph* graph) {
  this->graph = graph;

  std::vector<float> positionV;
  positionV.push_back(position.x);
  positionV.push_back(position.y);
  positionV.push_back(position.z);

  std::vector<float> destinationV;
  destinationV.push_back(destination.x);
  destinationV.push_back(destination.y);
  destinationV.push_back(destination.z);

  std::vector<float> start =
      graph->NearestNode(positionV, EuclideanDistance())->GetPosition();
  std::vector<float> end =
      graph->NearestNode(destinationV, EuclideanDistance())->GetPosition();

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
  std::cout << "The total distance for Dijkstra route is " << distance
            << std::endl;
  currentIndex = 0;
  maxIndex = path.size() - 1;
}

bool DijkstraStrategy::IsCompleted() { return currentIndex == maxIndex; }

void DijkstraStrategy::Move(IEntity* entity, double dt) {
  // collect time per drone
  Singleton* s = Singleton::GetInstance();
  s->AddTotalTime(dt);
  s->AddTripTime(dt);

  Vector3 currentPos = entity->GetPosition();
  Vector3 destination =
      Vector3(path[currentIndex].at(0), path[currentIndex].at(1),
              path[currentIndex].at(2));
  Vector3 direction = (destination - currentPos).Unit();
  float speed = entity->GetSpeed();

  // collect distance per drone
  s->AddTripDistance(speed * dt);
  s->AddTotalDistance(speed * dt);

  currentPos = currentPos + direction * speed * dt;
  entity->SetPosition(currentPos);
  entity->SetDirection(direction);
  if ((destination - currentPos).Magnitude() < 1.0) {
    currentIndex++;
  }
}