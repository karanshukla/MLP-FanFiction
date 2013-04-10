#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int CalculateScore (char arr[][36], int ROW, int COL){
    int i, j;
    int fscore = 0; //score for function
    int tempscore; //dummy variable
    for (i = 0; i < ROW; i++) //Loop through Array
        for (j = 0; j < COL;j++){
            tempscore = fscore
            if (arr[i][j] == '0')
                fscore++; //Increases score!
            else if (tempscore == fscore)
                return -1;
       
        }
    return fscore*fscore; //ITS HIP TO BE SQUARE
}
