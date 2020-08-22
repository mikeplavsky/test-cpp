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

    for (;;){

        string t;
        cin >> t;

        auto b = t.begin();
        auto e = t.rbegin();

        if (*b == '<'){

            string tag = t.substr(1);
            cout << tag << std::endl;

            if (*next(b) == '/') {
                string tag = t.substr(2,t.length()-3);
                cout << tag << std::endl;
            }

        }

        if (*e == '>') {
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
