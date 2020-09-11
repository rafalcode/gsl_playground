/* 10.7 Examples
   The example program below prints all subsets of the set {0, 1, 2, 3} ordered by size. Subsets
   of the same size are ordered lexicographically. */
#include <stdio.h>
#include <gsl/gsl_permutation.h>

#define CHKNARGS(x, a); \
    if((x) != ((a)+1)) { \
        printf("Usage error: program requires %i argument.\n", (a)); \
        exit(EXIT_FAILURE); \
    }

int main (int argc, char *argv[])
{
    CHKNARGS(argc, 1);
    gsl_permutation * c;
    size_t i, k, n=(size_t)atoi(argv[1]);
    char charr[4]={'A','C','G','T'};

    c = gsl_permutation_calloc (n);

    printf ("All permutations of {0,1,2,3} by size:\n") ;

    do {
        for(i=0;i<n;++i) {
            k=gsl_permutation_get(c, i);
            printf("%c", charr[k]);
        }
        printf(","); 
    } while (gsl_permutation_next (c) == GSL_SUCCESS);
    printf("\n"); 

    gsl_permutation_free (c);

    return 0;
}

/* Here is the output from the program,
   $ ./a.out
   All subsets of {0,1,2,3} by size:
   { }
   { 0 }
   { 1 }
   { 2 }
   { 3 }
   { 0 1 }
   { 0 2 }
   { 0 3 }
   { 1 2 }
   { 1 3 }
   { 2 3 }
   { 0 1 2 }
   { 0 1 3 }
   { 0 2 3 }
   { 1 2 3 }
   { 0 1 2 3 }
   All 16 subsets are generated, and the subsets of each size are sorted lexicographically.
   */
