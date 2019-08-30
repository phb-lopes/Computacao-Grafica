#include <stdlib.h>
#include <string.h>
#include <stdio.h>
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
	int vetor[256];
	int media;
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
                    for(i=0;i<256;i++)
                    {
                    vetor[media]++;
                    }

					//imgSetPixel(rImg, x, y, media, media, media);
				}
			}
    for(i=0; i<256; i++)
    {
        printf("%d\n",vetor[i]);
    }

	return rImg;
}
