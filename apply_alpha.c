/*
gcc -o apply-alpha apply_alpha.c -lm
*/

#include <stdio.h>
#include <stdlib.h>

/** Do alpha mixing of a foreground and background.
 * @param fg - (int[3]) The foreground RGB vector.
 * @param bg - (int[3]) The background RGB vector.
 * @param alpha - (float) The alpha channel. 
 * @param out - (int[3]) The output buffer.
 */
void applyAlpha(int fg[3], int bg[3], float alpha, int out[3]) {
    float a = 0 <= alpha && alpha <= 1 ? alpha : 1;
    for (int i=0; i<3; i++) {
        out[i] = (1 - a) * bg[i] + a * fg[i];
    }
}

int main(int argc, char** argv) {
    if (argc != 8) {
        printf("Usage: %s <r1 (0-255 int)> <g1 (0-255 int)> "
               "<b2 (0-255 int)> <r2 (0-255 int)> <g2 (0-255 int)> "
               "<b2 (0-255 int)> <alpha (0-1 float)> <>", argv[0]);
        return 1;
    }
    int rgb[] = {
        atoi(argv[1]),
        atoi(argv[2]),
        atoi(argv[3]),
    };
    int bg[] = {
        atoi(argv[4]),
        atoi(argv[5]),
        atoi(argv[6]),
    };
    float a = atof(argv[7]);
    int out[] = {0, 0, 0, 0};
    applyAlpha(rgb, bg, a, out);
    printf("%d %d %d\n", out[0], out[1], out[2]);
    return 0;
}
