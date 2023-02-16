#include <iostream>
#include "tinyxml.h"
#include <string>
#include "CD.h"
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
    CD toSave;
    for (TiXmlElement *elem = root->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement()) {
        string elemName = elem->Value();
        const string text = elem->GetText();
        if(elemName == "TITLE"){
            if(!text.empty())
                toSave.setTitle(text);
        }else if(elemName == "ARTIST"){
            if(!text.empty())
                toSave.setArtist(text);
//        }else if(elemName == "COUNTRY"){
//            if(!text.empty())
//                cout << "COUNTRY is: " << text << "\n";
//        }else if(elemName == "COMPANY"){
//            if(!text.empty())
//                cout << "COMPANY is: " << text << "\n";
        }else if(elemName == "PRICE"){
            if(!text.empty())
                toSave.setPrice(text);
        }else if(elemName == "YEAR"){
            if(!text.empty())
                toSave.setYear(text);
        }
    }
    toSave.print();
    doc.Clear();
}
