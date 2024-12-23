#include "container.h"
#include "note.h"
#include "check.h"
#include "sentence.h"

void display_menu() {
    cout << "\n===== Menu =====" << endl;
    cout << "1. Add a note" << endl;
    cout << "2. Delete the note" << endl;
    cout << "3. Edit the note" << endl;
    cout << "4. Show all notes" << endl;
    cout << "5. Sort notes by date of birth" << endl;
    cout << "6. Find the note by number" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
}

int first_program() {
    Container notes;
    int choice;

    while (true) {
        display_menu();
        choice = check_input();

        switch (choice) {
        case 1: {
            int index;
            string name;
            double number;
            int date_of_birth[3];
            cout << "Enter the name: ";
            getline(cin, name);
            cout << "Enter the phone number: ";
            cin >> number;
            cout << "Enter the day of birth (DD): ";
            date_of_birth[0] = check_date_day();
            cout << "Enter the month of birth (MM): ";
            date_of_birth[1] = check_date_month();
            cout << "Enter the year of birth (YYYY): ";
            date_of_birth[2] = check_input();
            check_date(date_of_birth[0], date_of_birth[1], date_of_birth[2]);
            cout << "Enter the index, where to insert the note ";
            index = check_input();

            Note* new_note = new Note(name, number, date_of_birth);
            try {
                notes.add_note(new_note, index - 1);
                cout << "The note has been added." << endl;
            }
            catch (const out_of_range& e) {
                cout << e.what() << endl;
                delete new_note;
            }
            break;
        }
        case 2: {
            int index;
            cout << "Enter the index of note for deleting: ";
            index = check_input();
            try {
                notes.delete_note(index - 1);
                cout << "The note has been deleted" << endl;
            }
            catch (const out_of_range& e) {
                cout << e.what() << endl;
            }
            break;
        }
        case 3: {
            int index;
            cout << "Enter the index of note for editing: ";
            index = check_input();
            try {
                notes.edit_note(index - 1);
                cout << "The note has been edited." << endl;
            }
            catch (const out_of_range& e) {
                cout << e.what() << endl;
            }
            break;
        }
        case 4: {
            notes.display_notes();
            break;
        }
        case 5: {
            notes.sort_notes_by_date();
            cout << "The notes are sorted by date of birth." << endl;
            notes.display_notes();
            break;
        }
        case 6: {
            cout << "Enter the phone number to search for: ";
            double number;
            cin >> number;
            notes.search_note(number);
            break;
        }
        case 0: {
            cout << "Exit." << endl;
            return 0;
        }
        default: {
            cout << "Incorrect choice. Please try again." << endl;
            break;
        }
        }
    }

    return 0;
}

int second_program() {
    try {
        int choice;
        cout << "Select source (1 - string, 2 - file): ";
        if (!(cin >> choice)) {
            throw invalid_argument("Error: incorrect input of the source selection.");
        }
        if (choice == 1) {
            cin.ignore();
            char text[8192];
            cout << "Enter the text: ";
            cin.getline(text, sizeof(text));

            if (cin.fail()) {
                throw overflow_error("Error: the maximum text length has been exceeded.");
            }

            SentenceFilter filter(text, true);
            filter.result();
        }
        else if (choice == 2) {
            char filename[256];
            cout << "Enter the name of file: ";
            cin >> filename;
            ifstream file(filename);
            if (!file) {
                throw runtime_error("Error: the file was not found or could not be opened.");
            }
            file.close();
            SentenceFilter filter(filename);
            filter.result();
        }
        else {
            throw out_of_range("Error: a non-existent source has been selected.");
        }
    }
    catch (const invalid_argument& e) {
        cerr << e.what() << endl;
        return 1;
    }
    catch (const overflow_error& e) {
        cerr << e.what() << endl;
        return 2;
    }
    catch (const runtime_error& e) {
        cerr << e.what() << endl;
        return 3;
    }
    catch (const out_of_range& e) {
        cerr << e.what() << endl;
        return 4;
    }
    catch (...) {
        cerr << "Unknown error." << endl;
        return -1;
    }
    return 0;
}


int main() {
    int choice;
    while (1) {
        cout << "Select the type of task:" << endl;
        cout << "1. Standard streams" << endl;
        cout << "2. File and string streams" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        choice = check_input();

        switch (choice) {
        case 1:
            first_program();
            break;
        case 2:
            second_program();
            break;
        case 3:
            cout << "Exit." << endl;
            return 0;
        default:
            cout << "Incorrect choice. Please try again." << endl;
            break;
        }
    }
    return 0;
}
