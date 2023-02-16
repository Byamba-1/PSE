//
// Created by byamba on 16/02/23.
//

#include "CD.h"
#include <iostream>
#include <stdlib.h>
using namespace std;
CD::CD(string &artist, string &title, string &year, string &price)
    : ARTIST(artist), TITLE(title), YEAR(atoi(year.c_str())), PRICE(atof(price.c_str()))
{}

string CD::getTitle() const {
    return TITLE;
}

string CD::getArtist() const {
    return ARTIST;
}

double CD::getPrice() const {
    return PRICE;
}

int CD::getYear() const {
    return YEAR;
}

void CD::setArtist(const string &artist) {
    ARTIST = artist;
}

void CD::setPrice(const string &price) {
    PRICE = atoi( price.c_str() );
}

void CD::setTitle(const string &title) {
    TITLE = title;
}

void CD::setYear(const string &year) {
    YEAR = atof( year.c_str());
}

void CD::print() const {
    if(!TITLE.empty())
        cout << "TITLE is: " << TITLE << "\n";
    if(!ARTIST.empty())
        cout << "ARTIST is: " << ARTIST << "\n";
    if(PRICE >= 0)
        cout << "PRICE is: " << PRICE << "\n";
//    if(!YEAR.empty())
    cout << "YEAR is: " << YEAR << "\n";
}