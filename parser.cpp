#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <memory>

using namespace std;

struct Tag {

    Tag () {}
    Tag(string  n): name(n){} 

    string name;
    shared_ptr<Tag> parent;

    map<string, shared_ptr<Tag>> tags;
    map<string,string> attrs;
};

auto parse_attrs(){

    map<string,string> res;

    bool attr = true;
    string attr_name;

    for (;;) {

        string l;
        cin >> l;

        auto e = l.rbegin();

        if (not attr) {

            auto v = l.substr(1,l.length() - 2);

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

    auto tag = make_shared<Tag>();
    auto closed = false;

    string t;
    cin >> t;

    auto b = t.begin();
    auto empty = *prev(t.end()) == '>';

    tag -> name = t.substr(1);

    if (empty) {
        tag -> name = t.substr(1,t.length()-2);
    }

    if (*next(b) == '/') {
        tag -> name = t.substr(2,t.length()-3);
        closed = true;
    }
    else if (not empty) {
        tag -> attrs = parse_attrs();
    }

    return make_pair(tag,closed);

}

template<class T> void print(T *root) {

    for (auto &[a,b]: root -> tags) {

        cout 
            << a
            << ' ' << (b -> parent? b -> parent  -> name: "")
            << "\n";

        for (auto [attr,val]: b -> attrs){
            cout << attr << ":" << val << std::endl;
        }

    }

}

int main() {

    long n, q;
    cin >> n >> q; 

    auto root = make_shared<Tag>("root");
    auto parent = root;

    for (int i = 0; i < n ; ++i) {

        auto res = parse_tag();

        auto opened = not res.second;
        auto tag = res.first;

        if (opened) {

            tag -> parent = parent; 
            parent -> tags[ tag -> name ] = tag;

            parent = tag;

        } 
        else {
            parent = parent -> parent;
        } 

    }

    for (int i = 0; i < q; ++i) {

        string q;
        cin >> q;

        istringstream in(q);
        string t;

        auto curr = *root;

        while (getline(in,t,'.')) {

            auto pos = t.find('~');

            if (pos == t.npos) {

                auto res = curr.tags.find(t);

                if (res == curr.tags.end()) {

                    std::cout << "Not Found!" << std::endl;
                    break;

                } 

                curr = *res -> second;

            }
            else {

                auto tag = t.substr(0,pos);
                auto a = t.substr(pos + 1);

                auto next = curr.tags.find(tag);

                if (next == curr.tags.end()) {

                    std::cout << "Not Found!" << std::endl;
                    break;

                } 

                auto res = next -> second -> attrs.find(a);

                if (res == next -> second -> attrs.end()) {

                    std::cout << "Not Found!" << std::endl;
                    break;

                } 

                std::cout << res -> second << std::endl;

            }
        }
    }
}
