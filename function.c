#include <stdio.h>
#include <string.h>
#include "function.h"
#include "chess.h"
char str[] = {'M' ,'L', 'D', 'G', 'F', 'F', 'P', 'H', 'I'};
int num[]  = {10  ,16 , 11 , 11 , 5  , 14 , 12 , 13 , 13};
int check(char board[19][19]){
    for(int k = 0; k < strlen(str); k++){
        int correct = 1;
        for(int i=0; i<19; i++){
            for(int j=0; j<19; j++){
                if(board[i][j] != chess[k][i][j]) correct = 0;
            }
        }
        if(correct){
            printf("%c, %d\n", str[k], num[k]);
            return k;
        }
    }
    return -1;
}

int weight(char board[19][19], int i, int j, int dr, int dc, char color){
    int count = 1;
    int hole = 0;

    int r = i + dr;
    int c = j + dc;
    while(0 <= r && r < 19 && 0 <= c && c < 19 && board[r][c] == color){
        count++;
        r += dr;
        c += dc;
    }
    if(0 <= r && r < 19 && 0 <= c && c < 19 && board[r][c] == '.') hole++;

    r = i - dr;
    c = j - dc;
    while(0 <= r && r < 19 && 0 <= c && c < 19 && board[r][c] == color){
        count++;
        r -= dr;
        c -= dc;
    }
    if(0 <= r && r < 19 && 0 <= c && c < 19 && board[r][c] == '.') hole++;

    if(count >= 5) return 10000000;

    if(count >= 4){
        if (hole == 2) return 500000;
        if (hole == 1) return 100000;
    }

    if (count == 3) {
        if (hole == 2) return 5000;
        if (hole == 1) return 500;
    }

    if (count == 2) {
        if (hole == 2) return 100;
        if (hole == 1) return 50;
    }

    return 0;
}