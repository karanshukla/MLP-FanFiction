#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int CalculateScore (char arr[][36], int ROW, int COL){
    int i, j;
    int score = 0;
    for (i = 0; i < ROW; i++) //Loop through Array
        for (j = 0; j < COL;j++){
            if (arr[i][j] == 0)
                score++; //Increases score!
        }
    return score*score; //ITS HIP TO BE SQUARE
}
