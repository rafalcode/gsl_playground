/* I do it my own way */
#include <stdio.h>
#include <stdlib.h>

#define CHKNARGS(x, a); \
    if((x) != ((a)+1)) { \
        printf("Usage error: program requires %i argument.\n", (a)); \
        exit(EXIT_FAILURE); \
    }

int main (int argc, char *argv[])
{
    CHKNARGS(argc, 1);
    size_t i, j, ct=0, n=(size_t)atoi(argv[1]);

    for(i=0;i<n-1;++i) {
        for(j=i+1;j<n;++j) {
            printf("{%zu,%zu}\n",i,j);
            ct++;
        }
    }
    printf("# Pairings = %zu\n", ct); 

    return 0;
}
