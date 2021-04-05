#include<fstream>
#include<iostream>
#include<string>
#include<cctype>

using namespace std;

void merge_file(const char *src1, const char *src2, const char *dst)
{
	ifstream infile;
	infile.open(src1, ios::in);
	ofstream outfile;
	outfile.open(dst, ios::app | ios::out);
	if (!infile.is_open())
	{
		cout << "error" << endl;
		return;
	}
	if (!outfile.is_open())
	{
		cout << "error" << endl;
		return;
	}
	char arr[10];
	while (!infile.eof())
	{
		infile >> arr;
		//cout << arr << endl;
		outfile << arr << endl;
	}
	infile.close();
	outfile.close();

	ifstream in;
	in.open(src2, ios::in);
	ofstream out;
	out.open(dst, ios::app | ios::out);
	if (!in.is_open())
	{
		cout << "error" << endl;
		return;
	}
	if (!out.is_open())
	{
		cout << "error" << endl;
		return;
	}
	char a[10];
	while (!in.eof())
	{
		in >> a;
		//cout << a << endl;
		out << a << endl;
	}
	in.close();
	out.close();

}

void upper_file(const char *src, const char *dst)
{
	char arr;
	ifstream infile;
	infile.open(src, ios::in);
	if (!infile.is_open())
	{
		cout << "error" << endl;
		return;
	}
	ofstream outfile;
	outfile.open(dst, ios::out | ios::app);
	while (!infile.eof())
	{
		infile >> arr;
    }
	if ((arr <= 'z') && (arr >= 'a'))
	{
		arr = arr - 32;
	}
	cout << arr << endl;
	outfile << arr << endl;
	infile.close();
	outfile.close();
}

int main()
{
	merge_file("A.txt", "B.txt", "C.txt");
	upper_file("C.txt", "Cupper.txt");
	return 0;
}