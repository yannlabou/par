#include <iostream>
#include "run_filter.h"
#include "sensor_data_reader.h"

int main() {
    SensorDataReader reader;
    reader.readSensorData(SENSOR_DATA);

    const auto ground_truth_x_values = reader.getGroundTruthX();
    const auto ground_truth_y_values = reader.getGroundTruthY();
    const auto sensor_1_x_values = reader.getSensor1X();
    const auto sensor_1_y_values = reader.getSensor1Y();

    // do cross check
    cout << ground_truth_x_values.size() << endl;
    cout << ground_truth_y_values.size() << endl;
    cout << sensor_1_x_values.size() << endl;
    cout << sensor_1_x_values.size() << endl;

    // TODO run filter on input data

    return 0;
}