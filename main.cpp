#include "edge_matrix.hpp"
#include "screen.hpp"
#include <fstream>
#include <iostream>

int main() {
    std::ofstream fout("main.ppm");
    screen<512, 512> s;
    edge_matrix e;
    e.add_edge({0, 0, 0}, {511, 511, 0});
    s.drawMatrix(e, {255, 255, 255});
    fout << s;
    std::cout << e;
    fout.close();
}