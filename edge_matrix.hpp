#pragma once

#include "matrix.hpp"

class edge_matrix : public matrix {
    private:
        void add_point(std::tuple<double, double, double> point);
    public:
        edge_matrix();

        void add_edge(std::tuple<double, double, double> a, std::tuple<double, double, double> b);
        using matrix::operator=;
};