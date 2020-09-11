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
    size_t i, n=(size_t)atoi(argv[1]);

    c = gsl_permutation_calloc (n);

    printf ("All permutations of {0,1,2,3} by size:\n") ;

    do {
        /* In versions of the GNU C library prior to the ISO C99 standard, the type modiﬁer Z was used instead. */
        printf ("{");
        /*  the next is a convenience-yet-inflexible function, chucks out each permutation straight out */
        gsl_permutation_fprintf (stdout, c, " %u");
        printf (" }\n");
    } while (gsl_permutation_next (c) == GSL_SUCCESS);

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
