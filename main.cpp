#include "edge_matrix.hpp"
#include "screen.hpp"
#include "matrix.hpp"
#include <fstream>
#include <iostream>

int main() {
    std::ofstream fout("main.ppm");
    screen<512, 512> s;
    edge_matrix e;
    e.add_edge({0, 0, 0}, {511, 256, 0});
    matrix ident(4, 4);
    for(int i = 0; i < 4; ++i) {
        ident[i][i] = 1;
    }
    e = dot(ident, e);
    s.drawMatrix(e, {255, 255, 255});
    fout << s;
    std::cout << e;
    fout.close();
}