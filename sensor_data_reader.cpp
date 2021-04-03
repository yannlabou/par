#include <fstream>
#include "sensor_data_reader.h"

void SensorDataReader::readSensorData(string file_path) {
    string ground_truth_x, sensor_1_x, ground_truth_y, sensor_1_y, line;
    
    ifstream input_file_stream(file_path);

    while( getline(input_file_stream, line)){
        istringstream iss(line);

        // get current line values
        getline(iss, ground_truth_x, ',');
        getline(iss, sensor_1_x, ',');
        getline(iss, ground_truth_y, ',');
        getline(iss, sensor_1_y, ',');

        // store values into corresponding vectors
        ground_truth_x_values.push_back(toNumber(ground_truth_x));
        sensor_1_x_values.push_back(toNumber(sensor_1_x));
        ground_truth_y_values.push_back(toNumber(ground_truth_y));
        sensor_1_y_values.push_back(toNumber(sensor_1_y));
    }
}

vector<double> SensorDataReader::getGroundTruthX() {
    return ground_truth_x_values;
}

vector<double> SensorDataReader::getGroundTruthY() {
    return ground_truth_y_values;
}
vector<double> SensorDataReader::getSensor1X() {
    return sensor_1_x_values;
}

vector<double> SensorDataReader::getSensor1Y() {
    return sensor_1_y_values;
}