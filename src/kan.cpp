#include "kan.hpp"
#include <cmath>

KAN::KAN(int input_dim, int hidden_units, const std::vector<double>& knots, BasisType basis)
    : input_dim_(input_dim), hidden_units_(hidden_units), basis_(basis) {
    weights_.resize(hidden_units_, std::vector<double>(input_dim_, 0.0));
    splines_.resize(hidden_units_);
    for (int i = 0; i < hidden_units_; ++i) {
        splines_[i].setKnots(knots);
    }
}

double KAN::forward(const std::vector<double>& x) {
    double out = 0.0;
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
                activation = sin(z);
                break;
            case BasisType::Tanh:
                activation = tanh(z);
                break;
        }

        out += activation;
    }
    return out;
}

void KAN::setWeights(int neuron, const std::vector<double>& w, const std::vector<double>& coeffs) {
    if (neuron >= 0 && neuron < hidden_units_) {
        weights_[neuron] = w;
        splines_[neuron].setCoefficients(coeffs);
    }
}

int KAN::numNeurons() const {
    return hidden_units_;
}

std::vector<double> KAN::getNeuronWeights(int i) const {
    return weights_[i];
}

std::vector<double> KAN::getNeuronCoeffs(int i) const {
    return splines_[i].getCoefficients();
}
