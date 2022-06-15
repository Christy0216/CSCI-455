#include "ShiruiChen_6958613091_HW2_Q3EC2.h"
#include <cmath>

void createFractal(double cxmin, double cxmax, double cymin, double cymax, int xr, int yr, int maxIter, string outputImgName){
    PGMImage *p = new PGMImage(xr,yr,outputImgName);
    ComplexNumber c;
     for (int y = 0; y < yr; y++){
        for(int x = 0; x < xr; x++){
            ComplexNumber z = 0;
            int iter = 0;
            c = ComplexNumber(cxmin + ((double)x/(xr-1))*(cxmax-cxmin),cymin + ((double)y/(yr-1))*(cymax-cymin));
            while (iter < maxIter && z.abs() < 2){
                z = z.squared();
                z = z.add(c);
                iter++;
            }
            if (z.abs() >= 2){
                p -> setPixel(x,y,iter);
            }
            else{
                p -> setPixel(x,y,0);
            }
            
        }
    }
    p -> writeFile();
}

int main(){
    double delta = 0.01;
    double cx = 0.275, cy = 0;
    int xr = 1800, yr = 1000;
    int maxIter = 255;
    string outputImgName[12] = {"/Users/shiruichen/Desktop/CSCI 455/ShiruiChen_6958613091_HW2/fun.0001.pgm",
                                "/Users/shiruichen/Desktop/CSCI 455/ShiruiChen_6958613091_HW2/fun.0002.pgm",
                                "/Users/shiruichen/Desktop/CSCI 455/ShiruiChen_6958613091_HW2/fun.0003.pgm",
                                "/Users/shiruichen/Desktop/CSCI 455/ShiruiChen_6958613091_HW2/fun.0004.pgm",
                                "/Users/shiruichen/Desktop/CSCI 455/ShiruiChen_6958613091_HW2/fun.0005.pgm",
                                "/Users/shiruichen/Desktop/CSCI 455/ShiruiChen_6958613091_HW2/fun.0006.pgm",
                                "/Users/shiruichen/Desktop/CSCI 455/ShiruiChen_6958613091_HW2/fun.0007.pgm",
                                "/Users/shiruichen/Desktop/CSCI 455/ShiruiChen_6958613091_HW2/fun.0008.pgm",                                                                       
                                "/Users/shiruichen/Desktop/CSCI 455/ShiruiChen_6958613091_HW2/fun.0009.pgm",
                                "/Users/shiruichen/Desktop/CSCI 455/ShiruiChen_6958613091_HW2/fun.0010.pgm",
                                "/Users/shiruichen/Desktop/CSCI 455/ShiruiChen_6958613091_HW2/fun.0011.pgm",
                                "/Users/shiruichen/Desktop/CSCI 455/ShiruiChen_6958613091_HW2/fun.0012.pgm"};
    for (int i = 0; i < 12; i++){
        double cxmin = cx - (delta*i);
        double cxmax = cx + (delta*i);
        double cymin = cy - (delta*i);
        double cymax = cy + (delta*i);
        createFractal(cxmin, cxmax, cymin, cymax, xr, yr, maxIter, outputImgName[i]);
    }
    return 0;   
}