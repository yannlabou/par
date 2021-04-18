#include "bayesian_filter.h"
#include "sensor_data_handler.h"

using namespace std;


namespace {
  vector<double> getBelief(const vector<double>& confidences) {
    vector<double> belief;
    // initial belief
    belief.push_back(1.0);
    // define motion uncertainty
    constexpr double motion_uncertainty = 0.99;
    // keep track of the index
    unsigned long int current_index = 0;
    // iterate reverse through confidence vector
     for (auto confidence_it = confidences.rbegin(); confidence_it != confidences.rend(); ++confidence_it) {
      current_index++;
      auto last_index = current_index - 1;
      // prediction step
      // we expect the prediction step to be only relying on the uncertainty of the
      // motion control
      auto predicted_belief =  motion_uncertainty * belief[last_index];
      // update step
      double current_belief = *confidence_it * predicted_belief;
      belief.push_back(current_belief);
    }
    return belief;
  }
} // unnamed namespace

void BayesianFilter::generateBelief(const SensorData& sensor_data) {
  
  belief.sensor_1_x_belief = getBelief(sensor_data.sensor_1_x_confidence);
  belief.sensor_1_y_belief = getBelief(sensor_data.sensor_1_y_confidence);
}