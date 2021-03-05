#pragma once

#include <vector>
#include <array>
#include <ostream>

class matrix {
protected:
    std::vector<std::vector<double>> data;
public:
    matrix(int rows, int cols);
    friend std::ostream& operator<<(std::ostream& out, matrix& mat);
    friend matrix dot(matrix& a, matrix& b);
    std::vector<double>& operator[](int index);
    double get(int row, int col);
    void set(int row, int col, double num);

    int width();
    int height();
};

