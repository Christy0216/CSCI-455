#include <iostream>
#include <fstream>

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
};//PGMImage 