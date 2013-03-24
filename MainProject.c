#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

FILE* logfile; //LogFile Part
void file (void)
{
    logfile = fopen("log.txt", "w");
    fprintf(logfile, "Karan Shukla 999593293\nRachel Baker\nPolly Lin 999639299\nYung-Hsiang Chih 999751148"); //Student Numbers
    fclose(logfile);
    return;
}

char NumToColour(int num){ //Board Generator Section
char colour;
if (num==1)    colour = 'r';
else if (num==2)    colour = 'y';
else if (num==3)    colour = 'b';
else if (num==4)    colour = 'g';
return colour;
}

void compileBoard (char arr[][36], int ROW, int COL){	//editted Rachel's original one

int i, j;
srand ((unsigned)time(NULL));
for (i=0;i<ROW;i++){
    for (j=0;j<COL;j++){
        arr[i][j]=NumToColour(rand()%4+1);
    }
}
return;
}

void printBoard (char arr[][36], int ROW, int COL){

int col, row;   //row and col are inverted because of some weird logic going on here

for (col=0; col<COL+1; col++){
    for (row=-1; row<ROW; row++){
        if (row==-1){        //for y-coordinates
            if (col==COL)       //for the bottom left corner space
                printf ("    ");
            else if ((COL-col)>10)  //for coordinates bigger than 10
                printf ("%3c ", ((COL-col) + '9' -3));
            else
            printf ("%3d ", COL-col-1); //inverting coordinates from column number in array
        }
        else if (col==COL){     //for the x-coorfinates
            if (row>9)     //for coordinates bigger than 10
                printf ("%c ", (row + '9'-2));
            else
            printf ("%d ", row);
        }
        else
        printf ("%c ", arr[col][row]);
    }
printf ("\n");
}
}


/* below are the functions I did I have not tested them yet and I still need to add more comments--- Rachel*/
char compileBoard(int rows, int cols){/* this function creates an arry of characters (arr) ith the specified size. it is formatted with the colums first (x coordanite) and the rows second (y cordinate)
                                         it takes as paramers the row and colom size
                                         the character array corisponds to a color.*/
                                         //I've fixed some stuff in this function, scroll up. -Beaver
    int i,j, temp;
    char arr[col][row];
    srand ((unsigned)time(NULL));
    for(i=0;i<cols;i++){
        for(j=0;j<rows;j++){
            temp=rand()%4+1;
            arr[i][j]=NumToColour(temp);
            }

        }
    return arr;
}
int deleteAreaCheck(int x, int y, char arr){
    int score=0
    char given=arr[x][y];
    if(arr[x+1][y]==given ||arr[x-1][y]==given ||arr[x][y+1]==given ||arr[x][y-1]==given){
        score=deleteArea(given, x, y, arr,0);
    }
    return score;
}
int deleteArea(char given, int x, int y, char arr[][], int score){
    if(arr[x][y]==given){
        arr[x][y]='0';
        score+=1// check to see if this is the right way to calculate the score.
        score+=deleteArea(given, x+1, y, arr);
        score+=deleteArea(given, x-1, y, arr);
        score+=deleteArea(given, x, y+1, arr);
        score+=deleteArea(given, x, y-1, arr);
        return score;
    }
    else{
        return 0
    }
}

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

//These are the AI/Computer Play Functions.

int RowPick (void)
{
    srand(time(NULL)); //ensure random number
	int Rowpick = rand()%(ROW); //ROWS as defined by the function for grabbing the amount of rows
	printf("I pick row %d", Rowpick);
	return Rowpick;
}

int ColPick (void)
{
		srand(time(NULL));
		int Colpick = rand() % (COL);
		printf("I pick row %d", Colpick);
		return Colpick;
}

