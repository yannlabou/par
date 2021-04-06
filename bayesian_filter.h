#ifndef BAYESIAN_FILTER_H_
#define BAYESIAN_FILTER_H_

#include "sensor_data_handler.h"
#include <vector>


struct Belief
{
  std::vector<double> sensor_1_x_belief;
  std::vector<double> sensor_1_y_belief;
};

class BayesianFilter
{
public:
  // sensor data incl. ground truth
  Belief belief;

  // filter
  void generateBelief(const SensorData& sensor_data);
};

#endif // BAYESIAN_FILTER_H_