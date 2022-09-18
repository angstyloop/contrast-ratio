/******************************************************************************* 
gcc -o contrast-ratio contrast_ratio.c -lm
*******************************************************************************/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/** Compute the relative luminance of an RGB vector as defined in the CIELAB
 * color space.
 *
 * @param rgb - The 3-d RGB vector. 
 *
 * @return The relative luminance.
 */
float relativeLuminance(int rgb[3]) {
    float srgb[3] = {0};
    float RGB[3] = {0};
    float coeff[] = {.2126, .7152, .0722};
    float L = 0;
    for (int i=0; i<3; i++) {
        srgb[i] = rgb[i] / 255.;
        RGB[i] = srgb[i] <= 0.03928
                ? srgb[i] / 12.92 
                : pow((srgb[i] + 0.055)/1.055, 2.4);
        L += coeff[i] * RGB[i];
    }
    return L;
}

/** Compute the contrast ratio of two colors.
 * @param rgb1 - One color.
 * @param rgb2 - The other color
 */
float contrastRatio(int rgb1[3], int rgb2[3]) {
    float L1 = relativeLuminance(rgb1); 
    float L2 = relativeLuminance(rgb2); 
    float contrast_ratio = L1 > L2
            ? (L1 + 0.05) / (L2 + 0.05)
            : (L2 + 0.05) / (L1 + 0.05);
    return contrast_ratio;
}

int main(int argc, char* argv[]) {
    if (argc != 7) {
        printf("Usage: %s <r1> <b1> <g1> <r2> <b2> <g2>\n", argv[0]);
        return 1;
    }
    int rgb1[] = {atoi(argv[1]), atoi(argv[2]), atoi(argv[3])};
    int rgb2[] = {atoi(argv[4]), atoi(argv[5]), atoi(argv[6])};
    printf("%f\n", contrastRatio(rgb1, rgb2));
    return 0;
}

/******************************************************************************
https://www.w3.org/TR/2008/REC-WCAG20-20081211/#contrast-ratiodef
https://www.w3.org/TR/2008/REC-WCAG20-20081211/#relativeluminancedef
******************************************************************************/ 
