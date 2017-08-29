#ifndef __MEMORY_LAYOUT_H
#define __MEMORY_LAYOUT_H

#include <stdlib.h>

/**
 * Allocates memory for a square matrix of size `n` and assigns random values to
 * the elements of the matrix in the range [0, RAND_MAX).
 *
 * @param n size of the matrix
 *
 * @return pointer to the matrix
 */
int** allocate_square_matrix(size_t n);

/**
 * Allocates memory for a square matrix of size `n` of long and assigns random
 * values to the element of the matrix in the range [0, RAND_MAX).
 *
 * @param n size of the matrix
 *
 * @return pointer to the matrix
 */
long** allocate_square_matrix_long(size_t n);

/**
 * Prints the elements of the matrix, formatted as a rectangle with the passed
 * in dimensions.
 *
 * @param m pointer to matrix
 * @param rows number of rows
 * @param cols number of cols
 */
void print_matrix(int** m, size_t rows, size_t cols);

/**
 * Prints the memory address of the elements of the matrix, formatted as a
 * rectangle with the passed in dimensions.
 *
 * @param m pointer to matrix
 * @param rows number of rows
 * @param cols number of cols
 */
void print_matrix_memory_layout(int** m, size_t rows, size_t cols);

/**
 * Prints the memory address of the elements of the matrix, formatted as a
 * rectangle with the passed in dimensions. Note this function is for a matrix
 * of longs.
 *
 * @param m pointer to matrix
 * @param rows number of rows
 * @param cols number of cols
 */
void print_matrix_memory_layout_long(long** m, size_t rows, size_t cols);

/**
 * Prints various statistics about machine data sizes. This can be useful for
 * analyzing address spacing in memory layout.
 */
void print_size_info();

/**
 * Releases memory of int matrix.
 *
 * @param m matrix to be freed
 * @param rows number of rows
 */
void int_mat_free(int** m, size_t rows);

/**
 * Releases memory of long matrix
 *
 * @param m matrix to be freed
 * @param rows number of rows
 */
void long_mat_free(long**, size_t rows);

#endif // __MEMORY_LAYOUT_H
