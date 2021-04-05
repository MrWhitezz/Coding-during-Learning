#include<iostream>
#include<map>
#include<string>
using namespace std;
const int ArSize = 100;
struct IP
{
    int m1;
    int m2;
    int m3;
    int m4;

        bool operator <(const IP &I2) const{
        if (m1 != I2.m1) return m1 < I2.m1;
        else if (m2 != I2.m2) return m2 < I2.m2;
        else if (m3 != I2.m3) return m3 < I2.m3;
        else return m4 < I2.m4;
        }
};
IP web(IP &I1, IP &I2);
IP host(IP &I1, IP &I2);
IP getIP();
void getint(int *,char **);
long long gethost(IP &I);
int cont_0(int val);
string getstr(IP I);

int main()
{
    map<IP,map<IP,long long>> Net;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        IP I1 = getIP();
        IP I2 = getIP();
        IP Web = web(I1, I2);
        map<IP,map<IP,long long>> :: iterator pos = Net.find(Web);
        if (pos == Net.end())
        {
            map<IP,long long> Net_temp;
            Net_temp.insert(pair<IP,long long>(I2,gethost(I2)));
            Net.insert(pair<IP,map<IP,long long>>(Web,Net_temp));
        }
        else{
            map<IP,long long> :: iterator pos2 = pos->second.find(I2);
        if (pos2 == pos->second.end())
            pos->second.insert(pair<IP,long long>(I2,gethost(I2)));
        else{
            (pos->second)[I2] = (pos->second)[I2] > gethost(I2) ? (pos->second)[I2] : gethost(I2);
            }
        }
    }
    for (map<IP,map<IP,long long>> :: iterator it = Net.begin(); it != Net.end(); it++){
            for (map<IP, long long> :: iterator it2 = (it->second).begin(); it2 != (it->second).end(); it2++)
                cout << getstr(it->first) << " " << (it2->second) << endl;
    }
    return 0;
}
IP web(IP &I1, IP &I2)
{
    IP I_temp;
    I_temp.m1 = I1.m1 & I2.m1;
    I_temp.m2 = I1.m2 & I2.m2;
    I_temp.m3 = I1.m3 & I2.m3;
    I_temp.m4 = I1.m4 & I2.m4;
    return I_temp;
}
IP host(IP &I1, IP &I2)
{
    IP I_temp;
    I_temp.m1 = I1.m1 - web(I1,I2).m1;
    I_temp.m2 = I1.m2 - web(I1,I2).m2;
    I_temp.m3 = I1.m3 - web(I1,I2).m3;
    I_temp.m4 = I1.m1 - web(I1,I2).m4;
    return I_temp;
}
IP getIP()
{
    IP I_temp;
    char ch[ArSize];
    cin >> ch;
    char *p0 = ch;
    char **p = &p0;
    getint(&I_temp.m1, p);
    getint(&I_temp.m2, p);
    getint(&I_temp.m3, p);
    getint(&I_temp.m4, p);
    return I_temp;
}
void getint(int *x,char **p)
{
    int res = 0;
    while ((**p != '.') && (**p != '\0'))
    {
        res = res * 10 + (int)**p - 48;
        (*p)++;
    }
    (*p)++;
    *x = res;
}

int cont_0(int val)
{
    int cont = 0;
    for (;val; val -= val & (-val) )
        cont++;
    return 8 - cont;
}
long long gethost(IP &I)
{
    long long temp1, temp2, temp3, temp4;
    temp1 = (1 << cont_0(I.m1));
    temp2 = (1 << cont_0(I.m2));
    temp3 = (1 << cont_0(I.m3));
    temp4 = (1 << cont_0(I.m4));
    return temp1 * temp2 * temp3 * temp4 - 2;
}
string getstr(IP I)
{
    return to_string(I.m1) + "." + to_string(I.m2) + "." + to_string(I.m3) + "." + to_string(I.m4);
}
