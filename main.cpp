#include <cmath>
#include <cstdio>
#include <vector>
#include <array>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int n,q;
    cin >> n >> q;
    
    vector<vector<int>> arr;
    
    for (int i = 0; i < n ; ++i ) {

        int k;
        cin >> k; 

        auto c = vector<int>();

        for (int j = 0; j < k ; ++j ) {

            int el;  
            cin >> el;

            c.push_back(el);

        }

        arr.push_back(c);

    }
    
    vector<array<int,2>> qs;

    for (int i = 0; i < q ; ++i){

        array<int,2> query;
        cin >> query[0] >> query[1];

        qs.push_back(query);

    }

    for_each(qs.begin(),qs.end(),[&arr](auto q){
            cout << arr[q[0]][q[1]] << std::endl; });

    return 0;

}
