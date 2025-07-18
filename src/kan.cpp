#include "kan.hpp"

KAN::KAN(int input_dim, int hidden_units, const std::vector<double>& knots)
    : input_dim_(input_dim), hidden_units_(hidden_units) {
    for (int i = 0; i < hidden_units_; ++i)
        splines_.emplace_back(knots);
    linear_weights_ = std::vector<std::vector<double>>(hidden_units_, std::vector<double>(input_dim_, 1.0));
}

void KAN::setWeights(int neuron, const std::vector<double>& w, const std::vector<double>& coeffs) {
    linear_weights_[neuron] = coeffs;
    splines_[neuron].setWeights(w);
}

double KAN::forward(const std::vector<double>& x) {
    double activation = splines_[i].evaluate(z);
    if (basis_ == BasisType::Sin) activation = std::sin(z);
    else if (basis_ == BasisType::Tanh) activation = std::tanh(z);
        out += activation;

    for (int i = 0; i < hidden_units_; ++i) {
        double z = 0.0;
        for (int j = 0; j < input_dim_; ++j)
            z += linear_weights_[i][j] * x[j];
        out += splines_[i].evaluate(z);
    }
    return out;
}
