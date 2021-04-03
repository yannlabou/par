#include <iostream>
#include "run_filter.h"
#include <type_traits>
#include "sensor_data_handler.h"
#include <string>

using namespace std;

int main() {
    SensorDataHandler data_handler;
    data_handler.readSensorData(SENSOR_DATA);

    // do cross check 
    cout << data_handler.sensor_data.ground_truth_x_values.size() << endl;
    cout << data_handler.sensor_data.ground_truth_y_values.size() << endl;
    cout << data_handler.sensor_data.sensor_1_x_values.size() << endl;
    cout << data_handler.sensor_data.sensor_1_y_values.size() << endl;

    // TODO run filter on input data

    return 0;
}