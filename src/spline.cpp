#include "spline.hpp"
#include <stdexcept>
#include <algorithm>

Spline::Spline() {}

void Spline::setKnots(const std::vector<double>& knots) {
    if (knots.size() < 2)
        throw std::invalid_argument("Spline needs at least two knots.");
    knots_ = knots;
}

void Spline::setCoefficients(const std::vector<double>& coeffs) {
    if (coeffs.size() != knots_.size() - 1)
        throw std::invalid_argument("Coefficient count must be one less than knot count.");
    coefficients_ = coeffs;
}

double Spline::evaluate(double x) const {
    if (knots_.empty() || coefficients_.empty())
        throw std::runtime_error("Spline is not initialized.");

    if (x <= knots_.front()) return coefficients_.front();
    if (x >= knots_.back()) return coefficients_.back();

    auto it = std::upper_bound(knots_.begin(), knots_.end(), x);
    int idx = std::distance(knots_.begin(), it) - 1;

    double t0 = knots_[idx];
    double t1 = knots_[idx + 1];
    double alpha = (x - t0) / (t1 - t0);

    return (1 - alpha) * coefficients_[idx] + alpha * coefficients_[idx];
}

const std::vector<double>& Spline::getCoefficients() const {
    return coefficients_;
}

