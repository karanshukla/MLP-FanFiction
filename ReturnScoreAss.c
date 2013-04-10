#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int CalculateScore (char arr[][36], int ROW, int COL){
    int i, j;
    int fscore = 0; //score for function
    for (i = 0; i < ROW; i++) //Loop through Array
        for (j = 0; j < COL;j++){
            if (arr[i][j] == '0')
                fscore++; //Increases score!
        }
    if (fscore == 0)
        return -1;
    else
    return fscore*fscore; //ITS HIP TO BE SQUARE
}
