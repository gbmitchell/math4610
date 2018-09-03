# Math 4610 Fundamentals of Computational Mathematics
Homework 1, Solution 1a.

**Routine Name:**           smaceps

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    smaceps.c

will produce an executable **smaceps.exe** that can be executed.

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

    #include <stdio.h>
    #include <math.h>
    
    int main() {
    
        // create and initialize arguments
        float seps = 1.0;
        int ipow = 0;
        
        // call smaceps function passing arguments by reference
        smaceps(&seps, &ipow);
        
        // print the resulting values to the console
        printf("\n%d\t%.8e", ipow, seps);
        
        // keeps the console open until a key is pressed
        getch();

        return 0;
    }

Output from the lines above:

      24    5.96046448e-08

The first value (24) is the number of binary digits that define the machine epsilon and the second is related to the
decimal version of the same value. The number of decimal digits that can be represented is roughly eight (e-08 on the
end of the second value).

**Implementation/Code:** The following is the code for smaceps()

    void smaceps(float *seps, int *ipow) {
    
        // create an initialize function variables
        // initialized to find machine value near 1.0
        float one = 0.0, appone = 0.0;
        int i = 0;
        one = 1.0;
        *seps = 1.0;
        appone = one + *seps;
        *ipow = 0;

        // loop, dividing by 2 each time to determine when the difference
        //  between one and the approximation is zero in single precision
        for (i = 0; i < 1000; i++) {
            *ipow = *ipow + 1;
            *seps = *seps / 2.0;
            appone = one + *seps;
            if (fabs(appone - one) == 0.0) return;
        }

        // print error message to console if loops more than 1000 times
        // code should never reach this point unless there is an error
        printf("The loop limit has been exceeded");

        return;
    }
    
# Math 4610 Fundamentals of Computational Mathematics
Homework 1, Solution 1b.

**Routine Name:**           dmaceps

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    dmaceps.c

will produce an executable **dmaceps.exe** that can be executed.

**Description/Purpose:** This function will compute the double precision value for the machine epsilon or the number of digits
in the representation of real numbers in double precision. This is a function for analyzing the behavior of any computer. This
usually will need to be run one time for each computer.

**Input:** There are no inputs needed in this case. Arguments are passed by reference and the function will change their values.
The real purpose is to produce values in those variables to be used as needed.

**Output:** This function returns a double precision value for the number of decimal digits that can be represented on the
computer being queried.

**Usage/Example:**

The function has two arguments needed to produce the values of the precision in terms of the smallest number that can be
represented. Since the code is written in terms of a C function, the value of the machine epsilon (seps) is a double
precision value (double) and the power of two that gives the machine epsilon (ipow) is an integer.

    #include <stdio.h>
    #include <math.h>
    
    int main() {
    
        // create and initialize arguments
        double seps = 1.0;
        int ipow = 0;
        
        // call dmaceps function passing arguments by reference
        dmaceps(&seps, &ipow);
        
        // print the resulting values to the console
        printf("\n%d\t%.8e", ipow, seps);
        
        // keeps the console open until a key is pressed
        getch();

        return 0;
    }

Output from the lines above:

      53    1.11022302e-16

The first value (53) is the number of binary digits that define the machine epsilon and the second is related to the
decimal version of the same value. The number of decimal digits that can be represented is roughly sixteen (e-16 on the
end of the second value).

**Implementation/Code:** The following is the code for dmaceps()

    void dmaceps(double *seps, int *ipow) {
    
        // create an initialize function variables
        // initialized to find machine value near 1.0
        double one = 0.0, appone = 0.0;
        int i = 0;
        one = 1.0;
        *seps = 1.0;
        appone = one + *seps;
        *ipow = 0;

        // loop, dividing by 2 each time to determine when the difference
        //  between one and the approximation is zero in double precision
        for (i = 0; i < 1000; i++) {
            *ipow = *ipow + 1;
            *seps = *seps / 2.0;
            appone = one + *seps;
            if (fabs(appone - one) == 0.0) return;
        }

        // print error message to console if loops more than 1000 times
        // code should never reach this point unless there is an error
        printf("The loop limit has been exceeded");

        return;
    }

**Last Modified:** September/2018
