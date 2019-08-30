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
	int x, y;
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

                    media = (red + green + blue)/3;

                    if(media>50){
                    red = 255;
                    }else{
                    red = 0;
                    }
                    if(media>50){
                        blue = 255;
                    }else{
                    blue = 0;
                    }
                    if(media>50){
                        green = 255;
                    }else{
                    green = 0;
                    }
                    imgSetPixel(rImg, x, y, red, green, blue);
				}
			}

	return rImg;
}
