#include "kkimp.h"
#include "alg.h"

using namespace std;

/*
*  Plain old Karmarkar-Karp.
*/

// Use binary search to insert an element
// into the correct position.
void binarysearch(uint64_t x, vector<uint64_t> &a) {
    int m;
    int l = 0;
    int r = a.size() - 1;
    while (l <= r) {
        m = (l+r)/2;
        if (l == r) {
            if (a[m] < x) {
                m++;
            }
            break;
        }
        if (a[m] < x) {
            l = m+1;
        }
        if (a[m] > x) {
            r = m-1;
        }
        if (a[m] == x) {
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

// Implementation of the KK algorithm
uint64_t kk(vector<uint64_t> a) {
    sort(a.begin(),a.end());

    while(a[0] == 0) {
        a.erase(a.begin());
    }
    
    if (a.empty()) return 0;

    while (a.size() > 1) {
        uint64_t x = a[a.size()-1];
        a.pop_back();
        uint64_t y = a[a.size()-1];
        a.pop_back();
        binarysearch(x-y,a);
    }

    return a[0];
}