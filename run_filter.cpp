#include "bayesian_filter.h"
#include "sensor_data_handler.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv) {
    if (argc != 3) {
        cerr << "usage: run_filter <input_file_path> <output_file_path>\n";
        return EXIT_FAILURE;
    }
    string input_file_path{argv[1]};
    string output_file_path{argv[2]};

    SensorDataHandler data_handler;
    data_handler.readSensorData(input_file_path);

    BayesianFilter bayesian_filter;
    bayesian_filter.generateBelief(data_handler.sensor_data);

    auto result = data_handler.writeSensorData(output_file_path,
                                              "x_belief", bayesian_filter.belief.sensor_1_x_belief,
                                              "y_belief", bayesian_filter.belief.sensor_1_y_belief);
    if (result) {
        cerr << "storing output failed\n";
        return EXIT_FAILURE;
    }
    cout << "done. output stored in " << output_file_path << "\n";
    return 0;
}