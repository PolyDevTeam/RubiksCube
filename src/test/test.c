/************************************
 * \file test.c
 * \brief Test unitaire
 *
 * Test les fonctions du programme
 *
 ************************************/

#include "test.h"

#include "../util.h"
#include "../cube.h"
#include "../define.h"
#include "../file.h"
#include "../rotations.h"
#include "../display.h"
#include "../resolution_mecanique.h"

/* Launch test for a function without argument */
/**
 * \fn void test(int (*f)(), void (*init)(), int result)
 * \brief Lance un test unitaire si celui-ci echou alors termine le programme
 * \param (*f)() fonction de test (fonctor)
 * \param (*init)() fonction d'initialisation
 * \param result Resultat du test attendus
 */
void test(int (*f)(), void (*init)(), int result) {
    int res;
    (*init)();
    res = (*f)();

    printf("Run test : ");
    if(res == 0) {
        color(PRINT_COLOR_GREEN);
        printf("OK\n");
        color(PRINT_COLOR_WHITE);
    }
    else {
        color(PRINT_COLOR_RED);
        printf("FAIL !\n");
        color(PRINT_COLOR_WHITE);
        exit(EXIT_FAILURE);
    }
}

/**
 * \fn void testCube(void (*f)(miniCube cube[6][N][N]), char* fileInitPath, char* fileResultPath)
 * \brief Lance un test unitaire si celui-ci echou alors termine le programme
 * \param (*f)() fonction a tester (fonctor) qui prend en paramètre un cube
 * \param fileInitPath Chemin du fichier de cube d'initialisation (format JSON)
 * \param fileResultPath Chemin du fichier de resultat de cube a obtenir (format JSON)
 */
void testCube(void (*f)(miniCube cube[6][N][N]), char* fileInitPath, char* fileResultPath) {
    miniCube tmp[6][N][N];
    miniCube result[6][N][N];

    initCube(tmp);
    initCube(result);

    printf("Run test : ");

    char* extensionInit = getExtension(fileInitPath);
    if(strcmp(extensionInit, EXTENSION_JSON) == 0)
        readJSON(fileInitPath, tmp);
    else if(strcmp(extensionInit, EXTENSION_ROT) == 0)
        ReadROT(fileInitPath, tmp);
    else
        printError("Extension non reconnue");

    char* extensionResult = getExtension(fileInitPath);
    if(strcmp(extensionResult, EXTENSION_JSON) == 0)
        readJSON(fileResultPath, result);
    else if(strcmp(extensionResult, EXTENSION_ROT) == 0)
        ReadROT(fileResultPath, result);
    else
        printError("Extension non reconnue");

    // Launch test function

    (*f)(tmp);

    // Check result

    for(int i = 0; i < 6; ++i) {
        for(int j = 0; j < N; ++j) {
            for(int k = 0; k < N; ++k) {
                int colorTmp = tmp[i][j][k]->color;
                int colorResult = result[i][j][k]->color;

                if(colorTmp != colorResult) {
                    color(PRINT_COLOR_RED);
                    printf("FAIL !\n");
                    color(PRINT_COLOR_WHITE);
                    saveCube(tmp, EXTENSION_JSON);
                    exit(EXIT_FAILURE);
                }
            }
        }
    }

    color(PRINT_COLOR_GREEN);
    printf("OK\n");
    color(PRINT_COLOR_WHITE);
}

/**
 * \fn void executeTest()
 * \brief Lance la série de test unitaire
 */
void executeTest() {
    printf("===> Test Unit : \n");
    testCube(up_rotation, "input/cube.json", "input/testUpRotation.json");
    testCube(up_rotation_reverse, "input/testUpRotation.json", "input/cube.json");
    testCube(down_rotation, "input/cube.json", "input/testDownRotation.json");
    testCube(down_rotation_reverse, "input/testDownRotation.json", "input/cube.json");
    testCube(front_rotation, "input/cube.json", "input/testFrontRotation.json");
    testCube(front_rotation_reverse, "input/testFrontRotation.json", "input/cube.json");
    testCube(right_rotation, "input/cube.json", "input/testRightRotation.json");
    testCube(right_rotation_reverse, "input/testRightRotation.json", "input/cube.json");
    testCube(left_rotation, "input/cube.json", "input/testLeftRotation.json");
    testCube(left_rotation_reverse, "input/testLeftRotation.json", "input/cube.json");
    testCube(cube_rotation_side, "input/cube.json", "input/testSideRotation.json");
    testCube(cube_rotation_upside_down, "input/cube.json", "input/testUpsideDownRotation.json");
    testCube(middle_vectical_rotation, "input/cube.json", "input/testMiddleVecticalRotation.json");
    testCube(middle_vectical_rotation_reverse, "input/testMiddleVecticalRotation.json", "input/cube.json");
    testCube(middle_horizontal_rotation, "input/cube.json", "input/testMiddleHorizontalRotation.json");
    testCube(middle_horizontal_rotation_reverse, "input/testMiddleHorizontalRotation.json", "input/cube.json");
    testCube(middle_rotation_side, "input/cube.json", "input/testMiddleSideRotation.json");
    testCube(middle_rotation_side_reverse, "input/testMiddleSideRotation.json", "input/cube.json");
    printf("===> DONE\n");
}
