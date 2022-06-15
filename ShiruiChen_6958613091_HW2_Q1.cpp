#include <iostream>
using namespace std;

class array2D{
private:
    float **xtable;
    int xRes;
    int yRes;
public:
    array2D(int x, int y){
        xRes = x;
        yRes = y;

        xtable = new float*[yRes];
        for(int i=0;i < yRes;i++){
            xtable[i] = new float[xRes];
        }
    }
    void getSize(int &x, int &y){
        x = xRes;
        y = yRes;
    }
    void setValue(int x, int y, float val){
        xtable[y][x] = val;
    }
    float getValue(int x, int y){
        return xtable[y][x];
    }
    ~array2D(){
        for (int i = 0; i < yRes; i++)
            delete xtable[i];
        delete []xtable;
    }
};

int main(){
    array2D *a = new array2D(320,240);
    int xRes, yRes;
    a->getSize(xRes,yRes);

    for(int i=0;i < yRes;i++){
        for(int j=0;j < xRes;j++){
            a->setValue(j,i,100);
        }
    }
    for(int i=0;i < yRes;i++){
        for(int j=0;j < xRes;j++){
            cout << a->getValue(j,i) << " "; 
        }
   cout << endl;
    }

    delete a;
return 0;
}