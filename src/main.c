#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "test/test.h"
#include "util.h"
#include "display.h"
#include "rotations.h"
#include "file.h"
#include "resolution_mecanique.h"

// TODO : Mettre tous les fonctions dans les .h respectif

/*
 * Left side = cube[0]
 * Front side = cube[1]
 * Upper side = cube[2]
 * Bottom side = cube[3]
 * Right side = cube[4]
 * Behind side = cube[5]
 */
miniCube cube[6][N][N];

void initCube() {
    for(int i = 0; i < 6; ++i) {
        for(int j = 0; j < N; ++j) {
            for(int k = 0; k < N; ++k) {
                miniCube cubeTmp = malloc(sizeof(face*));
                cube[i][j][k] = cubeTmp;
                cube[i][j][k]->color = getFinalColorId(i);
                cube[i][j][k]->finalPos = getFinalLibelle(i, j, k);
            }
        }
    }
}

void completeCube(char* path) {
    char* extension = getExtension(path);
    if(strcmp(extension, EXTENSION_JSON) == 0) {
        miniCube tmp[6][N][N];
        readJSON(path, tmp);
        for(int i = 0; i < 6; ++i) {
            for(int j = 0; j < N; ++j) {
                for(int k = 0; k < N; ++k) {
                    int buff  = cube[i][j][k]->color;
                    buff = tmp[i][j][k]->color;
                    cube[i][j][k]->color = buff;
                }
            }
        }
        // TODO : Determine final position
    }
    else if(strcmp(extension, EXTENSION_ROT) == 0)
        ReadROT(path, cube);
    else // Unknown extension
        printError("Extension inconnue");
}

void menu() {
    int select = 0;
#ifndef DEBUG
    clearScreen();
#endif /* DEBUG */
    printTitle();
    printf("1) Voir en 2D\n");
    printf("2) Voir en 3D\n");
    printf("3) Quitter\n");
    printf("Votre choix ? ");

    // Error preventing
    if(scanf("%d", &select) != 1) {
        while (getchar() != '\n');
        menu();
    }

    switch(select) {
        case 1:
            displayCube2D(cube);
        break;
        case 2:
            printError("OpenGL non implémenté");
        break;
        case 3:
        break;
        default:
            return menu();
    }
} 

int main(int argc, char** argv) {
    if(argc != 2)
        printError("Nombre d'argument invalide");
#ifdef DEBUG
    executeTest();
#endif
    initCube();
    completeCube(argv[1]);
    resolution_mecanique(cube);
    menu();
    return EXIT_SUCCESS;
}
