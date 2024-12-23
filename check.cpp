#include "check.h"
//ïðîâåðêà
int check_input() {
    int val;
    while (true) {
        cin >> val;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Incorrect input. Please enter a number: " << endl;
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return val;
        }
    }
}
int check_date_day() {
    int val;
    while (true) {
        val = check_input();
        if (val > 31 || val < 0) {
            cout << "Incorrect day of date. Please enter a number from 1 to 31: " << endl;
        }
        else {
            return val;
        }
    }
}
//ïðîâåðêà
int check_date_month() {
    int val;
    while (true) {
        val = check_input();
        if (val > 12 || val <= 0) {
            cout << "Incorrect month of date. Please enter a number from 1 to 12: " << endl;
        }
        else {
            return val;
        }
    }
}
bool exist_date(int d, int m, int y) {
    if (d > 31 || d < 0) {
        cout << "Incorrect day of date. Please enter a number from 1 to 31. " << endl;
        return false;
    }
    if (m > 12 || m <= 0) {
        cout << "Incorrect month of date. Please enter a number from 1 to 12. " << endl;
        return false;
    }
    if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) {
        return false;
    }
    if ((m == 2) && (y % 4 != 0) && (d == 29 || d == 30 || d == 31)) {
        return false;
    }
    if ((m == 2) && (y % 4 == 0) && (d == 30 || d == 31)) {
        return false;
    }
    return true;
}

void check_date(int& d, int& m, int& y) {
    while (true) {
        if (exist_date(d, m, y)) {
            break;
        }
        else {
            cout << "Error. Non-existent date. Please enter the date again." << endl;
            cout << "Enter day: ";
            d = check_date_day();
            cout << "Enter month: ";
            m = check_date_month();
            cout << "Enter year: ";
            y = check_input();
        }
    }
}
