#include <stdlib.h>
#include <string.h>
#include <stdio.h>
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
	int x, y,i;
	float media;
	unsigned char red, green, blue;
	Image *rImg = imgCreate(imgGetWidth(origImg), imgGetHeight(origImg));

	if (rImg == NULL)
			return NULL;

	for (y = 0; y < imgGetHeight(origImg); y++)
			{
				for (x = 0; x < imgGetWidth(origImg); x++)
				{
					red = imgGetPixelRed(origImg, x, y);
					green = imgGetPixelGreen(origImg, x, y);
					blue = imgGetPixelBlue(origImg, x, y);

                    media = green;

                        i = rand() % 100;
                        //i = i*0.2;
                        if(i <= 50 && media <= 128){
                            media = 0;
                        }else{
                            media = 255;
                        }

                    imgSetPixel(rImg, x, y, media, media, media);
				}
			}

	return rImg;
}
