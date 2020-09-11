/*
  27.7 Examples

   The following program demonstrates the use of the interpolation and
   spline functions. It computes a cubic spline interpolation of the
   10-point dataset (x_i, y_i) where x_i = i + \sin(i)/2 and y_i = i +
   \cos(i^2) for i = 0 \dots 9.

   The output is designed to be used with the GNU plotutils graph program,

$ ./a.out > interp.dat
$ graph -T ps < interp.dat > interp.ps

   The result shows a smooth interpolation of the original points. The
   interpolation method can be changed simply by varying the first
   argument of gsl_spline_alloc.

*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_spline.h>

int main (void)
{
  int i;
  double xi, yi, x[10], y[10];

  printf ("#m=0,S=2\n");

  for (i = 0; i < 10; i++) {
      x[i] = i + 0.5 * sin (i);
      y[i] = i + cos (i * i);
      printf ("%g %g\n", x[i], y[i]);
    }

  printf ("#m=1,S=0\n");

  {
    gsl_interp_accel *acc
      = gsl_interp_accel_alloc ();
    gsl_spline *spline
      = gsl_spline_alloc (gsl_interp_cspline, 10);

    gsl_spline_init (spline, x, y, 10);

    for (xi = x[0]; xi < x[9]; xi += 0.01)
      {
        yi = gsl_spline_eval (spline, xi, acc);
        printf ("%g %g\n", xi, yi);
      }
    gsl_spline_free (spline);
    gsl_interp_accel_free (acc);
  }
  return 0;
}
