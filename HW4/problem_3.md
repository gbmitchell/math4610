# Math 4610 Fundamentals of Computational Mathematics
Homework 4 problem 3.

**Routine Name:**           forwardSub

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    squareGauss.c

will produce an executable **squareGauss.exe** that can be executed.

**Description/Purpose:** This function will compute the single precision value for the machine epsilon or the number of digits
in the representation of real numbers in single precision. This is a function for analyzing the behavior of any computer. This
usually will need to be run one time for each computer.

**Input:** There are no inputs needed in this case. Arguments are passed by reference and the function will change their values.
The real purpose is to produce values in those variables to be used as needed.

**Output:** This function returns a single precision value for the number of decimal digits that can be represented on the
computer being queried.

**Usage/Example:**

The function has two arguments needed to produce the values of the precision in terms of the smallest number that can be
represented. Since the code is written in terms of a C function, the value of the machine epsilon (seps) is a single
precision value (float) and the power of two that gives the machine epsilon (ipow) is an integer. 



Output from the lines above:



The first value (24) is the number of binary digits that define the machine epsilon and the second is related to the
decimal version of the same value. The number of decimal digits that can be represented is roughly eight (e-08 on the
end of the second value).

**Implementation/Code:** The following is the code for forwardSub()

    void forwardSub(double A[50][50], double x[50], double b[50], int n) {
        int i, j = 0;
        double sum = 0.0;

        x[0] = b[0] / A[0][0];
        for (i = 1; i < n; i++) {
            sum = 0.0;
            for (j = 0; j < i; j++) {
                sum = sum + (A[i][j] * x[j]);
            }
            x[i] = (b[i] - sum) / A[i][i];
        }
    }

**Last Modified:** November/2018
