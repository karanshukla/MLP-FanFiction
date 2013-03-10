#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

FILE* logfile;
void file (void)
{
    logfile = fopen("log.txt", "w");
    fprintf(logfile, "Karan Shukla 999593293\nRachel Baker\nPolly Lin 999639299\nCindy Chih");
    fclose(logfile);
    return;
}

