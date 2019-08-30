/*
 ============================================================================
 Name        : pdi.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "image.h"
#include "pdiAlgorithm.h"

int main(void) {
	//puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	Image *lenaImg = imgReadPPM("C:/Users/Paulo Henrique/Desktop/Programação/CC/Computação Gráfica/lena256Gray.ppm");
	//imgWritePPM(lenaImg, "./images/lena256color.ppm");

	Image *lenaImgGray = img_ConvertGray(lenaImg);
	imgWritePPM(lenaImgGray, "C:/Users/Paulo Henrique/Desktop/Programação/CC/Computação Gráfica/Histograma00/Lena-Historada00.ppm");

	imgDestroy(lenaImg);
	//imgDestroy(lenaImgGray);
	return EXIT_SUCCESS;
}
