#pragma once
#include <vector>

class Spline {
public:
    Spline(const std::vector<double>& knots);

    double evaluate(double x) const;
    void setWeights(const std::vector<double>& w);

private:
    std::vector<double> knots_;
    std::vector<double> weights_;
    int findInterval(double x) const;
};
