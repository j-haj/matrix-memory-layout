#include "memory_layout.h"

#include <stdio.h>

int main() {
	print_size_info();

	int** A = allocate_square_matrix(5);
	int** B = allocate_square_matrix(6);
	int** C = allocate_square_matrix(7);
	int** D = allocate_square_matrix(8);
	int** E = allocate_square_matrix(9);

	long** A_long = allocate_square_matrix_long(4);
	long** B_long = allocate_square_matrix_long(5);
	long** C_long = allocate_square_matrix_long(6);

	printf("Matrix A memory layout:\n");
	print_matrix_memory_layout(A, 5, 5);

	printf("Matrix B memory layout:\n");
	print_matrix_memory_layout(B, 6, 6);

	printf("Matrix C memory layout:\n");
	print_matrix_memory_layout(C, 7, 7);

	printf("Matric D memory layout:\n");
	print_matrix_memory_layout(D, 8, 8);

	printf("Matrix E memory layout:\n");
	print_matrix_memory_layout(E, 9, 9);

	printf("Matrix A_long memory layout:\n");
	print_matrix_memory_layout_long(A_long, 4, 4);

	printf("Matrix B_long memory layout:\n");
	print_matrix_memory_layout_long(B_long, 5, 5);

	printf("Matrix C_long memory layout:\n");
	print_matrix_memory_layout_long(C_long, 6, 6);

	// Free memory
	int_mat_free(A, 5);
	int_mat_free(B, 6);
	int_mat_free(C, 7);
	int_mat_free(D, 8);
	int_mat_free(E, 9);

	long_mat_free(A_long, 4);
	long_mat_free(B_long, 5);
	long_mat_free(C_long, 6);

	return 0;
}
