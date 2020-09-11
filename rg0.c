/* thi sis from the GSL manual examples. Though not mentioend, you can indeed set a seed, albeit
 * during runtime, in unix fashion, as in 
      $ GSL_RNG_SEED=123 ./a.out */
#include <stdio.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>

#define CHKNARGS(x, a); \
    if((x) != ((a)+1)) { \
        printf("Usage error: program requires %i argument.\n", (a)); \
        exit(EXIT_FAILURE); \
    }

int main (int argc, char *argv[])
{

    CHKNARGS(argc, 1);
	int i, n=atoi(argv[1]);

	/* this seems to be the GSL wants it */
    gsl_rng_env_setup();
    const gsl_rng_type *T = gsl_rng_default;
    gsl_rng *r = gsl_rng_alloc(T);

	/* OK, time to get going */
	double *rva=malloc(n*sizeof(double)); /* random variate array */
	double tot=0;
	for(i=0;i<n;++i) {
        rva[i]= gsl_ran_ugaussian(r);
		tot += pow(rva[i],2);
	}

	for(i=0;i<n;++i) 
        printf("%4.4f ", rva[i]);
    printf ("tot squared was %4.4f\n", tot);

    gsl_rng_free (r);
	free(rva);
    return 0;
}
