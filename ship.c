/**
*@author: Jozef Balint
*@date: 16.11.2016
*@description: SHIPS!!!1111!11!!!!!11!!!
*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int checkCode(int);
void checkCodeUsingPointer(int *);
void printArray(int [8][8]);

int main(){
    int code1,code2,code3,code4;
    int field[8][8];
    int i,j;
    int position = -1;
    int positionRow, positionCol;
    int count = 1;

    printf("Welcome to the world of tomorrow! Made by Jozef Balint.");
    printf("\n\nEnter 1. code: ");
    scanf("%d",&code1);
    printf("Enter 2. code: ");
    scanf("%d",&code2);
    printf("Enter 3. code: ");
    scanf("%d",&code3);
    printf("Enter 4. code: ");
    scanf("%d",&code4);

    code1 = checkCode(code1);
    code2 = checkCode(code2);
    checkCodeUsingPointer(&code3);
    checkCodeUsingPointer(&code4);

    //printf("\n%d %d %d %d",code1,code2,code3,code4);

    for(i = 1; i >= 0 ; i--)
    {
        for(j = 7; j >= 0; j--)
        {
            if(code1 % 2 == 0){
                field[i][j] = 0;
                code1>>=1;
            }else{
                field[i][j] = -1;
                code1>>=1;
            }
            if(code2 % 2 == 0){
                field[i+2][j] = 0;
                code2>>=1;
            }else{
                field[i+2][j] = -1;
                code2>>=1;
            }
            if(code3 % 2 == 0){
                field[i+4][j] = 0;
                code3>>=1;
            }else{
                field[i+4][j] = -1;
                code3>>=1;
            }
            if(code4 % 2 == 0){
                field[i+6][j] = 0;
                code4>>=1;
            }else{
                field[i+6][j] = -1;
                code4>>=1;
            }
        }
    }
    /*
    for(j=7; j>=0; j--){
        int bit = code1 & 1;
        field[1][j] = bit *(-1);
        bit = code2 & 1;
        field[3][j] = bit *(-1);
        bit = code3 & 1;
        field[5][j] = bit *(-1);
        bit = code4 & 1;
        field[7][j] = bit *(-1);
        code1>>=1;
        code2>>=1;
        code3>>=1;
        code4>>=1;
    }
    for(j=7; j>=0; j--){
        int bit = code1 & 1;
        field[0][j] = bit *(-1);
        bit = code2 & 1;
        field[2][j] = bit *(-1);
        bit = code3 & 1;
        field[4][j] = bit *(-1);
        bit = code4 & 1;
        field[6][j] = bit *(-1);
        code1>>=1;
        code2>>=1;
        code3>>=1;
        code4>>=1;
    }
    */

    printArray(field);

    while(position > 63 || position < 0){
        printf("\nEnter SHIP position (0-63): ");
        scanf("%d",&position);
    }

    positionRow = position / 8;
    positionCol = position % 8;

    if(field[positionRow][positionCol] == -1){
        printf("Wrong position - you hit an island!");
        return 2;
    }else{
        field[positionRow][positionCol] = -2;

    }

    if(positionCol > 0 && field[positionRow][positionCol-1] == 0){
        field[positionRow][positionCol-1] = 1;
    }
    if(positionCol < 7 && field[positionRow][positionCol+1] == 0){
        field[positionRow][positionCol+1] = 1;
    }
    if(positionRow > 0 && field[positionRow-1][positionCol] == 0){
        field[positionRow-1][positionCol] = 1;
    }
    if(positionRow < 7 && field[positionRow+1][positionCol] == 0){
        field[positionRow+1][positionCol] = 1;
    }

    while(count < 39){
        for(i = 0; i<8; i++){
            for(j = 0; j<8; j++){

                if(field[i][j] == count){

                    if(j > 0 && field[i][j-1] == 0){
                        field[i][j-1] = count+1;
                    }
                    if(j < 7 && field[i][j+1] == 0){
                        field[i][j+1] = count+1;
                    }
                    if(i > 0 && field[i-1][j] == 0){
                        field[i-1][j] = count+1;
                    }
                    if(i < 7 && field[i+1][j] == 0){
                        field[i+1][j] = count+1;
                    }
                }
            }
        }
        count++;
    }
    printArray(field);
    //return 0;
}

int checkCode(int num){
    if(num >= 0 && num <= (pow(2,16))-1){
        return num;
    }else{
        return 0;
    }
}

void checkCodeUsingPointer(int *pnum){
    if(*pnum < 0 || *pnum > pow(2,16)-1){
        *pnum = 0;
    }
}

void printArray(int array[8][8]){
    int i,j;
    /*
    for(i = 0; i<10; i++){
        printf(" %c ",196);
    }
    */
    for(i = 0; i<8; i++){
        printf("\n");
        //printf("%c",179);
        for(j = 0; j<8; j++){
            if(array[i][j] == 0){
                printf("   ");
            }else if(array[i][j] == -1){
                printf("  #");
            }else if(array[i][j] == -2){
                printf("  O");
            }else{
                printf("%3d",array[i][j]);
            }

        }
    }
}
