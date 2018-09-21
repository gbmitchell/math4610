# Math 4610 Fundamentals of Computational Mathematics
Software Manual.

**Routine Name:**           expSecantHybrid

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    approximation.c

will produce an executable **approximation.exe** that can be executed.

**Description/Purpose:** This function will compute an approximation for a root of a defined
function f(x) given two initial values for an interval on which a root exists. The hybrid
secant root finding method starts with two iterations of the secant method. If the value
from the first two iterations of the secant method do not fall within the interval specified,
then bisection is implimented to narrowthe interval by an error of about 10^(-1). Another two
iterations of the secant method are done and if the result falls within the narrowed interval
then the secant method is used to finish the approximation to an error of 10^(-10). The idea is
to bring the interval close enough to the root with bisection and then finish with the secant
method to find the root faster than just using bisection.

**Input:** There are six inputs needed in this cases. A defined function f(x), two initial values
for an interval on which a root exisits (initialGuess, initialGuess1), a tolerance (prec10), a
maximum amount of times to iterate (maxIteration), and the expected value of the root (exproot) to
calculate the error for analizing the hybrid secant method.

**Output:** The function returns a double precision value that represents an approximation for the
root of a defined function f(x) given two initial values for an interval on which a root exisits.

**Usage/Example:**

The code below uses two defined functions, f(x) = x^2 - 3 and f(x) = sin(Pi * x) as functions to find
the roots of. We know that x^2 - 3 has a root at sqrt(3) and sin(Pi * x) has a root at 3.0. In the
following code, initial values were given for an interval on which the known root exists for each function.
The approximate roots and error were calculated based on the known roots to analize the behavior of the
hybrid secant method.

    int main() {

        int  maxIteration = 0;
        double root = 0.0;
        double exproot = 0.0;
        double initialGuess = 0.0;
        double initialGuess1 = 0.0;
        double prec10 = 0.0000000001;
        
        //***************************************************************************************
        //***************  root finding hybrid secant method for x^2 - 3   **********************
        //***************************************************************************************
        initialGuess = -1.54;
        initialGuess1 = 1.74;
        exproot = sqrt(3);
        maxIteration = 10;
        dmaceps(&eps, &ipow);

        printf("hybrid secant method approximation for f(x) = ( x^2 - 3 )\n\n");

        root = expSecantHybrid(fnct4, initialGuess, initialGuess1, prec10, maxIteration, exproot);



        //***************************************************************************************
        //***************  root finding hybrid secant method for sin(Pi * x) ********************
        //***************************************************************************************
        initialGuess = 2.99;
        initialGuess1 = 3.99;
        exproot = 3.0;
        maxIteration = 10;
        dmaceps(&eps, &ipow);

        printf("hybrid secant method approximation for f(x) = sin(Pi * x)\n\n");

        root = expSecantHybrid(fnct6, initialGuess, initialGuess1, prec10, maxIteration, exproot); 
    }
        
Output from the lines above:

    hybrid secant method approximation for f(x) = ( x^2 - 3 )

    tolerance =  1.000e-10
    Initial values = -1.540000 and 1.740000
    expected root = 1.732050807569

    i       | root secant           | e absolute    | e relative
    --------------------------------------------------------------------------------------------
    1       | 1.60200000e+00        | 1.301e-01     | 7.508e-02
    2       | 1.73174147e+00        | 3.093e-04     | 1.786e-04



    tolerance =  1.000e-10
    Initial values = -1.540000 and 1.740000
    expected root = 1.732050807569

    i       | root secant           | e absolute    | e relative
    --------------------------------------------------------------------------------------------
    1       | 1.60200000e+00        | 1.301e-01     | 7.508e-02
    2       | 1.73174147e+00        | 3.093e-04     | 1.786e-04
    3       | 1.73206287e+00        | 1.207e-05     | 6.967e-06
    4       | 1.73205081e+00        | 1.078e-09     | 6.222e-10
    5       | 1.73205081e+00        | 3.775e-15     | 2.179e-15



    expected root = 1.732050807569

    j       | root hybrid secant    | e absolute    | e relative
    --------------------------------------------------------------------------------------------
    1       | 1.73205081e+00        | 3.775e-15     | 2.179e-15




    hybrid secant method approximation for f(x) = sin(Pi * x)

    tolerance =  1.000e-10
    Initial values = 2.990000 and 3.990000
    expected root = 3.000000000000

    i       | root secant           | e absolute    | e relative
    --------------------------------------------------------------------------------------------
    1       | 3.49000000e+00        | 4.900e-01     | 1.633e-01
    2       | 4.00622296e+00        | 1.006e+00     | 3.354e-01



    max itterations = 3, for tollerence = 1.000e-01
    Lower initial value = 2.990, Upper initial value = 3.990
    expected root = 3.000000000000

    i       | root bisection        | e absolute    | e relative
    --------------------------------------------------------------------------------------------
    1       | 3.49000000e+00        | 4.900e-01     | 1.633e-01
    2       | 3.24000000e+00        | 2.400e-01     | 8.000e-02
    3       | 3.11500000e+00        | 1.150e-01     | 3.833e-02



    expected root = 3.000000000000

    j       | root hybrid secant    | e absolute    | e relative
    --------------------------------------------------------------------------------------------
    1       | 3.11500000e+00        | 1.150e-01     | 3.833e-02




    tolerance =  1.000e-10
    Initial values = 2.990000 and 3.115000
    expected root = 3.000000000000

    i       | root secant           | e absolute    | e relative
    --------------------------------------------------------------------------------------------
    1       | 3.00020133e+00        | 2.013e-04     | 6.711e-05
    2       | 2.99999554e+00        | 4.455e-06     | 1.485e-06



    tolerance =  1.000e-10
    Initial values = 2.990000 and 3.115000
    expected root = 3.000000000000

    i       | root secant           | e absolute    | e relative
    --------------------------------------------------------------------------------------------
    1       | 3.00020133e+00        | 2.013e-04     | 6.711e-05
    2       | 2.99999554e+00        | 4.455e-06     | 1.485e-06
    3       | 3.00000000e+00        | 2.909e-13     | 9.696e-14



    expected root = 3.000000000000

    j       | root hybrid secant    | e absolute    | e relative
    --------------------------------------------------------------------------------------------
    2       | 3.00000000e+00        | 2.909e-13     | 9.696e-14

The result in both cases is convergence to an approximation of a bracketed root for the defined functions f(x).
In each case the hybrid routine starts with two iterations of the secant method. If the value from the first two
iterations of the secant method do not fall within the interval specified, then bisection is implimented to narrow
the interval by an error of about 10^(-1). Another two iterations of the secant method are done and if the result falls
within the narrowed interval then the secant method is used to finish the approximation to an error of 10^(-10). Each
stage of the hybrid secant method is displayed in the data above, this includes the different iterations for secant
and bisection methods.

**Implementation/Code:** The following is the code for expSecantHybrid()

    double expSecantHybrid(double(*f)(double), double a, double b, double tol, int maxItr, double exproot) {
        int i = 0, j = 0;
        double c = 0.0;
        double Fxc = 1.0;
        double Fxa = f(a);
        double Fxb = f(b);
        double root = 0.0;
        double eabsolute = 0.0;
        double erelative = 0.0;
        double initialGuess = 0.0;
        double prec1 = 0.1;
        int maxIteration = 0;
        //double temp = 0.0;

        eabsolute = 10.0 * tol;

        while ((eabsolute > tol) && maxItr > 0) {

            maxItr--;
            j++;

            maxIteration = 2;

            root = expsecant(f, a, b, tol, maxIteration, exproot);

            if (root >= a && root <= b) {
                maxIteration = 10;

                root = expsecant(f, a, b, tol, maxIteration, exproot);

                printf("expected root = %.12lf\n\n", exproot);
                printf("j\t| root hybrid secant\t| e absolute\t| e relative\n");
                printf("--------------------------------------------------------------------------------------------\n");
                eabsolute = eabs(root, exproot);
                erelative = erel(root, exproot);
                printf("%d\t| %.8e\t| %.3e\t| %.3e\n", j, root, eabsolute, erelative);
                printf("\n\n\n\n");
                break;
            }
            else {

                maxIteration = bisMaxItr(a, b, prec1);

                printf("max itterations = %d, for tollerence = %.3e\n", maxIteration, prec1);
                printf("Lower initial value = %.3lf, Upper initial value = %.3lf\n", a, b);
                printf("expected root = %.12lf\n\n", exproot);
                printf("i\t| root bisection\t| e absolute\t| e relative\n");
                printf("--------------------------------------------------------------------------------------------\n");

                if ((Fxa * Fxb) < 0.0) {
                    i = 0;
                    while (maxIteration > 0) {

                        maxIteration--;
                        i++;

                        c = (a + b) / 2.0;

                        Fxc = f(c);

                        if ((Fxa * Fxc) < 0.0) {
                            b = c;
                            Fxb = f(b);
                        }
                        else if ((Fxa * Fxc) > 0.0) {
                            a = c;
                            Fxa = f(a);
                        }
                        else {
                            eabsolute = eabs(c, exproot);
                            erelative = erel(c, exproot);
                            printf("%d\t| %.8e\t| %.3e\t| %.3e\n", i, c, eabsolute, erelative);
                            break;
                        }
                        eabsolute = eabs(c, exproot);
                        erelative = erel(c, exproot);
                        printf("%d\t| %.8e\t| %.3e\t| %.3e\n", i, c, eabsolute, erelative);
                    }

                    root = c;

                }
                else if ((Fxa * Fxb) == 0.0) {

                    if (Fxa == 0) {
                        root = a;
                        eabsolute = eabs(a, exproot);
                        erelative = erel(a, exproot);
                        printf("%d\t| %.8e\t| %.3e\t| %.3e\n", i, a, eabsolute, erelative);
                    }
                    if (Fxb == 0) {
                        root = b;
                        eabsolute = eabs(b, exproot);
                        erelative = erel(b, exproot);
                        printf("%d\t| %.8e\t| %.3e\t| %.3e\n", i, b, eabsolute, erelative);
                    }

                }
                else {

                    printf("\n\nThere is no root or an even number of roots between the upper and lower initial values.");
                    root = 0.0;
                }

                printf("\n\n\n");

            }


            printf("expected root = %.12lf\n\n", exproot);
            printf("j\t| root hybrid secant\t| e absolute\t| e relative\n");
            printf("--------------------------------------------------------------------------------------------\n");
            eabsolute = eabs(root, exproot);
            erelative = erel(root, exproot);
            printf("%d\t| %.8e\t| %.3e\t| %.3e\n", j, root, eabsolute, erelative);
            printf("\n\n\n\n");
        }


        return root;
    }

**Last Modified:** September/2018
