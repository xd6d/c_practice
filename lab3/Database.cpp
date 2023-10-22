#include "Database.h"

using namespace std;

Database::Database() {
    mNextSlot = 0;
}

Database::~Database() {
}

Client &Database::addClient(string name, Sex sex) {
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

void Database::blockClient(int inClientNumber) {
    mClients[inClientNumber].setBlocked(true);
}

void Database::unblockClient(int inClientNumber) {
    mClients[inClientNumber].setBlocked(false);
}

void Database::displayAll() {
    cout << getAllDisplayed();
}

std::string Database::getAllDisplayed() {
    std::string all;
    for (int i = 0; i < mNextSlot; i++)
        if (!mClients[i].getBlocked()) {
            all.append("Client: ").append(mClients[i].getName())
            .append(" with id ").append(to_string(mClients[i].getId())).append("\n")
            .append("Sex: ").append(mClients[i].getSex() == Sex::MALE ? "Male" : "Female").append("\n")
            .append("\n");
        }
    return all;
}

void Database::displayGirls() {
    for (int i = 0; i < mNextSlot; i++) {
        if (!mClients[i].getBlocked() && mClients[i].getSex() == Sex::FEMALE) {
            mClients[i].display();
        }
    }
}

std::string Database::getGirlsDisplayed() {
    std::string all;
    for (int i = 0; i < mNextSlot; i++)
        if (!mClients[i].getBlocked() && mClients[i].getSex() == Sex::FEMALE) {
            all.append("Client: ").append(mClients[i].getName())
                    .append(" with id ").append(to_string(mClients[i].getId())).append("\n")
                    .append("Sex: ").append("Female").append("\n")
                    .append("\n");
        }
    return all;
}

void Database::displayBoys() {
    for (int i = 0; i < mNextSlot; i++) {
        if (!mClients[i].getBlocked() && mClients[i].getSex() == Sex::MALE) {
            mClients[i].display();
        }
    }
}

Client* Database::getAll() {
    return mClients;
}

int Database::size() {
    return mNextSlot;
}

void Database::flush() {
    std::fill( std::begin(mClients), std::end(mClients), Client());
    mNextSlot = 0;
}

std::string Database::getBoysDisplayed() {
    std::string all;
    for (int i = 0; i < mNextSlot; i++)
        if (!mClients[i].getBlocked() && mClients[i].getSex() == Sex::MALE) {
            all.append("Client: ").append(mClients[i].getName())
                    .append(" with id ").append(to_string(mClients[i].getId())).append("\n")
                    .append("Sex: ").append("Male").append("\n")
                    .append("\n");
        }
    return all;
}
