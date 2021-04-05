#include<fstream> 
#include<iostream> 
using namespace std; 
void merge_file(const char *src1, const char *src2, const char *dst) 
{ 
   ifstream infile; infile.open(src1, ios::in); 
   ofstream outfile; outfile.open(dst, ios::out); 
   if (!infile.is_open()) { cout << "error" << endl; return; }
   while (!infile.eof()) { char arr[10]; 
   infile.getline(arr, sizeof(arr), '\n'); 
   outfile << arr; }
   infile.close(); 
   outfile.close(); 

   ifstream in; in.open(src2, ios::in); 
   ofstream out; out.open(dst, ios::app); 
   if (!in.is_open()) { cout << "error" << endl; return; }
   while (!in.eof()) { char a[10]; 
   in.getline(a, sizeof(a), '\n'); 
   out << a; }
   in.close();
   out.close(); }
   void upper_file(const char *src, const char *dst) {} 
   void lower_file(const char *src, const char *dst) {} 
   void sort_inc_file(const char *src, const char *dst) {} 
   void sort_dec_file(const char *src, const char *dst) {} 
   int main() 
   { 
      merge_file("A.txt", "B.txt", "C.txt"); 
   return 0; 
   }