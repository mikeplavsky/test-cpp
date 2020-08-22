#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

struct Tag {
    string name;
    map<string, Tag> tags;
    map<string,string> attrs;
};

std::pair<Tag,bool> parse_tag() {

    Tag tag;
    bool closed = false;

    for (;;){

        string t;
        cin >> t;

        auto b = t.begin();
        auto e = t.rbegin();

        if (*b == '<'){

            tag.name = t.substr(1);

            if (*next(b) == '/') {
                tag.name = t.substr(2,t.length()-3);
                closed = true;
            }

        }

        if (*e == '>') {
            break;
        } 
    }

    return make_pair(tag,closed);

}

int main() {

    long n, q;
    cin >> n >> q; 

    for (int i = 0; i < n ; ++i) {
        auto res = parse_tag();
        cout << res.first.name << ' ' << res.second << std::endl;
    }

    for (int i = 0; i < q; ++i) {
        string query;
        cin >> query;
    }

}
