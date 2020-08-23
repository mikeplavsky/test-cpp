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
    string attr_name;

    for (;;) {

        string l;
        cin >> l;

        auto e = l.rbegin();

        if (not attr) {

            string v = l.substr(1,l.length() - 2);

            if (v.back() == '\"') {
                v = v.substr(0,v.length() - 1);
            }

            res[attr_name] = v;
            attr = true;

        } 
        else if (attr and *e == '=') {
            attr = false;
        }
        else if (attr) {
            attr_name = l;
        }

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

    shared_ptr<Tag> parent; 
    map<string, shared_ptr<Tag>> tags;

    for (int i = 0; i < n ; ++i) {

        auto res = parse_tag();

        auto opened = not res.second;
        auto tag = res.first;

        if (opened) {

            tag -> parent = parent; 
            parent = tag;

            tags[tag -> name] = tag;

        } 
        else {
            parent = tags[tag -> name] -> parent;
        } 

    }

    for (auto [a,b]: tags) {

        cout 
            << a
            << ' ' << (b -> parent? b -> parent  -> name: "")
            << "\n";

        for (auto [attr,val]: b -> attrs){
            cout << attr << ":" << val << std::endl;
        }

    }

    for (int i = 0; i < q; ++i) {

        string q;
        cin >> q;

        istringstream in(q);
        string t;

        while (getline(in,t,'.')) {
            cout << t << std::endl;
        }

    }

}
