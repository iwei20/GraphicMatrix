#include "edge_matrix.hpp"
#include <tuple>
edge_matrix::edge_matrix() : matrix(4, 0) {}

void edge_matrix::add_point(std::tuple<int, int, int> point) {
    int x, y, z;
    std::tie(x, y, z) = point;
    data[0].push_back(x);
    data[1].push_back(y);
    data[2].push_back(z);
    data[3].push_back(1);
}

void edge_matrix::add_edge(std::tuple<int, int, int> a, std::tuple<int, int, int> b) {
    add_point(a);
    add_point(b);
};