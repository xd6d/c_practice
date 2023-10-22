#include "Client.h"

const int kMax = 100;
class Database {
public:
    Database();
    ~Database();
    Client& addClient(std::string name, Sex sex);
    Client& getClient(int inClientNumber);
    void blockClient(int inClientNumber);
    void unblockClient(int inClientNumber);
    void displayAll();
    std::string getAllDisplayed();
    std::string getBoysDisplayed();
    std::string getGirlsDisplayed();
    void displayGirls();
    void displayBoys();
    Client* getAll();
    int size();
    void flush();
protected:
    Client mClients[kMax];
    int mNextSlot;
};
