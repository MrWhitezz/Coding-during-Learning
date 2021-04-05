#include<bits/stdc++.h>
#include<fstream>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

void merge_file(const char *src1, const char *src2, const char *dst)
{
	ifstream infile;
	infile.open(src1, ios::in);
	ofstream outfile;
	outfile.open(dst, ios::out);
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
	out.open(dst, ios::app);
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

void sort_inc_file(const char *src, const char *dst)
{
	ifstream infile;
	infile.open(src, ios::in);
	if (!infile.is_open())
	{
		cout << "error" << endl;
		return;
	}
	ofstream outfile;
	outfile.open(dst, ios::out | ios::app);
    string str;
    vector<string> v;
	while (infile >> str)
	{
        v.push_back(str);
	}
    sort(v.begin(),v.end());
    for (auto it = v.begin(); it != v.end(); it++){
        outfile << *it << " ";
        cout << *it << " ";
    }
	infile.close();
	outfile.close();
}

int main()
{
	merge_file("A.txt", "B.txt", "C.txt");
	sort_inc_file("C.txt", "D.txt");
	return 0;
}