/* quick go a beta function */
#include <stdio.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>

int main (void)
{
    gsl_rng * r;

    int i, n = 10;
    double k;
    /* scenario 1: a parabola, quasi normal distribution */
    // double a = 2.0, b=2.0;
    /* scenario 1: the opposite of the parabola */
    double a = 0.5, b=0.5;

    /* create a generator chosen by the environment variable GSL_RNG_TYPE */
    gsl_rng_env_setup();
    /* let's get going then */
    const gsl_rng_type *T = gsl_rng_default;
    r = gsl_rng_alloc(T);

    /* print n random variates chosen from
       the poisson distribution with mean
       parameter mu */
    for (i = 0; i < n; i++) {
        k = gsl_ran_beta(r, a, b);
        printf (" %4.6f", k);
    }
    printf ("\n");

    /* let's get out of here functions */
    gsl_rng_free (r);
    return 0;
}
