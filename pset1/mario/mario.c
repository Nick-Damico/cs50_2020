#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Capture valid input from user for pyramid height.
    int height;

    // Loop until a positive value within range of (1 - 8) is supplied.
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Iterate with supplied height value.
    // initialize i as 1 so that it also acts as an offset
    // when calculating block placement in inner loop.
    for (int i = 0; i < height; i++)
    {
        for (int j = 1; j <= height; j++)
        {
            if (j >= (height - i))
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }

        // Separate pyramids with (2) spaces.
        printf("  ");

        // Build right side of pyramid.
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }

        // Print newline character return when loop reaches the end of the row.
        printf("\n");
    }
}
