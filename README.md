# Contrast Ratio

The WCAG2 a11y standards want foreground/background colors to be used which
have a Contrast Ratio of 4.5:1 or higher.

Chaining the following definitions together will reproduce the formula
used in the implementation(s) in this repo.

    * https://www.w3.org/TR/2008/REC-WCAG20-20081211/#contrast-ratiodef
    * https://www.w3.org/TR/2008/REC-WCAG20-20081211/#relativeluminancedef

# Applications

    * Determining lightest shade of gray on which the brightest solid red
      rgb(255, 0, 0) will be visible, by WCAG2 standards.

        `./contrast-ratio 23 23 23 255 0 0`
        `4.483667`

        `./contrast-ratio 22 22 22 255 0 0`
        `4.525776`

    * Determining the lightest shade of gray on which soid bright white text
      rgb(255, 255, 255) will be WCAG2-visible.

      ./contrast-ratio 255 255 255 118 118 118
      4.542225

      ./contrast-ratio 255 255 255 119 119 119
      4.478089

## The issue with red on gray

The brightest solid red `rgb(255, 0 0)` is not WCAG2-visible on any shade of
gray that is lighter than `rgb(8, 8, 8)`.

The color contrast ratio of `rgb(255, 255, 255)` with a shade of gray that is
`rgb(23, 23, 23)` or darker is always less than 4.5, the value demanded by
WCAG2.
o
minimum. 

## The issue with using color effects

When you use blur, opacity, etc., you need to use the color picker and a
color-contrast ratio tool to check the WCAG2 minimum ratio of 4.5 is met or
exceeded for TEXT on backgrounds.

The color picker is accessed via the browser dev tools in your web browser.
Different browsers do it differently, but most browsers let you access it
by clicking on the color that appears next to the color-valued CSS
property in the styles menu (where you can view/modify the CSS on the web
page).

Additionally you need to consider that while there are no requirements related
to color-contrast ratio around non-text content, non-text content that does WILL
NOT BE not meet the same requirements WILL NOT BE VISIBLE TO USERS the
requirements are aimed at assisting.

# Longer Description of Color Contrast Ratio (CCR)

The CCR acronym is non-standard. I just like it, and it's shorter.

There is this thing called the color contrast ratio - it's defined by the
WCAG2,or at least they've adopted a definition. It's just some math. It's to
help visually impaired people USE YOUR APPLICATION and SEE YOUR BRAND.

The minimum CCR is 4.5. You need to use colors that contrast more than that.
For text on a background, absolutely don't use colors with a CCR less than 4.5.

There are two formulas that are used to produce the numerical result from two
RGB vectors. The magnitudes of the RGB values matter, but so do their
differences.

