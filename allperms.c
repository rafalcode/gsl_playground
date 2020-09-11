/*  this is the second example from the permutations chapter in 
 *  the GSL reference manual */
//    The next example program steps forwards through all possible third order permutations, starting from the identity,
#include <stdio.h>
#include <gsl/gsl_permutation.h>

int main (void)
{
    gsl_permutation *p = gsl_permutation_alloc(4);

    gsl_permutation_init (p);

    do {
        gsl_permutation_fprintf (stdout, p, " %u");
        printf ("; ");
    } while (gsl_permutation_next(p) == GSL_SUCCESS);
    printf ("\n");

    gsl_permutation_free (p);

    return 0;
}
/* Expected output:
   Here is the output from the program,

   $ ./a.out
   0 1 2
   0 2 1
   1 0 2
   1 2 0
   2 0 1
   2 1 0
   */
