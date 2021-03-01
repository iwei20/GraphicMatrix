#pragma once

#include <vector>
#include <array>
#include <ostream>

class matrix {
private:
    std::vector<std::vector<int>> data;
public:
    matrix(int rows, int cols);
    friend std::ostream& operator<<(std::ostream& out, matrix& mat);

    static matrix& dot(matrix& a, matrix& b);

    std::vector<int>& operator[](int index);
    int get(int row, int col);
    void set(int row, int col, int num);
};