#pragma once

#include <vector>

class Spline {
public:
    Spline(const std::vector<double>& knots);

    double evaluate(double x) const;
    void setCoefficients(const std::vector<double>& coeffs);

private:
    std::vector<double> knots_;
    std::vector<double> coeffs_;
};
