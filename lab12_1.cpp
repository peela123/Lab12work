#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[], int, double[]);

int main()
{
    double A[] = {1.2, 3.5, 6.9, 7.8, 12.5, 0.5};
    int N = sizeof(A) / sizeof(A[0]);
    double B[6];
    stat(A, N, B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}
void stat(const double A[], int N, double B[])
{
    double sum = 0, dbl = 0, sum2 = 0;
    double min = A[0], max = A[0];
    double sum1 = 1;
    for (int i = 0; i < N; i++)
    {
        sum = A[i] + sum;
        dbl = pow(A[i], 2) + dbl;
        sum1 = sum1 * A[i];
        sum2 = sum2 + (1.00 / A[i]);
        if (A[i] > max)
            max = A[i];
        if (A[i] < min)
            min = A[i];
    }
    double mean = sum / N;
    double sd = 1.0 / N * dbl - mean * mean;
    double gm = pow(sum1, 1.0 / N);
    double hm = N / sum2;
    B[0] = mean;
    B[1] = sqrt(sd);
    B[2] = gm;
    B[3] = hm;
    B[4] = max;
    B[5] = min;
}