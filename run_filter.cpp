#include "bayesian_filter.h"
#include "sensor_data_handler.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "usage: run_filter <file_path>\n";
        return EXIT_FAILURE;
    }
    string file_path{argv[1]};

    SensorDataHandler data_handler;
    data_handler.readSensorData(file_path);

    // do cross check
    cout << data_handler.sensor_data.ground_truth_x_values.size() << endl;
    cout << data_handler.sensor_data.ground_truth_y_values.size() << endl;
    cout << data_handler.sensor_data.sensor_1_x_values.size() << endl;
    cout << data_handler.sensor_data.sensor_1_x_confidence.size() << endl;
    cout << data_handler.sensor_data.sensor_1_y_values.size() << endl;
    cout << data_handler.sensor_data.sensor_1_y_confidence.size() << endl;

    BayesianFilter bayesian_filter;
    bayesian_filter.generateBelief(data_handler.sensor_data);

    data_handler.writeSensorData("hello_sensor_data.csv", "x_belief", bayesian_filter.belief.sensor_1_x_belief);
    

    return 0;
}