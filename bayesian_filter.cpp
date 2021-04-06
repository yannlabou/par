#include "bayesian_filter.h"
#include "sensor_data_handler.h"

using namespace std;


namespace {
  vector<double> getBelief(const vector<double>& confidences) {
    vector<double> belief;
    // initial belief
    belief.push_back(1.0);
    // define motion uncertainty
    constexpr double motion_uncertainty = 0.95;
    uint current_index = 0;
    // iterate through confidence vector
    for (const auto& confidence_it : confidences) {
      // prediction step
      auto predicted_belief =  motion_uncertainty * belief.at(current_index - 1);
      // update step
      auto current_belief = confidence_it * predicted_belief;
      belief.push_back(current_belief);
    }
    return belief;
  }
} // unnamed namespace

void BayesianFilter::generateBelief(const SensorData& sensor_data) {
  
  belief.sensor_1_x_belief = getBelief(sensor_data.sensor_1_x_confidence);
  belief.sensor_1_y_belief = getBelief(sensor_data.sensor_1_y_confidence);
}