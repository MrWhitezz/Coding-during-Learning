#include <iostream>
using namespace std;
int main()
{
   int sum = 0, value = 0;
   while (cin >> value)//理解cin对象的返回值
      sum += value;
   cout << "Sum is " << sum << endl;
   return 0;
}