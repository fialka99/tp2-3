#include "note.h"

Note::Note() : name(""), phone_number(0) {
    date_of_birth[0] = date_of_birth[1] = date_of_birth[2] = 0;
    cout << "Constructor called without parameters for Note class\n";
}

Note::Note(const string& name, double num, const int bd[3]) : name(name), phone_number(num) {
    for (int i = 0; i < 3; ++i) {
        date_of_birth[i] = bd[i];
    }
    cout << "Constructor called with parameters for Note class\n";
}

Note::Note(const Note& other) : name(other.name), phone_number(other.phone_number) {
    for (int i = 0; i < 3; ++i) {
        date_of_birth[i] = other.date_of_birth[i];
    }
    cout << "The copy constructor for the Note class has been called " << endl;
}

Note::~Note() { cout << "The destructor for the Note class has been called" << endl; }

string Note::get_name() {
    return name;
}

void Note::set_name(string& n) {
    name = n;
}

int Note::get_number() {
    return phone_number;
}

void Note::set_number(double& n) {
    phone_number = n;
}

void Note::set_date(int bd[3]) {
    for (int i = 0; i < 3; ++i) {
        date_of_birth[i] = bd[i];
    }
}

int* Note::get_date() {
    return date_of_birth;
}

void Note::display_note() {
    cout << fixed << setprecision(0);
    cout << "Name: " << name << "\nPhone: " << phone_number << endl;
    cout << "Birthday: ";
    for (int i = 0; i < 3; i++) {
        if (date_of_birth[i] < 10)
            cout << '0' << date_of_birth[i] << '.';
        else
            cout << date_of_birth[i] << '.';
    }
    cout << "\n";
}
void Note::edit_note() {
    int choice;
    string new_name;
    double new_number;
    int new_date_of_birth[3];

    cout << "Select which data you want to change" << endl;
    cout << "1. The name" << endl;
    cout << "2. The phone number" << endl;
    cout << "3. The date of birth" << endl;
    cout << "0. Exit" << endl;
    choice = check_input();

    switch (choice) {
    case 1: {
        cout << "Enter new name: ";
        getline(cin, new_name);
        set_name(new_name);
        break;
    }
    case 2: {
        cout << "Enter new phone number: ";
        cin >> new_number;
        set_number(new_number);
        break;
    }
    case 3: {
        cout << "Enter the day of birth (DD): ";
        new_date_of_birth[0] = check_date_day();
        cout << "Enter the month of birth (MM): ";
        new_date_of_birth[1] = check_date_month();
        cout << "Enter the year of birth (YYYY): ";
        new_date_of_birth[2] = check_input();
        check_date(new_date_of_birth[0], new_date_of_birth[1], new_date_of_birth[2]);
        set_date(new_date_of_birth);
        break;
    }
    case 0: {
        cout << "Exit from editing" << endl;
        break;
    }
    default:
        cout << "Incorrect choice. Please try again." << endl;
        break;

    }
}

ostream& operator<<(ostream& os, Note N) {
    os << fixed << setprecision(0);
    os << "Name: " << N.name << "\nPhone: " << N.phone_number << endl;
    cout << "Birthday: ";
    for (int i = 0; i < 3; i++) {
        if (N.date_of_birth[i] < 10)
            os << '0' << N.date_of_birth[i] << '.';
        else
            os << N.date_of_birth[i] << '.';
    }
    return os;
}
istream& operator>>(istream& is, Note& N) {
    cout << "Enter the name: ";
    getline(is, N.name);
    cout << "Enter the phone number: ";
    is >> N.phone_number;
    cout << "Enter the day of birth (DD): ";
    is >> N.date_of_birth[0];
    cout << "Enter the month of birth (MM): ";
    is >> N.date_of_birth[1];
    cout << "Enter the year of birth (YYYY): ";
    is >> N.date_of_birth[2];
    check_date(N.date_of_birth[0], N.date_of_birth[1], N.date_of_birth[2]);
    return is;
}
