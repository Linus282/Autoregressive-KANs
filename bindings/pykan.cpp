#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "../src/kan.hpp"

namespace py = pybind11;

PYBIND11_MODULE(pykan, m) {
    py::enum_<BasisType>(m, "BasisType")
        .value("LinearSpline", BasisType::LinearSpline)
        .value("Sin", BasisType::Sin)
        .value("Tanh", BasisType::Tanh)
        .export_values();

    py::class_<KAN>(m, "KAN")
        .def(py::init<int, int, const std::vector<double>&, BasisType>())
        .def("forward", &KAN::forward)
        .def("setWeights", &KAN::setWeights);
}
