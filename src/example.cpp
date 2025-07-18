#include "kan.hpp"
#include <iostream>

int main() {
    std::vector<double> knots = {0.0, 1.0, 2.0, 3.0};
    KAN model(3, 2, knots);

    model.setWeights(0, {1.0, 2.0, 1.5, 1.0}, {0.5, 0.3, 0.2});
    model.setWeights(1, {0.5, 0.8, 1.0, 1.2}, {0.2, 0.7, 0.1});

    std::vector<double> input = {1.0, 0.5, 2.0};
    double y_pred = model.forward(input);
    std::cout << "Forecast: " << y_pred << std::endl;

    return 0;
}
