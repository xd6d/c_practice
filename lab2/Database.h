#include "Client.h"

const int kMax = 100;
const int kFirstNumber = 1000;
class Database {
public:
    Database();
    ~Database();
    Client& addClient(std::string name, Sex sex);
    Client& getClient(int inClientNumber);
    void blockClient(int inClientNumber);
    void unblockClient(int inClientNumber);
    void displayAll();
    void displayGirls();
    void displayBoys();
protected:
    Client mClients[kMax];
    int mNextSlot;
    int mNextNumber;
};