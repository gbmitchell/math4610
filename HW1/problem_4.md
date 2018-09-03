# Math 4610 Fundamentals of Computational Mathematics
**Homework 1, Solution 4.**
  
Most computers have multiple core processors in some form or another. A typical C program uses only one of those
processors in a sequential way, one line after the other or series programing. It is possible to utilize more or
all of your computers processors through multiple threads or parallel programing. There is more than one way to
accomplish parallel programing, one solution is to use openMP.
  
OpenMP is an application programming interface (API) that supports parallel programming in C language on platforms
such as Windows and Linux. This solution shows how to use a simple C program with openMP to start multiple threads
and report back which thread is printing and the total number of threads running. Parallel programing makes better
use of a machines available resources and is important for use in problems that require speed with large volumes of
calculation.
  
**Implementation/Code:** The following is the code for openMP.c

    #include <stdio.h>
    
    int main() {
    
        // create and initialize variables
        int i = 0, id = 0, nthrds = 0;
        
        // begin parallel threads
        #pragma omp parallel private(id)
        {
            // all available threads execute this code
            id = omp_get_thread_num();
            printf("hellow world from thread %d\n", id);
            
            // each thread executes and waits at the barrier, when all
            // threads arrive at the barrier then each one continues.
            // if statement allows only thread 0 to print nthrds.
        #pragma omp barrier
            if (id == 0) {
                nthrds = omp_get_num_threads();
                printf("There are %d threads!", nthrds);
            }
        }
        
        // parallel threads end and series program continues
        printf("\n\n\n");
        return 0;
    }
  
Output from the lines above:
  
    hellow world from thread 0
    hellow world from thread 3
    hellow world from thread 1
    hellow world from thread 2
    There are 4 threads!
  
Each thread printed hello world along with its thread id. Parallel threads run at the same time, but one thread can be ahead or behind the other in terms of a timeline. The barrier in the code ensures that all threads have reached the barrier before proceding order each thread printed indicates value (24) is the number of binary digits that define the machine epsilon and the second is related to the
decimal version of the same value. The number of decimal digits that can be represented is roughly eight (e-08 on the
end of the second value).
  
**Last Modified:** September/2018
