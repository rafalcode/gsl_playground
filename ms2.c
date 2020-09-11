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
    CHKNARGS(argc, 2);
    gsl_multiset * c;
    size_t i, N=(size_t)atoi(argv[1]), K=(size_t)atoi(argv[2]);

    if(N<K) {
        printf("Your K is bigger than your N: Sorry but that's not allowed, no matter how interesting it could be.\n"); 
        exit(EXIT_FAILURE);
    }

    printf ("Listing of the multisets of size %zu, chosen from a pool-with-replacement of %zu.\n", K, N);
    c = gsl_multiset_calloc (N, K);
    i=0;
    printf("{ "); 
    do {
        printf("{"); 
        /*  the next is a convenience-yet-inflexible function, chucks out each multiset straight out */
        gsl_multiset_fprintf (stdout, c, "%zu, ");
        printf("}, "); 
        i++;
    } while (gsl_multiset_next(c) == GSL_SUCCESS);
    printf(" };\n"); 
    printf("Total number of multisets = %zu\n", i); 

    gsl_multiset_free (c);

    return 0;
}
