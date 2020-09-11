/* From the GSL manual, using "view" to grab the columns of a matrix */
#include <math.h>
#include <stdio.h>
#include <gsl/gsl_matrix.h>
// #include <gsl/gsl_blas.h>
#include <goto/cblas.h>

int main (void)
{
    size_t i, j;
    double d;

    gsl_matrix *m = gsl_matrix_alloc (10, 10);
    gsl_vector_view columnsview;

    for (i = 0; i < 10; i++)
        for (j = 0; j < 10; j++)
            gsl_matrix_set (m, i, j, sin (i) + cos (j));

    for (j = 0; j < 10; j++) {
        columnsview = gsl_matrix_column (m, j);
        d = gsl_blas_dnrm2 (&columnsview.vector);
        printf ("matrix column %zu, norm = %g\n", j, d);
    }

    gsl_matrix_free (m);
    return 0;
}
