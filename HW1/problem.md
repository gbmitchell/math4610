# Math 4610 Fundamentals of Computational Mathematics
Homework 1 problem 1.

**Routine Name:**           smaceps

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    smaceps.c

will produce an executable **smaceps.exe** than can be executed.

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
    	float one = 0.0, appone = 0.0;
    	int i = 0;

    	one = 1.0;
    	*seps = 1.0;
    	appone = one + *seps;
    	*ipow = 0;

    	for (i = 0; i < 1000; i++) {
    	    *ipow = *ipow + 1;
    	    *seps = *seps / 2.0;
    	    appone = one + *seps;
    	    if (fabs(appone - one) == 0.0) return;
    	}

    	printf("The loop limit has been exceeded");

    	return;
    }

**Last Modified:** September/2018
