#include "matrix.hpp"

#include <stdexcept>
matrix::matrix(int rows, int cols) : data(rows, std::vector<int>(cols)) {}

std::ostream& operator<<(std::ostream& out, matrix& mat) {
    for(std::vector<int> row : mat.data) {
        for(int item : row) {
            out << item << " ";
        }
        out << "\n";
    }
    return out;
}

matrix dot(matrix& a, matrix& b) {
    if(a.width() != b.height()) {
        throw std::invalid_argument("Number of columns in matrix a should be equal to rows in matrix b");
    }
    matrix result(a.height(), b.width());
    for(int i = 0; i < a.height(); ++i) {
        for(int j = 0; j < b.width(); ++j) {
            int sum = 0;
            for(int k = 0; k < a.width(); ++k) {
                sum += a.data[i][k] * b.data[k][j];
            }
            result[i][j] = sum;
        }
    }
    return result;
}

std::vector<int>& matrix::operator[](int index) {
    return data[index];
}

int matrix::get(int row, int col) {
    return data[row][col];
}

void matrix::set(int row, int col, int num) {
    data[row][col] = num;
}

int matrix::width() {
    return data[0].size();
}

int matrix::height() {
    return data.size();
}