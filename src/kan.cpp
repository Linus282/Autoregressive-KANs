#include "kan.hpp"
#include <cmath>

KAN::KAN(int input_dim, int hidden_units, const std::vector<double>& knots, BasisType basis)
    : input_dim_(input_dim), hidden_units_(hidden_units), basis_(basis) {
    
    weights_.resize(hidden_units_, std::vector<double>(input_dim_, 0.0));
    coeffs_.resize(hidden_units_, std::vector<double>(knots.size(), 0.0));
    
    for (int i = 0; i < hidden_units_; ++i) {
        splines_.emplace_back(knots);
    }
}

void KAN::setWeights(int neuron, const std::vector<double>& weights, const std::vector<double>& coeffs) {
    weights_[neuron] = weights;
    coeffs_[neuron] = coeffs;

    if (basis_ == BasisType::LinearSpline) {
        splines_[neuron].setCoefficients(coeffs);
    }
}

double KAN::forward(const std::vector<double>& x) {
    double output = 0.0;

    for (int i = 0; i < hidden_units_; ++i) {
        double z = 0.0;
        for (int j = 0; j < input_dim_; ++j) {
            z += weights_[i][j] * x[j];
        }

        double activation = 0.0;
        switch (basis_) {
            case BasisType::LinearSpline:
                activation = splines_[i].evaluate(z);
                break;
            case BasisType::Sin:
                activation = std::sin(z);
                break;
            case BasisType::Tanh:
                activation = std::tanh(z);
                break;
        }

        output += activation;
    }

    return output;
}
