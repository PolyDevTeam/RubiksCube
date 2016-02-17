#include "stdio.h"
#include "file.h"
#include "util.h"
#include "rotations.h"
#include <ctype.h>
#include <string.h>

FILE* openFile(char* path, char* mode) {
    FILE* file = fopen(path, mode);
    return file;
}

void closeFile(FILE* file) {
    fclose(file);
}

char* toUpper(char* str) {
    for(int i = 0; i < strlen(str); ++i)
        str[i] = (char) toupper((int) str[i]);
    return str;
}

int translateWord(char* word) {
    char* str = toUpper(word);
    if(strcmp(str, JSON_LEFT) == 0)
        return SIDE_LEFT;
    if(strcmp(str, JSON_FRONT) == 0)
        return SIDE_FRONT;
    if(strcmp(str, JSON_UPPER) == 0)
        return SIDE_UPPER;
    if(strcmp(str, JSON_BOTTOM) == 0)
        return SIDE_BOTTOM;
    if(strcmp(str, JSON_RIGHT) == 0)
        return SIDE_RIGHT;
    if(strcmp(str, JSON_BEHIND) == 0)
        return SIDE_BEHIND;
    if(strcmp(str, JSON_RED) == 0)
        return COLOR_RED;
    if(strcmp(str, JSON_BLUE) == 0)
        return COLOR_BLUE;
    if(strcmp(str, JSON_YELLOW) == 0)
        return COLOR_YELLOW;
    if(strcmp(str, JSON_WHITE) == 0)
        return COLOR_WHITE;
    if(strcmp(str, JSON_GREEN) == 0)
        return COLOR_GREEN;
    if(strcmp(str, JSON_ORANGE) == 0)
        return COLOR_ORANGE;
    if(strcmp(str, JSON_NONE) == 0)
        return COLOR_NONE;
    return -1;
}

char* reverseTranslateWord(int value) {
    switch(value) {
        case SIDE_LEFT:
            return JSON_LEFT;
        case SIDE_FRONT:
            return JSON_FRONT;
        case SIDE_UPPER:
            return JSON_UPPER;
        case SIDE_BOTTOM:
            return JSON_BOTTOM;
        case SIDE_RIGHT:
            return JSON_RIGHT;
        case SIDE_BEHIND:
            return JSON_BEHIND;
        case COLOR_RED:
            return JSON_RED;
        case COLOR_BLUE:
            return JSON_BLUE;
        case COLOR_YELLOW:
            return JSON_YELLOW;
        case COLOR_WHITE:
            return JSON_WHITE;
        case COLOR_GREEN:
            return JSON_GREEN;
        case COLOR_ORANGE:
            return JSON_ORANGE;
        default:
            return JSON_NONE;
    }
}
void readJSON(char * path, miniCube tmp[6][N][N]) {
    /*
     * Exemple of syntax :
     * {
            "left": ["BLUE", "RED", "GREEN", "YELLOW", "YELLOW", "WHITE", "RED", "YELLOW", "GREEN"],
            "front": ["RED", "GREEN", "WHITE", "GREEN", "BLUE", "WHITE", "YELLOW", "ORANGE", "GREEN"],
            "upper": ["YELLOW", "GREEN", "YELLOW", "YELLOW", "RED", "BLUE", "WHITE", "RED", "BLUE"],
            "bottom": ["ORANGE", "BLUE", "WHITE", "ORANGE", "ORANGE", "WHITE", "YELLOW", "WHITE", "ORANGE"],
            "right": ["RED", "YELLOW", "BLUE", "ORANGE", "WHITE", "BLUE", "ORANGE", "BLUE", "BLUE"],
            "behind": ["RED", "ORANGE", "ORANGE", "RED", "GREEN", "GREEN", "WHITE", "RED", "GREEN"],
        }
     */

    char str[200];
    char* buff;
    int index;
    int i = 0;
    int j = 0;
    int lastTranslated;

    FILE* file = openFile(path, OPEN_READ);

    if(!file)
        printError("Impossible d'ouvrir le fichier demande");

    while(fgets(str, 200, file)) {
        i = 0;
        j = 0;
        buff = strtok (str, "{}:[], \"");
        do {
            if(buff != NULL) {
                buff = toUpper(buff);
                lastTranslated = translateWord(buff);
                if(lastTranslated < 10) // TODO : Improve this condition
                    index = lastTranslated;
                else {
                    if(j == N) {
                        j = 0;
                        ++i;
                    }
                    if(i == N)
                        i = 0;
                    tmp[index][i][j]->color = lastTranslated;
                    ++j;
                }
            }
            buff = strtok (NULL, "{}:[], \"");
        } while(buff != NULL);
    }
    closeFile(file);
}

void translateRotation(miniCube cube[6][N][N], char car, int direction) {
    switch(car) {
        case 'U':
            if(direction == DIRECTION_NORMAL)
                up_rotation(cube);
            else
                up_rotation_reverse(cube);
        break;
        case 'L':
            if(direction == DIRECTION_NORMAL)
                left_rotation(cube);
            else
                left_rotation_reverse(cube);
            break;
        case 'F':
            if(direction == DIRECTION_NORMAL)
                front_rotation(cube);
            else
                front_rotation_reverse(cube);
        break;
        case 'R':
            if(direction == DIRECTION_NORMAL)
                right_rotation(cube);
            else
                right_rotation_reverse(cube);
        break;
        case 'B':
            cube_rotation_side(cube);
            cube_rotation_side(cube);
            if(direction == DIRECTION_NORMAL)
                front_rotation(cube);
            else
                front_rotation_reverse(cube);
            cube_rotation_side(cube);
            cube_rotation_side(cube);
        break;
        case 'D':
            if(direction == DIRECTION_NORMAL)
                down_rotation(cube);
            else
                down_rotation_reverse(cube);
        break;
        case 'M':
            if(direction == DIRECTION_NORMAL)
                middle_vectical_rotation(cube);
            else
                middle_vectical_rotation_reverse(cube);
        break;
        case 'u':
            if(direction == DIRECTION_NORMAL) {
                middle_horizontal_rotation(cube);
                up_rotation(cube);
            }
            else {
                middle_horizontal_rotation_reverse(cube);
                up_rotation_reverse(cube);
            }
        break;
        case 'l':
            if(direction == DIRECTION_NORMAL) {
                middle_vectical_rotation(cube);
                left_rotation_reverse(cube);
            }
            else {
                middle_vectical_rotation_reverse(cube);
                left_rotation(cube);
            }
        break;
        case 'E':
            if(direction == DIRECTION_NORMAL) {
                middle_horizontal_rotation(cube);
            }
            else {
                middle_horizontal_rotation_reverse(cube);
            }
        break;
        case 'f':
            if(direction == DIRECTION_NORMAL) {
                front_rotation(cube);
                middle_rotation_side(cube);
            }
            else {
                middle_rotation_side_reverse(cube);
                front_rotation_reverse(cube);
            }
        break;
        case 'r':
            if(direction == DIRECTION_NORMAL) {
                right_rotation(cube);
                middle_vectical_rotation_reverse(cube);
            }
            else {
                right_rotation_reverse(cube);
                middle_vectical_rotation(cube);
            }
        break;
        case 'S':
            if(direction == DIRECTION_NORMAL) {
                middle_rotation_side(cube);
            }
            else {
                middle_rotation_side_reverse(cube);
            }
        break;
        case 'b':
            if(direction == DIRECTION_NORMAL) {
                cube_rotation_side(cube);
                cube_rotation_side(cube);
                front_rotation(cube);
                cube_rotation_side(cube);
                cube_rotation_side(cube);
                middle_rotation_side_reverse(cube);
            }
            else {
                cube_rotation_side(cube);
                cube_rotation_side(cube);
                front_rotation_reverse(cube);
                cube_rotation_side(cube);
                cube_rotation_side(cube);
                middle_rotation_side(cube);
            }
        break;
        case 'd':
            if(direction == DIRECTION_NORMAL) {
                down_rotation_reverse(cube);
                middle_horizontal_rotation_reverse(cube);
            }
            else {
                down_rotation(cube);
                middle_horizontal_rotation(cube);
            }
        break;
        case 'X':
            if(direction == DIRECTION_NORMAL)
                cube_rotation_upside_down(cube);
            else {
                cube_rotation_upside_down(cube);
                cube_rotation_upside_down(cube);
                cube_rotation_upside_down(cube);
            }
        break;
        case 'Y':
            if(direction == DIRECTION_NORMAL) {
                cube_rotation_side(cube);
            }
            else {
                cube_rotation_side(cube);
                cube_rotation_side(cube);
                cube_rotation_side(cube);
            }
        break;
        case 'Z':
            if(direction == DIRECTION_NORMAL) {
                cube_rotation_side(cube);
                cube_rotation_side(cube);
                front_rotation_reverse(cube);
                cube_rotation_side(cube);
                cube_rotation_side(cube);
                middle_rotation_side(cube);
                front_rotation(cube);
            }
            else {
                cube_rotation_side(cube);
                cube_rotation_side(cube);
                front_rotation(cube);
                cube_rotation_side(cube);
                cube_rotation_side(cube);
                middle_rotation_side_reverse(cube);
                front_rotation_reverse(cube);
            }
        break;
        default:
        break;
    }
}

void ReadROT(char* path, miniCube tmp[6][N][N]) {
    /*
     * Exemple of syntax :
     * ULFRBDU'L'F'R'B'D'MuM'lEfE'rSbS'du'Xl'X'f'Yr'Y'b'Zd'Z'U2
     */

    char car = '0';
    char buff;

    FILE* file = openFile(path, OPEN_READ);

    if(!file)
        printError("Impossible d'ouvrir le fichier demande");

    do {
        car = getc(file);
        buff = getc(file);

        if(car == EOF || buff == EOF)
            break;

        fseek(file, -1, SEEK_CUR);

        if(buff == '\'')
            translateRotation(tmp, car, DIRECTION_REVERSE);
        else if(isdigit((int) buff)) {
            for(int i = 0; i < (int)(buff - '0'); ++i)
                translateRotation(tmp, car, DIRECTION_NORMAL);
        }
        else
            translateRotation(tmp, car, DIRECTION_NORMAL);
    } while(car != EOF);
}

char* getExtension(char* path) {
    char *dotPosition = strrchr(path, '.');
    if(dotPosition == NULL || dotPosition == path)
    	return "";
    return dotPosition;
}

void saveCubeJSON(int cube[6][N][N]) {
    FILE* file = openFile("output/save.json", "w");

    if (file != NULL) {
        fprintf(file, "{\n");

        for(int i = 0; i < 6; ++i) {
            fprintf(file, "\t\"%s\": [", reverseTranslateWord(i));
            for(int j = 0; j < N; ++j) {
                for(int k = 0; k < N; ++k)
                    if(j == N - 1 && k == N - 1)
                        fprintf(file, "\"%s\"", reverseTranslateWord(cube[i][j][k]));
                    else
                        fprintf(file, "\"%s\", ", reverseTranslateWord(cube[i][j][k]));
            }
            fprintf(file, "],\n");
        }
        fprintf(file, "}\n");

        closeFile(file);
    }
    else
        printError("Impossible d'ouvrir le fichier test.txt");
}

void saveCube(miniCube cube[6][N][N], char* extension) {
    int cubeTmp[6][N][N];
    getColorArray(cube, cubeTmp);
    if(strcmp(extension, EXTENSION_JSON) == 0)
        saveCubeJSON(cubeTmp);
    else
        printError("Extension inconnue");
}
