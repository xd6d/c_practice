#include <iostream>
#include "Database.h"

using namespace std;

int displayMenu();

void client(Database &inDB);

void age(Database &inDB);

void setBirth(Database &inDB);

void addClient(Database &inDB);

void blockUnblockClient(Database &inDB);

int main() {
    Database db;

    db.addClient("Julia Roberts", Sex::FEMALE);
    db.addClient("Jake Black", Sex::MALE);
    db.addClient("Tina White", Sex::FEMALE);
    db.addClient("John Brown", Sex::MALE);
    db.addClient("Diana Yellow", Sex::FEMALE);

    bool done = false;
    while (!done) {
        int selection = displayMenu();
        switch (selection) {
            case 1:
                client(db);
                break;
            case 2:
                setBirth(db);
                break;
            case 3:
                addClient(db);
                break;
            case 4:
                blockUnblockClient(db);
                break;
            case 5:
                db.displayAll();
                break;
            case 6:
                db.displayGirls();
                break;
            case 7:
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
    cout << "1) Get client" << endl;
    cout << "2) Set birth date" << endl;
    cout << "3) Add client" << endl;
    cout << "4) Block/unblock client" << endl;
    cout << "5) List all clients" << endl;
    cout << "6) List all female clients" << endl;
    cout << "7) List all male clients" << endl;
    cout << "0) Quit" << endl;
    cout << endl;

    cout << "---> ";
    cin >> selection;
    return selection;
}

void client(Database &inDB) {
    int id;
    cout << "Enter id: ";
    cin >> id;
    Client client1 = inDB.getClient(id);
    client1.display();
    cout << "Age: " << inDB.getClient(id).getAge() << endl;
}

void setBirth(Database &inDB) {
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
    Client &client = inDB.getClient(id);
    client.setBDay(day);
    client.setBMonth(month);
    client.setBYear(year);
}

void addClient(Database &inDB) {
    std::string name;
    int sexNum;
    Sex sex;
    cout << "Enter name: ";
    cin >> name;

    cout << "Enter sex(0 for FEMALE or 1 for MALE): ";
    cin >> sexNum;
    if (sexNum == 0)
        sex = Sex::FEMALE;
    else
        sex = Sex::MALE;
    inDB.addClient(name, sex);
}

void blockUnblockClient(Database &inDB) {
    int id;
    cout << "Enter id: ";
    cin >> id;
    bool blocked = inDB.getClient(id).getBlocked();
    if (blocked)
        inDB.unblockClient(id);
    else
        inDB.blockClient(id);
}