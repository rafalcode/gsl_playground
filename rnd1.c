/* thi sis from the GSL manual examples. Though not mentioend, you can indeed set a seed, albeit
 * during runtime, in unix fashion, as in 
      $ GSL_RNG_SEED=123 ./a.out */
#include <stdio.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>

int main (void)
{
    gsl_rng * r;

    int i, n = 10;
    double mu = 3.0;

    /* create a generator chosen by the environment variable GSL_RNG_TYPE */
    gsl_rng_env_setup();
    /* let's get going then */
    const gsl_rng_type *T = gsl_rng_default;
    r = gsl_rng_alloc(T);

    /* print n random variates chosen from
       the poisson distribution with mean
       parameter mu */
    for (i = 0; i < n; i++) {
        unsigned int k = gsl_ran_poisson (r, mu);
        printf (" %u", k);
    }
    printf ("\n");

    /* let's get out of here functions */
    gsl_rng_free (r);
    return 0;
}
