#include <fstream>
#include <iostream>
#include <vector>
#include <cstdint>
#include <cmath>
#include <random>
#include <algorithm>
#include "kk.h"

using namespace std;


int main() {
//	random_device rd;
//	mt19937_64 gen(rd());
//	uniform_int_distribution<uint64_t> dis(1,pow(10,12));
//	for (int i = 0; i < 7; ++i)
//	{
//		cout << dis(gen) << endl;
//	}
    
    vector<int> a = {10, 15, 0, 6, 5};
    
    int b = kk(a);
    
    cout << a.size() << endl;
    cout << a[0] << endl;
    
    cout << b << endl;
    
    return 0;
}

void binarysearch(int x, vector<int> &a)
{

    int m;
    int l = 0;
    int r = a.size() - 1;
    while (l <= r)
    {
        m = (l+r)/2;
        if (l == r) {
            if (a[m] < x)
            {
                m++;
            }
            break;
        }
        if (a[m] < x)
        {
            l = m+1;
        }
        if (a[m] > x)
        {
            r = m-1;
        }
        if (a[m] == x)
        {
            break;
        }
    }
    if (a.size()==0) {
        a.push_back(x);
    }
    else {
        a.insert(a.begin()+m,x);
    }
}

int kk(vector<int> a)
{
    sort(a.begin(),a.end());
    while(a[0] == 0)
    {
        a.erase(a.begin());
    }
    
    if (a.empty())
    {
        return 0;
    }
    while (a.size() > 1)
    {
        int x = a[a.size()-1];
        a.pop_back();
        int y = a[a.size()-1];
        a.pop_back();
        binarysearch(x-y,a);
    }
    
    return a[0];
}
