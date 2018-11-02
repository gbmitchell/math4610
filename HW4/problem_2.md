# Math 4610 Fundamentals of Computational Mathematics
Homework 4 problem 2.

**Routine Name:**           generalGauss

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    squareGauss.c

will produce an executable **squareGauss.exe** that can be executed.

**Description/Purpose:** This routine will compute the necassary factors and carry out row operations for Gauss Elimination of a general matrix mxn up to size 50x50. No pivoting methods are used in this routine.

**Input:** There are four inputs needed in this case. A general matrix of size mxn and a vector of size n are arguments passed by reference and the routine will change their values according to the process for Gauss Elimination. The variables m and n are also passed to the routine to indicate the size of the matrix and vector. The vector and matrix are treated as though they are combined to form an augmented matrix even though they remain separate.

**Output:** This routine does not return anything, instead it changes the original matrix and vector values as though they were an augmented matrix going through the Gauss Elimination process.

**Usage/Example:**

There are four inputs needed in this case. A general matrix (C) of size mxn (4x5) and a vector (bc) of size m (4) are arguments passed by reference and the routine will change their values according to the process for Gauss Elimination. The variables m (4) and n (5) are also passed to the routine to indicate the size of the matrix and vector. The vector and matrix are treated as though they are combined to form an augmented matrix even though they remain separate. This routine does not return anything, instead it changes the original matrix and vector values as though they were an augmented matrix going through the Gauss Elimination process. 



Output from the lines above:



The output from the example code prints the matix B and vector bb as though they are augmented even though they remain separate. The output shows the original values of B and bb. The Gauss Elimination process is then executed and the output prints the modified values of B and bb. Gauss Elimination results in an upper triangular matrix that can be used to solve for a solution to x in the problem of Bx=bb.

**Implementation/Code:** The following is the code for generalGauss()

    void generalGauss(double A[50][50], double b[50], int m, int n) {
        int i, j, k = 0;
        double factor = 0.0;
        for (k = 0; k < (n - 1); k++) {
            for (i = (k + 1); i < m; i++) {
                factor = A[i][k] / A[k][k];
                A[i][k] = 0.0;
                for (j = (k + 1); j < n; j++) {
                    A[i][j] = A[i][j] - (factor * A[k][j]);
                }
                b[i] = b[i] - (factor * b[k]);
            }
        }
    }

**Last Modified:** November/2018
