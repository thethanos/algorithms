#pragma once

#include <vector>
#include <array>

using std::array;
using matrix = std::vector<std::vector<int>>;

/*******Strassen's matrix multiplication******
*  Time complexity: O(n^log7 base 2)         *
*  Auxiliary space: O(n)                     *
**********************************************/

matrix operator+(const matrix& m1, const matrix& m2);
matrix operator-(const matrix& m1, const matrix& m2);

std::array<matrix, 4> split(const matrix& m);
matrix unite(const matrix& m1, const matrix& m2, const matrix& m3, const matrix& m4);

//Strassen's formulas
//P = (A11 + A22)(B11 + B22)
//Q = (A21 + A22) * B11
//R = A11 * (B12 - B22)
//S = A22 * (B21 - B11)
//T = (A11 + A12) * B22
//U = (A21 - A11) * (B11 + B12)
//V = (A12 - A22) * (B21 + B22) 

//c11 = P + S - T + V
//c12 = R + T
//c21 = Q + S
//c22 = P + R - Q + U

matrix strassen_algorithm(const matrix& matrix_a, const matrix& matrix_b)
{
    if (matrix_a.size() == 1 && matrix_b.size() == 1)
        return matrix{{matrix_a[0][0] * matrix_b[0][0]}};

    auto [a11, a12, a21, a22] = split(matrix_a);
    auto [b11, b12, b21, b22] = split(matrix_b);

    auto P = strassen_algorithm(a11 + a22, b11 + b22);
    auto Q = strassen_algorithm(a21 + a22, b11);
    auto R = strassen_algorithm(a11, b12 - b22);
    auto S = strassen_algorithm(a22, b21 - b11);
    auto T = strassen_algorithm(a11 + a12, b22);
    auto U = strassen_algorithm(a21 - a11, b11 + b12);
    auto V = strassen_algorithm(a12 - a22, b21 + b22);

    auto c11 = P + S - T + V;
    auto c12 = R + T;
    auto c21 = Q + S;
    auto c22 = P + R - Q + U;

    return unite(c11, c12, c21, c22);
}

matrix operator+(const matrix& m1, const matrix& m2)
{
    size_t size = m1.size();

    matrix res(size, std::vector<int>(size));

    for (size_t i(0); i < res.size(); ++i)
    {
        for (size_t j(0); j < res.size(); ++j)
            res[i][j] = m1[i][j] + m2[i][j];
    }

    return res;
}

matrix operator-(const matrix& m1, const matrix& m2)
{
    size_t size = m1.size();

    matrix res(size, std::vector<int>(size));

    for (size_t i(0); i < res.size(); ++i)
    {
        for (size_t j(0); j < res.size(); ++j)
            res[i][j] = m1[i][j] - m2[i][j];
    }

    return res;
}

std::array<matrix, 4> split(const matrix& m)
{
    size_t size = m.size()/2;

    matrix q1(size, std::vector<int>(size));
    matrix q2(size, std::vector<int>(size));
    matrix q3(size, std::vector<int>(size));
    matrix q4(size, std::vector<int>(size));

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            q1[i][j] = m[i][j];
            q2[i][j] = m[i][j+size];
            q3[i][j] = m[i+size][j];
            q4[i][j] = m[i+size][j+size];
        }
    }

    return std::array<matrix, 4>{q1, q2, q3, q4};
}

matrix unite(const matrix& m1, const matrix& m2, const matrix& m3, const matrix& m4)
{
    size_t res_size = m1.size() * 2;
    size_t size     = m1.size();

    matrix res(res_size, std::vector<int>(res_size));

    for (size_t i(0); i < size; ++i)
    {
        for (size_t j(0); j < size; ++j)
        {
            res[i][j]               = m1[i][j];
            res[i][j+size]          = m2[i][j];
            res[i + size][j]        = m3[i][j];
            res[i + size][j + size] = m4[i][j];
        }   
    }

    return res;
}