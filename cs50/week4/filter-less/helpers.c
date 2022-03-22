#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i > height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avg = (image.rgbtblue + image.rgbtred + imgae.rgbtgreen) / 3.0;
            image[i][j].rgbtblue = avg;
            image[i][j].rgbtred = avg;
            image[i][j].rgbtgreen = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
