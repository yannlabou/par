# Probabilistic Algorithms for Robotics (par)

## Implement probablistic filters (for tracking)

1. Simple Bayesian Filter
2. Gaussian Filters: Kalman / EKF / UKF
3. Nonparametric Filters: Histogram / Particle Filter

Add helpers for data processing (input / output)

Input: noisy x-z-theta positions from different modalities (sensor types).
Output: estimated position using at least one filter mentioned above.

## Perfomance comparison

Output of each filter will be compared with standart metrics (i.e. RMSE). More detailed analysis including plots in Python (Jupyter Notebook).


## Data

Noisy observations of positions from different modalities (sensors).
TODO: either find some data or generate x-y-theta trajectories with additional noise.
