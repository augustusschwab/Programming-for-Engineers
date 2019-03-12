// Augustus Schwab
// HW 4 - ME EN 5250
// Due: 10/4/15
// Problem 4 - Matrix Multiplication
// 
// This program is composed of 2 functions, one to read arbitrary
// sized matrices and another to multiply them together. The result
// will be a single matrix of the two input matrices multiplied together.


#include <iostream>


double* read_matrix(const int n, const int m) {
	std::size_t size = m * n;
	
	double *mat = new double[size];

	// Loop over each row
	for (int i = 0; i < n; ++i) {
		// Loop over each column in the i'th row
		for (int j = 0; j < m; ++j) {
			// Element [i, j] index = row_num * num_cols + col_num
			std::cin >> mat[i * m + j];
		}
	}
	
	return mat;
	delete[] mat;
}

double* mult_matrices(double* mat1, double* mat2, int n1, int m1, int n2, int m2) {
	int count = n1 * m2;
	double *new_matrix = new double[count];
	
	for (int k = 0; k < n1; ++k) {
		for (int i = 0; i < m2; ++i) {
			for (int j = 0; j < n2; ++j) {
				if (j == 0) {
					new_matrix[k*m2 + i] = mat1[k*m1 + j] * mat2[j*m2 + i];
				}
				else {
					new_matrix[k*m2 + i] += mat1[k*m1 + j] * mat2[j*m2 + i];
				}

			}
		}
	}
	
	// Loop over each row
	for (int i = 0; i < n1; ++i) {
		// Loop over each column in the i'th row
		for (int j = 0; j < m2; ++j) {
			// Element [i, j] index = row_num * num_cols + col_num
			std::cout << new_matrix[i * m2 + j] << " ";
		}
		std::cout << "\n";
	}


	delete[] new_matrix;

	return 0;

}


int main() {
	int num_cases;
	std::cin >> num_cases;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
		'\n');

	for (int i = 0; i < num_cases; ++i) {
		std::cout << "Case " << i << ":\n";
		int row1 = 0;
		int col1 = 0;
		int row2 = 0;
		int col2 = 0;

		int n = 2;
		double *mat = nullptr;
		
		double *matrices[2] = { 0,0 };
		for (int j = 0; j < n; ++j) {
			int row = 0;
			int col = 0;
			std::cin >> row;
			std::cin >> col;
			if (j == 0) {
				row1 = row;
				col1 = col;
			}
			else {
				row2 = row;
				col2 = col;
			}
			matrices[j] = read_matrix(row, col);

		}
		mult_matrices(matrices[0], matrices[1], row1, col1, row2, col2);

	}
	return 0;
}