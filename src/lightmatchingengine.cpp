#include <pybind11/pybind11.h>
#include "lightmatchingengine.h"

namespace py = pybind11;

PYBIND11_MODULE(lightmatchingengine, m) {
    // Enum Side
    py::enum_<Side>(m, "Side")
        .value("BUY", Side::BUY)
        .value("SELL", Side::SELL)
        .export_values();

    // Struct Order
    py::class_<Order>(m, "Order")
        .def(py::init<
            int,
            string&,
            double,
            double,
            Side>());

    // Struct Trade
    py::class_<Trade>(m, "Trade")
        .def(py::init<
            int,
            const string&,
            double,
            double,
            Side,
            int>());

    // Class LightMatchingEngine
    py::class_<LightMatchingEngine>(m, "LightMatchingEngine")
        .def(py::init())
        .def("add_order", &LightMatchingEngine::add_order)
        .def("cancel_order", &LightMatchingEngine::cancel_order)
        .def_property_readonly("order_books", &LightMatchingEngine::order_books)
        .def_property_readonly("curr_order_id", &LightMatchingEngine::curr_order_id)
        .def_property_readonly("curr_trade_id", &LightMatchingEngine::curr_trade_id);
}
