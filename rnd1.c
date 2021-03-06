/* another example from the GSL ref man, a 2D random walk */
#include <stdio.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>

int main (void)
{
    unsigned int k;
    double x=0, y=0, dx, dy;
    int i, n=12;

    /* GSL specifics, likely to be very very common */
    const gsl_rng_type *T;
    gsl_rng *r;

    /* create a generator chosen by the environment variable GSL_RNG_TYPE */
    gsl_rng_env_setup();
    T = gsl_rng_default;
    r = gsl_rng_alloc(T);

    /* print n random variates chosen from the poisson distribution with mean parameter mu */
    for (i = 0; i < n; i++) {
        gsl_ran_dir_2d(r, &dx, &dy); // unlike the randist poisson, this does not return anything.
        x += dx;
        y += dy;
        printf("%g %g\n", x, y);
    }

    /* free up */
    gsl_rng_free (r);
    return 0;
}

// output should be
// 2 5 5 2 1 0 3 4 1 1
