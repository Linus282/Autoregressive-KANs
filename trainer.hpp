#pragma once
#include "kan.hpp"
#include <vector>

class KANTrainer {
public:
    KANTrainer(KAN& model, double lr);

    void train(const std::vector<std::vector<double>>& X,
               const std::vector<double>& y,
               int epochs);

private:
    KAN& model_;
    double lr_;

    double computeLoss(const std::vector<std::vector<double>>& X,
                       const std::vector<double>& y);
};
