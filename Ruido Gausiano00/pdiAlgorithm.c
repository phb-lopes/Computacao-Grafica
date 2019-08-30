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
	int x, y,cont=0,numero;
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
                    cont++;
                    numero = rand() % 255;      // Retorna um numero aleatório entre 0 e 255

                    if(cont>10){    // Lena 00
                        media = numero;
                        cont = 0;
                    }else{
                    media = (red + green + blue)/3;
                    }

                    /*if(x%2==0){ // Lena 01
                    media = numero;
                    }else{
                    media = (red + green + blue)/3;
                    }*/

                    /*if(numero %2 ==0){    //Lena 02
                    numero = rand() % 255;
                    media = numero;
                    }else{
                    media = (red + green + blue)/3;
                    }*/

					imgSetPixel(rImg, x, y, media, media, media);
				}
			}

	return rImg;
}
