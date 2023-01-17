// SpiralTraversalOfGrid.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

int main()
{
    const int _size = 4;
    int a[_size][_size] = { { 1, 2, 3, 4 },

                    { 5, 6, 7, 8 },

                    { 9, 10, 11, 12 },

                    { 13, 14, 15, 16 } };

    int i, left = 0, right = _size - 1, top = 0, bottom = _size - 1;

    while (left <= right && top <= bottom) {

        /* Print the first row
        from the remaining rows */
        for (i = left; i <= right; ++i) {
            std::cout << a[top][i] << " ";
        }
        top++;

        /* Print the last column
        from the remaining columns */
        for (i = top; i <= bottom; ++i) {
            std::cout << a[i][right] << " ";
        }
        right--;

        /* Print the last row from
        the remaining rows */
        if (top <= bottom) {
            for (i = right; i >= left; --i) {
                std::cout << a[bottom][i] << " ";
            }
            bottom--;
        }

        /* Print the first column from
        the remaining columns */
        if (left <= right) {
            for (i = bottom; i >= top; --i) {
                std::cout << a[i][left] << " ";
            }
            left++;
        }
    }

    return 0;
}