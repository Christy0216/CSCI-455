#include "ShiruiChen_6958613091_HW2_Q2.h"
#include <cmath>

int main(){
    int xr = 320, yr = 240;
    PGMImage *p = new PGMImage(xr,yr,"/Users/shiruichen/Desktop/CSCI 455/test.pgm");
    for (int i = 0; i < xr; i++){
        for(int j=0; j < yr; j++){
                p -> setPixel(i,j,100);
        }
    }
    p->writeFile();
    return 0;
}