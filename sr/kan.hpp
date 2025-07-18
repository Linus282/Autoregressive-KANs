#pragma once
#include "spline.hpp"
#include <vector>
#include <cmath>

enum class BasisType { LinearSpline, Sin, Tanh };

class KAN {
public:
    KAN(int input_dim, int hidden_units,
        const std::vector<double>& knots,
        BasisType basis = BasisType::LinearSpline);

    double forward(const std::vector<double>& x);

    void setWeights(int neuron,
                    const std::vector<double>& spline_weights,
                    const std::vector<double>& coeffs);

    std::vector<double> getNeuronWeights(int neuron) const;
    std::vector<double> getNeuronCoeffs(int neuron) const;

    int numNeurons() const { return hidden_units_; }

private:
    int input_dim_;
    int hidden_units_;
    BasisType basis_;

    std::vector<Spline> splines_;                        // nur bei LinearSpline
    std::vector<std::vector<double>> linear_weights_;    // shape: [neurons][input_dim]
    std::vector<std::vector<double>> spline_weights_;    // für spätere Updates
};



    


