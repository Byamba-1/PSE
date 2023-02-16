#include <iostream>
#include "tinyxml.h"
#include <string>
using namespace std;

int main() {
    TiXmlDocument doc;
    if (!doc.LoadFile("./eenCD.xml")) {
        std::cerr << doc.ErrorDesc() << std::endl;
        return 1;
    }
    TiXmlElement *root = doc.FirstChildElement();
    if (root == NULL) {
        std::cerr << "Failed to load file: No root element." << std::endl;
        doc.Clear();
        return 1;
    }
    for (TiXmlElement *elem = root->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement()) {
        string elemName = elem->Value();
        const string text = elem->GetText();
        if(elemName == "TITLE"){
            if(!text.empty())
                cout << "TITLE is: " << text << "\n";
        }else if(elemName == "ARTIST"){
            if(!text.empty())
                cout << "ARTIST is: " << text << "\n";
        }else if(elemName == "COUNTRY"){
            if(!text.empty())
                cout << "COUNTRY is: " << text << "\n";
        }else if(elemName == "COMPANY"){
            if(!text.empty())
                cout << "COMPANY is: " << text << "\n";
        }else if(elemName == "PRICE"){
            if(!text.empty())
                cout << "PRICE is: " << text << "\n";
        }else if(elemName == "YEAR"){
            if(!text.empty())
                cout << "YEAR is: " << text << "\n";
        }
    }
    doc.Clear();
}
