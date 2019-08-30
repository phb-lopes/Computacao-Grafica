#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "image.h"

unsigned char validColor(int c)
{
    if (c < 0) return 0;
    if (c > 255) return 255;

    return ((unsigned char) c);
}

Image * img_ConvertGray(Image * origImg)
{
    int x, y,i;
    float vetor[256];
    float p[256] = {0}, pm[256]= {0}, rop[255]= {0}, il[256]= {0};
    float total = 0;
    int media = 0;
    unsigned char red, green, blue;
    Image *rImg = imgCreate(imgGetWidth(origImg), imgGetHeight(origImg));

    if (rImg == NULL)
        return NULL;
    for(i=0; i<256; i++)
    {
        vetor[i] = 0;
    }

    for (y = 0; y < imgGetHeight(origImg); y++)
    {
        for (x = 0; x < imgGetWidth(origImg); x++)
        {
            red = imgGetPixelRed(origImg, x, y);
            green = imgGetPixelGreen(origImg, x, y);
            blue = imgGetPixelBlue(origImg, x, y);

            media = (red + blue + green)/3;
            for(i=0; i<256; i++)
            {
                vetor[media]++;
            }

        }
    }
    for(i = 0; i<256; i++)
    {
        total = vetor[i] + total;

    }
    for(i = 0; i<256; i++)
    {

        p[i] = vetor[i]/total;
    }
    pm[0] = p[0];
    for(i = 1; i<256; i++)
    {
        pm[i] = pm[i -1] + p[i];
    }
    for(i = 0; i<256; i++)
    {
        rop[i] = pm[i] * 255;
        printf("rop[%d] = %f\n", i , rop[i]);
    }
    for(i = 0; i<256; i++)
    {
        il[i] = round(rop[i]);
    }
    for (y = 0; y < imgGetHeight(origImg); y++)
    {
        for (x = 0; x < imgGetWidth(origImg); x++)
        {
            red = imgGetPixelRed(origImg, x, y);
            green = imgGetPixelGreen(origImg, x, y);
            blue = imgGetPixelBlue(origImg, x, y);

            media = (red + blue + green)/3;
            media = il[media];
            imgSetPixel(rImg, x, y, media, media, media);
        }
    }
    return rImg;
}
