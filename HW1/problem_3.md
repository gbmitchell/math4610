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
Also in the folder was a header file I made containing the library function declarations and an application file
to link the libray to. Next, I compiled the smaceps and dmaceps functions using gcc compiler. Compiling the
functions produced object files and these object files were used to create one static library file containing both
the smaceps and dmaceps functions. Finally, the application was compiled with the static library linked to it and
executing the application resulted in the output shown in Figure 1.
  
![](gcc(Linux).png)
**Figure 1**
  
**Library Header File:** The following is the code for mylib.h

    #ifndef MYLIB_H
    #define MYLIB_H
    void smaceps(float *seps, int *ipow);
    void dmaceps(double *seps, int *ipow);
    #endif
  
**Function smaceps:** The following is the code for smaceps.c
  
    #include <stdio.h>
    #include <math.h>
    
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
  
**Function dmaceps:** The following is the code for dmaceps.c
  
    #include <stdio.h>
    #include <math.h>
    
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
  
**Application File:** The following is the code for errorCalculation.c
  
    #include "mylib.h"
    
    int main() {
    
        // create and initialize arguments
        float seps1 = 1.0;
        int ipow = 0;
        
        // call smaceps function passing arguments by reference
        smaceps(&seps1, &ipow);
        
        // print the resulting values to the console
        printf("\n%d\t%.8e", ipow, seps1);
        
        // create and initialize arguments
        double seps2 = 1.0;
        ipow = 0;
        
        // call smaceps function passing arguments by reference
        dmaceps(&seps2, &ipow);
        
        // print the resulting values to the console
        printf("\n%d\t%.8e", ipow, seps2);

        return 0;
    }

Output from the lines above:

      24    5.96046448e-08
      53    1.11022302e-16
    

**Last Modified:** September/2018
