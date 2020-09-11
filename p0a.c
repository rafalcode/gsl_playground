/*   Very simple permu: 
 *   The next example program steps forwards through all possible third order permutations,
     starting from the identity, */
#include <stdio.h>
#include <gsl/gsl_permutation.h>

void saywhatwelldo(char *exename, unsigned syasz)
{
    printf("Program %s will print all permutations of a symbol size %u.\n", exename, syasz);
    printf("The idea of such a permutation is that each symbol is allotted a space, but the relative position of that\n");
    printf("space is arbitrary, i.e. could be any, which gives rise to a factorial number of possible sequences that\n");
    printf("may be reported in full.\n");
    printf("The idea that there may be more or less spaces than the number of symbols, in which we'd be talking about\n");
    printf("Combinations, rather than permutations is not possible here because the number of symbols and spaces are bound together.\n");
    return;
}

int main(int argc, char *argv[])
{
    if(argc!=2) {
        printf("Error. Pls supply 1 integer argument: size of symbol alphabet.\n");
        exit(EXIT_FAILURE);
    }
    unsigned syasz=atoi(argv[1]); /* size of the symbol alphabet: how many different symbols? */
    unsigned ct =0;
    saywhatwelldo(argv[0], syasz);

    /* let's pretend we have an alphabet */
    char *carr=malloc(syasz*sizeof(char));
    carr[0]='A';
    int i;
    for(i=1;i<syasz;++i) 
        carr[i]=carr[i-1]+1;

    /* Let's declare our gslpermu and also allocate it */
    gsl_permutation *p = gsl_permutation_alloc(syasz);
    size_t *pptr = NULL;

    /* Now this also needs initialization:
     * the third stage in the initialization, which presumable sets it to the so-called identity permutation
     * THisis basic ordered by number value (also called lexicographic ordering) starting with zero */
    gsl_permutation_init(p);

    /* the prescribed style is to use a "nexting" function to run through all of them */
    do {
        pptr = gsl_permutation_data(p);
        for(i=0;i<syasz;++i) 
            printf((i!=syasz-1)? "%c ": "%c\n", carr[*(pptr+i)]);
        ct++;
    } while (gsl_permutation_next(p) == GSL_SUCCESS);
    printf("There was a total of %u permutations in this run.\n", ct); 

    free(carr);
    gsl_permutation_free (p);
    return 0;
}
