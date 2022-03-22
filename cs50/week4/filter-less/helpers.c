#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avg = round((image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen) / 3.0);
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int max = 255;
            int originalRed = image[i][j].rgbtRed;
            int originalBlue = image[i][j].rgbtBlue;
            int originalGreen = image[i][j].rgbtGreen;

            int sepiaBlue =  round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);
            if (sepiaBlue > max)
            {
                sepiaBlue = max;
            }
            image[i][j].rgbtBlue = sepiaBlue;

            int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            if (sepiaRed > max)
            {
                sepiaRed = max;
            }
            image[i][j].rgbtRed = sepiaRed;

            int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            if (sepiaGreen > max)
            {
                sepiaGreen = max;
            }
            image[i][j].rgbtGreen = sepiaGreen;

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp_pixel[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            tmp_pixel[i][j] = image[i][width - j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = tmp_pixel[i][j];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // make a copy of the original image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // creating variables to track growing sum of RGB colours
    int sumRed = 0;
    int sumBlue = 0;
    int sumGreen = 0;
    // tracking number of cells used
    int counter = 0;

    // looping through copy to find averages
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // top left corner
            if (i == 0 || j == 0)
            {
                sumRed = (copy[i][j].rgbtRed + copy[i + 1][j].rgbtRed + copy[i][j + 1].rgbtRed + copy[i+1][j + 1].rgbtRed);
                sumBlue = (copy[i][j].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i+1][j + 1].rgbtBlue);
                sumGreen = (copy[i][j].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i+1][j + 1].rgbtGreen);
                counter = 4;
            }

            // top right corner
            else if (i == 0 || j == (width - 1))
            {
                sumRed = (copy[i][j].rgbtRed + copy[i + 1][j].rgbtRed + copy[i][j - 1].rgbtRed + copy[i + 1][j - 1].rgbtRed);
                sumBlue = (copy[i][j].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i][j - 1].rgbtBlue + copy[i + 1][j - 1].rgbtBlue);
                sumGreen = (copy[i][j].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i][j - 1].rgbtGreen + copy[i + 1][j - 1].rgbtGreen);
                counter = 4;
            }

            // top edge
            else if (i == 0 && (j != 0 || j != width -1))
            {
                sumRed = (copy[i][j].rgbtRed + copy[i][j - 1].rgbtRed + copy[i][j + 1].rgbtRed + copy[i - 1][j].rgbtRed + copy[i - 1][j - 1].rgbtRed + copy[i - 1][j + 1].rgbtRed);
                sumBlue = (copy[i][j].rgbtBlue + copy[i][j - 1].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i - 1][j - 1].rgbtBlue + copy[i - 1][j + 1].rgbtBlue);
                sumGreen = (copy[i][j].rgbtGreen + copy[i][j - 1].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i - 1][j - 1].rgbtGreen + copy[i - 1][j + 1].rgbtGreen);
                counter = 6;
            }

            // bottom left corner
            else if (i == (height - 1) || j == 0)
            {
                sumRed = (copy[i][j].rgbtRed + copy[i - 1][j].rgbtRed + copy[i][j + 1].rgbtRed + copy[i - 1][j + 1].rgbtRed);
                sumBlue = (copy[i][j].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i - 1][j + 1].rgbtBlue);
                sumGreen = (copy[i][j].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i - 1][j + 1].rgbtGreen);
                counter = 4;
            }

            // bottom right corner
            else if (i == (height - 1) || j == (width - 1))
            {
                sumRed = (copy[i][j].rgbtRed + copy[i - 1][j].rgbtRed + copy[i][j - 1].rgbtRed + copy[i - 1][j - 1].rgbtRed);
                sumBlue = (copy[i][j].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i][j - 1].rgbtBlue + copy[i - 1][j - 1].rgbtBlue);
                sumGreen = (copy[i][j].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i][j - 1].rgbtGreen + copy[i - 1][j - 1].rgbtGreen);
                counter = 4;
            }

            // bottom edge
            else if (i == (height - 1) && (j != 0 || j != width - 1))
            {
                sumRed = (copy[i][j].rgbtRed + copy[i][j - 1].rgbtRed + copy[i][j + 1].rgbtRed + copy[i + 1][j].rgbtRed + copy[i + 1][j - 1].rgbtRed + copy[i + 1][j + 1].rgbtRed);
                sumBlue = (copy[i][j].rgbtBlue + copy[i][j - 1].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i + 1][j - 1].rgbtBlue + copy[i + 1][j + 1].rgbtBlue);
                sumGreen = (copy[i][j].rgbtGreen + copy[i][j - 1].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i + 1][j - 1].rgbtGreen + copy[i + 1][j + 1].rgbtGreen);
                counter = 6;
            }

            // left edge
            else if (j == 0 && (i != 0 || i != (height - 1)))
            {
                sumRed = (copy[i][j].rgbtRed + copy[i - 1][j].rgbtRed + copy[i + 1][j].rgbtRed + copy[i][j + 1].rgbtRed + copy[i - 1][j + 1].rgbtRed + copy[i + 1][j + 1].rgbtRed);
                sumBlue = (copy[i][j].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i - 1][j + 1].rgbtBlue + copy[i + 1][j + 1].rgbtBlue);
                sumGreen = (copy[i][j].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i - 1][j + 1].rgbtGreen + copy[i + 1][j + 1].rgbtGreen);
                counter = 6;
            }

            // right edge
            else if (j == (width - 1) && (i != 0 || i != (height - 1)))
            {
                sumRed = (copy[i][j].rgbtRed + copy[i - 1][j].rgbtRed + copy[i + 1][j].rgbtRed + copy[i][j - 1].rgbtRed + copy[i - 1][j - 1].rgbtRed + copy[i + 1][j - 1].rgbtRed);
                sumBlue = (copy[i][j].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i][j - 1].rgbtBlue + copy[i - 1][j - 1].rgbtBlue + copy[i + 1][j - 1].rgbtBlue);
                sumGreen = (copy[i][j].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i][j - 1].rgbtGreen + copy[i - 1][j - 1].rgbtGreen + copy[i + 1][j - 1].rgbtGreen);
                counter = 6;
            }

            // any other pixels
            else
            {
                sumRed = (copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed + copy[i][j - 1].rgbtRed + copy[i - 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed + copy[i][j - 1].rgbtRed + copy[i + 1][j].rgbtRed + copy[i + 1][j + 1].rgbtRed + copy[i + 1][j - 1].rgbtRed);
                sumBlue = (copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i][j - 1].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue + copy[i][j - 1].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i + 1][j + 1].rgbtBlue + copy[i + 1][j - 1].rgbtBlue);
                sumGreen = (copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i][j - 1].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen + copy[i][j - 1].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i + 1][j + 1].rgbtGreen + copy[i + 1][j - 1].rgbtGreen);
                counter = 9;
            }

            // find average and assign to image[i][j]
            image[i][j].rgbtRed = round(sumRed / counter);
            image[i][j].rgbtBlue = round(sumBlue / counter);
            image[i][j].rgbtGreen = round(sumGreen / counter);
        }
    }
    return;
}
