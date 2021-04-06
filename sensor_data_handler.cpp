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

int SensorDataHandler::writeSensorData(std::string_view filename,
                                        std::string_view column_name_1, std::vector<double> values_1,
                                        std::string_view column_name_2, std::vector<double> values_2) {
    // get filename
    std::ofstream csv_file(filename.data());
    // write header
    csv_file << column_name_1 << ";" << column_name_2 << "\n";
    // error handling
    if (values_1.size() != values_2.size()) {return 1;}
    // write values
    for (unsigned long int index = 0; index < values_1.size(); ++index) {
      csv_file << values_1[index] << ";" << values_2[index] << "\n";
    }
    return 0;
    csv_file.close();
}