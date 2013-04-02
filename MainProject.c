#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

//arr [rownum][colsnum]

//functions

FILE*logfile; //Global Pointer
logfile = fopen("log.txt", "w");
fprintf(logfile, "Karan Shukla 999593293\nRachel Baker\nPolly Lin 999639299\nYung-Hsiang Chih 999751148"); //Student Numbers
void printBoard (char arr[][36], int ROW, int COL);
void dropDown(char arr[][36], int ROW, int COL);
void shrinkSideways(char arr[][36], int ROW, int *COL); //What are these doing here? Are they just initialising something?
void compileBoard(int rows, int cols, char array[][36]);//compiles the board
int deleteAreaCheck(int x, int y, char arr[][36]);//checks if it is a valid move returns the score from deleted area (if it returns 0 then  not a valid move
int deleteArea(char given, int x, int y, char arr[][36], int score);//gets rid of area that is not used by programn
char NumToColour(int num);//given a number it changes to a char representing a color
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

void checkCoord (x, y, board, ROW, COL ) {// I'm still working on this function - Polly
  
    if (board[x+1][y] == board[x][y] && (x+1) < COL && y < ROW[x+1] ) { // checks the grids to the left of the selected grid
    	checkCoord(x+1, y, board);
    }
    
    if (board[x-1][y] == board[x][y] && (x-1) > 0 && (x-1) >= o) { // checks the grids to the right of the selected grid
    	checkCoord(x-1, y, board);
    }
    
    if (board[x][y+1] == board[x][y] && (y+1) <= COL) { //checks the grids above the selected grid
    	checkCoord(x, y+1, board);
    }
    
    if (board[x][y-1] == board[x][y] && (y-1) <= COL && (y-1) >= 0) { // checks the grids below the selected grid
    	checkCoord(x, y-1, board);
    }
    
    board[x][y]=0;
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

char NumToColour(int num){ //this takes a number from 1 to 4 and replaces it with  a character representing a color
char colour;
if (num==1)    colour = 'r';//rech
else if (num==2)    colour = 'y';//yellow
else if (num==3)    colour = 'b';//blue
else if (num==4)    colour = 'g';//green
return colour;
}

void compileBoard(int rows, int cols, char arr[][36]){/* this function creates an arry of characters (arr) ith the specified size. it is formatted with the colums first (x coordanite) and the rows second (y cordinate)
                                         it takes as paramers the row and colom size
                                         the character array corisponds to a color.*/
    int i,j, temp;
    srand((unsigned)time(NULL));
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            temp=rand()%4+1;
            arr[i][j]=NumToColour(temp);
            }

        }
    return;
}
int deleteAreaCheck(int rows, int cols, char arr[][36]){/// this checks if it a valid move adn returns the score for the move
    int score=0;
    char given=arr[rows][cols];
    if(arr[rows+1][cols]==given || arr[rows][cols+1]==given || arr[rows-1][cols]==given || arr[rows][cols-1]==given){
        score=deleteArea(given, rows, cols, arr,0);
    }

    return score*score;
}
int deleteArea(char given, int x, int y, char arr[][36], int score){//this is a recursive function replaces same characters that are touching with a zero
//returns the number of characters deleted
    if(arr[x][y]==given){
        arr[x][y]='0'; //if the given char (the one that was selected by the user) is the same as a the new spot given then it is replaced by a zeor
        //moveing out to the right and left, up and down
        score+=deleteArea(given, x+1, y, arr, score+1); //returns a score if it runs into the same character
        score+=deleteArea(given, x-1, y, arr, score+1);
        score+=deleteArea(given, x, y+1, arr, score+1);
        score+=deleteArea(given, x, y-1, arr, score+1);
        return score;
    }
    return 0;
}
/*--- thus is Rachel Baker's print board--- keep it as a refference?
void printBoard(int rows, int cols, char arr[][36]){
    int i, j;
    for (i=0; i<rows; i++){
            printf("%-2d",rows-i-1);
            for (j=0;j<cols;j++){
                printf("%2c", arr[i][j]);
            }
        printf ("\n");
    }
    printf("\n   ");
    for(i=0;i<cols;i++){
        printf("%-2d", i);
    }
    return;
}
*/
