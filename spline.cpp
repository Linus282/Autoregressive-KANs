#include "spline.hpp"
#include <stdexcept>

Spline::Spline(const std::vector<double>& knots)
    : knots_(knots), weights_(knots.size(), 0.0) {}

void Spline::setWeights(const std::vector<double>& w) {
    if (w.size() != knots_.size()) throw std::invalid_argument("Wrong size");
    weights_ = w;
}

int Spline::findInterval(double x) const {
    for (size_t i = 1; i < knots_.size(); ++i)
        if (x < knots_[i]) return i - 1;
    return knots_.size() - 2;
}

double Spline::evaluate(double x) const {
    int i = findInterval(x);
    double t = (x - knots_[i]) / (knots_[i+1] - knots_[i]);
    return (1 - t) * weights_[i] + t * weights_[i+1]; // Linear interpolation
}
