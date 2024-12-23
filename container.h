#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "note.h"

using namespace std;

struct Element
{
    Element* next;
    Note* data;
};

class Container
{
private:
    Element* head;
    Element* tail;
    int count;

public:
    Container();
    Container(Element* h, Element* t, const int c);
    Container(const Container& other);
    ~Container();

    Element* get_head();
    Element* get_tail();

    void add_note(Note* N, int index);
    Container& delete_note(int index);
    Container& edit_note(int index);
    void display_notes();
    void sort_notes_by_date();
    void search_note(const double number);
};
