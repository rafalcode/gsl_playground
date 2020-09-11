#include <stdio.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>

int main (void)
{
    int i, n = 10;
    int nu = 2;
    double ret;

    /* GSL specifics, likely to be very very common */
    const gsl_rng_type *T;
    gsl_rng *r;
    /* create a generator chosen by the environment variable GSL_RNG_TYPE */
    gsl_rng_env_setup();
    T = gsl_rng_default;
    r = gsl_rng_alloc(T);

    /* print n random variates chosen from the poisson distribution with mean parameter mu */
    for (i = 0; i < n; i++) {
        ret = gsl_ran_chisq(r, (double)nu); // as yu can see degrees of freedom, while clearly an int, needs to be fed in as a double, and it returns a double too.
        printf(" %2.4f", ret);
    }
    printf ("\n");

    /* free up */
    gsl_rng_free (r);
    return 0;
}
