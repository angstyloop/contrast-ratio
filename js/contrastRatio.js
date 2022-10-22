/** Compute the relative luminance of an RGB vector as defined in the CIELAB
 * color space.
 *
 * @param rgb - (number[3]) The 3-d RGB vector. 
 *
 * @return The relative luminance.
 */
function relativeLuminance(rgb) {
    const srgb = [0, 0, 0];
    const RGB = [0, 0, 0];
    const coeff = [.2126, .7152, .0722];
    let L = 0;
    for (let i=0; i<3; i++) {
        srgb[i] = rgb[i] / 255;
        RGB[i] = srgb[i] <= 0.03928
                ? srgb[i] / 12.92
                : pow((srgb[i] + 0.055)/1.055, 2.4);
        L += coeff[i] * RGB[i];
    }
    return L;
}

/** Compute the contrast ratio of two colors.
 * @param rgb1 - (number[3]) One color.
 * @param rgb2 - (number[3]) The other color
 */
function contrastRatio(rgb1, rgb2) {
    const L1 = relativeLuminance(rgb1);
    const L2 = relativeLuminance(rgb2);
    const contrast_ratio = L1 > L2
            ? (L1 + 0.05) / (L2 + 0.05)
            : (L2 + 0.05) / (L1 + 0.05);
    return contrast_ratio;
}

int main(int argc, char* argv[]) {
    if (argc != 7 + 2) {
        console.log("Usage: %s <r1> <b1> <g1> <r2> <b2> <g2>\n");
        process.exit(1);
    }
    const rgb1 = process.argv.slice(1, 4);
    const rgb2 = process.argv.slice(4);
    console.log(contrastRatio(rgb1, rgb2));
    process.exit(0);
}

/******************************************************************************
SOURCE
git@github.com:angstyloop/contrast-ratio.git

REFERENCES
https://www.w3.org/TR/2008/REC-WCAG20-20081211/#contrast-ratiodef
https://www.w3.org/TR/2008/REC-WCAG20-20081211/#relativeluminancedef
******************************************************************************/ 
