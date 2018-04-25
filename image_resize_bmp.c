#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"

int main(int argc, char* argv[]){

    if (argc != 4){
        printf("Usage: ./resize n infile outfile\n");
        return 1;
    }

    char* infile = argv[2];
    char* outfile = argv[3];
    int n = atoi(argv[1]);

    if (n < 1 || n > 100){
        printf("N must be [1..100]\n");
        return 2;
    }

    FILE* inputFile = fopen(infile, "r");
    if (inputFile == NULL){
        printf("Cant open: %s\n", infile);
        return 3;
    }

    FILE* outputFile = fopen(outfile, "w");
    if (outputFile == NULL){
        fclose(inputFile);
        printf("Cant open or create: %s\n", outfile);
        return 4;
    }

    BITMAPFILEHEADER bf;
    BITMAPFILEHEADER bf_new;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inputFile);
    bf_new = bf;

    BITMAPINFOHEADER bi;
    BITMAPINFOHEADER bi_new;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inputFile);
    bi_new = bi;

    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biCompression != 0 ||
        bi.biSize != 40 || bi.biBitCount != 24){
            fclose(inputFile);
            fclose(outputFile);
            printf("Unsupported file format \n");
            return 5;
    }

    bi_new.biWidth = bi.biWidth * n;
    bi_new.biHeight = bi.biHeight * n;

    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int new_padding = (4 - (bi_new.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    bi_new.biSizeImage = (bi_new.biWidth * sizeof(RGBTRIPLE) + new_padding) * abs(bi_new.biHeight);
    bf_new.bfSize = bf.bfSize - bi.biSizeImage + bi_new.biSizeImage;

    fwrite(&bf_new, sizeof(BITMAPFILEHEADER), 1, outputFile);
    fwrite(&bi_new, sizeof(BITMAPINFOHEADER), 1, outputFile);

    for (int i = 0, bi_height = abs(bi.biHeight); i < bi_height; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0, bi_width = bi.biWidth; k < bi_width; k++){

                RGBTRIPLE triple;
                fread(&triple, sizeof(RGBTRIPLE), 1, inputFile);

                for (int m = 0; m < n; m++){
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outputFile);
                }
            }
            for (int l = 0; l < new_padding; l++){
                fputc(0x00, outputFile);
            }
            if (j < n - 1)
                fseek(inputFile, -bi.biWidth * sizeof(RGBTRIPLE), SEEK_CUR);
        }
        fseek(inputFile, padding, SEEK_CUR);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
