#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Function prototypes
void readMatrixFromFile(int matrix[][100], int N, ifstream &file);
void printMatrix(int matrix[][100], int N);
void addMatrices(int matrix1[][100], int matrix2[][100], int result[][100], int N);
void multiplyMatrices(int matrix1[][100], int matrix2[][100], int result[][100], int N);
void subtractMatrices(int matrix1[][100], int matrix2[][100], int result[][100], int N);

// Main program
int main() {
    cout << "Drew Meyer" << endl;
    cout << "Lab #6: Matrix manipulation" << endl;
    int N;
    int matrixA[100][100], matrixB[100][100], result[100][100];
    ifstream file("matrix_input.txt");

    // Read size of matrices
    if (file.is_open()) {
        file >> N;
    }

    // Reading and displaying matrix A
    readMatrixFromFile(matrixA, N, file);
    cout << "Matrix A:" << endl;
    printMatrix(matrixA, N);

    // Reading and displaying matrix B
    readMatrixFromFile(matrixB, N, file);
    cout << "\nMatrix B:" << endl;
    printMatrix(matrixB, N);

    // Adding matrices and displaying the result
    addMatrices(matrixA, matrixB, result, N);
    cout << "\nMatrix Sum (A + B):" << endl;
    printMatrix(result, N);

    // Multiplying matrices and displaying the result
    multiplyMatrices(matrixA, matrixB, result, N);
    cout << "\nMatrix Product (A * B):" << endl;
    printMatrix(result, N);

    // Subtracting matrices and displaying the result
    subtractMatrices(matrixA, matrixB, result, N);
    cout << "\nMatrix Difference (A - B):" << endl;
    printMatrix(result, N);

    return 0;
}


// Function definitions
void readMatrixFromFile(int matrix[][100], int N, ifstream &file) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            file >> matrix[i][j];
        }
    }
}

void printMatrix(int matrix[][100], int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}


void addMatrices(int matrix1[][100], int matrix2[][100], int result[][100], int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void multiplyMatrices(int matrix1[][100], int matrix2[][100], int result[][100], int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < N; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}


void subtractMatrices(int matrix1[][100], int matrix2[][100], int result[][100], int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}


