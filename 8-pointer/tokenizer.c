#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int process(char *start, char *end);

int main () {
    char *s = malloc(5000 * sizeof (*s));
    int *save = malloc(5000 * sizeof (*save));
    int i = 0;
    for (i = 0; i < 5000; i++) {
        *(save + i) = 0;
        *(s + i) = ' ';
    }
    i = 0;
    //i is the ptr of save
    while (scanf("%s", s) != EOF) {
        int end = 0;
        for (end = 0; end < 5000; end++) {
            if (*(s + end) == '\0') {
                end = end - 1;
                break;
            }
        }
        char *position = strchr(s, ';');
        if (position == NULL) {
            *(save + i) = process(s, s + end);
            i = i + 1;
        } else if (position == s && end == 0) {
            *(save + i) = 1;
            i = i + 1;
        } else if (position == s + end) {
            *(save + i) = process(s, s + end - 1);
            i = i + 1;
            *(save + i) = 1;
            i = i + 1;
        } else {
            *(save + i) = process(s, position - 1);
            i = i + 1;
            *(save + i) = 1;
            i = i + 1;
            *(save + i) = process(position + 1, s + end);
            i = i + 1;
        }
        int j = 0;
        for (j = 0; j < 5000; j++) {
            *(s + j) = ' ';
        }
    }
    int j = 0;
    int judge = 1;
    //give people the benefit of doubt
    for (j = 0; j < 5000; j++) {
        if (*(save + j) == 2) {
            printf("Compile Error");
            judge = 0;
            break;
        }
    }
    if (judge == 1) {
        for (j = 0; j < 5000; j++) {
            if (*(save + j) == 1) {
                printf("\n");
            } else if (*(save + j) == 3) {
                printf("float ");
            } else if (*(save + j) == 4) {
                printf("integer ");
            } else if (*(save + j) == 5) {
                printf("operator ");
            } else if (*(save + j) == 6) {
                printf("variable ");
            } else if (*(save + j) == 7) {
                printf("reserved ");
            }
        }
    }
}
//0 nothing
//1 \n
//2 Compile Error
//3 float
//4 integer
//5 operator
//6 variable
//7 reserved


int process(char *start, char *end) {
    int length = (end - start);
    int i = 0;
    for (i = 0; i <= length; i++) {
        if (*(start + i) < 48 || *(start + i) > 57) {
            break;
        } else if (*(start + i) >= 48 && *(start + i) <= 57 && i == length) {
            return 4;
        }
    }
    for (i = 0; i <= length; i++) {
        if (length >= 1 && *(start + i) == '.' && *(start + i + 1) == '.') {
            return 2;
        } else if (length >= 1 && *start == '-') {
            return 2;
        } else if (length >= 1 && *start >= 48 && *start <= 57 && *(start + i) >= 65 && *(start + i) <= 126) {
            return 2;
        } else if (*(start + i) == '|' && *(start + i + 1) == '|') {
            return 2;
        }
    }
    for (i = 0; i <= length; i++) {
        if (*(start + i) == '.') {
            return 3;
        }
    }
    //别忘了只有';'的情况
    if (length == 0) {
        if (*(start) == '+' || *(start) == '-' || *(start) == '*' || *(start) == '/' || *(start) == '>' || *(start) == '<' || *(start) == '=') {
            return 5;
        } else if (*start == ';'){
            return 0;
        } else {
            return 6;
        }
    } else if (length == 1) {
        if (*(start) == '>' && *(start + 1) == '=') {
            return 5;
        } else if (*(start) == '<' && *(start + 1) == '=') {
            return 5;
        } else if (*(start) == '=' && *(start + 1) == '=') {
            return 5;
        } else if (*(start) == '!' && *(start + 1) == '=') {
            return 5;
        } else {
            return 6;;
        }
    } else if (length == 2) {
        if (*(start) == 'i' && *(start + 1) == 'n' && *(start + 2) == 't') {
            return 7;
        } else {
            return 6;
        }
    } else if (length == 3) {
        if (*(start) == 'l' && *(start + 1) == 'o' && *(start + 2) == 'n' && *(start + 3) == 'g') {
            return 7;
        } else if (*(start) == 'v' && *(start + 1) == 'o' && *(start + 2) == 'i' && *(start + 3) == 'd') {
            return 7;
        } else if (*(start) == 'c' && *(start + 1) == 'h' && *(start + 2) == 'a' && *(start + 3) == 'r') {
            return 7;
        } else if (*(start) == 'e' && *(start + 1) == 'n' && *(start + 2) == 'u' && *(start + 3) == 'm') {
            return 7;
        } else if (*(start) == 'g' && *(start + 1) == 'o' && *(start + 2) == 't' && *(start + 3) == 'o') {
            return 7;
        } else {
            return 6;
        }
    } else if (length == 4) {
        if (*(start) == 'c' && *(start + 1) == 'o' && *(start + 2) == 'n' && *(start + 3) == 's' && *(start + 4) == 't') {
            return 7;
        } else if (*(start) == 'f' && *(start + 1) == 'l' && *(start + 2) == 'o' && *(start + 3) == 'a' && *(start + 4) == 't') {
            return 7;
        } else if (*(start) == 'b' && *(start + 1) == 'r' && *(start+ 2) == 'e' && *(start + 3) == 'a' && *(start + 4) == 'k') {
            return 7;
        } else if (*(start) == 'u' && *(start + 1) == 'n' && *(start + 2) == 'i' && *(start + 3) == 'o' && *(start + 4) == 'n') {
            return 7;
        } else {
            return 6;
        }
    } else if (length == 5) {
        if (*(start) == 'd' && *(start + 1) == 'o' && *(start + 2) == 'u' && *(start + 3) == 'b' && *(start + 4) == 'l' && *(start + 5) == 'e') {
            return 7;
        } else if (*(start) == 's' && *(start + 1) == 't' && *(start + 2) == 'a' && *(start + 3) == 't' && *(start + 4) == 'i' && *(start + 5) == 'c') {
            return 7;
        } else if (*(start) == 'e' && *(start + 1) == 'x' && *(start + 2) == 't' && *(start + 3) == 'e' && *(start + 4) == 'r' && *(start + 5) == 'n') {
            return 7;
        } else if (*(start) == 'r' && *(start + 1) == 'e' && *(start + 2) == 't' && *(start + 3) == 'u' && *(start + 4) == 'r' && *(start + 5) == 'n') {
            return 7;
        } else if (*(start) == 's' && *(start + 1) == 't' && *(start+ 2) == 'r' && *(start + 3) == 'u' && *(start + 4) == 'c' && *(start + 5) == 't') {
            return 7;
        } else {
            return 6;
        }
    } else if (length == 6) {
        if (*(start) == 't' && *(start + 1) == 'y' && *(start + 2) == 'p' && *(start + 3) == 'e' && *(start + 4) == 'd' && *(start + 5) == 'e' && *(start + 6) == 'f') {
            return 7;
        } else {
            return 6;
        }
    }
    return 6;
}