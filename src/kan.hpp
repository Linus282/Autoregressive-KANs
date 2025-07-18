#pragma once

#include "spline.hpp"
#include <vector>

enum class BasisType { LinearSpline, Sin, Tanh };

class KAN {
public:
    KAN(int input_dim, int hidden_units,
        const std::vector<double>& knots,
        BasisType basis = BasisType::LinearSpline);

    double forward(const std::vector<double>& x);
    void setWeights(int neuron, const std::vector<double>& w, const std::vector<double>& coeffs);

    int numNeurons() const;
    std::vector<double> getNeuronWeights(int i) const;
    std::vector<double> getNeuronCoeffs(int i) const;

private:
    int input_dim_;
    int hidden_units_;
    std::vector<std::vector<double>> weights_;  // [hidden_units][input_dim]
    std::vector<Spline> splines_;
    BasisType basis_;
};



    


