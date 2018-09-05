# Math 4610 Fundamentals of Computational Mathematics
**Homework 1, Solution 6.**

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
  
![](Integrate.pdf)
**Figure 1**
