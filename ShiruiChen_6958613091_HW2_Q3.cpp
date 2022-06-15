#include "ShiruiChen_6958613091_HW2_Q3.h"
#include <cmath>

int main(){
    int xr = 640, yr = 480;
    ComplexNumber c;

    PGMImage *p = new PGMImage(xr,yr,"/Users/shiruichen/Desktop/CSCI 455/fractal.pgm");
    for (int y = 0; y < yr; y++){
        for(int x = 0; x < xr; x++){
            double cxmin = -2, cymin = -1;
            double cxmax = 1, cymax = 1;
            ComplexNumber z = 0;
            int iter = 0;
            int maxIter = 255;
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
    p->writeFile();
    return 0;
}