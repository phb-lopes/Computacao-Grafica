/*
 * pdiAlgorithm.h
 *
 *  Created on: 10/09/2012
 *      Author: wilfredo
 */

#ifndef PDIALGORITHM_H_
#define PDIALGORITHM_H_

Image * img_ConvertGray(Image * origImg);
Image * img_Blur(Image * origImg, int sizeMask);

unsigned int * img_GetHistogram (Image * img);
void printHistogramToConsole(Image * img);

#endif /* PDIALGORITHM_H_ */
