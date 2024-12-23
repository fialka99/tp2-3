#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "check.h"
#include <iomanip>

using namespace std;

class Note {
private:
    string name;
    double phone_number;
    int date_of_birth[3];
public:
    Note();
    Note(const string& name, double num, const int bd[3]);
    Note(const Note& other);
    ~Note();

    string get_name();
    void set_name(string& n);
    int get_number();
    void set_number(double& n);
    int* get_date();
    void set_date(int bd[3]);

    void display_note();
    void edit_note();

    friend ostream& operator<<(ostream& stream, Note N);
    friend istream& operator>>(istream& stream, Note& N);
};
