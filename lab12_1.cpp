#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double A[],int N,double B[])
{
    double sum = 0,mean,sumpow = 0,multisum = 1,sumre = 0,SD,G_mean,HM,Min=A[0],Max=A[0];
    for(int i=0 ;i < N;i++)
    {
        sum += A[i];
        sumpow += A[i]*A[i];
        multisum *= A[i];
        sumre += 1/A[i];
        if(A[i] > Max)
            Max = A[i];
        if(A[i] < Min)
            Min = A[i];
    }
    mean = sum/N;
    SD = sqrt(sumpow/N-(mean*mean));
    G_mean = pow(multisum,1.0/N);
    HM = N/sumre;
    B[0] = mean;
    B[1] = SD;
    B[2] = G_mean;
    B[3] = HM;
    B[4] = Max;
    B[5] = Min;
}