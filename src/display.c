#include <SDL/SDL.h>
#include <time.h> // rand()
#include "display.h"
#include "file.h"
#include "rotations.h"
#include "util.h"
#include "resolution_mecanique.h"

static int goContinue = 1;
static SDL_Surface* screen = NULL;

Uint32 getSDLColor(int color) {
    switch(color) {
        case COLOR_WHITE:
            return SDL_MapRGB(screen->format, 255, 255, 255);
        case COLOR_BLUE:
            return SDL_MapRGB(screen->format, 38, 18, 222);
        case COLOR_GREEN:
            return SDL_MapRGB(screen->format, 18, 222, 35);
        case COLOR_RED:
            return SDL_MapRGB(screen->format, 222, 18, 18);
        case COLOR_ORANGE:
            return SDL_MapRGB(screen->format, 222, 89, 18);
        case COLOR_YELLOW:
            return SDL_MapRGB(screen->format, 226, 245, 24);
        case COLOR_NONE:
        default:
            return 0;
    }
}

void changeFaceColor(miniCube cube[6][N][N], int side, int i, int j, int color) {
    cube[side][i][j]->color = color;
}

SDL_Surface* createFace() {
    return SDL_CreateRGBSurface(SDL_HWSURFACE, FACE_SIZE, FACE_SIZE, 32, 0, 0, 0, 0);
}

void freeFace(SDL_Surface* screen) {
    SDL_FreeSurface(screen);
}

void printLeftSide(miniCube cube[N][N]) {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            SDL_Rect pos;
            SDL_Surface* faceScreen = createFace();
            int tmp = cube[i][j]->color;
            pos.x = j*FACE_SIZE + 5*j + 100;
            pos.y = SCREEN_HEIGHT/2 - ((N-i-1)*FACE_SIZE + 5*(N-i));
            SDL_FillRect(faceScreen, NULL, getSDLColor(tmp));
            SDL_BlitSurface(faceScreen, NULL, screen, &pos);
        }
    }
}

void printFrontSide(miniCube cube[N][N]) {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            SDL_Rect pos;
            SDL_Surface* faceScreen = createFace();
            int tmp = cube[i][j]->color;
            pos.x = j*FACE_SIZE + 5*j + 100 + (3*FACE_SIZE + 4*5);
            pos.y = SCREEN_HEIGHT/2 - ((N-i-1)*FACE_SIZE + 5*(N-i));
            SDL_FillRect(faceScreen, NULL, getSDLColor(tmp));
            SDL_BlitSurface(faceScreen, NULL, screen, &pos);
        }
    }
}

void printUpperSide(miniCube cube[N][N]) {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            SDL_Rect pos;
            SDL_Surface* faceScreen = createFace();
            int tmp = cube[i][j]->color;
            pos.x = j*FACE_SIZE + 5*j + 100 + (3*FACE_SIZE + 4*5);
            pos.y = SCREEN_HEIGHT/2 - ((N-i-1)*FACE_SIZE + 5*(N-i)) - (3*FACE_SIZE + 4*5);
            SDL_FillRect(faceScreen, NULL, getSDLColor(tmp));
            SDL_BlitSurface(faceScreen, NULL, screen, &pos);
        }
    }
}

void printBottomSide(miniCube cube[N][N]) {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            SDL_Rect pos;
            SDL_Surface* faceScreen = createFace();
            int tmp = cube[i][j]->color;
            pos.x = j*FACE_SIZE + 5*j + 100 + (3*FACE_SIZE + 4*5);
            pos.y = SCREEN_HEIGHT/2 - ((N-i-1)*FACE_SIZE + 5*(N-i)) + (3*FACE_SIZE + 4*5);
            SDL_FillRect(faceScreen, NULL, getSDLColor(tmp));
            SDL_BlitSurface(faceScreen, NULL, screen, &pos);
        }
    }
}

void printRightSide(miniCube cube[N][N]) {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            SDL_Rect pos;
            SDL_Surface* faceScreen = createFace();
            int tmp = cube[i][j]->color;
            pos.x = j*FACE_SIZE + 5*j + 100 + (3*FACE_SIZE + 4*5)*2;
            pos.y = SCREEN_HEIGHT/2 - ((N-i-1)*FACE_SIZE + 5*(N-i));
            SDL_FillRect(faceScreen, NULL, getSDLColor(tmp));
            SDL_BlitSurface(faceScreen, NULL, screen, &pos);
        }
    }
}

void printBehindSide(miniCube cube[N][N]) {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            SDL_Rect pos;
            SDL_Surface* faceScreen = createFace();
            int tmp = cube[i][j]->color;
            pos.x = j*FACE_SIZE + 5*j + 100 + (3*FACE_SIZE + 4*5)*3;
            pos.y = SCREEN_HEIGHT/2 - ((N-i-1)*FACE_SIZE + 5*(N-i));
            SDL_FillRect(faceScreen, NULL, getSDLColor(tmp));
            SDL_BlitSurface(faceScreen, NULL, screen, &pos);
        }
    }
}

void printLibelleCube(miniCube cube[6][N][N]) {
/*
 *
 * Exemple :
                     ----- ----- -----
                    | A00 | A01 | A02 |
                     ----- ----- -----
                    | A10 | A11 | A12 |
                     ----- ----- -----
                    | A20 | A21 | A31 |
                     ----- ----- -----
 ----- ----- -----   ----- ----- -----   ----- ----- -----   ----- ----- -----
| A00 | A01 | A02 | | A00 | A01 | A02 | | A00 | A01 | A02 | | A00 | A01 | A02 |
 ----- ----- -----   ----- ----- -----   ----- ----- -----   ----- ----- -----
| A10 | A11 | A12 | | A10 | A11 | A12 | | A10 | A11 | A12 | | A10 | A11 | A12 |
 ----- ----- -----   ----- ----- -----   ----- ----- -----   ----- ----- -----
| A20 | A21 | A31 | | A20 | A21 | A31 | | A20 | A21 | A31 | | A20 | A21 | A31 |
 ----- ----- -----   ----- ----- -----   ----- ----- -----   ----- ----- -----
                     ----- ----- -----
                    | A00 | A01 | A02 |
                     ----- ----- -----
                    | A10 | A11 | A12 |
                     ----- ----- -----
                    | A20 | A21 | A31 |
                     ----- ----- -----
 */

    /* Space for upper side */

    for(int i = 0; i < N; ++i) {
        for(int k = 0; k < 20; ++k)
            printf(" ");
        printf(" ----- ----- -----\n");
        for(int k = 0; k < 20; ++k)
            printf(" ");
        for(int j = 0; j < N; ++j) {
            printf("| %03d ", cube[SIDE_UPPER][i][j]->finalPos);
        }
        printf("|\n");
    }
    for(int k = 0; k < 20; ++k)
        printf(" ");
    printf(" ----- ----- -----\n");

    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < N; ++j) {
            printf(" -----");
        }
        printf("  ");
    }
    printf("\n");

    int selectColumn = 0;
    int sideSelect;

    while(selectColumn != N) {
        sideSelect = SIDE_LEFT;
        for(int i = 0; i < 4; ++i) {
            for(int j = 0; j < N; ++j) {
                printf("| %03d ", cube[sideSelect][selectColumn][j]->finalPos);
            }
            sideSelect++;
            if(sideSelect == SIDE_UPPER || sideSelect == SIDE_BOTTOM)
                sideSelect = SIDE_RIGHT;
            printf("| ");
        }
        printf("\n");

        for(int i = 0; i < 4; ++i) {
            for(int j = 0; j < N; ++j) {
                printf(" -----");
            }
            printf("  ");
        }
        printf("\n");
        ++selectColumn;
    }

    /* Bottom side */

    for(int i = 0; i < N; ++i) {
        for(int k = 0; k < 20; ++k)
            printf(" ");
        printf(" ----- ----- -----\n");
        for(int k = 0; k < 20; ++k)
            printf(" ");
        for(int j = 0; j < N; ++j) {
            printf("| %03d ", cube[SIDE_BOTTOM][i][j]->finalPos);
        }
        printf("|\n");
    }
    for(int k = 0; k < 20; ++k)
        printf(" ");
    printf(" ----- ----- -----\n");
}

void printHelp() {
    printf("Rappel :\n\n");
    printf("- U : Rotation haut\n");
    printf("- L : Rotation gauche\n");
    printf("- F : Rotation de face\n");
    printf("- R : Rotation droite\n");
    printf("- B : Rotation face arriere\n");
    printf("- D : Rotation bas\n");
    printf("- M : Rotation milieu vertical\n");
    printf("- E : Rotation milieu horizontal\n");
    printf("- X : Rotation du cube de facon vertical\n");
    printf("- Y : Rotation du cube de facon horizontal\n");
    printf("- Tab : Reset du cube\n");
    printf("- CTRL : Inverse le sens de rotation\n");
    printf("- S : Sauvegarde le cube courant\n");
    printf("- Entree : Resoudre le cube de facon mecanique\n");
    printf("- CTRL + Entree : Resoudre le cube de facon optimise\n");
    printf("- * : Melange le cube\n\n");
}

typedef struct
{
    char key[SDLK_LAST];
} Input;

void keyboardEventManager(SDLKey key, miniCube cube[6][N][N], Input* in) {
    switch (key) {
        case SDLK_u:
            if(in->key[SDLK_LCTRL] == 0)
                up_rotation(cube);
            else
                up_rotation_reverse(cube);
        break;
        case SDLK_l:
            if(in->key[SDLK_LCTRL] == 0)
                left_rotation_reverse(cube);
            else
                left_rotation(cube);
        break;
        case SDLK_f:
            if(in->key[SDLK_LCTRL] == 0)
                front_rotation(cube);
            else
                front_rotation_reverse(cube);
        break;
        case SDLK_r:
            if(in->key[SDLK_LCTRL] == 0)
                right_rotation(cube);
            else
                right_rotation_reverse(cube);
        break;
        case SDLK_b:
            cube_rotation_side(cube);
            cube_rotation_side(cube);
            if(in->key[SDLK_LCTRL] == 0)
                front_rotation(cube);
            else
                front_rotation_reverse(cube);
            cube_rotation_side(cube);
            cube_rotation_side(cube);
        break;
        case SDLK_d:
            if(in->key[SDLK_LCTRL] == 0)
                down_rotation_reverse(cube);
            else
                down_rotation(cube);
        break;
        case SDLK_m:
            if(in->key[SDLK_LCTRL] == 0)
                middle_vectical_rotation(cube);
            else
                middle_vectical_rotation_reverse(cube);
        break;
        case SDLK_e:
            if(in->key[SDLK_LCTRL] == 0)
                middle_horizontal_rotation(cube);
            else
                middle_horizontal_rotation_reverse(cube);
        break;
        case SDLK_x:
            if(in->key[SDLK_LCTRL] == 0)
                cube_rotation_upside_down(cube);
            else {
                cube_rotation_upside_down(cube);
                cube_rotation_upside_down(cube);
                cube_rotation_upside_down(cube);
            }
        break;
        case SDLK_y:
            if(in->key[SDLK_LCTRL] == 0)
                cube_rotation_side(cube);
            else {
                cube_rotation_side(cube);
                cube_rotation_side(cube);
                cube_rotation_side(cube);
            }
        break;
        case SDLK_TAB:
            for(int i = 0; i < 6; ++i) {
                for(int j = 0; j < N; ++j) {
                    for(int k = 0; k < N; ++k) {
                        cube[i][j][k]->color = getFinalColorId(i);
                        cube[i][j][k]->finalPos = getFinalLibelle(i, j, k);
                    }
                }
            }
        break;
        case SDLK_s:
            saveCube(cube, EXTENSION_JSON);
        break;
        case SDLK_RETURN:
            if(in->key[SDLK_LCTRL] == 0)
                resolution_mecanique(cube);
            else
                printf("RESOUDRE !!!!\n");
        break;
        case SDLK_ASTERISK:
        {
            // TODO : Créer une fonction
            int selectRotation;
            srand(time(NULL)); // initialisation de rand
            for(int i = 0; i < RAND_SIZE; ++i) {
                selectRotation = rand()%24;
                switch(selectRotation) {
                    case 0:
                        up_rotation(cube);
                        printf("U");
                    break;
                    case 1:
                        up_rotation_reverse(cube);
                        printf("U'");
                    break;
                    case 2:
                        left_rotation(cube);
                        printf("L");
                    break;
                    case 3:
                        left_rotation_reverse(cube);
                        printf("L'");
                    break;
                    case 4:
                        front_rotation(cube);
                        printf("F");
                    break;
                    case 5:
                        front_rotation_reverse(cube);
                        printf("F'");
                    break;
                    case 6:
                        right_rotation(cube);
                        printf("R");
                    break;
                    case 7:
                        right_rotation_reverse(cube);
                        printf("R'");
                    break;
                    case 8:
                        cube_rotation_side(cube);
                        cube_rotation_side(cube);
                        front_rotation(cube);
                        cube_rotation_side(cube);
                        cube_rotation_side(cube);
                        printf("B");
                    break;
                    case 9:
                        cube_rotation_side(cube);
                        cube_rotation_side(cube);
                        front_rotation_reverse(cube);
                        cube_rotation_side(cube);
                        cube_rotation_side(cube);
                        printf("B'");
                    break;
                    case 10:
                        down_rotation(cube);
                        printf("D");
                    break;
                    case 11:
                        down_rotation_reverse(cube);
                        printf("D'");
                    break;
                    case 12:
                        middle_vectical_rotation(cube);
                        printf("M");
                    break;
                    case 13:
                        middle_vectical_rotation_reverse(cube);
                        printf("M'");
                    break;
                    case 14:
                        middle_horizontal_rotation(cube);
                        printf("E");
                    break;
                    case 15:
                        middle_horizontal_rotation_reverse(cube);
                        printf("E'");
                    break;
                    case 16:
                        middle_rotation_side(cube);
                        printf("S");
                    break;
                    case 17:
                        middle_rotation_side_reverse(cube);
                        printf("S'");
                    break;
                    case 18:
                        cube_rotation_upside_down(cube);
                        printf("X");
                    break;
                    case 19:
                        cube_rotation_upside_down(cube);
                        cube_rotation_upside_down(cube);
                        cube_rotation_upside_down(cube);
                        printf("X'");
                    break;
                    case 20:
                        cube_rotation_side(cube);
                        printf("Y");
                    break;
                    case 21:
                        cube_rotation_side(cube);
                        cube_rotation_side(cube);
                        cube_rotation_side(cube);
                        printf("Y'");
                    break;
                    case 22:
                        cube_rotation_side(cube);
                        cube_rotation_side(cube);
                        front_rotation_reverse(cube);
                        cube_rotation_side(cube);
                        cube_rotation_side(cube);
                        middle_rotation_side(cube);
                        front_rotation(cube);
                        printf("Z");
                    break;
                    case 23:
                        cube_rotation_side(cube);
                        cube_rotation_side(cube);
                        front_rotation(cube);
                        cube_rotation_side(cube);
                        cube_rotation_side(cube);
                        middle_rotation_side_reverse(cube);
                        front_rotation_reverse(cube);
                        printf("Z'");
                    break;
                    default: break;
                }
            }
            printf("\nFINI\n");
        }
        break;
        default: break;
    }

    clearScreen();
    printTitle();
    printHelp();
    printLibelleCube(cube);

#ifdef DEBUG
    if(key >= 'a' && key <= 'z')
        printf("Key pressed : %c\n", key - 32);
    if(key == SDLK_TAB)
        printf("Key pressed : TAB\n");
    if(key == SDLK_RETURN)
        printf("Key pressed : RETURN\n");
    if(key == SDLK_ASTERISK)
        printf("Key pressed : ASTERISK\n");
#endif
}

void UpdateEvents(Input* in, miniCube cube[6][N][N])
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
            goContinue = 0;
            break;
            case SDL_KEYDOWN:
                in->key[event.key.keysym.sym] = 1;
                keyboardEventManager(event.key.keysym.sym, cube, in);
            break;
            case SDL_KEYUP:
                in->key[event.key.keysym.sym] = 0;
            break;
            default:
            break;
        }
    }
}

void displayCube2D(miniCube cube[6][N][N]) {
    SDL_Init(SDL_INIT_VIDEO);

    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Rubik's Cube", NULL);

    if(screen == NULL) {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    Input in;
    // init SDL, chargement, tout ce que vous faites avant la boucle.
    memset(&in,0,sizeof(in));

    clearScreen();
    printTitle();
    printHelp();
    printLibelleCube(cube);

    while(goContinue) {
        UpdateEvents(&in, cube);

        SDL_FillRect(screen, NULL, getSDLColor(COLOR_NONE));

        printLeftSide(cube[SIDE_LEFT]);
        printFrontSide(cube[SIDE_FRONT]);
        printUpperSide(cube[SIDE_UPPER]);
        printBottomSide(cube[SIDE_BOTTOM]);
        printRightSide(cube[SIDE_RIGHT]);
        printBehindSide(cube[SIDE_BEHIND]);

        /* Update screen */
        SDL_Flip(screen);
    }

        SDL_Quit();
}
