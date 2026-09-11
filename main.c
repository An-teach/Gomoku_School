#include <stdio.h>
#include <string.h>
#include "function.h"

int main(int argc, char *argv[]){
    char myC = (strcmp(argv[1], "Black") == 0) ? '1' : '0';
    char oppC = (strcmp(argv[1], "Black") == 0) ? '0' : '1';

    char board[19][19];

    for(int i=0; i<19; i++)
        for(int j=0; j<19; j++)
            scanf(" %c", &board[i][j]);

    int k = check(board);
    if(k != -1){
        //
    }else{
        int dr[] = {0, 1, 1, 1};
        int dc[] = {1, 0, 1, -1};

        int r = -1, c = -1;
        double maxScore = -1.0;

    for(int i = 0; i < 19; i++){
        for(int j = 0; j < 19; j++){
            if(board[i][j] == '.'){
                int myScore = 0;
                int oppScore = 0;

                for (int d = 0; d < 4; d++) {
                    myScore += weight(board, i, j, dr[d], dc[d], myC);
                    oppScore += weight(board, i, j, dr[d], dc[d], oppC);
                }

                double score = 0;

                if(myScore >= 10000000){
                    score = myScore*2 + oppScore;
                }
                else score = myScore*1.3 + oppScore;

                if(score > maxScore){
                    maxScore = score;
                    r = i;
                    c = j;
                }
            }
        }
    }
        int b = 0, w = 0;
        for(int i = 0; i < 19; i++){
            for(int j = 0; j < 19; j++){
                if(board[i][j] == '1') b++;
                if(board[i][j] == '0') w++;
            }
        }
        if(b == 0 && w == 0) printf("I, 9\n");
        else printf("%c, %d\n", 'A'+ c, r + 1);
    }
}