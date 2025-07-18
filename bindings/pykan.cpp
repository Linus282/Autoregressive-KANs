#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "../kan.hpp"  // Pfad zur Header-Datei anpassen

namespace py = pybind11;

PYBIND11_MODULE(pykan, m) {
    py::class_<KAN>(m, "KAN")
        .def(py::init<int, int, const std::vector<double>&, BasisType>())
        .def("forward", &KAN::forward)
        .def("setWeights", &KAN::setWeights);
}
