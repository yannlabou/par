#ifndef SENSOR_DATA_HANDLER_H_
#define SENSOR_DATA_HANDLER_H_

#include <sstream>
#include <string>
#include <string_view>
#include <vector>


struct SensorData
{
  std::vector<double> ground_truth_x_values{};
  std::vector<double> sensor_1_x_values;
  std::vector<double> sensor_1_x_confidence;
  std::vector<double> ground_truth_y_values;
  std::vector<double> sensor_1_y_values;
  std::vector<double> sensor_1_y_confidence;
};

class SensorDataHandler
{
public:
  // sensor data incl. ground truth
  SensorData sensor_data;

  // reader
  void readSensorData(std::string_view file_path);

  // writer
  bool writeSensorData(std::string_view filename, std::string_view column_name_1, std::vector<double> values_1,
                      std::string_view column_name_2, std::vector<double> values_2);
};

#endif // SENSOR_DATA_HANDLER_H_