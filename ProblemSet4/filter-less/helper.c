#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int sum = 0;
    int average = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            average = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);

            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed, sepiaGreen, sepiaBlue;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j <width; j++) {
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;

            sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

            if (sepiaRed > 255) {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255) {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255) {
                sepiaBlue = 255;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // [0][0]在左上角 左右交换即对每一行来说只需要交换边界列的情况，也就是只要变化第二维数组即可
    // 这里的交换值我认为应该用指针的 不知道为什么不可以
    int half = width / 2;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < half; j++) {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE pixel[height][width];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            pixel[i][j] = image[i][j];
        }
    }

     for (int i = 0; i < height; i++)
    {
        // For every pixel...
        for (int j = 0; j < width; j++)
        {
            int counter = 0, red = 0, green = 0, blue = 0;
            // Current pixel
            red += pixel[i][j].rgbtRed;
            green += pixel[i][j].rgbtGreen;
            blue += pixel[i][j].rgbtBlue;
            counter++;

            // Check if pixel above and to the left exists
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                red += pixel[i - 1][j - 1].rgbtRed;
                green += pixel[i - 1][j - 1].rgbtGreen;
                blue += pixel[i - 1][j - 1].rgbtBlue;
                counter++;
            }
            // Pixel directly above
            if (i - 1 >= 0 && j >= 0)
            {
                red += pixel[i - 1][j].rgbtRed;
                green += pixel[i - 1][j].rgbtGreen;
                blue += pixel[i - 1][j].rgbtBlue;
                counter++;
            }
            // Pixel above and to the right
            if (i - 1 >= 0 && j + 1 < width)
            {
                red += pixel[i - 1][j + 1].rgbtRed;
                green += pixel[i - 1][j + 1].rgbtGreen;
                blue += pixel[i - 1][j + 1].rgbtBlue;
                counter++;
            }
            // Pixel to the left
            if (j - 1 >= 0)
            {
                red += pixel[i][j - 1].rgbtRed;
                green += pixel[i][j - 1].rgbtGreen;
                blue += pixel[i][j - 1].rgbtBlue;
                counter++;
            }
            //Pixel to the right
            if (j + 1 < width)
            {
                red += pixel[i][j + 1].rgbtRed;
                green += pixel[i][j + 1].rgbtGreen;
                blue += pixel[i][j + 1].rgbtBlue;
                counter++;
            }
            // Pixel below and to the left
            if (i + 1 < height && j - 1 >= 0)
            {
                red += pixel[i + 1][j - 1].rgbtRed;
                green += pixel[i + 1][j - 1].rgbtGreen;
                blue += pixel[i + 1][j - 1].rgbtBlue;
                counter++;
            }
            // Pixel directly below
            if (i + 1 < height && j >= 0)
            {
                red += pixel[i + 1][j].rgbtRed;
                green += pixel[i + 1][j].rgbtGreen;
                blue += pixel[i + 1][j].rgbtBlue;
                counter++;
            }
            // Pixel below and to the right
            if (i + 1 < height && j + 1 < width)
            {
                red += pixel[i + 1][j + 1].rgbtRed;
                green += pixel[i + 1][j + 1].rgbtGreen;
                blue += pixel[i + 1][j + 1].rgbtBlue;
                counter++;
            }

            image[i][j].rgbtRed = round(red / (counter * 1.0));
            image[i][j].rgbtGreen = round(green / (counter * 1.0));
            image[i][j].rgbtBlue = round(blue / (counter * 1.0));
        }
    }
    return;
}

