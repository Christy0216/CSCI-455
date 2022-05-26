#include <iostream>
#include <cmath>

using namespace std;

void printStars(int x){
    for(int i =0 ; i<x; i++){
        cout<<"*";
    }
cout << endl;
}/// printStars()

double randomNumber()
{
double x = ((double)rand())/RAND_MAX;
return x;
}/// random numbers from 0 to 1


int main(){
int N = 1000000;
int counters[10] = {};
double a = 0.0003;
int largestVal = -1000000;
int smallestVal = 1000000;
for(int i = 0; i < N; i++)
{
double U = randomNumber();
double x = 1/(pow(U, (1/a)));
if(x > largestVal)
{
largestVal = x;        
}
if(x < smallestVal)
{
smallestVal = x;
}
}
for(int i = 0; i< N; i++){
double U = randomNumber();
double x = 1/(pow(U, (1/a)));
double xNorm = (x - smallestVal)/(largestVal - smallestVal);
int bin = floor(xNorm*10);
switch(bin){
case 0:
counters[0]++;
break;
case 1:
counters[1]++;
break;            
case 2:
counters[2]++;
break;
case 3:
counters[3]++;
break;
case 4:
counters[4]++;
break;
case 5:
counters[5]++;
break;
case 6:
counters[6]++;
break;
case 7:
counters[7]++;
break; 
case 8:
counters[8]++;
break;
case 9:
counters[9]++;
break;
case 10:
counters[9]++;
break;
default:
break;
}
}
int total = counters[0]+counters[1]+counters[2]+counters[3]+counters[4]+counters[5]+counters[6]+counters[7]+counters[8]+counters[9];
cout << "perato distribution:" << endl;
for(int i = 0 ; i < 10; i++)
{
int nAsterisks = floor(100*counters[i]/total);
printStars(nAsterisks);
}  
}

