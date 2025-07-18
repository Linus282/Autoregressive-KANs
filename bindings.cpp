#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "kan.hpp"

namespace py = pybind11;

PYBIND11_MODULE(kanpy, m) {
    py::class_<KAN>(m, "KAN")
        .def(py::init<int, int, const std::vector<double>&, BasisType>(), py::arg("input_dim"), py::arg("hidden_units"), py::arg("knots"), py::arg("basis") = BasisType::LinearSpline)
        .def("forward", &KAN::forward)
        .def("setWeights", &KAN::setWeights);

    py::enum_<BasisType>(m, "BasisType")
        .value("LinearSpline", BasisType::LinearSpline)
        .value("Sin", BasisType::Sin)
        .value("Tanh", BasisType::Tanh);
}
