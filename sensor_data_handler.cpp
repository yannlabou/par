#include "sensor_data_handler.h"
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

void SensorDataHandler::readSensorData(std::string_view file_path)
{
  string ground_truth_x;
  string sensor_1_x;
  string sensor_1_x_confidence;
  string ground_truth_y;
  string sensor_1_y;
  string sensor_1_y_confidence;
  string line;

  ifstream input_file_stream(file_path.data());

  while (getline(input_file_stream, line)) {
    istringstream iss(line);

    // get current line values
    getline(iss, ground_truth_x, ',');
    getline(iss, sensor_1_x, ',');
    getline(iss, sensor_1_x_confidence, ',');
    getline(iss, ground_truth_y, ',');
    getline(iss, sensor_1_y, ',');
    getline(iss, sensor_1_y_confidence, ',');

    // store values into corresponding vectors
    sensor_data.ground_truth_x_values.push_back(std::strtod(ground_truth_x.c_str(), 0));
    sensor_data.sensor_1_x_values.push_back(std::strtod(sensor_1_x.c_str(), 0));
    sensor_data.sensor_1_x_confidence.push_back(std::strtod(sensor_1_x_confidence.c_str(), 0));
    sensor_data.ground_truth_y_values.push_back(std::strtod(ground_truth_y.c_str(), 0));
    sensor_data.sensor_1_y_values.push_back(std::strtod(sensor_1_y.c_str(), 0));
    sensor_data.sensor_1_y_confidence.push_back(std::strtod(sensor_1_y_confidence.c_str(), 0));
  }
}