#include <sstream>
#include <string>
#include <string_view>
#include <vector>


struct SensorData
{
  std::vector<double> ground_truth_x_values{};
  std::vector<double> sensor_1_x_values;
  std::vector<double> ground_truth_y_values;
  std::vector<double> sensor_1_y_values;
};

class SensorDataHandler
{
public:
  // sensor data incl. ground truth
  SensorData sensor_data;

  // reader
  void readSensorData(std::string_view file_path);

  // TODO
  void writeSensorData(SensorData sensor_data);
};