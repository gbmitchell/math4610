# Math 4610 Fundamentals of Computational Mathematics
Homework 2, problem 8.

**Routine Name:**           expNewtonHybrid

**Author:** Gary Mitchell

**Language:** C. The code can be compiled using the Microsoft Visual C compiler.

For example,

    approximation.c

will produce an executable **approximation.exe** that can be executed.

**Description/Purpose:** This function will compute an approximation for a root of a defined
function f(x) given f'(x) and an initial guess for the root. The newton root finding method
uses the derivative of f(x) at the initial guess for x to obtain a tangent line. Where the
tangent line crosses the x axis is the approximation for the root. Recusivly applying the new
approximation as a guess will converge to a root.

**Input:** There are six inputs needed in this cases. A defined function f(x), a defined function
f'(x), an initial guess for the root (initialGuess), a tolerance (eps), a maximum amount of times
to itterate (maxIteration), and the expected value of the root (exproot) to calculate the error for
analizing the newton method.

**Output:** The function returns a double precision value that represents an approximation for the
root of a defined function f(x) given f'(x) and an initial guess for the root.

**Usage/Example:**

The code below uses two defined functions, f(x) = x^2 - 3 and f(x) = sin(Pi * x) as functions to find
the roots of. The derivatives of the defined functions are d/dx( x^2 - 3 ) = ( 2 * x ) and
d/dx( sin(Pi * x) ) = ( Pi * cos(Pi * x) ). We know that x^2 - 3 has a root at sqrt(3) and sin(Pi * x)
has a root at 6.0. In the following code, initial guesses were given relativly close to these known
roots and error was calculated based on the known roots to analize the behavior of the newton method.

    int main() {

        int  maxIteration = 0;
        double root = 0.0;
        double exproot = 0.0;
        double initialGuess = 0.0;
        double initialGuess1 = 0.0;
        double prec10 = 0.0000000001;
        
        //***************************************************************************************
        //***************  root finding hybrid newton method for x^2 - 3   **********************
        //***************************************************************************************
        initialGuess = -1.54;
        initialGuess1 = 1.74;
        exproot = sqrt(3);
        maxIteration = 10;

        printf("hybrid newton method approximation for f(x) = ( x^2 - 3 )\n\n");

        root = expNewtonHybrid(fnct4, fnct5, initialGuess, initialGuess1, prec10, maxIteration, exproot);



        //***************************************************************************************
        //***************  root finding hybrid newton method for sin(Pi * x) ********************
        //***************************************************************************************
        initialGuess = 2.99;
        initialGuess1 = 3.99;
        exproot = 3.0;
        maxIteration = 50;

        printf("hybrid newton method approximation for f(x) = sin(Pi * x)\n\n");

        root = expNewtonHybrid(fnct6, fnct7, initialGuess, initialGuess1, prec10, maxIteration, exproot);
    }

Output from the lines above:

    hybrid newton method approximation for f(x) = ( x^2 - 3 )

    tolerance =  1.000e-10
    Initial value = 0.100000
    expected root = 1.732050807569

    i       | root newton           | e absolute    | e relative
    --------------------------------------------------------------------------------------------
    1       | 1.50500000e+01        | 1.332e+01     | 7.689e+00



    max itterations = 5, for tollerence = 1.000e-01
    Lower initial value = -1.540, Upper initial value = 1.740
    expected root = 1.732050807569

    i       | root bisection        | e absolute    | e relative
    --------------------------------------------------------------------------------------------
    1       | 1.00000000e-01        | 1.632e+00     | 9.423e-01
    2       | 9.20000000e-01        | 8.121e-01     | 4.688e-01
    3       | 1.33000000e+00        | 4.021e-01     | 2.321e-01
    4       | 1.53500000e+00        | 1.971e-01     | 1.138e-01
    5       | 1.63750000e+00        | 9.455e-02     | 5.459e-02



    expected root = 1.732050807569

    j       | root hybrid newton    | e absolute    | e relative
    --------------------------------------------------------------------------------------------
    1       | 1.63750000e+00        | 9.455e-02     | 5.459e-02




    tolerance =  1.000e-10
    Initial value = 1.688750
    expected root = 1.732050807569

    i       | root newton           | e absolute    | e relative
    --------------------------------------------------------------------------------------------
    1       | 1.73260594e+00        | 5.551e-04     | 3.205e-04



    tolerance =  1.000e-10
    Initial value = 1.732606
    expected root = 1.732050807569

    i       | root newton           | e absolute    | e relative
    --------------------------------------------------------------------------------------------
    1       | 1.73205090e+00        | 8.893e-08     | 5.135e-08
    2       | 1.73205081e+00        | 2.442e-15     | 1.410e-15



    expected root = 1.732050807569

    j       | root hybrid newton    | e absolute    | e relative
    --------------------------------------------------------------------------------------------
    2       | 1.73205081e+00        | 2.442e-15     | 1.410e-15




    hybrid newton method approximation for f(x) = sin(Pi * x)

    tolerance =  1.000e-10
    Initial value = 3.490000
    expected root = 3.000000000000

    i       | root newton           | e absolute    | e relative
    --------------------------------------------------------------------------------------------
    1       | -6.63878481e+00       | 9.639e+00     | 3.213e+00



    max itterations = 3, for tollerence = 1.000e-01
    Lower initial value = 2.990, Upper initial value = 3.990
    expected root = 3.000000000000

    i       | root bisection        | e absolute    | e relative
    --------------------------------------------------------------------------------------------
    1       | 3.49000000e+00        | 4.900e-01     | 1.633e-01
    2       | 3.24000000e+00        | 2.400e-01     | 8.000e-02
    3       | 3.11500000e+00        | 1.150e-01     | 3.833e-02



    expected root = 3.000000000000

    j       | root hybrid newton    | e absolute    | e relative
    --------------------------------------------------------------------------------------------
    1       | 3.11500000e+00        | 1.150e-01     | 3.833e-02




    tolerance =  1.000e-10
    Initial value = 3.052500
    expected root = 3.000000000000

    i       | root newton           | e absolute    | e relative
    --------------------------------------------------------------------------------------------
    1       | 2.99951871e+00        | 4.813e-04     | 1.604e-04



    tolerance =  1.000e-10
    Initial value = 2.999519
    expected root = 3.000000000000

    i       | root newton           | e absolute    | e relative
    --------------------------------------------------------------------------------------------
    1       | 3.00000000e+00        | 3.668e-10     | 1.223e-10
    2       | 3.00000000e+00        | 4.441e-16     | 1.480e-16



    expected root = 3.000000000000

    j       | root hybrid newton    | e absolute    | e relative
    --------------------------------------------------------------------------------------------
    2       | 3.00000000e+00        | 4.441e-16     | 1.480e-16

The result in both cases is convergence to an approximation of a root for the defined functions f(x).

**Implementation/Code:** The following is the code for expNewtonHybrid()

    double expNewtonHybrid(double(*f)(double), double(*fp)(double), double a, double b, double tol, int maxItr, double exproot) {
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

        eabsolute = 10.0 * tol;

        while ((eabsolute > tol) && maxItr > 0) {

            maxItr--;
            j++;

            initialGuess = (a + b) / 2;
            maxIteration = 1;

            root = expnewton(f, fp, initialGuess, tol, maxIteration, exproot);

            if (root >= a && root <= b) {
                maxIteration = 10;
                initialGuess = root;
                root = expnewton(f, fp, initialGuess, tol, maxIteration, exproot);

                printf("expected root = %.12lf\n\n", exproot);
                printf("j\t| root hybrid newton\t| e absolute\t| e relative\n");
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
            printf("j\t| root hybrid newton\t| e absolute\t| e relative\n");
            printf("--------------------------------------------------------------------------------------------\n");
            eabsolute = eabs(root, exproot);
            erelative = erel(root, exproot);
            printf("%d\t| %.8e\t| %.3e\t| %.3e\n", j, root, eabsolute, erelative);
            printf("\n\n\n\n");
        }


        return root;
    }

**Last Modified:** September/2018
