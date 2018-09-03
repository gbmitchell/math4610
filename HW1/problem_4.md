# Math 4610 Fundamentals of Computational Mathematics
**Homework 1, Solution 4.**
  
Most computers have multiple core processors in some form or another. A typical C program uses only one of those
processors in a sequential way, one line after the other or series programing. It is possible to utilize more or
all of your computers processors through multiple threads or parallel programing. There is more than one way to
accomplish parallel programing, one solution is to use openMP.
  
OpenMP is an application programming interface (API) that supports parallel programming in C language on platforms
such as Windows and Linux. This solution shows how to use a simple C program with openMP to start multiple threads
and report back which thread is printing and the total number of threads running. Parallel programing better use
of a machines available resources and is important for use in problems that require speed with large volumes of
calculation.

  
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
