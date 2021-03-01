#pragma once

#include "matrix.hpp"

class edge_matrix : public matrix {
    private:
        void add_point(std::tuple<int, int, int> point);
    public:
        edge_matrix();

        void add_edge(std::tuple<int, int, int> a, std::tuple<int, int, int> b);
        using matrix::operator=;
};