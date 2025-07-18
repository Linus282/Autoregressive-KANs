#pragma once
#include <vector>

class Spline {
public:
    Spline();

    void setKnots(const std::vector<double>& knots);
    void setCoefficients(const std::vector<double>& coeffs);

    double evaluate(double x) const;
    const std::vector<double>& getCoefficients() const;

private:
    std::vector<double> knots_;
    std::vector<double> coefficients_;
};
