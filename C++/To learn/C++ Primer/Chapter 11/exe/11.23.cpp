#include<iostream>
#include<map>
#include<set>

using namespace std;
int main()
{
	multimap<string, string> authors{
		{ "alan", "DMA" },
		{ "pezy", "LeetCode" },
		{ "alan", "CLRS" },
		{ "wang", "FTP" },
		{ "pezy", "CP5" },
		{ "wang", "CPP-Concurrency" } };  
    
    map<string, multiset<string>> order_authors;

    for (const auto &au : authors){
        order_authors[au.first].insert(au.second);
    }

    for (const auto &au : order_authors){
        cout << au.first << " : ";
        for (const auto & book : au.second){
            cout << book << " ";
        } 
        cout << endl;
    }
    return 0;
}