#include <iostream>
#include <vector>

void setZeroes(std::vector<std::vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    // Flags to track zero rows and columns
    std::vector<bool> zeroRow(rows, false);
    std::vector<bool> zeroCol(cols, false);

    // Identify zero rows and columns
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == 0) {
                zeroRow[i] = true;
                zeroCol[j] = true;
            }
        }
    }

    // Set zero rows
    for (int i = 0; i < rows; ++i) {
        if (zeroRow[i]) {
            std::fill(matrix[i].begin(), matrix[i].end(), 0);
        }
    }

    // Set zero columns
    for (int j = 0; j < cols; ++j) {
        if (zeroCol[j]) {
            for (int i = 0; i < rows; ++i) {
                matrix[i][j] = 0;
            }
        }
    }
}

void displayMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int value : row) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<std::vector<int>> matrix = {{1, 1, 1},
                                           {1, 0, 1},
                                           {1, 1, 1}};

    setZeroes(matrix);

    std::cout << "Modified Matrix:" << std::endl;
    displayMatrix(matrix);

    return 0;
}
