
#include "container.h"

Container::Container() : head(nullptr), tail(nullptr), count(0) { cout << "Constructor called without parameters for Container class\n"; }

Container::Container(Element* h, Element* t, const int c) : head(h), tail(t), count(c) { cout << "The constructor with parameters for the Container class was called\n"; }

Container::Container(const Container& other) : head(other.head), tail(other.tail), count(other.count) { cout << "The copy constructor for the Container class has been called\n"; }

Container::~Container() {
    while (head != nullptr) {
        Element* temp = head;
        head = head->next;
        delete temp->data;
        delete temp;
    }
    tail = nullptr;
    count = 0;
    cout << "The destructor for the Container class has been called" << endl;
}


Element* Container::get_head() {
    return this->head;
}

Element* Container::get_tail() {
    return this->tail;
}

void Container::add_note(Note* N, int index) {
    if (index < 0 || index > count) {
        throw out_of_range("Index out of range");
    }

    Element* Element_to_add = new Element;
    Element_to_add->data = N;
    Element_to_add->next = nullptr;

    if (index == 0) {
        Element_to_add->next = head;
        head = Element_to_add;
        if (count == 0) {
            tail = Element_to_add;
        }
    }
    else {
        Element* prev = head;
        for (int i = 0; i < index - 1; ++i) {
            prev = prev->next;
        }
        Element_to_add->next = prev->next;
        prev->next = Element_to_add;

        if (Element_to_add->next == nullptr) {
            tail = Element_to_add;
        }
    }

    ++count;
}

Container& Container::delete_note(int index) {
    if (index < 0 || index >= count) {
        throw out_of_range("Index out of range");
    }

    Element* temp = head;

    if (index == 0) {
        head = head->next;
        delete temp->data;
        delete temp;
        if (head == nullptr) {
            tail = nullptr;
        }
    }
    else {
        Element* prev = nullptr;
        for (int i = 0; i < index; ++i) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        if (temp == tail) {
            tail = prev;
        }
        delete temp->data;
        delete temp;
    }

    --count;
    return *this;
}

void Container::display_notes() {
    Element* temp = head;
    if (count == 0) {
        cout << "There are no notes." << endl;
        return;
    }
    int index = 1;
    while (temp != 0) {
        cout << "\n" << index << " - Information about the person:\n";
        temp->data->display_note();
        temp = temp->next;
        index++;
    }
}

void Container::sort_notes_by_date() {
    if (count < 2) return;

    for (Element* i = head; i != nullptr; i = i->next) {
        for (Element* j = head; j->next != nullptr; j = j->next) {

            int* date1 = j->data->get_date();
            int* date2 = j->next->data->get_date();

            if ((date1[2] > date2[2]) ||
                (date1[2] == date2[2] && date1[1] > date2[1]) ||
                (date1[2] == date2[2] && date1[1] == date2[1] && date1[0] > date2[0])) {

                Note* temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
            }
        }
    }
}

void Container::search_note(const double number) {
    Element* temp = head;
    while (temp != nullptr) {
        if (temp->data->get_number() == number) {
            temp->data->display_note();
            return;
        }
        temp = temp->next;
    }
    cout << fixed << setprecision(0);
    cout << "The person with the phone number " << number << " not found." << endl;
}

Container& Container::edit_note(int index) {
    if (index < 0 || index >= count) {
        throw out_of_range("Index out of range");
    }

    Element* temp = head;
    for (int i = 0; i < index; ++i) {
        temp = temp->next;
    }

    temp->data->edit_note();
    return *this;
}
