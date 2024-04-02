#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Front[3][3] = {0};
int Back[3][3] = {0};
int Left[3][3] = {0};
int Right[3][3] = {0};
int Upside[3][3] = {0};
int Downside[3][3] = {0};

int IsFinished ();
void F0 ();
void B0 ();
void L0 ();
void R0 ();
void U0 ();
void D0 ();
void F1 ();
void B1 ();
void L1 ();
void R1 ();
void U1 ();
void D1 ();
void F2 ();
void B2 ();
void L2 ();
void R2 ();
void U2 ();
void D2 ();
void SevenOne();
void SevenTwo();
void SevenThree();
void Six();
void Five();
void Four();
void Three();
void Two();
void OneOne();
void OneTwo();

int main () {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &Front[j][i]);
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &Back[j][i]);
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &Left[j][i]);
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &Right[j][i]);
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &Upside[j][i]);
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &Downside[j][i]);
        }
    }
    int yellow = Upside[1][1];
    int white = Downside[1][1];
    int blue = Front[1][1];
    int red = Right[1][1];
    while (1) {
        if (IsFinished()) {
            return 0;
        }
        if (Downside[0][0] == Downside[1][1] && Downside[1][0] == Downside[1][1] && Downside[2][0] == Downside[1][1] && Downside[0][1] == Downside[1][1] &&
            Downside[2][1] == Downside[1][1] && Downside[0][2] == Downside[1][1] && Downside[1][2] == Downside[1][1] && Downside[2][2] == Downside[1][1] &&
            Front[0][1] == Front[1][1] && Front[2][1] == Front[1][1] && Front[0][2] == Front[1][1] && Front[1][2] == Front[1][1] && Front[2][2] == Front[1][1] &&
            Right[0][1] == Right[1][1] && Right[2][1] == Right[1][1] && Right[0][2] == Right[1][1] && Right[1][2] == Right[1][1] && Right[2][2] == Right[1][1] &&
            Left[0][1] == Left[1][1] && Left[2][1] == Left[1][1] && Left[0][2] == Left[1][1] && Left[1][2] == Left[1][1] && Left[2][2] == Left[1][1] &&
            Back[0][1] == Back[1][1] &&Back[2][1] == Back[1][1] && Back[0][2] == Back[1][1] && Back[1][2] == Back[1][1] && Back[2][2] == Back[1][1]) {
            //下两层OK
            if (Upside[0][0] == Upside[0][1] && Upside[0][0] == Upside[0][2] && Upside[0][0] == Upside[1][0] &&
                Upside[0][0] == Upside[1][1] &&
                Upside[0][0] == Upside[1][2] && Upside[0][0] == Upside[2][0] && Upside[0][0] == Upside[2][1] &&
                Upside[0][0] == Upside[2][2]) {
                //顶层OK
                if (Front[0][0] == Front[2][0] && Right[0][0] == Right[2][0] && Back[0][0] == Back[2][0] &&
                    Left[2][0] == Left[0][0]) {
                    if (Front[0][0] == Front[1][0] && Back[0][0] == Back[1][0] && Left[0][0] == Left[1][0] &&
                        Right[0][0] == Right[1][0]) {
                        while (Front[0][0] != Front[1][1]) {
//                            printf("A");
                            U0();
                        }
                    } else if (Left[1][0] == Left[0][0] || Right[1][0] == Right[0][0] || Front[1][0] == Front[0][0] || Back[1][0] == Back[0][0]) {
//                        printf("B");
                        SevenOne();
                    } else if (Front[1][0] == Back[0][0]) {
//                        printf("C");
                        SevenTwo();
                    } else {
//                        printf("D");
                        SevenThree();
                    }
                } else {
//                    printf("F");
                    Six();
                }
            } else if (Upside[1][0] == Upside[1][1] && Upside[0][1] == Upside[1][1] && Upside[2][1] == Upside[1][1] && Upside[1][2] == Upside[1][1]) {
                //顶层十字架
//                printf("G");
                Five();
            } else {
//                printf("H");
                Four();
            }
        } else if (Downside[0][0] == Downside[1][1] && Downside[1][0] == Downside[1][1] && Downside[2][0] == Downside[1][1] && Downside[0][1] == Downside[1][1] &&
                   Downside[2][1] == Downside[1][1] && Downside[0][2] == Downside[1][1] && Downside[1][2] == Downside[1][1] && Downside[2][2] == Downside[1][1] &&
                   Front[0][2] == Front[1][1] && Front[1][2] == Front[1][1] && Front[2][2] == Front[1][1] &&
                   Right[0][2] == Right[1][1] && Right[1][2] == Right[1][1] && Right[2][2] == Right[1][1] &&
                   Left[0][2] == Left[1][1] && Left[1][2] == Left[1][1] && Left[2][2] == Left[1][1] &&
                   Back[0][2] == Back[1][1] && Back[1][2] == Back[1][1] && Back[2][2] == Back[1][1]) {
//            printf("I");
            Three();
        } else if (Downside[1][0] == 4 && Downside[0][1] == 4 && Downside[2][1] == 4 && Downside[1][2] == 4 &&
                   Front[1][1] == Front[1][2] && Right[1][1] == Right[1][2] && Back[1][1] == Back[1][2] && Left[1][1] == Left[1][2]) {
//            printf("J");
            Two();
        } else {
//            printf("K");
            OneOne();
//            printf("L");
            OneTwo();
        }
    }
}

int IsFinished () {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if(Front[i][j] != Front[0][0]) {
                return 0;
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if(Back[i][j] != Back[0][0]) {
                return 0;
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if(Left[i][j] != Left[0][0]) {
                return 0;
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if(Right[i][j] != Right[0][0]) {
                return 0;
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if(Upside[i][j] != Upside[0][0]) {
                return 0;
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if(Downside[i][j] != Downside[0][0]) {
                return 0;
            }
        }
    }
    return 1;
}

void F0 () {
    //先旋转二维数组
    int temp = 0;
    temp = Front[0][0];
    Front[0][0] = Front[0][2];
    Front[0][2] = Front[2][2];
    Front[2][2] = Front[2][0];
    Front[2][0] = temp;
    temp = Front[0][1];
    Front[0][1] = Front[1][2];
    Front[1][2] = Front[2][1];
    Front[2][1] = Front[1][0];
    Front[1][0] = temp;
    //再旋转一维数组
    for (int i = 0; i < 3; i++) {
        temp = Downside[2 - i][0];
        Downside[2 - i][0] = Right[0][i];
        Right[0][i] = Upside[i][2];
        Upside[i][2] = Left[2][2 - i];
        Left[2][2 - i] = temp;
    }
    printf("f\n");
}
void B0 () {
    int temp = 0;
    temp = Back[0][0];
    Back[0][0] = Back[0][2];
    Back[0][2] = Back[2][2];
    Back[2][2] = Back[2][0];
    Back[2][0] = temp;
    temp = Back[0][1];
    Back[0][1] = Back[1][2];
    Back[1][2] = Back[2][1];
    Back[2][1] = Back[1][0];
    Back[1][0] = temp;

    int temp1 = Right[2][0];
    int temp2 = Right[2][1];
    int temp3 = Right[2][2];
    Right[2][0] = Downside[2][2];
    Right[2][1] = Downside[1][2];
    Right[2][2] = Downside[0][2];
    Downside[2][2] = Left[0][2];
    Downside[1][2] = Left[0][1];
    Downside[0][2] = Left[0][0];
    Left[0][2] = Upside[0][0];
    Left[0][1] = Upside[1][0];
    Left[0][0] = Upside[2][0];
    Upside[0][0] = temp1;
    Upside[1][0] = temp2;
    Upside[2][0] = temp3;
    printf("b\n");
}
void L0 () {
    int temp = 0;
    temp = Left[0][0];
    Left[0][0] = Left[0][2];
    Left[0][2] = Left[2][2];
    Left[2][2] = Left[2][0];
    Left[2][0] = temp;
    temp = Left[0][1];
    Left[0][1] = Left[1][2];
    Left[1][2] = Left[2][1];
    Left[2][1] = Left[1][0];
    Left[1][0] = temp;
    for (int i = 0; i < 3; i++) {
        temp = Front[0][i];
        Front[0][i] = Upside[0][i];
        Upside[0][i] = Back[2][2 - i];
        Back[2][2 - i] = Downside[0][i];
        Downside[0][i] = temp;
    }
    printf("l\n");
}
void R0 () {
    int temp = 0;
    temp = Right[0][0];
    Right[0][0] = Right[0][2];
    Right[0][2] = Right[2][2];
    Right[2][2] = Right[2][0];
    Right[2][0] = temp;
    temp = Right[0][1];
    Right[0][1] = Right[1][2];
    Right[1][2] = Right[2][1];
    Right[2][1] = Right[1][0];
    Right[1][0] = temp;
    for (int i = 0; i < 3; i++) {
        temp = Front[2][i];
        Front[2][i] = Downside[2][i];
        Downside[2][i] = Back[0][2 - i];
        Back[0][2 - i] = Upside[2][i];
        Upside[2][i] = temp;
    }
    printf("r\n");
}
void U0 () {
    int temp = 0;
    temp = Upside[0][0];
    Upside[0][0] = Upside[0][2];
    Upside[0][2] = Upside[2][2];
    Upside[2][2] = Upside[2][0];
    Upside[2][0] = temp;
    temp = Upside[0][1];
    Upside[0][1] = Upside[1][2];
    Upside[1][2] = Upside[2][1];
    Upside[2][1] = Upside[1][0];
    Upside[1][0] = temp;
    for (int i = 0; i < 3; i++) {
        temp = Left[i][0];
        Left[i][0] = Front[i][0];
        Front[i][0] = Right[i][0];
        Right[i][0] = Back[i][0];
        Back[i][0] = temp;
    }
    printf("u\n");
}
void D0 () {
    int temp = 0;
    temp = Downside[0][0];
    Downside[0][0] = Downside[0][2];
    Downside[0][2] = Downside[2][2];
    Downside[2][2] = Downside[2][0];
    Downside[2][0] = temp;
    temp = Downside[0][1];
    Downside[0][1] = Downside[1][2];
    Downside[1][2] = Downside[2][1];
    Downside[2][1] = Downside[1][0];
    Downside[1][0] = temp;
    for (int i = 0; i < 3; i++) {
        temp = Left[i][2];
        Left[i][2] = Back[i][2];
        Back[i][2] = Right[i][2];
        Right[i][2] = Front[i][2];
        Front[i][2] = temp;
    }
    printf("d\n");
}
void F1 () {
    F0();
    F0();
    F0();
}
void B1 () {
    B0();
    B0();
    B0();
}
void L1 () {
    L0();
    L0();
    L0();
}
void R1 () {
    R0();
    R0();
    R0();
}
void U1 () {
    U0();
    U0();
    U0();
}
void D1 () {
    D0();
    D0();
    D0();
}
void F2 () {
    F0();
    F0();
}
void B2 () {
    B0();
    B0();
}
void L2 () {
    L0();
    L0();
}
void R2 () {
    R0();
    R0();
}
void U2 () {
    U0();
    U0();
}
void D2 () {
    D0();
    D0();
}

void SevenOne () {
    int n = 0;
    if (Back[1][0] == Back[0][0]) {
        n = 0;
    } else if (Left[1][0] == Left[0][0]) {
        U0();
    } else if (Front[1][0] == Front[0][0]) {
        U2();
    } else {
        U1();
    }
    if (Front[1][0] == Right[0][0]) {
        n = 1;
    } else {
        n = 2;
    }
    for (int i = 0; i < n; i++) {
        R0();
        U1();
        R0();
        U0();
        R0();
        U0();
        R0();
        U1();
        R1();
        U1();
        R2();
    }
}

void SevenTwo () {
    R0();
    U1();
    R0();
    U0();
    R0();
    U0();
    R0();
    U1();
    R1();
    U1();
    R2();
    U0();
    R0();
    U1();
    R0();
    U0();
    R0();
    U0();
    R0();
    U1();
    R1();
    U1();
    R2();
}

void SevenThree () {
    if (Front[1][0] == Left[0][0]) {
        U0();
    }
    R0();
    U1();
    R0();
    U0();
    R0();
    U0();
    R0();
    U1();
    R1();
    U1();
    R2();
    U1();
    R0();
    U1();
    R0();
    U0();
    R0();
    U0();
    R0();
    U1();
    R1();
    U1();
    R2();
}

void Six () {
    int n = -1;
    if (Front[0][0] == Front[2][0]) {
        n = 0;
    } else if (Left[0][0] == Left[2][0]) {
        U1();
        n = 0;
    } else if (Back[0][0] == Back[2][0]) {
        U2();
        n = 0;
    } else if (Right[0][0] == Right[2][0]) {
        U0();
        n = 0;
    }
    if (n == -1) {
        R0();
        B1();
        R0();
        F2();
        R1();
        B0();
        R0();
        F2();
        R2();
        if (Front[0][0] == Front[2][0]) {
            n = 0;
        } else if (Left[0][0] == Left[2][0]) {
            U1();
            n = 0;
        } else if (Back[0][0] == Back[2][0]) {
            U2();
            n = 0;
        } else if (Right[0][0] == Right[2][0]) {
            U0();
            n = 0;
        }
    }
    R0();
    B1();
    R0();
    F2();
    R1();
    B0();
    R0();
    F2();
    R2();
}

void Five () {
    while(1) {
        if (Upside[2][2] == Upside[1][1] && Back[2][0] == Upside[1][1] && Right[2][0] == Upside[1][1] && Left[2][0] == Upside[1][1]) {
            R1();
            U2();
            R0();
            U0();
            R1();
            U0();
            R0();
            return;
        } else if (Upside[2][2] == Upside[1][1] && Back[0][0] == Upside[1][1] && Front[0][0] == Upside[1][1] && Left[0][0] == Upside[1][1]) {
            U1();
            R0();
            U2();
            R1();
            U1();
            R0();
            U1();
            R1();
            return;
        } else if (Upside[2][0] == Upside[1][1] && Upside[0][2] == Upside[1][1] && Right[0][0] == Upside[1][1] && Back[2][0] == Upside[1][1]) {
            R1();
            U2();
            R0();
            U0();
            R1();
            U0();
            R0();
            U1();
            R0();
            U2();
            R1();
            U1();
            R0();
            U1();
            R1();
            return;
        } else if (Upside[0][0] == Upside[1][1] && Upside[0][2] == Upside[1][1] && Back[0][0] == Upside[1][1] && Front[2][0] == Upside[1][1]) {
            U1();
            R0();
            U2();
            R1();
            U1();
            R0();
            U1();
            R1();
            R1();
            U2();
            R0();
            U0();
            R1();
            U0();
            R0();
            return;
        } else if (Upside[0][0] == Upside[1][1] && Upside[2][0] == Upside[1][1] && Front[0][0] == Upside[1][1] && Front[2][0] == Upside[1][1]) {
            U1();
            R0();
            U2();
            R1();
            U1();
            R0();
            U1();
            R1();
            U2();
            R1();
            U2();
            R0();
            U0();
            R1();
            U0();
            R0();
            return;
        } else if (Front[0][0] == Upside[1][1] && Front[2][0] == Upside[1][1] && Right[2][0] == Upside[1][1] && Left[0][0] == Upside[1][1]) {
            R1();
            U2();
            R0();
            U0();
            R1();
            U0();
            R0();
            U1();
            R1();
            U2();
            R0();
            U0();
            R1();
            U0();
            R0();
            return;
        } else if (Front[0][0] == Upside[1][1] && Front[2][0] == Upside[1][1] && Back[0][0] == Upside[1][1] && Back[2][0] == Upside[1][1]) {
            R1();
            U2();
            R0();
            U0();
            R1();
            U0();
            R0();
            R1();
            U2();
            R0();
            U0();
            R1();
            U0();
            R0();
            return;
        } else {
            U0();
        }
    }
}

void Four () {
    while(1) {
        if (Upside[2][1] == Upside[1][1] && Upside[0][1] == Upside[1][1] && Front[1][0] == Upside[1][1]) {
            F0();
            R0();
            U0();
            R1();
            U1();
            F1();
            return;
        } else if (Upside[0][1] == Upside[1][1] && Upside[1][0] == Upside[1][1] && Front[1][0] == Upside[1][1] && Right[1][0] == Upside[1][1]) {
            F0();
            R0();
            U0();
            R1();
            U1();
            F1();
            F0();
            R0();
            U0();
            R1();
            U1();
            F1();
            return;
        } else if (Front[1][0] == Upside[1][1] && Right[1][0] == Upside[1][1]) {
            F0();
            R0();
            U0();
            R1();
            U1();
            F1();
            F0();
            R0();
            U0();
            R1();
            U1();
            F1();
            U0();
            F0();
            R0();
            U0();
            R1();
            U1();
            F1();
            return;
        } else {
            U0();
        }
    }
}

void Three () {
    int n = 0;
    while (1) {
        n++;
        if (n > 4) {
            int std = Front[1][1] * Right[1][1];
            if (Front[2][1] * Right[0][1] == std) {
                R0();
                U0();
                R1();
            } else if (Right[2][1] * Back[0][1] == std) {
                B0();
                U0();
                B1();
            } else if (Back[2][1] * Left[0][1] == std) {
                L0();
                U0();
                L1();
            } else if (Left[2][1] * Front[0][1] == std) {
                F0();
                U0();
                F1();
            }
            return;
        }
        if (Right[0][1] == Front[1][1] && Front[2][1] == Right[1][1]) {
            U0();
            R0();
            U1();
            R1();
            U1();
            F1();
            U0();
            F0();
            U2();
            U0();
            R0();
            U1();
            R1();
            U1();
            F1();
            U0();
            F0();
            break;
        } else if (Front[1][0] == Front[1][1] && Upside[1][2] == Right[1][1]) {
            U0();
            R0();
            U1();
            R1();
            U1();
            F1();
            U0();
            F0();
            break;
        } else if (Right[1][0] == Right[1][1] && Upside[2][1] == Front[1][1]) {
            U1();
            F1();
            U0();
            F0();
            U0();
            R0();
            U1();
            R1();
            break;
        } else {
            U0();
        }
    }
    n = 0;
    while (1) {
        n++;
        if (n > 4) {
            int std = Back[1][1] * Right[1][1];
            if (Front[2][1] * Right[0][1] == std) {
                R0();
                U0();
                R1();
            } else if (Right[2][1] * Back[0][1] == std) {
                B0();
                U0();
                B1();
            } else if (Back[2][1] * Left[0][1] == std) {
                L0();
                U0();
                L1();
            } else if (Left[2][1] * Front[0][1] == std) {
                F0();
                U0();
                F1();
            }
            return;
        }
        if (Right[1][0] == Right[1][1] && Upside[2][1] == Back[1][1]) {
            U0();
            B0();
            U1();
            B1();
            U1();
            R1();
            U0();
            R0();
            break;
        } else if (Back[1][0] == Back[1][1] && Upside[1][0] == Right[1][1]) {
            U1();
            R1();
            U0();
            R0();
            U0();
            B0();
            U1();
            B1();
            break;
        } else if (Back[0][1] == Right[1][1] && Right[2][1] == Back[1][1]) {
            U0();
            B0();
            U1();
            B1();
            U1();
            R1();
            U0();
            R0();
            U2();
            U0();
            B0();
            U1();
            B1();
            U1();
            R1();
            U0();
            R0();
            break;
        } else {
            U0();
        }
    }
    n = 0;
    while (1) {
        n++;
        if (n > 4) {
            int std = Back[1][1] * Left[1][1];
            if (Front[2][1] * Right[0][1] == std) {
                R0();
                U0();
                R1();
            } else if (Right[2][1] * Back[0][1] == std) {
                B0();
                U0();
                B1();
            } else if (Back[2][1] * Left[0][1] == std) {
                L0();
                U0();
                L1();
            } else if (Left[2][1] * Front[0][1] == std) {
                F0();
                U0();
                F1();
            }
            return;
        }
        if (Left[1][0] == Left[1][1] && Upside[0][1] == Back[1][1]) {
            U1();
            B1();
            U0();
            B0();
            U0();
            L0();
            U1();
            L1();
            break;
        } else if (Back[1][0] == Back[1][1] && Upside[1][0] == Left[1][1]) {
            U0();
            L0();
            U1();
            L1();
            U1();
            B1();
            U0();
            B0();
            break;
        } else if (Back[2][1] == Left[1][1] && Left[0][1] == Back[1][1]) {
            U0();
            L0();
            U1();
            L1();
            U1();
            B1();
            U0();
            B0();
            U2();
            U0();
            L0();
            U1();
            L1();
            U1();
            B1();
            U0();
            B0();
            break;
        } else {
            U0();
        }
    }
    n = 0;
    while (1) {
        n++;
        if (n > 4) {
            int std = Front[1][1] * Left[1][1];
            if (Front[2][1] * Right[0][1] == std) {
                R0();
                U0();
                R1();
            } else if (Right[2][1] * Back[0][1] == std) {
                B0();
                U0();
                B1();
            } else if (Back[2][1] * Left[0][1] == std) {
                L0();
                U0();
                L1();
            } else if (Left[2][1] * Front[0][1] == std) {
                F0();
                U0();
                F1();
            }
            return;
        }
        if (Front[1][0] == Front[1][1] && Upside[1][2] == Left[1][1]) {
            U1();
            L1();
            U0();
            L0();
            U0();
            F0();
            U1();
            F1();
            break;
        } else if (Left[1][0] == Left[1][1] && Upside[0][1] == Front[1][1]) {
            U0();
            F0();
            U1();
            F1();
            U1();
            L1();
            U0();
            L0();
            break;
        } else if (Left[2][1] == Front[1][1] && Front[0][1] == Left[1][1]) {
            U0();
            F0();
            U1();
            F1();
            U1();
            L1();
            U0();
            L0();
            U0();
            F0();
            U1();
            F1();
            U1();
            L1();
            U0();
            L0();
            break;
        } else {
            U0();
        }
    }
}

void Two () {
    int n = 0;
    while (1) {
        n++;
        if (n > 4) {
            int std = Downside[1][1] * Front[1][1] * Right[1][1];
            if (Front[2][2] * Right[0][2] * Downside[2][0] == std) {
                R0();
                U0();
                R1();
            } else if (Right[2][2] * Back[0][2] * Downside[2][2] == std) {
                B0();
                U0();
                B1();
            } else if (Back[2][2] * Left[0][2] * Downside[0][2] == std) {
                L0();
                U0();
                L1();
            } else if (Left[2][2] * Front[0][2] * Downside[0][0] == std) {
                F0();
                U0();
                F1();
            } else {
                break;
            }
            n = 0;
        }
        if (Right[0][0] == Downside[1][1] && Front[2][0] == Front[1][1] && Upside[2][2] == Right[1][1]) {
            R0();
            U0();
            R1();
            break;
        } else if (Right[0][0] == Right[1][1] && Front[2][0] == Downside[1][1] && Upside[2][2] == Front[1][1]) {
            F1();
            U1();
            F0();
            break;
        } else if (Front[2][2] == Right[1][1] && Right[0][2] == Downside[1][1] && Downside[2][0] == Front[1][1]) {
            R0();
            U0();
            R1();
            U1();
            R0();
            U0();
            R1();
            break;
        } else if (Front[2][2] == Downside[1][1] && Right[0][2] == Front[1][1] && Downside[2][0] == Right[1][1]) {
            F1();
            U1();
            F0();
            U0();
            F1();
            U1();
            F0();
            break;
        } else if (Front[2][0] == Right[1][1] && Right[0][0] == Front[1][1] && Upside[2][2] == Downside[1][1]) {
            R0();
            U0();
            R1();
            R0();
            U0();
            R1();
            U1();
            R0();
            U0();
            R1();
            break;
        } else {
            U0();
        }
    }
    n = 0;
    while (1) {
        n++;
        if (n > 4) {
            int std = Downside[1][1] * Back[1][1] * Right[1][1];
            if (Front[2][2] * Right[0][2] * Downside[2][0] == std) {
                R0();
                U0();
                R1();
            } else if (Right[2][2] * Back[0][2] * Downside[2][2] == std) {
                B0();
                U0();
                B1();
            } else if (Back[2][2] * Left[0][2] * Downside[0][2] == std) {
                L0();
                U0();
                L1();
            } else if (Left[2][2] * Front[0][2] * Downside[0][0] == std) {
                F0();
                U0();
                F1();
            } else {
                break;
            }
            n = 0;
        }
        if (Right[2][0] == Right[1][1] && Back[0][0] == Downside[1][1] && Upside[2][0] == Back[1][1]) {
            B0();
            U0();
            B1();
            break;
        } else if (Right[2][0] == Downside[1][1] && Back[0][0] == Back[1][1] && Upside[2][0] == Right[1][1]) {
            R1();
            U1();
            R0();
            break;
        } else if (Right[2][2] == Back[1][1] && Back[0][2] == Downside[1][1] && Downside[2][2] == Right[1][1]) {
            B0();
            U0();
            B1();
            U1();
            B0();
            U0();
            B1();
            break;
        } else if (Right[2][2] == Downside[1][1] && Back[0][2] == Right[1][1] && Downside[2][2] == Back[1][1]) {
            R1();
            U1();
            R0();
            U0();
            R1();
            U1();
            R0();
            break;
        } else if (Right[2][0] == Back[1][1] && Back[0][0] == Right[1][1] && Upside[2][0] == Downside[1][1]) {
            B0();
            U0();
            B1();
            B0();
            U0();
            B1();
            U1();
            B0();
            U0();
            B1();
            break;
        } else {
            U0();
        }
    }
    n = 0;
    while (1) {
        n++;
        if (n > 4) {
            int std = Downside[1][1] * Back[1][1] * Left[1][1];
            if (Front[2][2] * Right[0][2] * Downside[2][0] == std) {
                R0();
                U0();
                R1();
            } else if (Right[2][2] * Back[0][2] * Downside[2][2] == std) {
                B0();
                U0();
                B1();
            } else if (Back[2][2] * Left[0][2] * Downside[0][2] == std) {
                L0();
                U0();
                L1();
            } else if (Left[2][2] * Front[0][2] * Downside[0][0] == std) {
                F0();
                U0();
                F1();
            } else {
                break;
            }
            n = 0;
        }
        if (Back[2][0] == Back[1][1] && Left[0][0] == Downside[1][1] && Upside[0][0] == Left[1][1]) {
            L0();
            U0();
            L1();
            break;
        } else if (Back[2][0] == Downside[1][1] && Left[0][0] == Left[1][1] && Upside[0][0] == Back[1][1]) {
            B1();
            U1();
            B0();
            break;
        } else if (Back[2][2] == Left[1][1] && Left[0][2] == Downside[1][1] && Downside[0][2] == Back[1][1]) {
            L0();
            U0();
            L1();
            U1();
            L0();
            U0();
            L1();
            break;
        } else if (Back[2][2] == Downside[1][1] && Left[0][2] == Back[1][1] && Downside[0][2] == Left[1][1]) {
            B1();
            U1();
            B0();
            U0();
            B1();
            U1();
            B0();
            break;
        } else if (Back[2][0] == Left[1][1] && Left[0][0] == Back[1][1] && Upside[0][0] == Downside[1][1]) {
            L0();
            U0();
            L1();
            L0();
            U0();
            L1();
            U0();
            L0();
            U0();
            L1();
            break;
        } else {
            U0();
        }
    }
    n = 0;
    while (1) {
        n++;
        if (n > 4) {
            int std = Downside[1][1] * Front[1][1] * Left[1][1];
            if (Front[2][2] * Right[0][2] * Downside[2][0] == std) {
                R0();
                U0();
                R1();
            } else if (Right[2][2] * Back[0][2] * Downside[2][2] == std) {
                B0();
                U0();
                B1();
            } else if (Back[2][2] * Left[0][2] * Downside[0][2] == std) {
                L0();
                U0();
                L1();
            } else if (Left[2][2] * Front[0][2] * Downside[0][0] == std) {
                F0();
                U0();
                F1();
            } else {
                break;
            }
            n = 0;
        }
        if (Left[2][0] == Left[1][1] && Front[0][0] == Downside[1][1] && Upside[0][2] == Front[1][1]) {
            F0();
            U0();
            F1();
            break;
        } else if (Left[2][0] == Downside[1][1] && Front[0][0] == Front[1][1] && Upside[0][2] == Left[1][1]) {
            L1();
            U1();
            F0();
            break;
        } else if (Left[2][2] == Front[1][1] && Front[0][2] == Downside[1][1] && Downside[0][0] == Left[1][1]) {
            F0();
            U0();
            F1();
            U1();
            F0();
            U0();
            F1();
            break;
        } else if (Left[2][2] == Downside[1][1] && Front[0][2] == Left[1][1] && Downside[0][0] == Front[1][1]) {
            L1();
            U1();
            F0();
            U0();
            L1();
            U1();
            F0();
            break;
        } else if (Left[2][0] == Front[1][1] && Front[0][0] == Left[1][1] && Upside[0][2] == Downside[1][1]) {
            F0();
            U0();
            F1();
            F0();
            U0();
            F1();
            U1();
            F0();
            U0();
            F1();
            break;
        } else {
            U0();
        }
    }
}

void OneOne () {
    while (1) {
        if (Upside[1][0] == 4 && Upside[2][1] == 4 && Upside[0][1] == 4 && Upside[1][2] == 4) {
            printf("OneOneFinished\n");
            break;
        }

        if (Front[0][1] == 4 || Front[2][1] == 4 || Front[1][0] == 4 || Front[1][2] == 4) {
            if (Front[0][1] == 4) {
                while (Upside[1][2] == 4) {
                    U0();
                }
                F2();
            } else if (Front[1][0] == 4) {
                F0();
            } else if (Front[1][2] == 4) {
                while (Upside[1][2] == 4) {
                    U0();
                }
                F1();
            }
            while (Upside[2][1] == 4) {
                U0();
            }
            R0();
        } else if (Right[0][1] == 4 || Right[2][1] == 4 || Right[1][0] == 4 || Right[1][2] == 4) {
            if (Right[0][1] == 4) {
                while (Upside[2][1] == 4) {
                    U0();
                }
                R2();
            } else if (Right[1][0] == 4) {
                R0();
            } else if (Right[1][2] == 4) {
                while (Upside[2][1] == 4) {
                    U0();
                }
                R1();
            }
            while (Upside[1][0] == 4) {
                U0();
            }
            B0();
        } else if (Back[0][1] == 4 || Back[2][1] == 4 || Back[1][0] == 4 || Back[1][2] == 4) {
            if (Back[0][1] == 4) {
                while (Upside[1][0] == 4) {
                    U0();
                }
                B2();
            } else if (Back[1][0] == 4) {
                B0();
            } else if (Back[1][2] == 4) {
                while (Upside[1][0] == 4) {
                    U0();
                }
                B1();
            }
            while (Upside[0][1] == 4) {
                U0();
            }
            L0();
        } else if (Left[0][1] == 4 || Left[2][1] == 4 || Left[1][0] == 4 || Left[1][2] == 4) {
            if (Left[0][1] == 4) {
                while (Upside[0][1] == 4) {
                    U0();
                }
                L2();
            } else if (Left[1][0] == 4) {
                L0();
            } else if (Left[1][2] == 4) {
                while (Upside[0][1] == 4) {
                    U0();
                }
                L1();
            }
            while (Upside[1][2] == 4) {
                U0();
            }
            F0();
        } else if (Downside[1][0] == 4) {
            while (Upside[1][2] == 4) {
                U0();
            }
            F2();
        } else if (Downside[0][1] == 4) {
            while (Upside[0][1] == 4) {
                U0();
            }
            L2();
        } else if (Downside[2][1] == 4) {
            while (Upside[2][1] == 4) {
                U0();
            }
            R2();
        } else if (Downside[1][2] == 4) {
            while (Upside[1][0] == 4) {
                U0();
            }
            B2();
        }
    }
//    printf("%d %d %d %d", Upside[1][0], Upside[2][1], Upside[0][1], Upside[1][2]);
}

void OneTwo() {
    while (Front[1][0] != 1 || Upside[1][2] != 4) {
        U0();
    }
    F2();
    while (Right[1][0] != 6 || Upside[2][1] != 4) {
        U0();
    }
    R2();
    while (Back[1][0] != 2 || Upside[1][0] != 4) {
        U0();
    }
    B2();
    while (Left[1][0] != 5 || Upside[0][1] != 4) {
        U0();
    }
    L2();
//    if (Downside[1][0] == 4 && Downside[2][1] == 4 && Downside[0][1] == 4 && Downside[1][2] == 4) {
//        printf("OneTwoFinished\n");
//    }
//    printf("%d %d %d %d", Downside[1][0], Downside[2][1], Downside[0][1], Downside[1][2]);
}