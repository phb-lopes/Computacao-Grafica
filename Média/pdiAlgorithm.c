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
	int x, y,i,soma,l,j;
	float mediocre;
	unsigned char red, green, blue;
	Image *rImg = imgCreate(imgGetWidth(origImg), imgGetHeight(origImg));

    printf("Digite o valor da Matriz\n3 - Para Alteracao 3x3\n5 - Para Alteracao 5x5\n7 - Para Alteracao 7x7\n");
    scanf("%d",&l);
    printf("Por favor aguarde\n");

	if (rImg == NULL)
			return NULL;

if(l == 3){
        for (y = 0; y < imgGetHeight(origImg)-2; y++)	{
            for (x = 0; x < imgGetWidth(origImg)-2; x++){
                soma =0;
                for(i=x; i<x+3; i++){
                    for(j=y; j<y+3; j++){
                        soma += imgGetPixelGreen(origImg, i, j);
                    }
                }
                mediocre = soma/9;
                mediocre = validColor(mediocre);
                imgSetPixel(rImg, x+1, y+1, mediocre,mediocre,mediocre );

               }
}
printf("Sua imagem foi alterada!\n");
 return rImg;
}
if(l == 5){
        for (y = 0; y < imgGetHeight(origImg)-2; y++)	{
            for (x = 0; x < imgGetWidth(origImg)-2; x++){
                soma=0;
                for(i=x; i<x+5; i++){
                    for(j=y; j<y+5; j++){
                        soma += imgGetPixelGreen(origImg, i, j);
                    }
                }
                mediocre = soma/25;
                mediocre = validColor(mediocre);
                imgSetPixel(rImg, x+1, y+1, mediocre,mediocre,mediocre );

               }
}
printf("Sua imagem foi alterada!\n");
 return rImg;
}
if(l == 7){
        for (y = 0; y < imgGetHeight(origImg)-2; y++)	{
            for (x = 0; x < imgGetWidth(origImg)-2; x++){
                soma =0;
                for(i=x; i<x+7; i++){
                    for(j=y; j<y+7; j++){
                        soma += imgGetPixelGreen(origImg, i, j);
                    }
                }
                mediocre = soma/42;
                mediocre = validColor(mediocre);
                imgSetPixel(rImg, x+1, y+1, mediocre,mediocre,mediocre );

               }
}
printf("Sua imagem foi alterada!\n");
 return rImg;
}
}

