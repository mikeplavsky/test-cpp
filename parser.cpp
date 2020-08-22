#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

struct Tag {

    string name;
    shared_ptr<Tag> parent;

    map<string, Tag> tags;
    map<string,string> attrs;
};

map<string,string> parse_attrs(){

    map<string,string> res;
    bool attr = true;

    for (;;) {

        string l;
        cin >> l;

        attr = !attr;

        auto e = l.rbegin();

        if (*e == '>') {
            break;
        } 

    }

    return res;

}

auto parse_tag() {

    shared_ptr<Tag> tag(new Tag());
    bool closed = false;

    string t;
    cin >> t;

    auto b = t.begin();
    tag -> name = t.substr(1);

    if (*next(b) == '/') {
        tag -> name = t.substr(2,t.length()-3);
        closed = true;
    }
    else {
        tag -> attrs = parse_attrs();
    }

    return make_pair(tag,closed);

}

int main() {

    long n, q;
    cin >> n >> q; 

    shared_ptr<Tag> curr; 

    for (int i = 0; i < n ; ++i) {

        auto res = parse_tag();

        if (curr) {
            res.first -> parent = curr; 
        } 
        else {
            curr = res.first; 
        }

        cout << res.first -> name 
            << ' ' 
            << res.second 
            <<  ' ' 
            << curr -> name 
            << std::endl;
    }

    for (int i = 0; i < q; ++i) {
        string query;
        cin >> query;
    }

}
