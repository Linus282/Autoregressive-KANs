#include "trainer.hpp"
#include <iostream>
#include <cmath>

KANTrainer::KANTrainer(KAN& model, double lr)
    : model_(model), lr_(lr) {}

double KANTrainer::computeLoss(const std::vector<std::vector<double>>& X,
                               const std::vector<double>& y) {
    double loss = 0.0;
    for (size_t i = 0; i < X.size(); ++i) {
        double pred = model_.forward(X[i]);
        double diff = pred - y[i];
        loss += diff * diff;
    }
    return loss / X.size();
}

void KANTrainer::train(const std::vector<std::vector<double>>& X,
                       const std::vector<double>& y,
                       int epochs) {
    for (int e = 0; e < epochs; ++e) {
        // Dummy-Gradient: Perturbation in Richtung Fehler
        for (int n = 0; n < model_.numNeurons(); ++n) {
            auto w = model_.getNeuronWeights(n);
            auto c = model_.getNeuronCoeffs(n);
            for (size_t j = 0; j < w.size(); ++j) {
                w[j] -= lr_ * 0.01; // simplifizierter update
            }
            model_.setWeights(n, w, c);
        }
        double loss = computeLoss(X, y);
        if (e % 10 == 0) std::cout << "Epoch " << e << " Loss: " << loss << "\n";
    }
}
