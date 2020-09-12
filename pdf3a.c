#include <math.h>
#include <stdio.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>

int main(int argc, char *argv[])
{

    // double o1=8./27, o2=15./27, o3=4./27;
    double o1=8., o2=15., o3=4.;
    double eaa=27*0.01,eab=27*0.6156831475,ebb=27*0.3743168525;
    double c1=58.3720223474999,c2=0.429132347964348,c3=225.155268573051;
    double d1=1.05595741166983e-13,d2=0.403445707373539,d3=6.41393638206853e-50;
    int nu=2;

    double s = (pow(o1-eaa, 2)/eaa) + (pow(o2-eab,2)/eab) + (pow(o3-ebb, 2)/ebb);
    printf("s=%4.12f / c3 = %4.12f\n", s, c3); 

    double ret;

    ret = gsl_ran_chisq_pdf(s, (double)nu);
    // printf("%2.4f\n", ret);
    printf("%g %g\n", d3, ret);

    return 0;
}
