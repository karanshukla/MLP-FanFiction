#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

//FILE* logfile; //LogFile Part
//arr [rownum][colsnum]

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
	char board;
	scanf ("%c", &board);
	if (board == Y) { // this part is from the bottom
		//file(); We'll add this later!
		int ROW = RowDefine(ROW); 	//don't think you need to send an integer over... Or maybe use pointers
		printf("\nYou have entered %d rows.\n", ROW);
		int COL = ColDefine(COL);
		printf("You have entered %d columns,\n", COL)
	
	} else {
		FILE *input; //based off of the input file specification in instructions
		char filename[13];
		printf("\n\n You have decided to use an existing board. Please enter a filename (xxxxxxxx.yyy): ");
		scanf("%s", filename);
		if ((input = fopen(filename, "r")) == NULL) {
		printf("\n Filename invalid");
		return -1;
	}
	
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

int coordSelect (x,y) // will continue to ask user for coord until it gets one within board and playable
{
	do {
		printf ("Please enter a set of coordinates that is within the grid and adjacent to at least one identical cart (row, column):",x,y);
		scanf ("%d, %d", &x, &y);
	} while (x < 0 || x > 36 || y <0 || y > 36); // will also need to check whether adjacent to one other cart!
	return (x,y);	
}

void file (void)
{
    logfile = fopen("log.txt", "w");
    fprintf(logfile, "Karan Shukla 999593293\nRachel Baker\nPolly Lin 999639299\nYung-Hsiang Chih 999751148"); //Student Numbers
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

void compileBoard (char arr[][36], int ROW, int COL){

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

for (col=0; col<=ROW; col++){
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
        else{
		if (arr[col][row]==0)
			printf("  ");
        else
        printf ("%c ", arr[col][row]);}
    }
printf ("\n");
}
return;
}

void dropDown(char arr[][36], int ROW, int COL){
int i, j, marker, zero, test;

for (j=0;j<COL;j++){	//let the reign of terror begin!

for (i=(ROW-1), zero=0, marker=0;i>=0;i--){

if (arr[i][j]==0){
	if (zero==0){
		marker=i;
		}
	zero++;
	}	//end marking the places of spaces

//printf ("column %d: zero is %d, marker is %d\n", j, zero, marker);
	
}	//end of down to up sweep

if (zero>0){	//once upon a time...when there are spaces in the middle of arrays...
//	printf("I'm gonna start dropping dat bass.\n");
	for (test=(marker-zero);test>=0;test--,marker--){
        arr[marker][j]=arr[test][j]; //replace spaces with numbers from above
        arr[test][j]=0;    //replace numbers from above with 0
	}	//end bass dropping
}	//
}	//end of left to right sweep
return;}

void shrinkSideways(char arr[][36], int ROW, int *COL){
int i, j, cave, marker=0,test;

for (j=0, cave=0;j<*COL;j++){
if (arr[ROW-1][j]==0){
	if (cave==0)
		marker=j;
	cave++;
	}
}	//end looking for caves

for (test=(marker+cave);test<*COL;test++,marker++){
	for (i=0;i<ROW;i++){
		arr[i][marker]=arr[i][test];
	}
}	//end shrinking the damn thing

*COL-=cave;	//DIE!!!!!
return;}

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

//These are the AI/Computer Play Functions.

int RowPick (int row)
{
    srand(time(NULL)); //ensure random number
	int Rowpick = rand()%(ROW); //ROWS as defined by the function for grabbing the amount of rows
	printf("I pick row %d", Rowpick);
	return Rowpick;
}

int ColPick (int col)
{
		srand(time(NULL));
		int Colpick = rand() % (COL);
		printf("I pick row %d", Colpick);
		return Colpick;
}

