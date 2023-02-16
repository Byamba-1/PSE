#include <iostream>
#include "tinyxml.h"
#include <string>
#include "CD.h"
#include <vector>

using namespace std;

bool is_int(const std::string &s) {
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

bool is_double(const string &s) {
    int nb_point = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '.') {
            nb_point++;
        } else if (!isdigit(s[i])) {
            return false;
        }
        if (nb_point <= 1) {
            return true;
        } else {
            return false;
        }
    }
}

int main() {
    TiXmlDocument doc;
    if (!doc.LoadFile("./eenCDError.xml")) {
        std::cerr << doc.ErrorDesc() << std::endl;
        return 1;
    }
    TiXmlElement *root = doc.FirstChildElement();
    if (root == NULL) {
        std::cerr << "Failed to load file: No root element." << std::endl;
        doc.Clear();
        return 1;
    }
    vector < CD > temp;

    for (TiXmlElement *elem = root->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement()) {
        CD toSave;
        for (TiXmlElement *elemInner = elem->FirstChildElement();
             elemInner != NULL; elemInner = elemInner->NextSiblingElement()) {
            string elemName = elemInner->Value();
            const string text = elemInner->GetText();
            if (elemName == "TITLE") {
                if (is_double(text) || is_int(text)){
                    cout << "ERROR: Title is an integer or a double!\n";
                    return 1;
                }
                if (!text.empty())
                    toSave.setTitle(text);
            } else if (elemName == "ARTIST") {
                if (is_double(text) || is_int(text)){
                    cout << "ERROR: Artist is an integer or a double!\n";
                    return 1;
                }
                if (!text.empty())
                    toSave.setArtist(text);
                //        }else if(elemName == "COUNTRY"){
                //            if(text != "")
                //                cout << "COUNTRY is: " << text << "\n";
                //        }else if(elemName == "COMPANY"){
                //            if(text != "")
                //                cout << "COMPANY is: " << text << "\n";
            } else if (elemName == "PRICE") {
                if (not is_int(text)){
                    cout << "ERROR: Price is not an integer!\n";
                    return 1;
                }
                if (!text.empty())
                    toSave.setPrice(text);
            } else if (elemName == "YEAR") {
                if (not is_double(text)){
                    cout << "ERROR: Year is not a double!\n";
                    return 1;
                }
                if (!text.empty())
                    toSave.setYear(text);
            }
        }
        temp.push_back(toSave);
    }
    for (int i = 0; i < temp.size(); i++)
        temp[i].print();
    doc.Clear();
}
