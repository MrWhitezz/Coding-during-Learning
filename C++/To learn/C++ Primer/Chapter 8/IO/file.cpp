#include <bits/stdc++.h>
using namespace std;

void test01()
{
    ofstream ofs;
    ofs.open("test.txt", ios ::out);
    ofs << "Name: Zhang" << endl;
    ofs << "Sex: man" << endl;
    ofs << "Age: 18" << endl;
    ofs.close();
}

void test02()
{
    ifstream ifs;
    ifs.open("test.txt", ios ::in);
    if (!ifs.is_open())
    {
        cout << "Fail to open a file\n";
        return;
    }
    /*
    char buf[1024] = {0};
    while (ifs >> buf)
    {
        cout << buf << endl;
    }
*/
    char buf1[1024] = {0};
    while (ifs.getline(buf1, sizeof(buf1)))
    {
        cout << buf1 << endl;
    }
    /*
    string buf;
    while (getline(ifs, buf))
    {
        cout << buf << endl;
    }

    char c;
    while ((c = ifs.get()) != EOF)
    {
        cout << c;
    }
*/
    ifs.close();
}

int main()
{
    test01();
    test02();
    return 0;
}