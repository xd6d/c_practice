#include "Database.h"

using namespace std;

Database::Database() {
    mNextSlot = 0;
    mNextNumber = kFirstNumber;
}

Database::~Database() {
}

Client &Database::addClient(string name, int sex) {
    if (mNextSlot >= kMax) {
        cerr << "There is no more room to add the new Client!" << endl;
        throw exception();

    }
    Client &theClient = mClients[mNextSlot];
    theClient.setId(mNextSlot++);
    theClient.setName(name);
    theClient.setSex(sex);
    return theClient;
}

Client &Database::getClient(int inClientNumber) {
    return mClients[inClientNumber];
}

void Database::displayAll() {
    for (int i = 0; i < mNextSlot; i++) {
        mClients[i].display();
    }
}

void Database::displayGirls() {
    for (int i = 0; i < mNextSlot; i++) {
        if (mClients[i].getSex() == 0) {
            mClients[i].display();
        }
    }
}

void Database::displayBoys() {

    for (int i = 0; i < mNextSlot; i++) {
        if (mClients[i].getSex() == 1) {
            mClients[i].display();
        }
    }
}
