#include "edge_matrix.hpp"
#include "screen.hpp"
#include <fstream>

int main() {
    std::ofstream fout("main.ppm");
    screen<512, 512> s;
    edge_matrix e;
    e.add_edge({0, 0, 0}, {0, 512, 0});
    fout << s;
    fout.close();
}