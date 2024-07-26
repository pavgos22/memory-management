#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

typedef struct Disc {
    char* str;
    int n_moved;
}Disc;

typedef struct Pole {
    int n_discs;
    Disc* discs[20];
}Pole;

void move_disc(Pole** poles, int i, int j) {

    if (poles[j]->n_discs == 20) {
        printf("!\n");
        return;
    }
    if (poles[i]->n_discs == 0) {
        printf("!\n");
        return;
    }
    if (i == j) {
        poles[i]->discs[poles[i]->n_discs - 1]->n_moved++;
        return;
    }


    int last_disc1 = poles[i]->n_discs - 1;
    int last_disc2 = poles[j]->n_discs;

    poles[i]->discs[last_disc1]->n_moved++;
    poles[j]->discs[last_disc2] = poles[i]->discs[last_disc1];
    poles[i]->discs[last_disc1] = nullptr;
    free(poles[i]->discs[last_disc1]);



    poles[i]->n_discs = poles[i]->n_discs - 1;
    poles[j]->n_discs = poles[j]->n_discs + 1;

}

void copystr(char* s2, char* s1) {
    int i;
    for (i = 0; s1[i] != '\0'; ++i) {
        s2[i] = s1[i];
    }
    s2[i] = '\0';
}

void add_disc(Pole** poles, int i, char* c) {
    if (poles[i]->discs[poles[i]->n_discs] == nullptr) {
        poles[i]->discs[poles[i]->n_discs] = (Disc*)malloc(sizeof(Disc));
        poles[i]->discs[poles[i]->n_discs]->n_moved = 0;
        poles[i]->discs[poles[i]->n_discs]->str = (char*)malloc(sizeof(char) * 20);
    }
    copystr(poles[i]->discs[poles[i]->n_discs]->str, c);
    poles[i]->n_discs++;
}


int main() {
    int n_poles;
    scanf("%d", &n_poles);

    Pole** poles = (Pole**)malloc(n_poles * sizeof(Pole));


    for (int i = 0; i < n_poles; i++) {
        poles[i] = (Pole*)malloc(sizeof(Pole));
        poles[i]->n_discs = 0;
        for (int j = 0; j < 20; j++) {
            poles[i]->discs[j] = (Disc*)malloc(sizeof(Disc));
            poles[i]->discs[j]->n_moved = 0;
            poles[i]->discs[j]->str = (char*)malloc(sizeof(char) * 20);
        }
    }

    int exit = 0;
    char input = 'x';
    int i, j;
    char* s = (char*)malloc(20 * sizeof(char));
    while (!exit) {
        scanf("%c", &input);

        switch (input)
        {
        case 'A': {
            scanf("%d", &i);
            scanf("%s", s);
            if (poles[i]->n_discs == 20) {
                printf("x\n");
            }
            else {
                add_disc(poles, i, s);
            }
            break;
        }
        case 'M': {
            scanf("%d", &i);
            scanf("%d", &j);
            move_disc(poles, i, j);
            break;
        }
        case 'P': {
            for (int i = 0; i < n_poles; i++) {
                printf("%d:\n", i);
                for (int j = poles[i]->n_discs - 1; j >= 0; j--) {
                    printf("\t\t %s %d \n", poles[i]->discs[j]->str, poles[i]->discs[j]->n_moved);
                }

            }
            printf("-\n");
            break;
        }
        case 'Q': {
            for (int i = 0; i < n_poles; i++) {

                for (int j = 0; j < 20; j++) {
                    free(poles[i]->discs[j]);
                }

                free(poles[i]);
            }
            free(s);
            exit = 1;
            break;
        }
        default:
            break;
        }
    }

    return 0;
}