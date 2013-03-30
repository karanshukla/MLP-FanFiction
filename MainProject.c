#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

//arr [rownum][colsnum]

//functions

FILE*logfile; //Global Pointer
logfile = fopen("log.txt", "w");
    fprintf(logfile, "Karan Shukla 999593293\nRachel Baker\nPolly Lin 999639299\nYung-Hsiang Chih 999751148"); //Student Numbers
char NumToColour(int num);
void compileBoard (char arr[][36], int ROW, int COL);
void printBoard (char arr[][36], int ROW, int COL);
void dropDown(char arr[][36], int ROW, int COL);
void shrinkSideways(char arr[][36], int ROW, int *COL); //What are these doing here? Are they just initialising something?

int main (void) //MAIN!
{
	char arr[36][36]={0};
	int ROW,COL;
	
	printf("\nWelcome to our APS106 Project. Let's play a game of checkout!\n\nPress enter to continue, anything else to quit");
	char choice = getchar(); //menu choice
	if (choice != '\n')
		return -2; //error code for Program Termination
		
	//Asking if user wants to create own board I did it! return values are really random though.
	printf ("\nType '1' to start a new game, type '2' to load an existing file. Anything else to exit.");
	char board;
	scanf ("%c", &board);
	if (board == '1') { // this part is from the bottom
		//file(); We'll add this later!
		int ROW = RowDefine(ROW); 	//don't think you need to send an integer over... Or maybe use pointers
		printf("\nYou have entered %d rows.\n", ROW);
		int COL = ColDefine(COL);
		printf("You have entered %d columns,\n", COL);	
	
	} else if (board == '2'){
		FileBoard(void); //look below for this function
	}

	else 
		return -2;
	
	compileBoard (arr, ROW, COL);
	
	while (SearchMove) //I think Rachel already made a function for this?
	system("cls");	//I think this is to wipe the last board off the screen right? I think it just makes sure that the grid stays in the same place - Polly 
	printfBoard(arr, ROW, COL); //unfortunately the system("cls") will only work in WinBlows
	coordSelect(void); // asks the user to pick coordinates
	
	checkCoord(void);//checks if the coordinate the user picks is valid and then changes them to zero. still in the works! -Polly 

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

int coordSelect (void) // will continue to ask user for coord until it gets one within board and playable
{
	int x, y;
	do {
		printf ("Please enter a set of coordinates that is within the grid and adjacent to at least one identical cart (row, column):",x,y);
		scanf ("%d, %d", &x, &y);
		fprintf(logfile,"%d, %d", &x, &y);
	} while (x < 0 || x > 36 || y <0 || y > 36); // will also need to check whether adjacent to one other cart!
	return (x,y);	
}

void checkCoord (x, y, board, colour_of_user_chosen_cell, ROW, COL ) { // I'm still working on this function - Polly
    if (board[x+1][y] == chosen_colour && (x+1) <= ROW) {
    	board[x+1][y] = 0;
    	checkCoord(x+1, y, board, colour_of_user_chosen_cell);
    }
    
    if (board[x-1][y] == chosen_colour && (x-1) <= ROW && (x-1) >= o) {
    	board [x-1][y] = 0;
    	checkCoord(x-1, y, board, colour_of_user_chosen_cell);
    }
    
    if (board[x][y+1] == chosen_colour && (y+1) <= COL) {
    	board [x][y+1] = 0;
    	checkCoord(x, y+1, board, colour_of_user_chosen_cell);
    }
    
    if (board[x][y-1] == chosen_colour && (y-1) <= COL && (y-1) >= 0) {
    	board [x][y-1] = 0;
    	checkCoord(x, y-1, board, colour_of_user_chosen_cell);
    }
    
    board[x][y]=0;
} 

void file (void) //may be deleted in favour of having a global log file
{
    FILE*logfile;
    logfile = fopen("log.txt", "w");
    fprintf(logfile, "Karan Shukla 999593293\nRachel Baker\nPolly Lin 999639299\nYung-Hsiang Chih 999751148"); //Student Numbers
    fclose(logfile);
    return;
}

//this function takes random int's 1-4 and convert them to char's
char NumToColour(int num){
char colour;
if (num==1)    colour = 'r';
else if (num==2)    colour = 'y';
else if (num==3)    colour = 'b';
else if (num==4)    colour = 'g';
return colour;
}

//this function randomly generates board according to user defined size
void compileBoard (char arr[][36], int ROW, int COL){

int i, j;
srand ((unsigned)time(NULL));
for (i=0;i<ROW;i++){
    for (j=0;j<COL;j++){
        arr[i][j]=NumToColour(rand()%4+1); //NumToColour sends back chars to be written into array
        fprintf(logfile, "%c", array[i][j]);
    }
}
return;
}

void printBoard (char arr[][36], int ROW, int COL){ //most of the code is writing coordinates

int col, row;   //row and col are inverted because of some weird logic going on here

for (col=0; col<=ROW; col++){
    for (row=-1; row<COL; row++){
        if (row==-1){        //for y-coordinates
            if (col==ROW)       //for the bottom left corner space
                printf ("    ");
            else if ((ROW-col)>10)  //for coordinates bigger than 10, writes alphabet coordinates
                printf ("%3c ", ((ROW-col) + '9' -3));
            else
            printf ("%3d ", ROW-col-1); //y-number coordinates here
        }
        else if (col==ROW){     //for the x-coorfinates
            if (row>9)     //for coordinates bigger than 10, writes alphabet coordinates
                printf ("%c ", (row + '9'-2));
            else
            printf ("%d ", row);	//x-number coordinates here
        }
        else{
		if (arr[col][row]==0)
			printf("  ");	//prints spaces when encountering 0's
        else
        printf ("%c ", arr[col][row]);}		//this actually prints the board
    }
printf ("\n");
}
return;
}

//this function drops the letters down to fill the spaces, I call it dropping the bass DROP THA BASS
void dropDown(char arr[][36], int ROW, int COL){
int i, j, marker, zero, test;

for (j=0;j<COL;j++){	//"sweeps" from left to right, column by column

for (i=(ROW-1), zero=0, marker=0;i>=0;i--){	//goes from bottom to top

if (arr[i][j]==0){
	if (zero==0){
		marker=i;	//marks the first space
		}
	zero++;	//how many spaces
	}	//end marking the places of spaces
	
}	//end of down to up sweep

if (zero>0){	//once upon a time...when there are spaces in the middle of arrays...
	for (test=(marker-zero);test>=0;test--,marker--){
        arr[marker][j]=arr[test][j]; //replace spaces with numbers from above
        arr[test][j]=0;    //replace numbers from above with 0
	}	//end bass dropping
}	//
}	//end of left to right sweep
return;}

//this function collapses columns
void shrinkSideways(char arr[][36], int ROW, int *COL){
int i, j, cave, marker=0,test;

for (j=0, cave=0;j<*COL;j++){	//sweeping from left to right
if (arr[ROW-1][j]==0){	//checks bottom number of column to see if column is empty
	if (cave==0)
		marker=j;	//marks first space
	cave++;		//num of spaces
	}
}	//end looking for caves

for (test=(marker+cave);test<*COL;test++,marker++){
	for (i=0;i<ROW;i++){
		arr[i][marker]=arr[i][test];	//overwriting
	}
}	//end shrinking the damn thing

*COL-=cave;	//DIE!!!!!(shrinkage of array)
return;}

int deleteAreaCheck(int x, int y, char arr){
    int score=0;
    char given = arr[x][y];
    if(arr[x+1][y]==given ||arr[x-1][y]==given ||arr[x][y+1]==given ||arr[x][y-1]==given){
        score=deleteArea(given, x, y, arr,0);
    }
    return score;
}
int deleteArea(char given, int x, int y, char arr[][], int score){
    if(arr[x][y]==given){
        arr[x][y]='0';
        score+=1;// check to see if this is the right way to calculate the score.
        score+=deleteArea(given, x+1, y, arr);
        score+=deleteArea(given, x-1, y, arr);
        score+=deleteArea(given, x, y+1, arr);
        score+=deleteArea(given, x, y-1, arr);
        return score;
    }
    else{
        return 0;
    }
}

//These are the AI/Computer Play Functions.

int RowPick (int row)
{
    srand((unsigned)time(NULL)); //ensure random number
	int Rowpick = rand()%(ROW); //ROWS as defined by the function for grabbing the amount of rows
	printf("I pick row %d", Rowpick);
	return Rowpick;
}

int ColPick (int col)
{
		srand((unsigned)time(NULL));
		int Colpick = rand() % (COL);
		printf("I pick row %d", Colpick);
		return Colpick;
}

int FileBoard (void) //this will ready the numbers/characters off the file
{
	FILE *input; //based off of the input file specification in instructions
	char filename[13];
	printf("\n\n You have decided to use an existing board. Please enter a filename (xxxxxxxx.yyy): ");
	scanf("%s", filename); //did we really want to scanf a string? Why not use a while loop and getchar?
	if ((input = fopen(filename, "r")) == NULL) {
	printf("\n Filename invalid");
	return -1;
	}
	else
	input = fopen("%s", "r", filename);
	int b;
	while (fscanf(input, "%d", &b) != EOF) //loop for getting them.
	{
		fscanf(input, "%d", &b);
		return b;
	}
}
