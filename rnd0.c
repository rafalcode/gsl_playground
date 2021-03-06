#include <stdio.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>

int main (void)
{
    const gsl_rng_type * T;
    unsigned int ret;
    gsl_rng * r;
    int i, n = 10;
    double mu = 3.0;

    /* create a generator chosen by the environment variable GSL_RNG_TYPE */
    gsl_rng_env_setup();
    T = gsl_rng_default;
    r = gsl_rng_alloc (T);

    /* print n random variates chosen from the poisson distribution with mean parameter mu */
    for (i = 0; i < n; i++) {
        ret = gsl_ran_poisson (r, mu); // many randists return a double, but poisson returns an int.
        printf (" %u", ret);
    }
    printf ("\n");
    gsl_rng_free (r);
    return 0;
}

// output should be
// 2 5 5 2 1 0 3 4 1 1
