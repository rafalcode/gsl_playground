/* 10.7 Examples
   The example program below prints all subsets of the set {0, 1, 2, 3} ordered by size. Subsets
   of the same size are ordered lexicographically. */
#include <stdio.h>
#include <gsl/gsl_combination.h>

#define CHKNARGS(x, a); \
    if((x) != ((a)+1)) { \
        printf("Usage error: program requires %i argument.\n", (a)); \
        exit(EXIT_FAILURE); \
    }

int main (int argc, char *argv[])
{
    CHKNARGS(argc, 1);
    gsl_combination *c;
    size_t ct=0, n=(size_t)atoi(argv[1]);

    printf ("All pairs:\n") ;
    c = gsl_combination_calloc (n, 2);
    do {
        printf ("{");
        gsl_combination_fprintf (stdout, c, " %u");
        printf (" }\n");
        ct++;
    } while (gsl_combination_next (c) == GSL_SUCCESS);
    printf("Total number of different pairings is: %zu\n", ct);
    gsl_combination_free (c);

    return 0;
}
