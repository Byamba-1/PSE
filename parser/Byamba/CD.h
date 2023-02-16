//
// Created by byamba on 16/02/23.
//

#ifndef XMLPARSER_CD_H
#define XMLPARSER_CD_H
#include <string>

using namespace std;

class CD {
public:
    CD(string& artist, string& title, string& year, string& price);
    CD(){};
    string getArtist() const;
    string getTitle() const;
    int getYear() const;
    double getPrice() const;
    void setArtist(const string&);
    void setTitle(const string&);
    void setYear(const string&);
    void setPrice(const string&);

    void print() const;
private:
    string ARTIST;
    string TITLE;
    int YEAR;
    double PRICE;
};


#endif //XMLPARSER_CD_H
