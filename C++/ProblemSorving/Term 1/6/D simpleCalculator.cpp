#include<iostream>
using namespace std;

int main()
{
    char ch;
    int temp = 0;
    int temp_mul = 1;
    int sum = 0;
    cin >> ch;
    while (ch != '\n')
    {
        if (ch == '*')
        {
            temp_mul *= temp;
            temp = 0;
            cin.get(ch);
            continue;
        }
        if (ch == '+')
        {
            temp_mul *= temp;
            sum += temp_mul;
            temp = 0;
            temp_mul = 1;
            cin.get(ch);
            continue;
        }
        if (ch == ' ')
        {
            cin.get(ch);
            continue;
        }
        temp = temp * 10 + (int)ch - 48;
        cin.get(ch);
    }
    temp_mul *= temp;
    sum += temp_mul;
    temp = 0;
    cout << sum;

    return 0;
}

