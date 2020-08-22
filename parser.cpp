#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

struct Tag {
    map<string, Tag> tags;
    map<string,string> attrs;
};

void parse_tag() {

    string t;

    for (;;){
        cin >> t;
        cout << t << std::endl;
        if (*t.rbegin() == '>') {
            break;
        } 
    }

}

int main() {

    long n, q;
    cin >> n >> q; 

    for (int i = 0; i < n ; ++i) {
        parse_tag();
    }

    for (int i = 0; i < q; ++i) {
        string query;
        cin >> query;
    }

}
