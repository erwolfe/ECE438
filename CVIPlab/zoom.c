//Eric Wolfe
//800480613
//Lab 2

#include "CVIPtoolkit.h"
#include "CVIPconvert.h"
#include "CVIPdef.h"
#include "CVIPimage.h"
#include "CVIPlab.h"

Image *zoom1(Image *inputImage, unsigned int row, unsigned int col, unsigned int height, unsigned int width, unsigned int zoomFactor) {
	inputImage = crop(inputImage, row, col, height, width);
	byte **image, **tempImage;
	unsigned numberBands = getNoOfBands_Image(inputImage);
	unsigned numberRows = getNoOfRows_Image(inputImage);
	unsigned numberCols = getNoOfCols_Image(inputImage);
	Image *temp = image_allocate(getFileFormat_Image(inputImage), getColorSpace_Image(inputImage), numberBands, numberRows*zoomFactor, numberCols*zoomFactor, getDataType_Image(inputImage), getDataFormat_Image(inputImage));
	for (int b = 0; b < numberBands; b++) {
		image = getData_Image(inputImage, b);
		tempImage = getData_Image(temp, b);
		for (int r = 0; r < numberRows; r++) {
			for (int c = 0; c < numberCols; c++) {
				for (int x = 0; x < zoomFactor; x++) {
					for (int y = 0; y < zoomFactor; y++) {
						tempImage[(r*zoomFactor)+x][(c*zoomFactor)+y] = image[r][c];
					}
				}
			}
		}
	}

	return (temp);
}