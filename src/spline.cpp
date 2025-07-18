#include "spline.hpp"
#include <stdexcept>

Spline::Spline(const std::vector<double>& knots)
    : knots_(knots), coeffs_(knots.size(), 0.0) {}

void Spline::setCoefficients(const std::vector<double>& coeffs) {
    if (coeffs.size() != knots_.size()) {
        throw std::invalid_argument("Number of coefficients must match number of knots.");
    }
    coeffs_ = coeffs;
}

double Spline::evaluate(double x) const {
    if (knots_.size() < 2) {
        throw std::runtime_error("Not enough knots.");
    }

    // lineare Interpolation zwischen zwei benachbarten Stützpunkten
    for (size_t i = 0; i < knots_.size() - 1; ++i) {
        double x0 = knots_[i];
        double x1 = knots_[i + 1];
        if (x >= x0 && x <= x1) {
            double t = (x - x0) / (x1 - x0);
            return (1 - t) * coeffs_[i] + t * coeffs_[i + 1];
        }
    }

    // falls x außerhalb der Stützstellen liegt → konstant extrapolieren
    if (x < knots_.front()) return coeffs_.front();
    return coeffs_.back();
}
