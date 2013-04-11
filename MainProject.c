#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


//Function Declarations

char NumToColour(int num); //this function takes random int's 1-4 and convert them to char's
int RowDefine (); //asks for # of rows
int ColDefine ();   //asks for # of cols
void compileBoard (char arr[][36], int ROW, int COL);   //Creates Initial Board!   
void printBoard (char arr[][36],int ROW, int COL);     //Print Board
void deleteAreaCheck(int x, int y, char arr[][36]); //checks if it is a valid move returns the score from deleted area (if it returns 0 then  not a valid move
int deleteArea(char given, int x, int y, char arr[][36]);//gets rid of area that is not used by program
void dropDown(char arr[][36], int ROW, int COL);    //drops the letter down to fill empty spaces
void shrinkSideways(char arr[][36], int ROW, int *COL); //collapses empty columns to the left
void coordSelect (int *x, int *y, int ROW, int COL, char arr[][36]); // will continue to ask user for coord until it gets one within board and playable
int convertCoord (char temp); //Converts coordinates greater than 9 to A, B, C, D etc...
int movesleft(int row, int cols, char arr[][36]); //Checks if there are moves left
void computermove(int *x, int *y,int row, int cols, char arr[][36]); //AI or Computer Play
int CalculateScore (char arr[][36], int ROW, int COL); //Calculates the score

//AI Stuff may be deleted
int RowPick (int ROW); //randomly picks a row
int ColPick (int COL); //randomly picks a column

FILE*logfile; //Global Pointer (We know this is bad practice, but only a pointer!)

int main (void) //MAIN!
{
    logfile = fopen("LogFile.txt", "w");
    char arr[36][36]; //main array
    int ROW,COL;
    int *x; //Pointer for x co-ordinate
    int *y; //Pointer for y co-ordinate
    x = (int*)(malloc(1 * sizeof(int))); //declare memory for the array, very efficient!
    y = (int*)(malloc(1 * sizeof(int))); 
    int score = 0, tmpscore; //tmpscore = score accumulated for that move
    printf("\nWelcome to our APS106 Project. Let's play a game of checkout!\n\n");
    printf ("\nType '1' to start a new game, \nType '2' to load an existing file.\nType '3' to see the computer play.\nType '4' to see a stupid computer play\nAnything else to exit.\n");
        char board;
        scanf ("%c", &board);
    if (board == '1') { // this part is from the bottom
        //file(); We'll add this later!
        ROW = RowDefine();  //This one doesnt use pointers, but coordselect does! Some variety eh?
        printf("\nYou have entered %d rows.\n", ROW);
        COL = ColDefine();
        printf("You have entered %d columns,\n", COL);
        compileBoard(arr, ROW, COL);
        while (movesleft(ROW, COL, arr) == 1)
        {
            printf("\n");
            printf("\nDAMN SON YOUR SCORE IS %d\n", score);
            printf("\n");
            printBoard(arr, ROW, COL);
            coordSelect(x, y, ROW, COL, arr);
            tmpscore = CalculateScore(arr, ROW, COL);
            if(tmpscore == 0){
                printf("\nYou did not make a valid move! Try again\n");
            }
            fprintf(logfile, "%d %d\n", *x, *y);
            score += tmpscore;
            dropDown(arr, ROW, COL);
            shrinkSideways(arr, ROW, &COL);
            printf("\n\nYour score is now %d\n", score);
            printf("\nPlease wait");
            sleep(3);
            system("clear");
        }
        }
   else if(board=='2'){//use file functions--- this gest file from user
       
   }
   else if(board=='3'){//computer play
       while(movesleft(ROW,COL,arr)==1){
            
            ROW = RowDefine();  //This one doesnt use pointers, but coordselect does! Some variety eh?
            printf("\nYou have entered %d rows.\n", ROW);
            COL = ColDefine();
            printf("You have entered %d columns,\n", COL);
            compileBoard(arr, ROW, COL);
            printf("\n");
            printf("\nDAMN SON YOUR SCORE IS %d\n", score);
            printf("\n");
            printBoard(arr, ROW, COL);
            computermove(x,y,ROW,COL,arr);
            deleteAreaCheck(*x,*y,arr);
            score+=CalculateScore(arr, ROW, COL);
            dropDown(arr, ROW, COL);
            shrinkSideways(arr, ROW, &COL);
            printf("\n\nYour score is now %d\n", score);
            printf("\nPlease wait");
            sleep(3);
            system("clear");
            }
   }
   else if(board=='4'){//stupid computer play
   }
   else{
    return 0; }  //if nothing else happens, program returns this weird shit
    }


void LogFile ( ) {

FILE*logfile;
    logfile = fopen("CheckOutLineLog.txt", "w");
    fprintf (logfile, "Rachel Baker, 999 865 196\nYung-Hsiang Chih, 999 751 148\nPolly Lin, 999 639 299\nKaran Shukla, 999 593 293\n\n");//prints names to file //Print Board
    fclose (logfile);//closes logfile

return;
}

int RowDefine ()
{
    int r;
        do
        {
            printf("Enter the number of rows you'd like. Note that this program will live forever until you do!:");
            scanf("%d", &r);
        }
        while (r < 1 || r > 36);    //need at least 1-36
    return r;
}

int ColDefine ()
{
    int c;
    do
        {
            printf("Enter the number of columns you'd like. Note that this program will live forever until you do!:");
            scanf("%d", &c);
        }
        while (c < 1 || c > 36);    //again, 1-36
        return c;
}

char NumToColour(int num){ 
char colour;
if (num==1)    colour = 'r';
else if (num==2)    colour = 'y';
else if (num==3)    colour = 'b';
else if (num==4)    colour = 'g';
return colour;
}

void printBoard (char arr[][36], int ROW, int COL){ //most of the code is writing coordinates

int col, row;   //row and col are inverted because of some weird logic going on here

for (col=0; col<=ROW; col++){
    for (row=-1; row<COL; row++){
        if (row==-1){        //for y-coordinates
            if (col==ROW)       //for the bottom left corner space
                printf ("     ");
            else if ((ROW-col)>10)  //for coordinates bigger than 10, writes alphabet coordinates
                printf ("%3c  ", ((ROW-col) + '9' -3));
            else
            printf ("%3d  ", ROW-col-1); //y-number coordinates here
        }
        else if (col==ROW){     //for the x-coorfinates
            if (row>9)     //for coordinates bigger than 10, writes alphabet coordinates
                printf ("%c ", (row + '9'-2));
            else
            printf ("%d ", row);    //x-number coordinates here
        }
        else{
        if (arr[col][row]==0)
            printf("  ");   //prints spaces when encountering 0's
        else
        printf ("%c ", arr[col][row]);}     //this actually prints the board
    }
printf ("\n");
}
return;
}

//this function drops the letters down to fill the spaces, I call it dropping the bass DROP THA BASS
void dropDown(char arr[][36], int ROW, int COL){
int i, j, marker, zero, test;//marker marks the first space, zero: number of zeors/spaces to pull down, test top of the space/the start of the characters 
                                //that need to be pulled down

for (j=0;j<COL;j++){    //"sweeps" from left to right, column by column

for (i=(ROW-1), zero=0, marker=0;i>=0;i--){ //goes from bottom to top

if (arr[i][j]==0){
    if (zero==0){
        marker=i;   //marks the first space
        }
    zero++; //how many spaces
    }   //end marking the places of spaces

}   //end of down to up sweep

if (zero>0){    //once upon a time...when there are spaces in the middle of arrays...
    for (test=(marker-zero);test>=0;test--,marker--){
        arr[marker][j]=arr[test][j]; //replace spaces with numbers from above
        arr[test][j]=0;    //replace numbers from above with 0
    }   //end bass dropping
}   //
}   //end of left to right sweep
return;}

int movesleft(int row, int cols, char arr[][36]){//returns 1 if there are any moves left other wise it returns 0
    int i, j;
    for (i=0; i<row;i++) {
        for (j=0;j<cols;j++){//this goes though the array and sees if there are any charaters that are side by side and the same.
            if(arr[i][j]== arr[i+1][j] || arr[i][j]== arr[i][j+1] || arr[i][j] == arr[i-1][j] || arr[i][j]==arr[i][j-1])
                 if(arr[i][j]!=0 && arr[i][j]!='0'){
                    return 1;
                    }

    }
    }
    return 0;
}
void shrinkSideways(char arr[][36], int ROW, int *COL){
int i, j, cave, marker=0,test;//cave counts how many empty rows there are. marker: marks the first space

for (j=0, cave=0;j<*COL;j++){   //sweeping from left to right
if (arr[ROW-1][j]==0){  //checks bottom number of column to see if column is empty
    if (cave==0)
        marker=j;   //marks first space
    cave++;     //num of spaces
    }
}   //end looking for caves

for (test=(marker+cave);test<*COL;test++,marker++){
    for (i=0;i<ROW;i++){
        arr[i][marker]=arr[i][test];    //overwriting
    }
}   //end shrinking the damn thing

*COL-=cave; //DIE!!!!!(shrinkage of array)
return;}

void coordSelect (int *x, int *y, int ROW, int COL, char arr[][36]) // will continue to ask user for coord until it gets one within board and playable
{
    int score;
    int tempx, tempy;
    printf ("\nEnter your Coordinates. First horizontal coordinate then vertical. Press enter after every coordinate:");
        scanf("%d %d", &tempy, &tempx);
        printf ("tempy is %c",tempy);
        *x = convertCoord (tempx);
        printf("x is %d\n", *x);
        *y = convertCoord (tempy);
        printf("y is %d\n", *y);
        while (*x < 0 || *x > ROW || *y < 0 || *y > COL)
        {
            printf("\nYou made an invalid move! Try again!");
            scanf("%d %d", &tempy, &tempx);
            *x = convertCoord (tempx);
            *y = convertCoord (tempy);
        }
        deleteAreaCheck(ROW-1-*x,*y,arr);
        printf ("\nYou have selected %d %d", (*y), (*x));
    return;
}

int convertCoord (char temp){

int coord;

if (temp>='0' && temp <='9'){
    coord = temp - '0';
    printf ("temp is %d\n", temp);
    return coord;}
else {
    coord = temp - 'A';
    printf ("temp is %d\n", temp);
    return coord;   
   } 
}
void compileBoard (char arr[][36], int ROW, int COL){ //compile board
logfile = fopen("log.txt", "w");
int i, j;
srand ((unsigned)time(NULL));
for (i=0;i<ROW;i++){
    for (j=0;j<COL;j++){
        arr[i][j]=NumToColour(rand()%4+1); //NumToColour sends back chars to be written into array
        fprintf(logfile, "%c", arr[i][j]);
    }
    fprintf(logfile, "\n");
}
return;
}

//These are the AI/Computer Play Functions.

int RowPick (int ROW)
{
    srand((unsigned)time(NULL)); //ensure random number
    int Rowpick = rand()%(ROW); //ROWS as defined by the function for grabbing the amount of rows
    return Rowpick;
}

int ColPick (int COL)
{
        srand((unsigned)time(NULL));
        int Colpick = rand() % (COL);
        printf("I pick row %d", Colpick);
        return Colpick;
}

int CalculateScore (char arr[][36], int ROW, int COL){
    int i, j;
    int fscore = 0; //score for function 
    for (i = 0; i < ROW; i++) //Loop through Array
        for (j = 0; j < COL;j++){
            if (arr[i][j] == '0'){
                fscore++; //Increases score!
                arr[i][j]=0;
                }
        }
        fprintf (logfile, "%d", fscore*fscore); 
        return fscore*fscore;
 }
 
void FileBoard ( ) { //this will read the numbers/characters off the file and print to screen. woooooooorking now :)

FILE *input; //based off of the input file specification in instructions

char filename[13]; // reads desired file
char c[100]; // characters off file
char ch; //characters to be printed to screen

    printf("You have decided to use an existing board.\nPlease enter a filename (xxxxxxxx.yyy): ");
    scanf("%s", filename); 
    printf("\n");

    if ((input = fopen(filename, "r")) == NULL) { // checks to find file and can't
        printf("Filename invalid");//invalid file
        return;
       }

    else {
        input = fopen(filename, "r");//if valid file, opens it
        do {
            fgets(c, 100, input); //reads the file
            printf ("%s", c); // prints the contents of the file to standard output
        } while ((ch = getc(input)) != EOF); //prints until it reads EOF from file
    }

       fclose(input);//close the file
       return;
}

 //FUNCTION THAT CHECKS COORDINATES AND CHANGES TO ZERO.
/*-int checkCoord (int x, int y, int ROW, int COL, int *area) {//uses recursion to turn all identical adjacent carts to zero
 
 if ((x+1) < COL && y < ROW) { //checks to see that (x+1)(y) is within playing board first
       if (board[x+1][y] == board[x][y] && (x+1) <= COL && y < ROW[x+1] ) { // if within the board, sets the identical carts to the left of selected cart to zero
-          area++;
           checkCoord(x+1, y, board);
      }
-    else  //is this in coordSelect already?
+    else
       break;// if not within board, leaves this loop moves onto the next
 
     if (board[x-1][y] == board[x][y] && (x-1) > 0 && (x-1) < COL && y > ROW[x-1]) { //rows in each game are different...need to adjust checks the grids to the right of the selected grid
-        area++;
         checkCoord(x-1, y, board);
     }
 
     if (board[x][y+1] == board[x][y] && (y+1) <= COL) { //checks the grids above the selected grid
-        area++;
         checkCoord(x, y+1, board);
     }
 
-    if (board[x][y-1] == board[x][y] && (y-1) <= COL && (y-1) >= 0) { // checks the grids below the selected grid and turns them to zero
-        area++;
+    if (board[x][y-1] == board[x][y] && (y-1) <= COL && (y-1) >= 0) { //checks the grids below the selected grid
         checkCoord(x, y-1, board);
     }
 
     board[x][y]=0;
-
-    return area*area;
 } 
*/
void deleteAreaCheck(int rows, int cols, char arr[][36]){// this checks if it a valid move adn returns the score for the move
    int score=0;
    char given=arr[rows][cols];
    if(arr[rows+1][cols]==given || arr[rows][cols+1]==given || arr[rows-1][cols]==given || arr[rows][cols-1]==given){
        deleteArea(given, rows, cols, arr);
    }

    return;
}
int deleteArea(char given, int x, int y, char arr[][36]){//this is a recursive function replaces same characters that are touching with a zero
//returns the number of characters deleted
    if(arr[x][y]==given){
        arr[x][y]='0'; //if the given char (the one that was selected by the user) is the same as a the new spot given then it is replaced by a zeor
        //moveing out to the right and left, up and down
        return deleteArea(given, x+1, y, arr)+deleteArea(given, x-1, y, arr)+deleteArea(given, x, y+1, arr)+deleteArea(given, x, y-1, arr);
    }
    return 0;
}
void computermove(int *x, int *y,int row, int cols, char arr[][36]) {//determines the best move for the computer to make
    char newarr[36][36];
    //copy the array
    int i, j, xtmp=-1, ytmp=-1, tmpscore=0, highscore=0;
    for(i=0;i<row;i++){
        for(j=0;j<cols;j++){
            arr[i][j]=newarr[i][j];
        }
    }
    for (i=0; i<row;i++) {
        for (j=0;j<cols;j++){//this goes though the copied array and turns everything into a '0'
            if(newarr[i][j]!='0'&&newarr[i][j]!=0){
                deleteAreaCheck(i,j,newarr); 
                tmpscore=CalculateScore(newarr, row,cols);
                if(tmpscore>highscore){//compares if the score for that location is greater than the highest recored score thus far
                    xtmp=i;//this keeps track of the position of where the high score was found
                    ytmp=j;
                    highscore=tmpscore; //hupdates high score
                }
            }
            arr[i][j]='0';//sets any passed by character to zero;
        }
    }
    *x=xtmp;
    *y=ytmp;
    return;
}

/*
//--- this is Rachel Baker's print board--- keep it as a refference?
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


/* TWO COMPILE BOARD LOL void compileBoard(int rows, int cols, char arr[][36]){/this function creates an arry of characters (arr) ith the specified size. it is formatted with the colums first (x coordanite) and the rows second (y cordinate)
                                         it takes as paramers the row and colom size
                                         the character array corisponds to a color.
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
*/
    /* PSEUDO CODE compileBoard (arr, ROW, COL);
    while (SearchMove) //I think Rachel already made a function for this?
    system("cls");  //I think this is to wipe the last board off the screen right? I think it just makes sure that the grid stays in the same place - Polly
    printfBoard(arr, ROW, COL); //unfortunately the system("cls") will only work in WinBlows
    coordSelect(void); // asks the user to pick coordinates

    checkCoord(void);//checks if the coordinate the user picks is valid and then changes them to zero. 

    }
    return 0; */
   
