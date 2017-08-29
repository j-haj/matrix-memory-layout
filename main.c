#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Allocates memory for a square matrix of size `n` and assigns random values to
 * the elements of the matrix in the range [0, RAND_MAX).
 *
 * @param n size of the matrix
 *
 * @return pointer to the matrix
 */
int** allocate_square_matrix(size_t n) {
	int** m = (int**)malloc(sizeof(int*) * n);
	for (size_t i = 0; i < n; ++i) {
		m[i] = (int*)malloc(sizeof(int) * n);
		for (size_t j = 0; j < n; ++j) {
			m[i][j] = rand();
		}
	}
	return m;
}

/**
 * Prints the elements of the matrix, formatted as a rectangle with the passed
 * in dimensions.
 *
 * @param m pointer to matrix
 * @param rows number of rows
 * @param cols number of cols
 */
void print_matrix(int** m, size_t rows, size_t cols) {
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < cols - 1; ++j) {
			printf("%d ", m[i][j]);
		}
		printf("%d\n", m[i][rows-1]);
	}
	printf("\n");
}

/**
 * Prints the memory address of the elements of the matrix, formatted as a
 * rectangle with the passed in dimensions.
 *
 * @param m pointer to matrix
 * @param rows number of rows
 * @param cols number of cols
 */
void print_matrix_memory_layout(int** m, size_t rows, size_t cols) {
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < cols - 1; ++j) {
			printf("%p ", (void*)&m[i][j]);
		}
		printf("%p\n", (void*)&m[i][cols - 1]);
	}
	printf("\n");
}

/**
 * Prints various statistics about machine data sizes. This can be useful for
 * analyzing address spacing in memory layout.
 */
void print_size_info() {
	printf("System data sizes:\n");
	printf("sizeof(int) = %lu bytes\n", sizeof(int));
	printf("sizeof(int*) = %lu bytes\n", sizeof(int*));
	printf("sizeof(int**) = %lu bytes\n", sizeof(int**));
	printf("\n");
}

int main() {
	// Seed random number generator
	srand(time(NULL));

	// Set matrix size
	const int N = 5;

	print_size_info();

	int** A = allocate_square_matrix(N);
	int** B = allocate_square_matrix(N);
	printf("Matrix A memory layout:\n");
	print_matrix_memory_layout(A, N, N);

	printf("Matrix B memory layout:\n");
	print_matrix_memory_layout(B, N, N);

	return 0;
}