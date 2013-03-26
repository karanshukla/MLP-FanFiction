#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

//FILE* logfile; //LogFile Part

int main (void) //heres a test main function just so we can get this bad boy compiling
{
	char arr[36][36]={0};
	int ROW,COL;
	
	printf("\nWelcome to our APS106 Project. Let's play a game of checkout!\n\nPress enter to continue, anything else to quit");
	char choice = getchar();
	if (choice != '\n')
		return -2; //error code for Program Termination
		
	//Asking if user wants to create own board, or use existing - may need editing? - Polly 
	printf ("Would you like to create your own checkout board (Y/N)", board)
	scanf ("%d", &board);
	if (board = Y) {
			//file(); We'll add this later!
		int ROW = RowDefine(ROW); 	//don't think you need to send an integer over... Or maybe use pointers
		printf("\nYou have entered %d rows.\n", ROW);
		int COL = ColDefine(COL);
		printf("You have entered %d columns,\n", COL)
		//file(); We'll add this later!
	
	} else {
		FILE *input; //based off of the input file specification in instructions
		char filename[13];
		printf("\n\n You have decided to use an existing board. Please enter a filename (xxxxxxxx.yyy): ");
		scanf("%s", filename);
		if ((input = fopen(filename, "r")) == NULL) {
		printf("\n Filename invalid");
		return -1;
	}

	//file(); We'll add this later!
	int ROW = RowDefine(ROW); 	//don't think you need to send an integer over... Or maybe use pointers
	printf("\nYou have entered %d rows.\n", ROW);
	int COL = ColDefine(COL);
	//file(); We'll add this later!
	
	compileBoard (arr, ROW, COL);
	
	while (searchFunction){		//let searchFunction return true or false (1 or 0)
	system(cls);	//I think this is to wipe the last board off the screen right? I think it just makes sure that the grid stays in the same place - Polly 
	printfBoard(arr, ROW, COL);
	
	coordSelect (x, y); // asks the user to pick coordinates
	

	}

	
	return 0;
			
}
	
	int RowDefine (int r)
{
	r = -1;
		do
		{
			printf("Enter the number of rows you'd like. Note that this program will live forever until you do!:");
			scanf("%d", &r);
		}
		while (r < 1 || r > 36);	//need at least 1-36
	return r;
}

int ColDefine (int c)
{
	c = -1;
	do
		{
			printf("Enter the number of columns you'd like. Note that this program will live forever until you do!:");
			scanf("%d", &c);
		}
		while (c < 1 || c > 36);	//again, 1-36
		return c;
}

int coordSelect (x,y) 
{
	printf ("Please enter a set of coordinates that is adjacent to at least one other same cart (row, column):",x,y);
	
	
}
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

for (col=0; col<ROW+1; col++){
    for (row=-1; row<COL; row++){
        if (row==-1){        //for y-coordinates
            if (col==ROW)       //for the bottom left corner space
                printf ("    ");
            else if ((ROW-col)>10)  //for coordinates bigger than 10
                printf ("%3c ", ((ROW-col) + '9' -3));
            else
            printf ("%3d ", ROW-col-1); //inverting coordinates from column number in array
        }
        else if (col==ROW){     //for the x-coorfinates
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

