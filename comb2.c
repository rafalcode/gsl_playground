/* Let's generate all possible combinaions of a 10.7 Examples
   The example program below prints all subsets of the set {0, 1, 2, 3} ordered by size. Subsets
   of the same size are ordered lexicographically. */
#include <stdio.h>
#include <gsl/gsl_combination.h>

#define CHARRSZ 4

int main (void)
{
    gsl_combination * c;
    size_t i, k;
    char ch[CHARRSZ]={'A', 'C', 'G', 'T'};

    printf ("All combinations:\n");
    c = gsl_combination_calloc(CHARRSZ, CHARRSZ);
    gsl_combination_init_first(c); /*  not really necessary */
    do {
        for (i = 0; i < CHARRSZ; i++) {
            k=gsl_combination_get(c, i);
            printf("%c", ch[k]);
        }
        printf("\n"); 
    } while (gsl_combination_next (c) == GSL_SUCCESS);

    gsl_combination_free (c);

    return 0;
}
