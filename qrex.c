/* GSL from the examples */
#include <stdio.h>
#include <gsl/gsl_qrng.h>

int main (void)
{
    int i;
    gsl_qrng *q = gsl_qrng_alloc(gsl_qrng_sobol, 2);

    double v[2];
    for (i = 0; i < 1024; i++) {
        gsl_qrng_get (q, v);
        printf ("%.5f %.5f\n", v[0], v[1]);
    }
    gsl_qrng_free (q);
    return 0;
}

/* Here is the output from the program,

   $ ./a.out
   0.50000 0.50000
   0.75000 0.25000
   0.25000 0.75000
   0.37500 0.37500
   0.87500 0.87500
   0.62500 0.12500
   0.12500 0.62500
   ....  */
