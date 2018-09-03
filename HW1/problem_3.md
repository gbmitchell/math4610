# Math 4610 Fundamentals of Computational Mathematics
**Homework 1, Solution 3.**

A static library was created containing both the smaceps and dmaceps functions from solution 1a and 1b.
Common machine routines can be used in many different programs. Libraries are used to eliminate the need
to reinvent the routine for each program. 
  
This solution demonstrates how to make a static library. A static library is used at compile time and gets
coppied dirrectly into your program code. Libraries are platform dependent, a static library for Windows
would be named something like,

    example.lib 

and on a Linux platform the same library would be named,

    libexample.a

On a Linux machine, I starting with the c code version of the smaceps and dmaceps functions in a single folder.
Next, I compiled both files using gcc compiler with the following command line,


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

**Last Modified:** September/2018
