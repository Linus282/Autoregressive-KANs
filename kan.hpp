#pragma once
#include "spline.hpp"
#include <vector>

class KAN {
public:
    KAN(int input_dim, int hidden_units, const std::vector<double>& knots);

    double forward(const std::vector<double>& x);
    void setWeights(int neuron, const std::vector<double>& w, const std::vector<double>& coeffs);

private:
    int input_dim_;
    int hidden_units_;
    std::vector<Spline> splines_;
    std::vector<std::vector<double>> linear_weights_;
};
