#include "memory_layout.h"

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void rand_init() {
	static bool init_once_token = false;
	if (!init_once_token) {
		init_once_token = true;
		srand(time(NULL));
	}
}

int** allocate_square_matrix(size_t n) {
	rand_init();

	int** m = (int**)malloc(sizeof(int*) * n);
	for (size_t i = 0; i < n; ++i) {
		m[i] = (int*)malloc(sizeof(int) * n);
		for (size_t j = 0; j < n; ++j) {
			m[i][j] = rand();
		}
	}
	return m;
}

long** allocate_square_matrix_long(size_t n) {
	rand_init();

	long** m = (long**)malloc(sizeof(long*) * n);
	for (size_t i = 0; i < n; ++i) {
		m[i] = (long*)malloc(sizeof(long) * n);
		for (size_t j = 0; j < n; ++j) {
			m[i][j] = rand();
		}
	}
	return m;
}

void print_matrix(int** m, size_t rows, size_t cols) {
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < cols - 1; ++j) {
			printf("%d ", m[i][j]);
		}
		printf("%d\n", m[i][rows-1]);
	}
	printf("\n");
}
void print_matrix_memory_layout(int** m, size_t rows, size_t cols) {
	printf("%zux%zu matrix\n", rows, cols);
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < cols - 1; ++j) {
			printf("%p ", (void*)&m[i][j]);
		}
		printf("%p\n", (void*)&m[i][cols - 1]);
	}
	printf("\n");
}

void print_matrix_memory_layout_long(long** m, size_t rows, size_t cols) {
	printf("%zux%zu matrix\n", rows, cols);
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < cols - 1; ++j) {
			printf("%p ", (void*)&m[i][j]);
		}
		printf("%p\n", (void*)&m[i][cols - 1]);
	}
	printf("\n");
}

void print_size_info() {
#ifdef _SC_PAGESIZE
	printf("System page size: %lu bytes\n\n", sysconf(_SC_PAGESIZE));
#endif
	printf("System data sizes:\n");
	printf("sizeof(int) = %lu bytes\n", sizeof(int));
	printf("sizeof(long) = %lu bytes\n", sizeof(long));
	printf("sizeof(long long) = %lu bytes\n", sizeof(long long));
	printf("sizeof(float) = %lu bytes\n", sizeof(float));
	printf("sizeof(double) = %lu bytes\n", sizeof(double));
	printf("sizeof(int*) = %lu bytes\n", sizeof(int*));
	printf("sizeof(long*) = %lu bytes\n", sizeof(long*));
	printf("sizeof(int**) = %lu bytes\n", sizeof(int**));
	printf("\n");
}

void int_mat_free(int** m, size_t rows) {
	for (size_t i = 0; i < rows; ++i) {
		free(m[i]);
	}
	free(m);
}

void long_mat_free(long** m, size_t rows) {
	for (size_t i = 0; i < rows; ++i) {
		free(m[i]);
	}
	free(m);
}
