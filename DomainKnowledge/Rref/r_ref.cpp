#include <cstddef>
#include <iostream>

struct item {
public:
  int* score;
  bool is_used;

  item(){}
  item(int* _score, bool _is_used): score(_score), is_used(_is_used) {}

};

class Matrix {
public:
  Matrix(int _row, int _col): row(_row), col(_col), data(new float* [_row]) {
    printf("Matrix(int _row, int _col)\n");
    for (int i = 0; i < row; i++) {
      data[i] = new float[col];
      for (int j = 0; j < col; j++) {
        data[i][j] = 1;  
      }
    }
  }

  // copy ctor
  Matrix(const Matrix& mat): row(mat.row), col(mat.col), data(new float* [mat.row]) {
    printf("Matrix(const Matrix& mat)\n");
    for (int i = 0; i < row; i++) {
      data[i] = new float[col];
      for (int j = 0; j < col; j++) {
        data[i][j] = mat.data[i][j];
      }
    }
  }

  // move ctor
  Matrix(Matrix&& mat): row(mat.row), col(mat.col), data(mat.data) {
    printf("Matrix(Matrix&& mat) \n");
    mat.data = nullptr;
  }
  
  ~Matrix() {
    if (data != nullptr) {
      for (int i = 0; i < row; i++) {
        if (data[i]) {
          delete[] data[i];
          data[i] = nullptr;
        }
      }
    }
  }

  // overload "+" for matrix with both first and second arguments: & and &
  friend Matrix operator + (const Matrix& a, const Matrix& b) {
    printf("friend operator+ with & and & \n");
    if (a.row != b.row || a.col != b.col) {
      printf("ERROR add operation\n");
    }
 
    Matrix res(a.row, a.col);
    for (int i = 0; i < a.row; i++) {
      for (int j = 0; j < a.col; j++) {
        res.data[i][j] = a.data[i][j] + b.data[i][j];
      }
    }
    return res;
  }

  // overload "+" for matrix with both first and second arguments: && and &
  friend Matrix operator + (Matrix&& a, const Matrix& b) {
    printf("friend operator+ with && and & \n");
    if (a.row != b.row || a.col != b.col) {
      printf("ERROR add operation\n");
    }

    printf("calling std::move() \n");
    // Matrix res(std::move(a));
    Matrix res = std::move(a);
    for (int i = 0; i < res.row; i++) {
      for (int j = 0; j < res.col; j++) {
        res.data[i][j] += b.data[i][j];
      }
    }
    return res;
  }


  int row = 0;
  int col = 0;

  float** data = nullptr;
};