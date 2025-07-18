#include "kan.hpp"
#include "trainer.hpp"
#include <iostream>

int main() {
    std::vector<std::vector<double>> X = {
        {1.0, 2.0, 3.0},
        {2.0, 3.0, 4.0},
        {3.0, 4.0, 5.0}
    };
    std::vector<double> y = {4.0, 5.0, 6.0};

    std::vector<double> knots = {0.0, 1.0, 2.0, 3.0};
    KAN model(3, 2, knots, BasisType::Tanh);
    KANTrainer trainer(model, 0.01);
    trainer.train(X, y, 100);

    std::vector<double> window = {4.0, 5.0, 6.0};
    std::cout << "Multi-step forecast:\n";
    for (int step = 0; step < 5; ++step) {
        double pred = model.forward(window);
        std::cout << "t+" << step+1 << ": " << pred << "\n";
        window.erase(window.begin());
        window.push_back(pred);
    }
}
