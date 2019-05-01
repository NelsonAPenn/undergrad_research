# Cycle Embeddings Project / Matrix template class / Polynomial template class

## Overview

Libraries built for the easy and quick calculation of matrix/polynomial expressions, tested on combinatorial problems involving matrices.

Hand-implemented matrix and polynomial template libraries that implement:

- normal matrix/polynomial arithmetic
- Hadamard product on matrices
- Derivative of the polynomial
- Determinant of the matrix
- Taylor Series expansion for a quotient of two polynomials
- A mostly-borrowed script for random matrix generation, written in Python

## Project Structure

- Implementation of polynomial template class is in `polynomial.h`
- Implementation of matrix template class is in `matrix.h`
- Testing by counting n-cycle embeddings is implemented in cycleEmbeddings.cpp
- Testing of calculation of generating function involving matrices done in main.cpp
- makefile is designed for compiling the programs on a Unix machine.
  - To this effect, use `make` followed by `./ur` (for "undergraduate research")
- Random matrix generation is done in the Python script that lies within the matrixGenerator directory
  - Watch out for the strange bytes Python appends to the beginning of the output of the random matrices, if fed directly to the C++ program it will not work. To resolve, simply copy and paste the output.

## Setup

This program uses GMP. As I run Linux on my machine, I used the out-of-the-box Unix GMP library, simply compiling with the flags `-lgmp` and `-lgmpxx`.

To compile the most recent programs for testing the libraries, navigate to the testing directory and use `make` followed by `./generatingFunction` (for testing with a generating function for counting closed walks in complete graphs) or by `./cycleEmbeddings` (for testing by using matrix expressions to count cycle embeddings). Currently the cycle embeddings program requires the input of a matrix, which can also be supplied via redirection in Linux. Make sure to follow the format as outlined in the `cycleEmbeddings.cpp` file.

If not running on a Unix OS, you must install GMP on your computer, and make sure you are using the appropriate flags to match your installation.

