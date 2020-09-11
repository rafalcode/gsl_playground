#include <stdio.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>

int main(int argc, char *argv[])
{
    /* argument accounting: remember argc, the number of arguments, _includes_ the executable */
    if(argc != 3) {
        printf("Reading a double off the chisquared distri PDF, for a given degrees of freedom number.\n");
        printf("Two arguments required: First, an integer for degrees of freedom, and second, a double.\n");
        exit(EXIT_FAILURE);
    }

    int nu = atoi(argv[1]);
    double subj = atof(argv[2]);
    double ret;

    ret = gsl_ran_chisq_pdf(subj, (double)nu);
    printf("%2.4f\n", ret);

    return 0;
}
