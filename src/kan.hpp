#pragma once

#include "spline.hpp"
#include <vector>

enum class BasisType { LinearSpline, Sin, Tanh };

class KAN {
public:
    KAN(int input_dim, int hidden_units, const std::vector<double>& knots, BasisType basis = BasisType::LinearSpline);

    double forward(const std::vector<double>& x);
    void setWeights(int neuron, const std::vector<double>& weights, const std::vector<double>& coeffs);

private:
    int input_dim_;
    int hidden_units_;
    BasisType basis_;

    std::vector<std::vector<double>> weights_;  // [hidden][input]
    std::vector<std::vector<double>> coeffs_;   // [hidden][basis_coeffs]
    std::vector<Spline> splines_;               // eine Spline pro Neuron
};



    


