#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

class array2D{
public:
    array2D(int x, int y){
        xRes = x;
        yRes = y;

        xtable = new int*[yRes];
        for(int i=0;i < yRes;i++){
            xtable[i] = new int[xRes];
        }
    }
    void getSize(int &x, int &y){
        x = xRes;
        y = yRes;
    }
    void setValue(int x, int y, int val){
        xtable[y][x] = val;
    }
    int getValue(int x, int y){
        return xtable[y][x];
    }
    ~array2D(){
        for (int i = 0; i < yRes; i++)
            delete xtable[i];
        delete []xtable;
    }
    protected:
    int **xtable;
    int xRes;
    int yRes;
};

class PGMImage: public array2D {
public:
     //constructor
    PGMImage(int xResolution, int yResolution, string imageFilename): array2D(xResolution, yResolution){
        filename = imageFilename;
    }
    void getResolution(int &xResolution, int &yResolution){
        xResolution = xRes;
        yResolution = yRes;
    }
    void setPixel(int x, int y, int val){
        xtable[y][x] = val;
    }
   int getPixel(int x,int y){
        return xtable[y][x];
    }
    void writeFile(){
    ofstream f(filename); // output image file we're creating
    f << "P2" << endl;
    f << xRes << " " << yRes << endl;
    f << "255" << endl;
    for(int i=0;i<yRes;i++){
            for(int j=0;j<xRes;j++){
                //f << xtable[i][j] << " ";
                f << getPixel(j,i) << " ";
        }
   f << endl;
    }
    f.close();
    }
private:
    string filename;
};

class ComplexNumber{
private:
double real;
double imag;
public:
ComplexNumber(double i = 0,double j = 0){
    real = i;
    imag = j;
}
ComplexNumber add(ComplexNumber c2){
    ComplexNumber sum;
    sum.real = real + c2.real;
    sum.imag = imag + c2.imag;
    return sum;
}
ComplexNumber squared(){
    ComplexNumber squared;
    double temp_real = (pow(real,2)-pow(imag,2));
    double temp_imag = (2*real*imag);
    squared.real = temp_real;
    squared.imag = temp_imag;
    return squared;
}
double abs(){
    double magnitude = sqrt(real*real+imag*imag);
    return magnitude;
}
void prt(){
    {
    if (imag == 0)
    {
        cout << real << endl;
    }
    else
    {
        string sign = (imag < 0)?"":"+";
        cout << real << sign << imag << "i" << endl;
    }
}
}
};