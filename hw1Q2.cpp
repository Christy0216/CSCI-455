//Question 2
#include <iostream>
#include <math.h>
using namespace std;

void printStars(int n) {
  for(int i=0;i < n;i++) {
    cout << "*";
  }
  cout << endl;
}/// printStars()

double randomNumber()
{
double x = ((double) rand() / (RAND_MAX));
return x;
}//generate random number between 0 to 1

int main()
{
srand((unsigned)time(NULL)); // random seed set
int counters[10] = {};
int N = 1000000;// number of tries
for(int i = 0; i < N; i++) //simulation N times
{int bin = floor(randomNumber()*10);
switch (bin)
{
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
default:
break;
}
}
int total = counters[0]+counters[1]+counters[2]+counters[3]+counters[4]+counters[5]+counters[6]+counters[7]+counters[8]+counters[9];
cout << "uniform distribution:" << endl;
for (int i = 0; i < 10; i++)
{int nAsterisks = floor(100*counters[i]/total);
printStars(nAsterisks); // prints a chain of nAsterisks *s
}


for(int i=0;i<10;i++){
counters[i]=0;
}

for(int i = 0; i < N; i++) //simulation N times
{
double r1 = randomNumber();
double r2 = randomNumber();
double r = 0.5*(r1+r2);
int bin = floor(r*10);
switch (bin)
{
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
default:
break;
}
}
cout << "triangular distribution:" << endl;
for (int i = 0; i < 10; i++)
{int nAsterisks = floor(100*counters[i]/total);
printStars(nAsterisks); // prints a chain of nAsterisks *s
}
}
