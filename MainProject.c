#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

FILE* logfile;
void file (void)
{
    logfile = fopen("log.txt", "w");
    fprintf(logfile, "Karan Shukla 999593293\nRachel Baker\nPolly Lin 999639299\nYung-Hsiang Chih 999751148");
    fclose(logfile);
    return;
}

char NumToColour(int num){
char colour;
if (num==1)    colour = 'r';
else if (num==2)    colour = 'y';
else if (num==3)    colour = 'b';
else if (num==4)    colour = 'g';
return colour;
}

void printBoard(){

srand((unsigned)time(NULL));

int col, row, A[ROW+1][COL+1];

for (col=0; col<COL+1; col++){
    for (row=0; row<ROW+1; row++){
        if (row==0){
            if (col==COL)
                printf ("    ");
            else if ((COL-col)>10)
                printf ("%3c ", ((COL-col) + '9' -3));
            else
            printf ("%3d ", COL-col-1);
        }
        else if (col==COL){
            if (row>10)
                printf ("%c ", (row + '9'-3));
            else
            printf ("%d ", row-1);
        }
        else {A[row][col] = rand()%4+1;
        printf ("%c ", NumToColour(A[row][col]));
        }
    }
printf ("\n");
}
return;
}
