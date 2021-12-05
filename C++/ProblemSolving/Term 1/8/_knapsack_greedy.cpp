#include<iostream>
using namespace std;
int main()
{
    int N;
    double C;
    cin >> N >> C;
    double Q[N], W[N], P[N];
    for (int i = 0; i < N; i++)
        cin >> Q[i];
    for (int i = 0; i < N; i++)
        cin >> W[i];
    for (int i = 0; i < N; i++)
        cin >> P[i];

    double R[N];
    for (int i = 0; i < N; i++)
        R[i] = (double)P[i] / (double)W[i];
    double F[N];
    double maxR = -1;
    double pack = C;

    while (maxR && pack != 0)
    {
        maxR = 0;
        int I = -1;
        for (int i = 0; i < N; i++)
        {
            if (maxR < R[i])
            {
                maxR = R[i];
                I = i;
            }
        }
        if (I != -1)
        {
            double A = Q[I] < (pack / W[I]) ? Q[I] : (pack / W[I]);
            F[I] = A;
            R[I] = 0;
            pack = pack - A * W[I];
        }
    }

    for (int i = 0; i < N; i++)
        cout << F[i] << " ";
    double total = 0;
    cout << '\n';
    for (int i = 0; i < N; i++)
        total += F[i] * P[i];
    cout << total;


    return 0;
}
