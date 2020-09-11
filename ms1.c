/* 10.7 Examples
   The example program below prints all subsets of the set {0, 1, 2, 3} ordered by size. Subsets
   of the same size are ordered lexicographically. */
#include <stdio.h>
#include <gsl/gsl_multiset.h>

#define CHKNARGS(x, a); \
    if((x) != ((a)+1)) { \
        printf("Usage error: program requires %i argument.\n", (a)); \
        exit(EXIT_FAILURE); \
    }

int main (int argc, char *argv[])
{
    CHKNARGS(argc, 1);
    gsl_multiset * c;
    size_t i, n=(size_t)atoi(argv[1]);

    printf ("All subsets of {0,1,2,3} by size:\n") ;
    for (i = 0; i <= n; i++) {
        c = gsl_multiset_calloc (n, i);
        do {
            /*      In versions of the GNU C library prior to the ISO C99 standard, the type modiﬁer Z was used instead. */
            printf ("{");
            /*  the next is a convenience-yet-inflexible function, chucks out each multiset straight out */
            gsl_multiset_fprintf (stdout, c, " %u");
            printf (" }\n");
        } while (gsl_multiset_next (c) == GSL_SUCCESS);
        gsl_multiset_free (c);
    }

    return 0;
}
