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
    int x,y,i,l,j;
	int media;
	int cont,aux;
	int vetor3[9],vetor5[25], vetor7[42];
	int mediana[9],a,b;
	unsigned char red, green, blue;
	Image *rImg = imgCreate(imgGetWidth(origImg), imgGetHeight(origImg));

	if (rImg == NULL)
    return NULL;

    printf("Digite um valor da mascara?\n3 - Para Alteracao 3x3\n5 - Para Alteracao 5x5\n7 - Para Alteracao 7x7\n");
    scanf("%d",&l);
    printf("Por favor aguarde!\n");
    if(l==3){


	for (y = 0; y < imgGetHeight(origImg)-2; y++)
			{
				for (x = 0; x < imgGetWidth(origImg)-2; x++)
				{


					cont=0;
                    for(i=x; i<x+3; i++) {
                        for(j=y; j<y+3; j++) {
                            vetor3[cont] = imgGetPixelGreen(origImg, i, j);
                            cont++;
                        }
                    }
                    for(a=0; a<9; a++){
                        for(b=a+1; b<9; b++){
                            if(vetor3[a] > vetor3[b]){
                                aux = vetor3[a];
                                vetor3[a] = vetor3[b];
                                vetor3[b]=aux;
                                }
                        }
                  }
                media = vetor3[5];
                imgSetPixel(rImg, x+1, y+1, media, media, media);
        }
    }
printf("Sua imagem foi alterada com sucesso!\n");
 return rImg;

}
if(l==5){


	for (y = 0; y < imgGetHeight(origImg)-2; y++)
			{
				for (x = 0; x < imgGetWidth(origImg)-2; x++)
				{


					cont=0;
                    for(i=x; i<x+5; i++) {
                        for(j=y; j<y+5; j++) {
                            vetor5[cont] = imgGetPixelGreen(origImg, i, j);
                            cont++;
                        }
                    }
                    for(a=0; a<25; a++){
                        for(b=a+1; b<25; b++){
                            if(vetor5[a] > vetor5[b]){
                                aux = vetor5[a];
                                vetor5[a] = vetor5[b];
                                vetor5[b]=aux;
                                }
                        }
                  }
                media = vetor5[13];
                imgSetPixel(rImg, x+1, y+1, media, media, media);
        }
    }
printf("Sua imagem foi alterada com sucesso!\n");
 return rImg;
}
    if(l==7){


	for (y = 0; y < imgGetHeight(origImg)-2; y++)
			{
				for (x = 0; x < imgGetWidth(origImg)-2; x++)
				{


					cont=0;
                    for(i=x; i<x+7; i++) {
                        for(j=y; j<y+7; j++) {
                            vetor7[cont] = imgGetPixelGreen(origImg, i, j);
                            cont++;
                        }
                    }
                    for(a=0; a<42; a++){
                        for(b=a+1; b<42; b++){
                            if(vetor7[a] > vetor7[b]){
                                aux = vetor7[a];
                                vetor7[a] = vetor7[b];
                                vetor7[b]=aux;
                                }
                        }
                  }
                media = vetor7[21];
                imgSetPixel(rImg, x+1, y+1, media, media, media);
        }
    }
 printf("Sua imagem foi alterada com sucesso!\n");
 return rImg;
}
}
