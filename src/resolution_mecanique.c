#include <stdio.h>
#include "test/test.h"
#include "util.h"
#include "display.h"
#include "file.h"
#include "rotations.h"

/*----------------------------------------------------------------------------*/
int recherche_case(miniCube cube[6][N][N], int x) {
    int i, j, k;
    int pos;

    for (i = 0; i < 6; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < N; k++) {
                if (cube[i][j][k]->finalPos == x) {
                   pos = 9 * i + 3 * j + k;
                }
            }
        }
    }

    return pos;
}

void white_center_placement (miniCube cube[6][N][N]) {
	int n = 0, pos;
	pos = recherche_case(cube, 11);

	while (n < 3 && pos != 13) {
		cube_rotation_side(cube);
		pos = recherche_case(cube, 11);
		n = n + 1;
	}

	n = 0;
	pos = recherche_case(cube, 11);
	while (n < 3 && pos != 13) {
		cube_rotation_upside_down(cube);
		pos = recherche_case(cube, 11);
		n = n + 1;
	}

	n = 0;
	pos = recherche_case(cube, 111);
	while (n < 3 && pos != 40) {
		cube_rotation_upside_down(cube);
		cube_rotation_side(cube);
		cube_rotation_upside_down(cube);
		cube_rotation_upside_down(cube);
		cube_rotation_upside_down(cube);
		pos = recherche_case(cube, 111);
		n = n + 1;
	}

	return ;
}

void white_cross(miniCube cube[6][N][N]) {
	int pos;

	/* positionnement de la case 001 */
	pos = recherche_case(cube, 1);

	if (pos == 37) {
		up_rotation(cube);
	}
	if (pos == 46) {
		up_rotation(cube);
		up_rotation(cube);
	}
	if (pos == 1) {
		up_rotation_reverse(cube);
	}
	if (pos == 21) {
		left_rotation_reverse(cube);
		front_rotation(cube);
	}
	if (pos == 30) {
		left_rotation(cube);
		front_rotation(cube);
	}
	if (pos == 23) {
		right_rotation_reverse(cube);
		front_rotation_reverse(cube);
	}
	if (pos == 32) {
		right_rotation(cube);
		front_rotation_reverse(cube);
	}
	if (pos == 12) {
		front_rotation(cube);
	}
	if(pos == 14) {
		front_rotation_reverse(cube);
	}
	if (pos == 16) {
		front_rotation_reverse(cube);
		front_rotation_reverse(cube);
	}
	if (pos == 7) {
		down_rotation_reverse(cube);
		front_rotation(cube);
		front_rotation(cube);
	}
	if (pos == 43) {
		down_rotation(cube);
		front_rotation(cube);
		front_rotation(cube);
	}
	if (pos == 52) {
		down_rotation(cube);
		down_rotation(cube);
		front_rotation(cube);
		front_rotation(cube);
	}
	if (pos == 3) {
		left_rotation_reverse(cube);
		up_rotation_reverse(cube);
	}
	if (pos == 5) {
		left_rotation(cube);
		up_rotation_reverse(cube);
	}
	if (pos == 39) {
		right_rotation(cube);
		up_rotation(cube);
	}
	if (pos == 41) {
		right_rotation_reverse(cube);
		up_rotation(cube);
	}
	if (pos == 48) {
		right_rotation(cube);
		right_rotation(cube);
		front_rotation_reverse(cube);
	}
	if (pos == 50) {
		left_rotation(cube);
		left_rotation(cube);
		front_rotation(cube);
	}
	if (pos == 25) {
		up_rotation_reverse(cube);
		right_rotation_reverse(cube);
		front_rotation_reverse(cube);
	}
	if (pos == 19) {
		up_rotation(cube);
		right_rotation_reverse(cube);
		front_rotation_reverse(cube);
	}
	if (pos == 28) {
		down_rotation_reverse(cube);
		right_rotation(cube); 
		front_rotation_reverse(cube);
	}
	if (pos == 34) {
		down_rotation(cube);
		right_rotation(cube);
		front_rotation_reverse(cube);
	}


	/* positionnement de la case 010*/
	pos = recherche_case(cube, 10);

	if (pos == 37) {
		front_rotation(cube);
		up_rotation(cube);
		front_rotation_reverse(cube);
	}
	if (pos == 46) {
		front_rotation(cube);
		up_rotation(cube);
		up_rotation(cube);
		front_rotation_reverse(cube);
	}
	if (pos == 1) {
		front_rotation(cube);
		up_rotation_reverse(cube);
		front_rotation_reverse(cube);
	}
	if (pos == 21) {
		left_rotation_reverse(cube);
	}
	if (pos == 30) {
		left_rotation(cube);
	}
	if (pos == 23) {
		front_rotation(cube);
		front_rotation(cube);
		right_rotation_reverse(cube);
		front_rotation_reverse(cube);
		front_rotation_reverse(cube);
	}
	if (pos == 32) {
		front_rotation(cube);
		front_rotation(cube);
		right_rotation(cube);
		front_rotation_reverse(cube);
		front_rotation_reverse(cube);
	}
	if(pos == 14) {
		right_rotation(cube);
		front_rotation_reverse(cube);
		front_rotation_reverse(cube);
		right_rotation_reverse(cube);
		front_rotation(cube);
		front_rotation(cube);
	}
	if (pos == 16) {
		down_rotation(cube);
		front_rotation_reverse(cube);
		down_rotation_reverse(cube);
		front_rotation(cube);
	}
	if (pos == 7) {
		front_rotation_reverse(cube);
		down_rotation_reverse(cube);
		front_rotation(cube);
	}
	if (pos == 43) {
		front_rotation_reverse(cube);
		down_rotation(cube);
		front_rotation(cube);
	}
	if (pos == 52) {
		front_rotation_reverse(cube);
		down_rotation(cube);
		down_rotation(cube);
		front_rotation(cube);
	}
	if (pos == 3) {
		left_rotation(cube);
		front_rotation_reverse(cube);
		down_rotation_reverse(cube);
		front_rotation(cube);

	}
	if (pos == 5) {
		left_rotation_reverse(cube);
		front_rotation_reverse(cube);
		down_rotation_reverse(cube);
		front_rotation(cube);
	}
	if (pos == 39) {
		right_rotation_reverse(cube);
		front_rotation_reverse(cube);
		down_rotation(cube);
		front_rotation(cube);
	}
	if (pos == 41) {
		right_rotation(cube);
		front_rotation_reverse(cube);
		down_rotation(cube);
		front_rotation(cube);
	}
	if (pos == 48) {
		front_rotation(cube);
		front_rotation(cube);
		right_rotation(cube);
		right_rotation(cube);
		front_rotation_reverse(cube);
		front_rotation_reverse(cube);
	}
	if (pos == 50) {
		left_rotation(cube);
		left_rotation(cube);
	}
	if (pos == 19) {
		up_rotation_reverse(cube);
		left_rotation_reverse(cube);
		up_rotation(cube);
	}
	if (pos == 28) {
		down_rotation(cube);
		left_rotation(cube);
	}
	if (pos == 34) {
		down_rotation_reverse(cube);
		left_rotation(cube);
	}

	/* positionnement de la case 012 */
	pos = recherche_case(cube, 12);

	if (pos == 37) {
		front_rotation_reverse(cube);
		up_rotation(cube);
		front_rotation(cube);
	}
	if (pos == 46) {
		front_rotation_reverse(cube);
		up_rotation(cube);
		up_rotation(cube);
		front_rotation(cube);
	}
	if (pos == 1) {
		front_rotation_reverse(cube);
		up_rotation_reverse(cube);
		front_rotation(cube);
	}
	if (pos == 21) {
		front_rotation(cube);
		front_rotation(cube);
		left_rotation_reverse(cube);
		front_rotation_reverse(cube);
		front_rotation_reverse(cube);
	}
	if (pos == 30) {
		front_rotation(cube);
		front_rotation(cube);
		left_rotation(cube);
		front_rotation_reverse(cube);
		front_rotation_reverse(cube);
	}
	if (pos == 23) {
		right_rotation_reverse(cube);

	}
	if (pos == 32) {
		right_rotation(cube);
	}
	if (pos == 16) {
		down_rotation(cube);
		front_rotation(cube);
		down_rotation_reverse(cube);
		front_rotation_reverse(cube);
	}
	if (pos == 7) {
		front_rotation(cube);
		down_rotation_reverse(cube);
		front_rotation_reverse(cube);
	}
	if (pos == 43) {
		front_rotation(cube);
		down_rotation(cube);
		front_rotation_reverse(cube);
	}
	if (pos == 52) {
		front_rotation(cube);
		down_rotation(cube);
		down_rotation(cube);
		front_rotation_reverse(cube);
	}
		if (pos == 3) {
		front_rotation(cube);
		front_rotation(cube);
		left_rotation(cube);
		front_rotation_reverse(cube);
		down_rotation_reverse(cube);
		front_rotation_reverse (cube);
	}
	if (pos == 39) {
		right_rotation(cube);
		front_rotation_reverse(cube);
		up_rotation(cube);
		front_rotation(cube);
	}
	if (pos == 41) {
		right_rotation(cube);
		front_rotation(cube);
		down_rotation(cube);
		front_rotation_reverse(cube);
	}
	if (pos == 48) {
		right_rotation(cube);
		right_rotation(cube);
	}
	if (pos == 50) {
		front_rotation(cube);
		front_rotation(cube);
		left_rotation(cube);
		left_rotation(cube);
		front_rotation_reverse(cube);
		front_rotation_reverse(cube);
	}
	if (pos == 19) {
		front_rotation_reverse(cube);
		up_rotation(cube);
		front_rotation(cube);
		right_rotation_reverse(cube);
	}
	if (pos == 28) {
		down_rotation_reverse(cube);
		right_rotation(cube);
	}
	if (pos == 34) {
		front_rotation(cube);
		down_rotation(cube);
		front_rotation_reverse(cube);
		right_rotation(cube);
	}
	
	/* positionnement de la case 021 */
	pos = recherche_case(cube, 21);

	if (pos == 37) {
		front_rotation_reverse(cube);
		front_rotation_reverse(cube);
		up_rotation(cube);
		front_rotation(cube);
		front_rotation(cube);
	}
	if (pos == 46) {
		front_rotation_reverse(cube);
		front_rotation_reverse(cube);
		up_rotation(cube);
		up_rotation(cube);
		front_rotation(cube);
		front_rotation(cube);
	}
	if (pos == 1) {
		front_rotation_reverse(cube);
		front_rotation_reverse(cube);
		up_rotation_reverse(cube);
		front_rotation(cube);
		front_rotation(cube);
	}
	if (pos == 21) {
		front_rotation(cube);
		left_rotation_reverse(cube);
		front_rotation_reverse(cube);
	}
	if (pos == 30) {
		front_rotation(cube);
		left_rotation(cube);
		front_rotation_reverse(cube);
	}
	if (pos == 23) {
		front_rotation_reverse(cube);
		right_rotation_reverse(cube);
		front_rotation(cube);

	}
	if (pos == 32) {
		front_rotation_reverse(cube);
		right_rotation(cube);
		front_rotation(cube);
	}
	if (pos == 7) {
		down_rotation_reverse(cube);
	}
	if (pos == 43) {
		down_rotation(cube);
	}
	if (pos == 52) {
		down_rotation(cube);
		down_rotation(cube);
	}
	if (pos == 3) {
		left_rotation(cube);
		down_rotation_reverse(cube);
		left_rotation_reverse(cube);
	}
	if (pos == 41) {
		right_rotation(cube);
		down_rotation(cube);
		right_rotation_reverse(cube);
	}
	if (pos == 48) {
		right_rotation(cube);
		front_rotation_reverse(cube);
		right_rotation(cube);
		front_rotation(cube);
		right_rotation_reverse(cube);
		right_rotation_reverse(cube);
	}
	if (pos == 50) {
		front_rotation(cube);
		left_rotation(cube);
		left_rotation(cube);
		front_rotation_reverse(cube);
	}
	if (pos == 19) {
		up_rotation(cube);
		front_rotation_reverse(cube);
		right_rotation_reverse(cube);
		front_rotation(cube);
		up_rotation_reverse(cube);
	}
	if (pos == 28) {
		down_rotation_reverse(cube);
		front_rotation_reverse(cube);
		right_rotation(cube);
		front_rotation(cube);
	}
	if (pos == 34) {
		down_rotation(cube);
		front_rotation_reverse(cube);
		right_rotation(cube);
		front_rotation(cube);
	}
}

void white_face(miniCube cube[6][N][N]) {
	int pos;

	/* recherche de la position de la case 000 */
	pos = recherche_case(cube, 0);

	if (pos == 20) {
		right_rotation(cube);
		down_rotation(cube);
		right_rotation_reverse(cube);
		left_rotation(cube);
		down_rotation_reverse(cube);
		left_rotation_reverse(cube);
	}
	if (pos == 26) {
		right_rotation_reverse(cube);
		down_rotation_reverse(cube);
		left_rotation(cube);
		down_rotation_reverse(cube);
		left_rotation_reverse(cube);
		right_rotation(cube);
	}
	if (pos == 24) {
		front_rotation_reverse(cube);
		down_rotation_reverse(cube);
		down_rotation_reverse(cube);
		front_rotation(cube);
		left_rotation(cube);
		down_rotation_reverse(cube);
		left_rotation_reverse(cube);
	}
	if (pos == 0) {
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		right_rotation_reverse(cube);
		down_rotation(cube);
		right_rotation(cube);
		down_rotation_reverse(cube);
		down_rotation_reverse(cube);
		front_rotation(cube);
		down_rotation(cube);
		front_rotation_reverse(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
	}
	if (pos == 2) {
		front_rotation_reverse(cube);
		down_rotation_reverse(cube);
		front_rotation(cube);
		down_rotation(cube);
		down_rotation(cube);
		left_rotation(cube);
		down_rotation_reverse(cube);
		left_rotation_reverse(cube);
	}
	if (pos == 9) {
		front_rotation_reverse(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		front_rotation(cube);
		down_rotation(cube);
		front_rotation_reverse(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		front_rotation(cube);
	}
	if (pos == 11) {
		front_rotation(cube);
		left_rotation(cube);
		down_rotation_reverse(cube);
		down_rotation_reverse(cube);
		left_rotation_reverse(cube);
		front_rotation_reverse(cube);
	}
	if (pos == 36) {
		right_rotation_reverse(cube);
		down_rotation(cube);
		right_rotation(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		left_rotation_reverse(cube);
		down_rotation(cube);
		left_rotation(cube);
		cube_rotation_side(cube);
	}
	if (pos == 38) {
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		left_rotation_reverse(cube);
		right_rotation_reverse(cube);
		down_rotation_reverse(cube);
		right_rotation(cube);
		left_rotation(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
	}
	if (pos == 45) {
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		front_rotation_reverse(cube);
		down_rotation(cube);
		front_rotation(cube);
		front_rotation(cube);
		down_rotation(cube);
		down_rotation(cube);
		front_rotation_reverse(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
	}
	if (pos == 47) {
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		right_rotation_reverse(cube);
		down_rotation_reverse(cube);
		right_rotation(cube);
		down_rotation(cube);
		right_rotation_reverse(cube);
		down_rotation_reverse(cube);
		right_rotation(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
	}
	if (pos == 6) {
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		down_rotation_reverse(cube);
		front_rotation(cube);
		down_rotation(cube);
		front_rotation_reverse(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
	}
	if (pos == 8) {
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		down_rotation(cube);
		down_rotation(cube);
		right_rotation_reverse(cube);
		down_rotation_reverse(cube);
		right_rotation(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
	}
	if (pos == 15) {
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		left_rotation_reverse(cube);
		down_rotation(cube);
		left_rotation(cube);
		cube_rotation_side(cube);
	}
	if (pos == 17) {
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		right_rotation_reverse(cube);
		down_rotation_reverse(cube);
		down_rotation_reverse(cube);
		right_rotation(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
	}
	if (pos == 42) {
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		front_rotation(cube);
		down_rotation(cube);
		down_rotation(cube);
		front_rotation_reverse(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
	}
	if (pos == 44) {
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		right_rotation_reverse(cube);
		down_rotation_reverse(cube);
		right_rotation(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
	}
	if (pos == 51) {
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		down_rotation_reverse(cube);
		down_rotation_reverse(cube);
		front_rotation(cube);
		down_rotation(cube);
		front_rotation_reverse(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
	}
	if (pos == 53) {
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		down_rotation(cube);
		right_rotation_reverse(cube);
		down_rotation_reverse(cube);
		right_rotation(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
	}
	if (pos == 27) {
		front_rotation_reverse(cube);
		down_rotation_reverse(cube);
		front_rotation(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		down_rotation_reverse(cube);
		down_rotation_reverse(cube);
		front_rotation(cube);
		down_rotation(cube);
		front_rotation_reverse(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
	}
	if (pos == 29) {
		right_rotation_reverse(cube);
		down_rotation_reverse(cube);
		down_rotation_reverse(cube);
		right_rotation(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		left_rotation_reverse(cube);
		down_rotation(cube);
		left_rotation(cube);
		cube_rotation_side(cube);
	}
	if (pos == 33) {
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		front_rotation_reverse(cube);
		down_rotation_reverse(cube);
		front_rotation(cube);
		left_rotation_reverse(cube);
		down_rotation(cube);
		down_rotation(cube);
		left_rotation(cube);
		cube_rotation_side(cube);
	}
	if (pos == 35) {
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		left_rotation_reverse(cube);
		down_rotation(cube);
		left_rotation(cube);
		down_rotation_reverse(cube);
		down_rotation_reverse(cube);
		right_rotation_reverse(cube);
		down_rotation_reverse(cube);
		right_rotation(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
	}

	/* recherche de la position de la case 002 */
	pos = recherche_case(cube, 2);

	if (pos == 26) {
		cube_rotation_side(cube);
		front_rotation_reverse(cube);
		down_rotation(cube);
		front_rotation(cube);
		right_rotation_reverse(cube);
		down_rotation_reverse(cube);
		down_rotation_reverse(cube);
		right_rotation(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
	}
	if (pos == 24) {
		left_rotation_reverse(cube);
		down_rotation_reverse(cube);
		left_rotation(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		down_rotation_reverse(cube);
		down_rotation_reverse(cube);
		left_rotation_reverse(cube);
		down_rotation(cube);
		left_rotation(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
	}
	if (pos == 2) {
		left_rotation_reverse(cube);
		down_rotation_reverse(cube);
		left_rotation(cube);
		cube_rotation_side(cube);
		right_rotation_reverse(cube);
		down_rotation_reverse(cube);
		right_rotation(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
	}
	if (pos == 9) {
		front_rotation_reverse(cube);
		down_rotation(cube);
		front_rotation(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		left_rotation_reverse(cube);
		down_rotation(cube);
		left_rotation(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
	}
	if (pos == 11) {
		right_rotation_reverse(cube);
		down_rotation_reverse(cube);
		right_rotation(cube);
		cube_rotation_side(cube);
		right_rotation_reverse(cube);
		down_rotation_reverse(cube);
		right_rotation(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
	}
	if (pos == 36) {
		right_rotation_reverse(cube);
		down_rotation(cube);
		right_rotation(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		left_rotation_reverse(cube);
		down_rotation(cube);
		down_rotation(cube);
		left_rotation(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
	}
	if (pos == 38) {
		cube_rotation_side(cube);
		right_rotation_reverse(cube);
		down_rotation_reverse(cube);
		right_rotation(cube);
		down_rotation(cube);
		right_rotation_reverse(cube);
		down_rotation_reverse(cube);
		right_rotation(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
	}
	if (pos == 45) {
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		front_rotation_reverse(cube);
		down_rotation_reverse(cube);
		down_rotation_reverse(cube);
		front_rotation(cube);
		left_rotation_reverse(cube);
		down_rotation(cube);
		down_rotation(cube);
		left_rotation(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
	}
	if (pos == 6) {
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		left_rotation_reverse(cube);
		down_rotation(cube);
		left_rotation(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
	}
	if (pos == 8) {
		cube_rotation_side(cube);
		right_rotation_reverse(cube);
		down_rotation_reverse(cube);
		down_rotation_reverse(cube);
		right_rotation(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
	}
	if (pos == 15) {
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		left_rotation_reverse(cube);
		down_rotation(cube);
		down_rotation(cube);
		left_rotation(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
	}
	if (pos == 17) {
		cube_rotation_side(cube);
		right_rotation_reverse(cube);
		down_rotation_reverse(cube);
		right_rotation(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
	}
	if (pos == 42) {
		cube_rotation_side(cube);
		down_rotation(cube);
		down_rotation(cube);
		front_rotation(cube);
		down_rotation(cube);
		front_rotation_reverse(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
	}
	if (pos == 44) {
		 cube_rotation_side(cube);
		 down_rotation(cube);
		 right_rotation_reverse(cube);
		 down_rotation_reverse(cube);
		 right_rotation(cube);
		 cube_rotation_side(cube);
		 cube_rotation_side(cube);
		 cube_rotation_side(cube);
	}
	if (pos == 51) {
		cube_rotation_side(cube);
		down_rotation_reverse(cube);
		front_rotation(cube);
		down_rotation(cube);
		front_rotation_reverse(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
	}
	if (pos == 53) {
		cube_rotation_side(cube);
		down_rotation_reverse(cube);
		down_rotation_reverse(cube);
		right_rotation_reverse(cube);
		down_rotation_reverse(cube);
		right_rotation(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
	}
	if (pos == 27) {
		left_rotation_reverse(cube);
		down_rotation_reverse(cube);
		down_rotation_reverse(cube);
		left_rotation(cube);
		cube_rotation_side(cube);
		right_rotation_reverse(cube);
		down_rotation_reverse(cube);
		right_rotation(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
	}
	if (pos == 29) {
		front_rotation(cube);
		down_rotation_reverse(cube);
		down_rotation_reverse(cube);
		front_rotation_reverse(cube);
		down_rotation(cube);
		cube_rotation_side(cube);
		right_rotation_reverse(cube);
		down_rotation_reverse(cube);
		right_rotation(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
	}
	if (pos == 33) {
		down_rotation_reverse(cube);
		left_rotation_reverse(cube);
		down_rotation_reverse(cube);
		down_rotation_reverse(cube);
		left_rotation(cube);
		cube_rotation_side(cube);
		right_rotation_reverse(cube);
		down_rotation_reverse(cube);
		right_rotation(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
	}
	if (pos == 35) {
		down_rotation(cube);
		front_rotation(cube);
		down_rotation_reverse(cube);
		down_rotation_reverse(cube);
		front_rotation_reverse(cube);
		down_rotation(cube);
		cube_rotation_side(cube);
		right_rotation_reverse(cube);
		down_rotation_reverse(cube);
		right_rotation(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
	}

		/* recherche de la position de la case 020 */
	pos = recherche_case(cube, 20);

	if (pos == 26) {
		front_rotation(cube);
		down_rotation_reverse(cube);
		front_rotation_reverse(cube);
		left_rotation_reverse(cube);
		down_rotation(cube);
		down_rotation(cube);
		left_rotation(cube);
	}
	if (pos == 2) {
		front_rotation_reverse(cube);
		down_rotation_reverse(cube);
		front_rotation(cube);
		down_rotation(cube);
		front_rotation_reverse(cube);
		down_rotation_reverse(cube);
		front_rotation(cube);
	}
	if (pos == 9) {
		front_rotation_reverse(cube);
		down_rotation(cube);
		front_rotation(cube);
		down_rotation_reverse(cube);
		down_rotation_reverse(cube);
		left_rotation_reverse(cube);
		down_rotation(cube);
		left_rotation(cube);
	}
	if (pos == 11) {
		right_rotation_reverse(cube);
		down_rotation_reverse(cube);
		right_rotation(cube);
		down_rotation(cube);
		down_rotation(cube);
		front_rotation_reverse(cube);
		down_rotation_reverse(cube);
		front_rotation(cube);
	}
	if (pos == 36) {
		right_rotation_reverse(cube);
		down_rotation(cube);
		right_rotation(cube);
		down_rotation_reverse(cube);
		left_rotation_reverse(cube);
		down_rotation(cube);
		left_rotation(cube);
	}
	if (pos == 6) {
		down_rotation_reverse(cube);
		down_rotation_reverse(cube);
		left_rotation_reverse(cube);
		down_rotation(cube);
		left_rotation(cube);
	}
	if (pos == 8) {
		down_rotation(cube);
		front_rotation_reverse(cube);
		down_rotation_reverse(cube);
		front_rotation(cube);
	}
	if (pos == 15) {
		down_rotation_reverse(cube);
		left_rotation_reverse(cube);
		down_rotation(cube);
		left_rotation(cube);
	}
	if (pos == 17) {
		down_rotation(cube);
		down_rotation(cube);
		front_rotation_reverse(cube);
		down_rotation_reverse(cube);
		front_rotation(cube);
	}
	if (pos == 42) {
		left_rotation_reverse(cube);
		down_rotation(cube);
		left_rotation(cube);
	}
	if (pos == 44) {
		front_rotation_reverse(cube);
		down_rotation_reverse(cube);
		down_rotation_reverse(cube);
		front_rotation(cube);
	}
	if (pos == 51) {
		down_rotation(cube);
		left_rotation_reverse(cube);
		down_rotation(cube);
		left_rotation(cube);
	}
	if (pos == 53) {
		front_rotation_reverse(cube);
		down_rotation_reverse(cube);
		front_rotation(cube);
	}
	if (pos == 27) {
		left_rotation_reverse(cube);
		down_rotation(cube);
		left_rotation(cube);
		front_rotation_reverse(cube);
		down_rotation_reverse(cube);
		down_rotation_reverse(cube);
		front_rotation(cube);
	}
	if (pos == 29) {
		right_rotation_reverse(cube);
		left_rotation_reverse(cube);
		down_rotation(cube);
		down_rotation(cube);
		left_rotation(cube);
		right_rotation(cube);
	}
	if (pos == 33) {
		down_rotation(cube);
		down_rotation(cube);
		right_rotation_reverse(cube);
		left_rotation_reverse(cube);
		down_rotation(cube);
		down_rotation(cube);
		left_rotation(cube);
		right_rotation(cube);
	}
	if (pos == 35) {
		down_rotation(cube);
		right_rotation_reverse(cube);
		left_rotation_reverse(cube);
		down_rotation(cube);
		down_rotation(cube);
		left_rotation(cube);
		right_rotation(cube);
	}

	/* recherche de la position de la case 022 */
	pos = recherche_case(cube, 22);

	if (pos == 11) {
		right_rotation_reverse(cube);
		down_rotation_reverse(cube);
		right_rotation(cube);
		down_rotation(cube);
		right_rotation_reverse(cube);
		down_rotation_reverse(cube);
		right_rotation(cube);
	}
	if (pos == 36) {
		right_rotation_reverse(cube);
		down_rotation_reverse(cube);
		down_rotation_reverse(cube);
		right_rotation(cube);
		front_rotation(cube);
		down_rotation(cube);
		down_rotation(cube);
		front_rotation_reverse(cube);
	}
	if (pos == 6) {
		front_rotation(cube);
		down_rotation(cube);
		down_rotation(cube);
		front_rotation_reverse(cube);
	}
	if (pos == 8) {
		right_rotation_reverse(cube);
		down_rotation_reverse(cube);
		right_rotation(cube);
	}
	if (pos == 15) {
		down_rotation(cube);
		front_rotation(cube);
		down_rotation(cube);
		down_rotation(cube);
		front_rotation_reverse(cube);
	}
	if (pos == 17) {
		down_rotation(cube);
		right_rotation_reverse(cube);
		down_rotation_reverse(cube);
		right_rotation(cube);
	}
	if (pos == 42) {
		down_rotation_reverse(cube);
		front_rotation(cube);
		down_rotation(cube);
		front_rotation_reverse(cube);
	}
	if (pos == 44) {
		down_rotation_reverse(cube);
		down_rotation_reverse(cube);
		right_rotation_reverse(cube);
		down_rotation_reverse(cube);
		right_rotation(cube);
	}
	if (pos == 51) {
		front_rotation(cube);
		down_rotation(cube);
		front_rotation_reverse(cube);
	}
	if (pos == 53) {
		down_rotation_reverse(cube);
		right_rotation_reverse(cube);
		down_rotation_reverse(cube);
		right_rotation(cube);
	}
	if (pos == 27) {
		down_rotation_reverse(cube);
		right_rotation_reverse(cube);
		down_rotation_reverse(cube);
		right_rotation(cube);
		front_rotation(cube);
		down_rotation(cube);
		down_rotation(cube);
		front_rotation_reverse(cube);
	}
	if (pos == 29) {
		right_rotation_reverse(cube);
		down_rotation_reverse(cube);
		right_rotation(cube);
		front_rotation(cube);
		down_rotation(cube);
		down_rotation(cube);
		front_rotation_reverse(cube);
	}
	if (pos == 33) {
		down_rotation(cube);
		down_rotation(cube);
		right_rotation_reverse(cube);
		down_rotation_reverse(cube);
		right_rotation(cube);
		front_rotation(cube);
		down_rotation(cube);
		down_rotation(cube);
		front_rotation_reverse(cube);
	}
	if (pos == 35) {
		down_rotation(cube);
		right_rotation_reverse(cube);
		down_rotation_reverse(cube);
		right_rotation(cube);
		front_rotation(cube);
		down_rotation(cube);
		down_rotation(cube);
		front_rotation_reverse(cube);
	}
	if (pos == 45) {
		up_rotation(cube);
		right_rotation_reverse(cube);
		down_rotation(cube);
		right_rotation(cube);
		down_rotation_reverse(cube);
		down_rotation_reverse(cube);
		front_rotation(cube);
		down_rotation(cube);
		front_rotation_reverse(cube);
		up_rotation_reverse(cube);
	}
}

void second_line_1(miniCube cube[6][N][N]) {
	int pos;

/* on cherche la position de la case 301 et on la place */
	pos = recherche_case(cube, 301);
	if (pos == 39) {
		second_line_right(cube);
		second_line_1(cube);
	}
	if (pos == 5 || pos == 12) {
		second_line_left(cube);
		second_line_1(cube);
	}
	if (pos == 3 || pos == 50) {
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		second_line_right(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		second_line_1(cube);
	}
	if (pos == 41 || pos == 48) {
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		second_line_left(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		second_line_1(cube);
	}
	if (pos == 16) {
		second_line_right(cube);
	}
	if (pos == 7) {
		down_rotation_reverse(cube);
		second_line_right(cube);
	}
	if (pos == 43) {
		down_rotation(cube);
		second_line_right(cube);
	}
	if (pos == 52) {
		down_rotation(cube);
		down_rotation(cube);
		second_line_right(cube);
	}
	if (pos == 28) {
		down_rotation_reverse(cube);
		cube_rotation_side(cube);
		second_line_left(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
	}
	if (pos == 32) {
		cube_rotation_side(cube);
		second_line_left(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
	}
	if (pos == 34) {
		down_rotation(cube);
		cube_rotation_side(cube);
		second_line_left(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
	}
	if (pos == 30) {
		down_rotation(cube);
		down_rotation(cube);
		cube_rotation_side(cube);
		second_line_left(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
	}

	return ;
}

void second_line_2 (miniCube cube[6][N][N]) {
	int pos;

	/* on cherche la position de la case 321 et on la place */
	pos = recherche_case(cube, 321);
	if (pos == 14 || pos == 39) {
		second_line_right(cube);
		second_line_2(cube);
	}
	if (pos == 5) {
		second_line_left(cube);
		second_line_2(cube);
	}
	if (pos == 3 || pos == 50) {
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		second_line_right(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		second_line_2(cube);
	}
	if (pos == 41 || pos == 48) {
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		second_line_left(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		second_line_2(cube);
	}
	if (pos == 16) {
		second_line_left(cube);
	}
	if (pos == 7) {
		down_rotation_reverse(cube);
		second_line_left(cube);
	}
	if (pos == 43) {
		down_rotation(cube);
		second_line_left(cube);
	}
	if (pos == 52) {
		down_rotation(cube);
		down_rotation(cube);
		second_line_left(cube);
	}
	if (pos == 28) {
		down_rotation(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		second_line_right(cube);
		cube_rotation_side(cube);
	}
	if (pos == 32) {
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		down_rotation(cube);
		down_rotation(cube);
		second_line_right(cube);
		cube_rotation_side(cube);
	}
	if (pos == 34) {
		down_rotation_reverse(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		second_line_right(cube);
		cube_rotation_side(cube);
	}
	if (pos == 30) {
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		second_line_right(cube);
		cube_rotation_side(cube);
	}
}

void second_line_3 (miniCube cube[6][N][N]) {
	int pos;

	/* on cherche la position de la case 221 et on la place */
	pos = recherche_case(cube, 221);
	if (pos == 14 || pos == 39) {
		second_line_right(cube);
		second_line_3(cube);
	}
	if (pos == 5) {
		second_line_left(cube);
		second_line_3(cube);
	}
	if (pos == 3 || pos == 50) {
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		second_line_right(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		second_line_3(cube);
	}
	if (pos == 41 || pos == 48) {
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		second_line_left(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		second_line_3(cube);
	}
	if (pos == 16) {
		second_line_left(cube);
	}
	if (pos == 7) {
		down_rotation_reverse(cube);
		second_line_left(cube);
	}
	if (pos == 43) {
		down_rotation(cube);
		second_line_left(cube);
	}
	if (pos == 52) {
		down_rotation(cube);
		down_rotation(cube);
		second_line_left(cube);
	}
	if (pos == 28) {
		down_rotation(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		second_line_right(cube);
		cube_rotation_side(cube);
	}
	if (pos == 32) {
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		down_rotation(cube);
		down_rotation(cube);
		second_line_right(cube);
		cube_rotation_side(cube);
	}
	if (pos == 34) {
		down_rotation_reverse(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		second_line_right(cube);
		down_rotation(cube);
		cube_rotation_side(cube);
		second_line_right(cube);
	}
	if (pos == 30) {
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		second_line_right(cube);
		cube_rotation_side(cube);
	}
}

void second_line_4(miniCube cube[6][N][N]) {
	int pos;

/* on cherche la position de la case 201 et on la place */
	pos = recherche_case(cube, 201);
	if (pos == 39) {
		second_line_right(cube);
		second_line_4(cube);
	}
	if (pos == 5 || pos == 12) {
		second_line_left(cube);
		second_line_4(cube);
	}
	if (pos == 3 || pos == 50) {
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		second_line_right(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		second_line_4(cube);
	}
	if (pos == 41 || pos == 48) {
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		second_line_left(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		second_line_4(cube);
	}
	if (pos == 16) {
		second_line_right(cube);
	}
	if (pos == 7) {
		down_rotation_reverse(cube);
		second_line_right(cube);
	}
	if (pos == 43) {
		down_rotation(cube);
		second_line_right(cube);
	}
	if (pos == 52) {
		down_rotation(cube);
		down_rotation(cube);
		second_line_right(cube);
	}
	if (pos == 28) {
		down_rotation_reverse(cube);
		cube_rotation_side(cube);
		second_line_left(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
	}
	if (pos == 32) {
		cube_rotation_side(cube);
		second_line_left(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
	}
	if (pos == 34) {
		down_rotation(cube);
		cube_rotation_side(cube);
		second_line_left(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
	}
	if (pos == 30) {
		down_rotation(cube);
		down_rotation(cube);
		cube_rotation_side(cube);
		second_line_left(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
		cube_rotation_side(cube);
	}

	return ;
}

void second_line (miniCube cube[6][N][N]) {
	second_line_1(cube);
	second_line_2(cube);
	cube_rotation_side(cube);
	cube_rotation_side(cube);
	second_line_3(cube);
	second_line_4(cube);
	cube_rotation_side(cube);
	cube_rotation_side(cube);
}

void yellow_cross (miniCube cube[6][N][N]) {
	int pos1, pos2, pos3, pos4;

/* on récupère la postion des quatre petit cube qui formeront la croix jaune */
	pos1 = recherche_case(cube, 401);
	pos2 = recherche_case(cube, 410);
	pos3 = recherche_case(cube, 412);
	pos4 = recherche_case(cube, 421);

	/* si la croix est déjà faite on sort de la fonction */
	if (pos1 == 25 || pos1 == 23 || pos1 == 21 || pos1 == 19) {
		if (pos2 == 25 || pos2 == 23 || pos2 == 21 || pos2 == 19) {
			if (pos3 == 25 || pos3 == 23 || pos3 == 21 || pos3 == 19) {
				if (pos4 == 25 || pos4 == 23 || pos4 == 21 || pos4 == 19) {
					return;
				}
			}
		}
	}

	if (pos1 == 25 || pos2 == 25 || pos3 == 25 || pos4 == 25) {
		if (pos1 == 19 || pos2 == 19 || pos3 == 19 || pos4 == 19) {
			yellow_cross_line(cube);
		}
		if (pos1 == 21 || pos2 == 21 || pos3 == 21 || pos4 == 21) {
			up_rotation(cube);
			yellow_cross_cross(cube);
		}
		if (pos1 == 23 || pos2 == 23 || pos3 == 23 || pos4 == 23) {
			up_rotation(cube);
			up_rotation(cube);
			yellow_cross_cross(cube);
		}
	}

	else if (pos1 == 19 || pos2 == 19 || pos3 == 19 || pos4 == 19) {
		if (pos1 == 21 || pos2 == 21 || pos3 == 21 || pos4 == 21) {
			yellow_cross_cross(cube);
		}
		if (pos1 == 23 || pos2 == 23 || pos3 == 23 || pos4 == 23) {
			up_rotation_reverse(cube);
			yellow_cross_cross(cube);
		}
	}

	else if (pos1 == 21 || pos2 == 21 || pos3 == 21 || pos4 == 21) {
		if (pos1 == 23 || pos2 == 23 || pos3 == 23 || pos4 == 23) {
			up_rotation(cube);
			yellow_cross_line(cube);
		}
	}
	else {
		yellow_cross_cross(cube);
		yellow_cross(cube);
	}

	return ;
}

void yellow_cross_right_orientation (miniCube cube[6][N][N], int p) {
	int pos1, pos2, pos3, n;

	pos1 = recherche_case(cube, p);
	while (pos1 != 10) {
		up_rotation(cube);
		pos1 = recherche_case(cube, p);
	}

	switch(p) {
		case 212:
			pos1 = recherche_case(cube, 510);
			pos2 = recherche_case(cube, 112);
			pos3 = recherche_case(cube, 312);
		break;
		case 112:
			pos1 = recherche_case(cube, 212);
			pos2 = recherche_case(cube, 312);
			pos3 = recherche_case(cube, 510);
		break;
		case 312:
			pos1 = recherche_case(cube, 112);
			pos2 = recherche_case(cube, 510);
			pos3 = recherche_case(cube, 212);
		break;
	}

	n = 0;

	/* si n = 3, on est revenu à l'état de départ */
	while ((n < 3) && (pos1 != 1 || pos2 != 37 || pos3 != 46)) {
		yellow_cross_orientation(cube);
		switch(p) {
		case 212:
			pos1 = recherche_case(cube, 510);
			pos2 = recherche_case(cube, 112);
			pos3 = recherche_case(cube, 312);
		break;
		case 112:
			pos1 = recherche_case(cube, 212);
			pos2 = recherche_case(cube, 312);
			pos3 = recherche_case(cube, 510);
		break;
		case 312:
			pos1 = recherche_case(cube, 112);
			pos2 = recherche_case(cube, 510);
			pos3 = recherche_case(cube, 212);
		break;
		}
		n = n + 1;
	}

	if (pos1 != 1 || pos2 != 37 || pos3 != 46) {
		if (pos1 == 1) {
			cube_rotation_side(cube);
			yellow_cross_right_orientation(cube, 112);
			
		}
		if (pos2 == 37) {
			cube_rotation_side(cube);
			cube_rotation_side(cube);
			yellow_cross_right_orientation(cube, 312);
		}
		if (pos3 == 46) {
			yellow_cross_orientation(cube);
			yellow_cross_right_orientation(cube, 212);
		}
	}

	return ;
}

void yellow_corners_right_placement (miniCube cube[6][N][N], int p) {
	int pos1, pos2, pos3, pos4, n;

	pos4 = recherche_case(cube, p);

	switch(p) {
		case 400:
			pos1 = recherche_case(cube, 402);
			pos2 = recherche_case(cube, 422);
			pos3 = recherche_case(cube, 420);
		break;
		case 420:
			pos1 = recherche_case(cube, 400);
			pos2 = recherche_case(cube, 402);
			pos3 = recherche_case(cube, 422);
		break;
		case 422:
			pos1 = recherche_case(cube, 420);
			pos2 = recherche_case(cube, 400);
			pos3 = recherche_case(cube, 402);
		break;
		case 402:
			pos1 = recherche_case(cube, 422);
			pos2 = recherche_case(cube, 420);
			pos3 = recherche_case(cube, 400);
		break;
		}

	if (pos4 == 11 || pos4 == 26 || pos4 == 36) {
		n = 0;

		while ((n < 3) && (pos1 != 9 && pos1 != 2 && pos1 != 24)) {
			yellow_corners_placement(cube);
			switch(p) {
				case 400:
					pos1 = recherche_case(cube, 402);
					pos2 = recherche_case(cube, 422);
					pos3 = recherche_case(cube, 420);
				break;
				case 420:
					pos1 = recherche_case(cube, 400);
					pos2 = recherche_case(cube, 402);
					pos3 = recherche_case(cube, 422);
				break;
				case 422:
					pos1 = recherche_case(cube, 420);
					pos2 = recherche_case(cube, 400);
					pos3 = recherche_case(cube, 402);
				break;
				case 402:
					pos1 = recherche_case(cube, 422);
					pos2 = recherche_case(cube, 420);
					pos3 = recherche_case(cube, 400);
				break;
			}
			n = n + 1;
		}
	}

	else {
		if (pos1 == 2 || pos1 == 9 || pos1 == 24) {
			cube_rotation_side(cube);
			cube_rotation_side(cube);
			cube_rotation_side(cube);
			yellow_corners_right_placement(cube, 402);
		}
		else if (pos2 == 0 || pos2 == 18 || pos2 ==47) {
			cube_rotation_side(cube);
			cube_rotation_side(cube);
			yellow_corners_right_placement(cube, 422);
		}
		else if (pos3 == 20 || pos3 == 38 || pos3 ==45) {
			cube_rotation_side(cube);
			yellow_corners_right_placement(cube, 420);
		}
		else {
			yellow_corners_placement(cube);
			yellow_corners_right_placement(cube, 400);
		}
	}

	return ;
}

void yellow_corners_right_orientation (miniCube cube[6][N][N], int p) {
	int pos1, pos2, pos3, pos4, n;

	pos4 = recherche_case(cube, p);
	n = 0;

	switch(p) {
		case 400:
			pos1 = recherche_case(cube, 402);
			pos2 = recherche_case(cube, 422);
			pos3 = recherche_case(cube, 420);
		break;
		case 420:
			pos1 = recherche_case(cube, 400);
			pos2 = recherche_case(cube, 402);
			pos3 = recherche_case(cube, 422);
		break;
		case 422:
			pos1 = recherche_case(cube, 420);
			pos2 = recherche_case(cube, 400);
			pos3 = recherche_case(cube, 402);
		break;
		case 402:
			pos1 = recherche_case(cube, 422);
			pos2 = recherche_case(cube, 420);
			pos3 = recherche_case(cube, 400);
		break;
	}

	if (pos1 != 24 && pos2 != 18 && pos3 != 20 && pos4 != 26) {
		yellow_corners_orientation(cube);
		yellow_corners_right_orientation(cube, p);
	}

	else if (pos1 != 24) {
		while (n < 3 && (pos4 != 24 && pos2 != 24 && pos3 != 24)) {
			cube_rotation_side(cube);
			switch(p) {
				case 400:
					pos1 = recherche_case(cube, 402);
					pos2 = recherche_case(cube, 422);
					pos3 = recherche_case(cube, 420);
					pos4 = recherche_case(cube, 400);
				break;
				case 420:
					pos1 = recherche_case(cube, 400);
					pos2 = recherche_case(cube, 402);
					pos3 = recherche_case(cube, 422);
					pos4 = recherche_case(cube, 420);
				break;
				case 422:
					pos1 = recherche_case(cube, 420);
					pos2 = recherche_case(cube, 400);
					pos3 = recherche_case(cube, 402);
					pos4 = recherche_case(cube, 422);
				break;
				case 402:
					pos1 = recherche_case(cube, 422);
					pos2 = recherche_case(cube, 420);
					pos3 = recherche_case(cube, 400);
					pos4 = recherche_case(cube, 402);
				break;
			}
			n = n + 1;
		}
		switch(n) {
			case 1:
				p = 420;
			break;
			case 2:
				p = 422;
			break;
			case 3:
				p = 402;
			break;
		}
		yellow_corners_right_orientation(cube, p);
	}

	if (pos1 == 24 && pos4 != 26) {
		yellow_corners_orientation(cube);
		yellow_corners_right_orientation(cube, p);
	}
	if (pos1 == 24 && pos4 == 26 && pos3 != 20) {
		cube_rotation_side(cube);
		yellow_corners_orientation(cube);
		switch(p) {
			case 400:
				p = 420;
			break;
			case 420:
				p = 422;
			break;
			case 422:
				p = 402;
			break;
			case 402:
				p = 400;
			break;
		}
		yellow_corners_right_orientation(cube, p);
	}

	return;
} 

void resolution_mecanique (miniCube cube[6][N][N]) {
	int pos;
	pos = recherche_case(cube, 11);

	white_center_placement(cube);
	white_cross(cube);
	cube_rotation_upside_down(cube);
	white_face(cube);
	second_line(cube);
	cube_rotation_upside_down(cube);
	cube_rotation_upside_down(cube);
	yellow_cross(cube);
	yellow_cross_right_orientation(cube, 212);

	pos = recherche_case(cube, 211);

	while (pos != 13) {
		cube_rotation_side(cube);
		pos = recherche_case(cube, 211);
	}

	yellow_corners_right_placement(cube, 400);

	pos = recherche_case(cube, 211);

	while (pos != 13) {
		cube_rotation_side(cube);
		pos = recherche_case(cube, 211);
	}

	yellow_corners_right_orientation(cube, 400);

	pos = recherche_case(cube, 211);
	while (pos != 13) {
		cube_rotation_side(cube);
		pos = recherche_case(cube, 211);
	}

	while (recherche_case(cube, 211) != 13) {
		cube_rotation_side(cube);
	}

	yellow_corners_right_orientation(cube, 400);

	while (recherche_case(cube, 211) != 13) {
		cube_rotation_side(cube);
	}

	cube_rotation_upside_down(cube);

	cubeRotation(cube, "Y");
}
