#include <sstream>
#include <vector>
#include <string>

using namespace std;

class SensorDataReader {
    private:
        // sensor data incl. ground truth
        vector<double> ground_truth_x_values, sensor_1_x_values, ground_truth_y_values, sensor_1_y_values;

    public:
        void readSensorData(string file_path);
        vector<double> getGroundTruthX();
        vector<double> getGroundTruthY();
        vector<double> getSensor1X();
        vector<double> getSensor1Y();
};