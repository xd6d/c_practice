#include <iostream>
#include "Database.h"

using namespace std;

int displayMenu();
void age(Database& inDB);
void setBirth(Database& inDB);

int main() {
    Database db;

    Client c1 = *new Client("Julia Roberts", 0);
    Client c2 = *new Client("Jake Black", 1);
    Client c3 = *new Client("Tina White", 0);
    Client c4 = *new Client("John Brown", 1);
    Client c5 = *new Client("Diana Yellow", 0);
    db.addClient(c1.getName(), c1.getSex());
    db.addClient(c2.getName(), c2.getSex());
    db.addClient(c3.getName(), c3.getSex());
    db.addClient(c4.getName(), c4.getSex());
    db.addClient(c5.getName(), c5.getSex());

    bool done = false;
    while (!done) {
        int selection = displayMenu();
        switch (selection) {
            case 1:
                age(db);
                break;
            case 2:
                setBirth(db);
                break;
            case 3:
                db.displayAll();
                break;
            case 4:
                db.displayGirls();
                break;
            case 5:
                db.displayBoys();
                break;
            case 0:
                done = true;
                break;
            default:
                cerr << "Unknown command." << endl;
        }
    }
}

int displayMenu() {
    int selection;
    cout << endl;
    cout << "Clients Database" << endl;
    cout << "-----------------" << endl;
    cout << "1) Get clients age" << endl;
    cout << "2) Set birth date" << endl;
    cout << "3) List all clients" << endl;
    cout << "4) List all female clients" << endl;
    cout << "5) List all male clients" << endl;
    cout << "0) Quit" << endl;
    cout << endl;

    cout << "---> ";
    cin >> selection;
    return selection;
}

void age(Database& inDB) {
    int id;
    cout << "Enter id: ";
    cin >> id;
    try {
        cout << inDB.getClient(id).getAge() << endl;
    } catch (std::exception ex) {
        cerr << "Something went wrong" << endl;
    }
}

void setBirth(Database& inDB) {
    int day;
    int month;
    int year;
    int id;
    cout << "Enter id: ";
    cin >> id;
    cout << "Enter day: ";
    cin >> day;
    cout << "Enter month: ";
    cin >> month;
    cout << "Enter year: ";
    cin >> year;
    Client& client = inDB.getClient(id);
    client.setBDay(day);
    client.setBMonth(month);
    client.setBYear(year);
}