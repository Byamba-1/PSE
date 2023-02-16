#include <iostream>
#include "tinyxml.h"
#include <string>
#include "CD.h"
#include <vector>
using namespace std;

int main() {
    TiXmlDocument doc;
    if (!doc.LoadFile("./cdCatalog.xml")) {
        std::cerr << doc.ErrorDesc() << std::endl;
        return 1;
    }
    TiXmlElement *root = doc.FirstChildElement();
    if (root == NULL) {
        std::cerr << "Failed to load file: No root element." << std::endl;
        doc.Clear();
        return 1;
    }
    vector<CD> temp;
    for (TiXmlElement *elem = root->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement()) {
        CD toSave;
        for (TiXmlElement *elemInner = elem->FirstChildElement(); elemInner != NULL; elemInner = elemInner->NextSiblingElement()) {
            string elemName = elemInner->Value();
            const string text = elemInner->GetText();
            if (elemName == "TITLE") {
                if (text != "")
                    toSave.setTitle(text);
            } else if (elemName == "ARTIST") {
                if (text != "")
                    toSave.setArtist(text);
                //        }else if(elemName == "COUNTRY"){
                //            if(text != "")
                //                cout << "COUNTRY is: " << text << "\n";
                //        }else if(elemName == "COMPANY"){
                //            if(text != "")
                //                cout << "COMPANY is: " << text << "\n";
            } else if (elemName == "PRICE") {
                if (text != "")
                    toSave.setPrice(text);
            } else if (elemName == "YEAR") {
                if (text != "")
                    toSave.setYear(text);
            }
        }
        temp.push_back(toSave);
    }
    for(int i = 0; i < temp.size(); i++)
        temp[i].print();
    doc.Clear();
}
