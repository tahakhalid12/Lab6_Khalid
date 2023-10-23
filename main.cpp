#include <iostream>
#include <fstream>
#include <iomanip>

// Static constant for max matrix size
const static int MAX_SIZE = 100; // Maximum size for the matrix
const static std::string FILENAME = "matrix_input.txt"; // Hardcoded filename to read matrix data from

// Function prototypes
// These are declarations of functions that will be defined later in the code.
// They inform the compiler about the function's name, return type, and parameters.

// Reads a matrix from a file
void readMatrixFromFile(int matrix[MAX_SIZE][MAX_SIZE], int &size, int matrixNumber);

// Prints a matrix to the console
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size, const std::string &label);

// Adds two matrices
void addMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);

// Multiplies two matrices
void multiplyMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);

// Subtracts the second matrix from the first
void subtractMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);

int main() {
    // Matrix declarations
    int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int size; // Size of the matrix (NxN)

    // Print header
    std::cout << "Taha Khalid\n";
    std::cout << "Lab #6: Matrix manipulation\n\n";

    // Read matrices from the file
    readMatrixFromFile(matrix1, size, 1); // Read first matrix
    readMatrixFromFile(matrix2, size, 2); // Read second matrix

    // Display matrices
    printMatrix(matrix1, size, "Matrix A:");
    std::cout << "\n";
    printMatrix(matrix2, size, "Matrix B:");
    std::cout << "\n";

    // Perform matrix addition and display the result
    addMatrices(matrix1, matrix2, result, size);
    printMatrix(result, size, "Matrix Sum (A + B):");
    std::cout << "\n";

    // Perform matrix multiplication and display the result
    multiplyMatrices(matrix1, matrix2, result, size);
    printMatrix(result, size, "Matrix Product (A * B):");
    std::cout << "\n";

    // Perform matrix subtraction and display the result
    subtractMatrices(matrix1, matrix2, result, size);
    printMatrix(result, size, "Matrix Difference (A - B):");

    return 0; // End of the program
}

// Function definitions

// Reads matrix data from the file
void readMatrixFromFile(int matrix[MAX_SIZE][MAX_SIZE], int &size, int matrixNumber) {
    std::ifstream inFile(FILENAME); // Open the file for reading
    if (inFile.is_open()) { // Check if the file opened successfully
        inFile >> size; // Read the matrix size
        for (int m = 1; m <= matrixNumber; m++) { // Loop to skip the first matrix if reading the second matrix
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    inFile >> matrix[i][j]; // Read each element of the matrix
                }
            }
        }
        inFile.close(); // Close the file
    } else {
        std::cerr << "Unable to open file " << FILENAME << std::endl; // Error message if the file cannot be opened
    }
}

// Prints the matrix in a formatted manner
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size, const std::string &label) {
    std::cout << label << std::endl; // Print the label (e.g., "Matrix A:")
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << std::setw(5) << matrix[i][j] << " "; // Print each element with a width of 5 spaces
        }
        std::cout << std::endl; // Move to the next line after printing a row
    }
}

// Adds two matrices
void addMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j]; // Sum of corresponding elements
        }
    }
}

// Multiplies two matrices
void multiplyMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = 0; // Initialize the result element to 0
            for (int k = 0; k < size; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j]; // Multiply and accumulate the result
            }
        }
    }
}

// Subtracts the second matrix from the first
void subtractMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j]; // Difference of corresponding elements
        }
    }
}
