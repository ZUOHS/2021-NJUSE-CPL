#include <stdio.h>

int main () {
    int board[10][10] = {
        {0},
        {0},
        {0},
        {0},
        {0},
        {0},
        {0},
        {0},
        {0},
        {0}};
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    int judge_one = 0;
    int judge_two = 0;
    int count[10];
    int also_count[10];
    for (int i = 1; i <= 9; i++) {
        for (int m = 0; m < 10; m++) {
            count[m] = 0;
            also_count[m] = 0;
        }
        for (int j = 1; j <= 9; j++) {
            count[board[i][j]]++;
        }
        for (int b = 1; b <= 9; b++) {
            also_count[board[b][i]]++;
        }
        for (int k = 1; k <= 9; k++) {
            if (count[k] != 1 || also_count[k] != 1) {
                printf("NO");
                judge_one = 1;
                break;
            }
        }
        if (judge_one == 1) {
            break;
        }
    }
    
    if (judge_one != 1) {
        for (int i = 1; i <= 7; i++) {
            for (int j = 1; j <= 7; j++) {
                for (int m = 0; m < 10; m++) {
                count[m] = 0;
            }
                count[board[i][j]]++;
                count[board[i][j + 1]]++;
                count[board[i][j + 2]]++;
                count[board[i + 1][j]]++;
                count[board[i + 1][j + 1]]++;
                count[board[i + 1][j + 2]]++;
                count[board[i + 2][j]]++;
                count[board[i + 2][j + 1]]++;
                count[board[i + 2][j + 2]]++;
                for (int k = 1; k <= 9; k++) {
                    if (count[k] != 1) {
                        printf("NO");
                        judge_two = 1;
                        break;
                    }
                }
                if (judge_two == 1) {
                    break;
                }
                j = j + 2;
            }
            if (judge_two == 1) {
                break;
            }
            i = i + 2;
        }
    }
    if ((judge_one == 0) && (judge_two == 0)) {
        printf("YES");
    }
    return 0;
}
