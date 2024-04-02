#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
HANDLE consoleHandle; 
int w, h; 
int speed = 0;
int direct = 4;
int dou = 0;
int foodx;
int foody;
int foodx1;
int foody1;

void Title(int y, int x);
void Wait(int y, int x);
void Begin(int y, int x);
void Clear(int y, int x);
void Prepare(int *score);
void Quit(int *state, int *score);
void Game(int *state, int *score);
void Score(int y, int x, int* score);
int FoodIsOnSnake(int a[], int b[], int *score);

int main() {
    int CountScore = 0;
    int *score = &CountScore;
    int ActuallyState = 0;
    int *state = &ActuallyState;
    while (1) {
        if (*state == 0) {
            Game(state, score);
        } else if (*state == 1 || *state == 4) {
            Quit(state, score);
            return 0;
        } else {
            Quit(state, score);
        }
        //0 means the game goes on
        //1 means you want to finish the game
        //2 means the snake hit the wall
        //3 means the snake ate itself
        //4 means the player wanna quit even before starting to play
    }
}

void Game (int *state, int *score) {
    Prepare(score);

    int judge = 1;
    while(judge) {
        while (kbhit() != 0) {
            char start = getch();
            if (start == 'a') {
                speed = 5;
                judge = 0;
                break;
            } else if (start == 'b') {
                speed = 50;
                judge = 0;
                break;
            } else if (start == 'c') {
                speed = 90;
                judge = 0;
                break;
            } else if (start == 'd') {
                speed = 50;
                judge = 0;
                dou = 1;
                break;
            } else if (start == 'q') {
                *state = 4;
                return;
            }
            //a is actually too slow to play
            //b is a little boring 
            //c ... can do
        }
    } 
    int x[10004] = {0};
    int y[10004] = {0};
    int tempx = 0;
    int tempy = 0;
    int foodx = rand() % (w - 3) + 1;
    int foody = rand() % (h - 6) + 4;

    int foodx1 = rand() % (w - 3) + 1;
    int foody1 = rand() % (h - 6) + 4;
    x[0] = w / 2;
    y[0] = h / 2 + 2;
    x[1] = w / 2 + 1;
    y[1] = h / 2 + 2;
    
    //len == *score + 2;
    
    system("cls");
    Title(0, w / 2 - 5);
    Begin(h, w);
    Score(h, w, score);
    COORD co = (COORD){ .X = foodx, .Y = foody };
    SetConsoleCursorPosition(consoleHandle, co); 
    printf("$");
    if (dou) {
        co = (COORD){ .X = foodx1, .Y = foody1 };
        SetConsoleCursorPosition(consoleHandle, co); 
        printf("$");
    }
    co = (COORD){ .X = x[*score + 1], .Y = y[*score + 1] };
    SetConsoleCursorPosition(consoleHandle, co); 
    printf("@");
    co = (COORD){ .X = x[*score], .Y = y[*score] };
    SetConsoleCursorPosition(consoleHandle, co); 
    printf("*");
    while (1) {
        if (kbhit()) {
            char c = getch();
            while (kbhit()) {
                char c;
                c = getch();
                if (!kbhit()) {
                break;
                }
            }
            //chear the stdin
            if (c == 'q') {
                *state = 1;
                return;
            } else if (c == 'p') {
                Wait(h / 2, w / 2);
                while(1) {
                    int sign = 0;
                    while (kbhit() != 0) {
                        char wait = getch();
                        if (wait == 'p') {
                            sign = 1;
                            Clear(h / 2, w / 2);
                            break;
                        } else if (wait == 'q') {
                            *state = 1;
                            return;
                        } else if (wait == 't') {
                            return;
                        }
                    }
                    if (sign) {
                        break;
                    }
                } 
            } else if (c == 'w' && direct != 2) {
                direct = 1;
            } else if (c == 's' && direct != 1) {
                direct = 2;
            } else if (c == 'a' && direct != 4) {
                direct = 3;
            } else if (c == 'd' && direct != 3) {
                direct = 4;
            } else if (c == 'o' && speed < 5) {
                speed = speed + 1;
            } else if (c == 'o' && speed <= 75 && speed >= 5) {
                speed = speed + 5;
            } else if (c == 'o' && speed < 100) {
                speed = speed + 1;
            } else if (c == 'i' && speed >= 10 && speed <= 80) {
                speed = speed - 5;
            } else if (c == 'i' && speed > 1 && speed <= 5) {
                speed = speed - 1;
            } else if (c == 'i' && speed > 80) {
                speed = speed - 1;
            } else if (c == 't') {
                system("cls");
                COORD co = (COORD){ .X = w / 2 - 20, .Y = 7 };
                SetConsoleCursorPosition(consoleHandle, co); 
                printf("You got %d scores.\n", *score);
                co = (COORD){ .X = w / 2 - 20, .Y = 8 };
                SetConsoleCursorPosition(consoleHandle, co); 
                printf("Back to title in 3 seconds.");
                Sleep(1000);
                SetConsoleCursorPosition(consoleHandle, co); 
                printf("Back to title in 2 seconds.");
                Sleep(1000);
                SetConsoleCursorPosition(consoleHandle, co); 
                printf("Back to title in 1 seconds.");
                Sleep(1000);
                return;
            }
        }
        if (direct == 1) {
            x[*score + 2] = x[*score + 1];
            y[*score + 2] = y[*score + 1] - 1;
        } else if (direct == 2) {
            x[*score + 2] = x[*score + 1];
            y[*score + 2] = y[*score + 1] + 1;
        } else if (direct == 3) {
            x[*score + 2] = x[*score + 1] - 1;
            y[*score + 2] = y[*score + 1];
        } else if (direct == 4) {
            x[*score + 2] = x[*score + 1] + 1;
            y[*score + 2] = y[*score + 1];
        }
        for (int i = 1; i < *score + 2; i++) {
            if (x[*score + 2] == x[i] && y[*score + 2] == y[i]) {
                *state = 3;
                return;
            }
        }

        if (x[*score + 2] == foodx && y[*score + 2] == foody) {
            *score = *score + 1;
            co = (COORD){ .X = x[*score + 1], .Y = y[*score + 1] };
            SetConsoleCursorPosition(consoleHandle, co); 
            printf("@");
            co = (COORD){ .X = x[*score], .Y = y[*score] };
            SetConsoleCursorPosition(consoleHandle, co); 
            printf("#");
AGAIN:
            foodx = rand() % (w - 3) + 1;
            foody = rand() % (h - 6) + 4;
            if (FoodIsOnSnake(x, y, score) == 1 || FoodIsOnSnake(x, y, score) == 3){
                goto AGAIN;
            } else if (foodx == foodx1 && foody == foody1) {
                goto AGAIN;
            }
            co = (COORD){ .X = foodx, .Y = foody };
            SetConsoleCursorPosition(consoleHandle, co); 
            printf("$");
            if (speed < 5) {
                speed = speed + 1;
            } else if (speed <= 75) {
                speed = speed + 5;
            } else if (speed < 100) {
                speed = speed + 1;
            }
        } else if (x[*score + 2] == foodx1 && y[*score + 2] == foody1) {
            *score = *score + 1;
            co = (COORD){ .X = x[*score + 1], .Y = y[*score + 1] };
            SetConsoleCursorPosition(consoleHandle, co); 
            printf("@");
            co = (COORD){ .X = x[*score], .Y = y[*score] };
            SetConsoleCursorPosition(consoleHandle, co); 
            printf("#");
AGAIN2:
            foodx1 = rand() % (w - 3) + 1;
            foody1 = rand() % (h - 6) + 4;
            if (FoodIsOnSnake(x, y, score) == 2 ){
                goto AGAIN2;
            } else if (foodx == foodx1 && foody == foody1) {
                goto AGAIN2;
            }
            co = (COORD){ .X = foodx1, .Y = foody1 };
            SetConsoleCursorPosition(consoleHandle, co); 
            printf("$");
            if (speed < 5) {
                speed = speed + 1;
            } else if (speed <= 75) {
                speed = speed + 5;
            } else if (speed < 100) {
                speed = speed + 1;
            }
        } else if (x[*score + 2] <= 0 || x[*score + 2] >= w - 1 
            || y[*score + 1] <= 3 || y[*score + 1] >= h - 1) {

            *state = 2;
            return;
        } else {
            co = (COORD){ .X = x[0], .Y = y[0] };
            SetConsoleCursorPosition(consoleHandle, co); 
            printf(" ");
            for (int i = 0; i < *score + 2; i++) {
                x[i] = x[i + 1] ;
                y[i] = y[i + 1] ;
            }
            co = (COORD){ .X = x[*score + 1], .Y = y[*score + 1] };
            SetConsoleCursorPosition(consoleHandle, co); 
            printf("@");
            co = (COORD){ .X = x[*score], .Y = y[*score] };
            SetConsoleCursorPosition(consoleHandle, co); 
            printf("*");
        }
        Score(h, w, score);
        Sleep(308 - 3 * speed);
        //clear stdin
    }
}

void Quit(int *state, int *score) {
    system("cls");
    if (*state == 2) {
        COORD co = (COORD){ .X = w / 2 - 20, .Y = 3 };
        SetConsoleCursorPosition(consoleHandle, co); 
        printf("Sorry, you hit the border!\n");
        co = (COORD){ .X = w / 2 - 20, .Y = 4 };
        SetConsoleCursorPosition(consoleHandle, co); 
        printf("It seems that you can't handle the snake well.\n");
        co = (COORD){ .X = w / 2 - 20, .Y = 5 };
        SetConsoleCursorPosition(consoleHandle, co); 
        printf("Do more practice!\n");
    } else if (*state == 3) {
        COORD co = (COORD){ .X = w / 2 - 20, .Y =3 };
        SetConsoleCursorPosition(consoleHandle, co); 
        printf("Sorry, you ate yourself!\n");
        co = (COORD){ .X = w / 2 - 20, .Y = 4 };
        SetConsoleCursorPosition(consoleHandle, co); 
        printf("You are way too GREEDY!\n");
        co = (COORD){ .X = w / 2 - 20, .Y = 5 };
        SetConsoleCursorPosition(consoleHandle, co); 
        printf("Be more patient!\n");
    }
    if (*state == 1 || *state == 2 || *state == 3) {
        COORD co = (COORD){ .X = w / 2 - 20, .Y = 7 };
        SetConsoleCursorPosition(consoleHandle, co); 
        printf("You got %d scores.\n", *score);
    }
    if (*state == 2 || *state == 3) {
        COORD co = (COORD){ .X = w / 2 - 20, .Y = 8 };
        SetConsoleCursorPosition(consoleHandle, co); 
        printf("Press 'b' to go back to the start page.");
        co = (COORD){ .X = w / 2 - 20, .Y = 9 };
        SetConsoleCursorPosition(consoleHandle, co); 
        printf("Press 'q' to shut down the game.");
        while(1) {
            while (kbhit() != 0) {
                char wait = getch();
                if (wait == 'b') {
                    *state = 0;
                    break;
                } else if (wait == 'q') {
                    *state = 4;
                    return;
                } 
            }
            if (! *state) {
                break;
            }
        }
    } else if (*state == 1) {
        COORD co = (COORD){ .X = w / 2 - 20, .Y = 8 };
        SetConsoleCursorPosition(consoleHandle, co); 
        printf("The game will shut down in 3 seconds.");
        Sleep(1000);
        SetConsoleCursorPosition(consoleHandle, co); 
        printf("The game will shut down in 2 seconds.");
        Sleep(1000);
        SetConsoleCursorPosition(consoleHandle, co); 
        printf("The game will shut down in 1 seconds.");
        Sleep(1000);
        SetConsoleCursorPosition(consoleHandle, co); 
        printf("                                     ");
        SetConsoleCursorPosition(consoleHandle, co); 
        printf("It's been an honor to have gamed with you!");
        co = (COORD){ .X = w / 2 - 20, .Y = 9 };
        SetConsoleCursorPosition(consoleHandle, co); 
        printf("Looking forward to the next play!");
        return;
    } else if (*state == 4) {
        COORD co = (COORD){ .X = w / 2 - 20, .Y = 8 };
        SetConsoleCursorPosition(consoleHandle, co); 
        printf("It's been an honor to have gamed with you!");
        co = (COORD){ .X = w / 2 - 20, .Y = 9 };
        SetConsoleCursorPosition(consoleHandle, co); 
        printf("Looking forward to the next play!");
        Sleep(2000);
        return;
    }
}

void Title(int y, int x) {
    COORD co = (COORD){ .X = x, .Y = 0 };
    SetConsoleCursorPosition(consoleHandle, co); 
    printf("Snake The Game"); 
}

void Score(int y, int x, int* score) {
    COORD co = (COORD){ .X = 1, .Y = 1 };
    SetConsoleCursorPosition(consoleHandle, co); 
    printf("Score : %d  Speed : %d   ", *score, speed);
    co = (COORD){ .X = x - 61, .Y = 1 };
    SetConsoleCursorPosition(consoleHandle, co);
    printf("Speed down : i  Speed up : o  Title : t  Pause : p  Quit : q");
}

void Begin(int y, int x) {
    for (int i = 1; i < x; i++) {
        COORD co = (COORD){ .X = i, .Y = 3 };
        SetConsoleCursorPosition(consoleHandle, co);
        printf("-");
        co = (COORD){ .X = i, .Y = y - 1 };
        SetConsoleCursorPosition(consoleHandle, co); 
        printf("-");
    }
    for (int i = 4; i < y; i++) {
        COORD co = (COORD){ .X = 0, .Y = i };
        SetConsoleCursorPosition(consoleHandle, co); 
        printf("|");
        co = (COORD){ .X = x - 1, .Y = i };
        SetConsoleCursorPosition(consoleHandle, co); 
        printf("|");
    }
    COORD co = (COORD){ .X = 0, .Y = 3 };
    SetConsoleCursorPosition(consoleHandle, co); 
    printf("+");
    co = (COORD){ .X = x - 1, .Y = 3 };
    SetConsoleCursorPosition(consoleHandle, co); 
    printf("+");
    co = (COORD){ .X = 0, .Y = y - 1 };
    SetConsoleCursorPosition(consoleHandle, co); 
    printf("+");
    co = (COORD){ .X = x - 1, .Y = y - 1 };
    SetConsoleCursorPosition(consoleHandle, co); 
    printf("+");
}

void Wait(int y, int x) {
    COORD co = (COORD){ .X = x - 9, .Y = 2 };
    SetConsoleCursorPosition(consoleHandle, co); 
    printf("Press 'p' to continue");
}

void Clear(int y, int x) {
    COORD co = (COORD){ .X = x - 9, .Y = 2 };
    SetConsoleCursorPosition(consoleHandle, co); 
    printf("                     ");
}

int FoodIsOnSnake(int a[], int b[], int *score) {
    for (int i = 0; i < *score + 2; i++) {
        if (a[i] == foodx && b[i] == foody) {
            return 1;
        } else if (a[i] == foodx1 && b[i] == foody1) {
            return 2;
        } 
    }
    return 0;
}

void Prepare (int *score) {
    *score = 0;
    consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); 
    CONSOLE_SCREEN_BUFFER_INFO csbi; 
    GetConsoleScreenBufferInfo(consoleHandle, &csbi);
    w = csbi.dwSize.X;
    h = csbi.dwSize.Y; 
    CONSOLE_CURSOR_INFO cci; 
    cci.dwSize = 100;
    cci.bVisible = FALSE; 
    SetConsoleCursorInfo(consoleHandle, &cci); 

    system("cls");
    COORD co = (COORD){ .X = w / 2 - 8, .Y = 2 };
    SetConsoleCursorPosition(consoleHandle, co); 
    printf("SNAKE THE GAME\n");

    co = (COORD){ .X = w / 2 - 8, .Y = 3 };
    SetConsoleCursorPosition(consoleHandle, co); 
    printf("Choose the mode\n");

    co = (COORD){ .X = w / 2 - 23, .Y =  4 };
    SetConsoleCursorPosition(consoleHandle, co); 
    printf("a:Very easy\n");

    co = (COORD){ .X = w / 2 - 23, .Y =  5 };
    SetConsoleCursorPosition(consoleHandle, co); 
    printf("b:Normal\n");

    co = (COORD){ .X = w / 2 - 23, .Y =  6 };
    SetConsoleCursorPosition(consoleHandle, co); 
    printf("c:I'm pro at playing the snake, just come on!\n");

    co = (COORD){ .X = w / 2 - 23, .Y =  7 };
    SetConsoleCursorPosition(consoleHandle, co); 
    printf("d:Sepcial -- double the food");

    co = (COORD){ .X = w / 2 - 23, .Y =  9 };
    SetConsoleCursorPosition(consoleHandle, co); 
    printf("Use 'w a s d' to control the snake");

    co = (COORD){ .X = w / 2 - 23, .Y =  10 };
    SetConsoleCursorPosition(consoleHandle, co); 
    printf("Tip : the snake will speed up as it gets longer,");
    co = (COORD){ .X = w / 2 - 23, .Y =  11 };
    SetConsoleCursorPosition(consoleHandle, co); 
    printf("but you can adjust the speed with 'i/o'.");
    co = (COORD){ .X = w / 2 - 23, .Y =  13 };
    SetConsoleCursorPosition(consoleHandle, co); 
    printf("Press 'q' to shut down the game");
}