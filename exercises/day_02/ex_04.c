//
// Created by tuan-nguyen on 28/12/2025.
//
#include <stdio.h>

int main()
{
    int max = 2147483647;
    max += 1;

    printf("Max: %d\n", max); // Max: -2147483648
    /**
     * @brief Explanation why adding 1 to max range of integer it will turn positive number into min range (negative number)
     *
     * A signed it typically 32 bits and use two's complement representation

    | Value             | Binary Representation                   |
    |-------------------|-----------------------------------------|
    | Max (2147483647)  | 0111 1111 1111 1111 1111 1111 1111 1111 |
    | Min (-2147483648) | 1000 0000 0000 0000 0000 0000 0000 0000 |

    When you add 1 to the maximum value:

    0111 1111 1111 1111 1111 1111 1111 1111  (2147483647)
    +                                     1
    ─────────────────────────────────────────
    1000 0000 0000 0000 0000 0000 0000 0000  (-2147483648)

    The carry bit flips the sign bit from 0 (positive) to 1 (negative), and all other bits become 0. In two's complement, this pattern represents the minimum negative value.
    Keypoints:
    - The leftmost bit is the sign bit. 0 = positive, 1 = negative
    - The integer wrap around from max to min like an odometer rolling over
    */
    return 0;
}