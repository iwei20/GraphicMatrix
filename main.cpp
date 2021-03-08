#include "edge_matrix.hpp"
#include "screen.hpp"
#include "matrix.hpp"
#include <fstream>
#include <iostream>

void rect(edge_matrix& e, int x, int y, int w, int h) {
    e.add_edge({x, y, 0}, {x + w, y, 0});
    e.add_edge({x, y, 0}, {x, y + h, 0});
    e.add_edge({x + w, y + h, 0}, {x + w, y, 0});
    e.add_edge({x + w, y + h, 0}, {x, y + h, 0});
}

int main() {
    std::ofstream fout("main.ppm");
    screen<512, 512> s;
    edge_matrix e;
    for(double i = 511; i >= 1; i /= 1.2) {
        e.add_edge({0, 0, 0}, {511, i, 0});
    }
    for(double i = 511; i >= 1; i /= 1.2) {
        e.add_edge({0, 0, 0}, {i, 511, 0});
    }
    e.add_edge({0, 0, 0}, {511, 510.5, 0});

    std::cout << "Testing add_edge: \n" << e;
    matrix ident(4, 4);
    for(int i = 0; i < 4; ++i) {
        ident[i][i] = 1;
    }
    e = ident * e;
    std::cout << "Testing identity dot product: \n" << e;
    s.drawMatrix(e, {0, 255, 0});
    fout << s;
    fout.close();
}