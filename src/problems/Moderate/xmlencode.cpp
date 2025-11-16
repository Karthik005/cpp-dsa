#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

struct Attribute {
    string name;
    string value;
};

struct Element {
    string name;
    vector<Attribute> attrs;
    vector<Element> children;
};

string generate_compressed(const Element& elem, const unordered_map<string, int>& tag_map) {
    if (tag_map.find(elem.name) == tag_map.end()) return elem.name;

    string compressed = to_string(tag_map.at(elem.name)) + ' ';
    for (const Attribute& attr : elem.attrs) {
        compressed+=(to_string(tag_map.at(attr.name))+ " " + attr.value+" ");
    }
    compressed+="0 ";
    for (const Element& child : elem.children) {
        compressed += generate_compressed(child, tag_map);
    }

    compressed+=" 0";
    return compressed;
}

int main() {
    Element root{"family"};
    root.attrs.push_back(Attribute{"lastName", "McDowell"});
    root.attrs.push_back(Attribute{"state", "CA"});
    Element person{"person"};
    person.attrs.push_back(Attribute{"firstName", "Gayle"});
    person.children.push_back(Element{"Some message"});
    root.children.push_back(person);
    unordered_map<string, int> tag_map {
        {"family", 1}, 
        {"person", 2}, 
        {"firstName", 3},
        {"lastName", 4},
        {"state",5}
    };
    cout << generate_compressed(root, tag_map) <<endl; 
}