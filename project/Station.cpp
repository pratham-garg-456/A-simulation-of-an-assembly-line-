// Name: Pratham Garg
// Seneca Student ID: 117900217
// Seneca email: pgarg13@myseneca.ca
// Date of completion: 2022-11-15
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#include <iostream>
#include <iomanip>
#include "Station.h"
#include "Utilities.h"

size_t sdds::Station::m_widthField = 0;
int sdds::Station::id_generator = 0;

sdds::Station::Station(const string& record) {
    Utilities utilities;
    size_t next_pos = 0;
    bool more = true;
    
    id = ++id_generator;
    name = utilities.extractToken(record, next_pos, more);
    nextSerialNum = stoi(utilities.extractToken(record, next_pos, more));
    numItems = stoi(utilities.extractToken(record, next_pos, more));
    m_widthField = m_widthField > utilities.getFieldWidth() ? m_widthField : utilities.getFieldWidth();
    description = utilities.extractToken(record, next_pos, more);
}

const string& sdds::Station::getItemName() const {
    return name;
}

size_t sdds::Station::getNextSerialNumber() {
    return nextSerialNum++;
}

size_t sdds::Station::getQuantity() const {
    return numItems;
}

void sdds::Station::updateQuantity() {
    if (numItems > 0) {
        numItems--;
    }
}

void sdds::Station::display(ostream& os, bool full) const {
    os << std::right;
    os << setw(3) << setfill('0') << id << " | ";
    os << left << setfill(' ') << setw(m_widthField + 1) << name << " | ";
    os << right << setw(6) << setfill('0') << nextSerialNum << " | ";

    if (full) {
        os << setfill(' ');
        os << right;
        os << setw(4) << numItems << " | " << description;
    }

    os << endl;
}