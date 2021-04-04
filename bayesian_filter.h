#include "sensor_data_handler.h"
#include <vector>


struct BeliefPoints
{
  std::vector<double> sensor_1_x_belief;
  std::vector<double> sensor_1_y_belief;
};

class BayesianFilter
{
public:
  // sensor data incl. ground truth
  BeliefPoints belief_points;

  // filter
  void generateBeliefPoints(const SensorData& sensor_data);
};