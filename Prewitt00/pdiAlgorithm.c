#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "image.h"

unsigned char validColor(int c)
{
    if (c < 0) return 0;
    if (c > 255) return 255;

    return ((unsigned char) c);
}

Image * img_ConvertGray(Image * origImg)
{
    int x, y;
    int j,i,soma;
    int presley [3][3] = {{1,0,-1},{1,0,-1},{1,0,-1}};
    int presley2 [3][3] = {{-1, -1, -1},{0, 0, 0},{1, 1, 1}};
    unsigned char red, green, blue;

    Image *rImg = imgCreate(imgGetWidth(origImg), imgGetHeight(origImg));
    Image *rImg2 = imgCreate(imgGetWidth(origImg), imgGetHeight(origImg));
    Image *rImg3 = imgCreate(imgGetWidth(origImg), imgGetHeight(origImg));
    if (rImg == NULL)
        return NULL;
    if (rImg2 == NULL)
        return NULL;
    if (rImg3 == NULL)
        return NULL;

    for (y = 0; y < imgGetHeight(origImg); y++)
    {
        for (x = 0; x < imgGetWidth(origImg); x++)
        {
            for (j=-1; j<=1; j++)
            {
                for (i=-1; i<=1; i++)
                {
                    soma += presley[j+1][i+1]*imgGetPixelGreen(origImg, x+i, y+j);
                }
            }
            soma= validColor(soma);
            imgSetPixel(rImg2, x, y, soma, soma, soma);
            soma = 0;
        }
    }
    for (y = 0; y < imgGetHeight(origImg); y++)
    {
        for (x = 0; x < imgGetWidth(origImg); x++)
        {
            for (j=-1; j<=1; j++)
            {
                for (i=-1; i<=1; i++)
                {
                    soma += presley2[j+1][i+1]*imgGetPixelGreen(origImg, x+i, y+j);
                }
            }

            soma= validColor(soma);
            imgSetPixel(rImg3, x, y, soma, soma, soma);
            soma = 0;
        }
    }
    for (y = 0; y < imgGetHeight(origImg); y++)
    {
        for (x = 0; x < imgGetWidth(origImg); x++)
        {
            soma = sqrt(pow(imgGetPixelGreen(rImg3, x, y), 2) + pow(imgGetPixelGreen(rImg2, x, y),2));
            soma= validColor(soma);
            imgSetPixel(rImg, x, y, soma, soma, soma);
        }
    }
    return rImg;
}
