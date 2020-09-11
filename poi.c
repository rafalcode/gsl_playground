#include <stdio.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>

int main (int argc, char *argv[])
{
	if(argc!=3) {
		printf("%s, a poisson variate emitter, accepts mu and number-of-variates arguments\n", argv[0]);
		printf("Usage. Pls 2 supply arguments: 1) mu, a float 2) n, number of variates required.\n");
		exit(EXIT_FAILURE);
	}
    const gsl_rng_type *T;
    gsl_rng *r;

    /* create a generator chosen by the environment variable GSL_RNG_TYPE */
    gsl_rng_env_setup();

    T = gsl_rng_default;
    r = gsl_rng_alloc (T);

    /* print n random variates chosen from the poisson distribution with mean parameter mu */
    unsigned k, sum=0;
    int i, n = atoi(argv[2]);
    double mu = atof(argv[1]);
    for (i = 0; i < n; i++) {
        k = gsl_ran_poisson (r, mu);
        printf ("%u ", k);
        sum += k;
    }
    printf ("\nTot ocs: %u\n", sum);

    gsl_rng_free (r);
    return 0;
}
    /*       2 5 5 2 1 0 3 4 1 1
             The variates depend on the seed used by the generator. The seed for the default generator
             type gsl_rng_default can be changed with the GSL_RNG_SEED environment variable to
             $ GSL_RNG_SEED=123 ./a.out
             GSL_RNG_SEED=123
             4 5 6 3 3 1 4 2 5 5
             */
