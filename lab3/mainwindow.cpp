#include <iostream>
#include "Database.h"
#include "mainwindow.h"
#include <QPushButton>
#include <QFileDialog>
#include <fstream>

Database db;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)

{

    db.addClient("Julia Roberts", Sex::FEMALE);
    db.addClient("Jake Black", Sex::MALE);
    db.addClient("Tina White", Sex::FEMALE);
    db.addClient("John Brown", Sex::MALE);
    db.addClient("Diana Yellow", Sex::FEMALE);

    setWindowTitle("Lab 3");
    setGeometry(550, 250, 200, 200);
    setMinimumSize(400, 450);

    outputField = new QTextEdit(this);
    outputField->setGeometry(10, 10, 380, 150);
    outputField->setReadOnly(true);

    int y = 170;
    int h = 25;
    int space = 10;

    QPushButton *displayAllButton = new QPushButton("Display all", this);
    displayAllButton->setGeometry(10, y, 380, h);
    y+=h+space;
    connect(displayAllButton, SIGNAL (released()), this, SLOT (displayAll()));

    QPushButton *displayBoysButton = new QPushButton("Display boys", this);
    displayBoysButton->setGeometry(10, y, 380, h);
    y+=h+space;
    connect(displayBoysButton, SIGNAL (released()), this, SLOT (displayBoys()));

    QPushButton *displayGirlsButton = new QPushButton("Display girls", this);
    displayGirlsButton->setGeometry(10, y, 380, h);
    y+=h+space;
    connect(displayGirlsButton, SIGNAL (released()), this, SLOT (displayGirls()));

    inputIdField = new QLineEdit(this);
    inputIdField->setPlaceholderText("Enter id");
    inputIdField->setGeometry(10, y, 190, h);

    QPushButton *clientButton = new QPushButton("Get client", this);
    clientButton->setGeometry(205, y, 90, h);
    QPushButton *blockUnblockButton = new QPushButton("Block/Unblock", this);
    blockUnblockButton->setGeometry(300, y, 90, h);
    y+=h+space;
    connect(clientButton, SIGNAL (released()), this, SLOT (client()));
    connect(blockUnblockButton, SIGNAL (released()), this, SLOT (blockUnblockClient()));

    inputDayField = new QLineEdit(this);
    inputDayField->setPlaceholderText("DD");
    inputDayField->setGeometry(10, y, 60, h);
    inputDayField->setInputMask("99");
    inputMonthField = new QLineEdit(this);
    inputMonthField->setPlaceholderText("MM");
    inputMonthField->setGeometry(75, y, 60, h);
    inputMonthField->setInputMask("99");
    inputYearField = new QLineEdit(this);
    inputYearField->setPlaceholderText("YYYY");
    inputYearField->setGeometry(140, y, 170, h);
    inputYearField->setInputMask("9999");
    QPushButton *bDayButton = new QPushButton("Set BDay", this);
    bDayButton->setGeometry(315, y, 75, h);
    connect(bDayButton, SIGNAL (released()), this, SLOT (setBirth()));

    inputName = new QLineEdit(this);
    inputName->setPlaceholderText("Enter name");
    y+=h+space;
    inputName->setGeometry(10, y, 220, h);
    inputSex = new QComboBox(this);
    inputSex->addItem("Male");
    inputSex->addItem("Female");
    inputSex->setGeometry(235, y, 75, h);
    QPushButton *addButton = new QPushButton("Add client", this);
    addButton->setGeometry(315, y, 75, h);
    connect(addButton, SIGNAL (released()), this, SLOT (addClient()));

    y+=h+space+30;
    QPushButton *loadFileButton = new QPushButton("Load file", this);
    loadFileButton->setGeometry(10, y, 180, h);
    connect(loadFileButton, SIGNAL (released()), this, SLOT (loadFile()));

    QPushButton *saveFileButton = new QPushButton("Save file", this);
    saveFileButton->setGeometry(210, y, 180, h);
    connect(saveFileButton, SIGNAL (released()), this, SLOT (saveFile()));
}

void MainWindow::displayAll() {
    outputField->setText(QString::fromStdString(db.getAllDisplayed()));
}

void MainWindow::displayBoys() {
    outputField->setText(QString::fromStdString(db.getBoysDisplayed()));
}

void MainWindow::displayGirls() {
    outputField->setText(QString::fromStdString(db.getGirlsDisplayed()));
}

void MainWindow::client() {
    std::string text;
    int id = inputIdField->text().toInt();
    Client client1 = db.getClient(id);
    text.append(client1.toString())
        .append("Age: ").append(std::to_string(db.getClient(id).getAge())).append("\n");
    outputField->setText(QString::fromStdString(text));
}

void MainWindow::setBirth() {
    int day = inputDayField->text().toInt();
    int month = inputMonthField->text().toInt();
    int year = inputYearField->text().toInt();
    int id = inputIdField->text().toInt();
    Client &client = db.getClient(id);
    client.setBDay(day);
    client.setBMonth(month);
    client.setBYear(year);
    MainWindow::client();
}

void MainWindow::addClient() {
    Client &client = db.addClient(inputName->text().toStdString(),
                 inputSex->currentText().toStdString()=="Male" ? Sex::MALE : Sex::FEMALE);
    int day = inputDayField->text().toInt();
    int month = inputMonthField->text().toInt();
    int year = inputYearField->text().toInt();
    inputName->clear();
    inputDayField->clear();
    inputMonthField->clear();
    inputYearField->clear();
    client.setBDay(day);
    client.setBMonth(month);
    client.setBYear(year);
    displayAll();
}

void MainWindow::blockUnblockClient() {
    int id = inputIdField->text().toInt();
    bool blocked = db.getClient(id).getBlocked();
    if (blocked)
        db.unblockClient(id);
    else
        db.blockClient(id);
    std::cout << db.getClient(id).getBlocked();
    displayAll();
}

void MainWindow::loadFile() {
    QString path = QFileDialog::getOpenFileName(this, "Open Text File", "", "Text files(*.txt);;All files (*.*)");
    if(!path.isEmpty()) {
        QFile myFile(path);
        if (myFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
            db.flush();
            QTextStream in(&myFile);
            while (!in.atEnd())
            {
                std::string line = in.readLine().toStdString();
                std::string delimiter = ",";
                size_t next = 0;
                next = line.find(delimiter);
                int id = stoi(line.substr(0, next));
                line.erase(0, next+1);
                next = line.find(delimiter);
                std::string name = line.substr(0, next);
                line.erase(0, next+1);
                next = line.find(delimiter);
                std::string sex = line.substr(0, next);
                line.erase(0, next+1);
                next = line.find(delimiter);
                int day = stoi(line.substr(0, next));
                line.erase(0, next+1);
                next = line.find(delimiter);
                int month = stoi(line.substr(0, next));
                line.erase(0, next+1);
                next = line.find(delimiter);
                int year = stoi(line.substr(0, next));
                line.erase(0, next+1);
                Client& client = db.addClient(name, sex=="M" ? Sex::MALE : Sex::FEMALE);
                client.setId(id);
                client.setBDay(day);
                client.setBMonth(month);
                client.setBYear(year);
                client.setBlocked(false);
            }
            myFile.close();
        }
    }
    displayAll();
}

void MainWindow::saveFile() {
    QString path = QFileDialog::getSaveFileName(this, "Save Text File", "", "Text files(*.txt);;All files (*.*)");
    if(!path.isEmpty()) {
       QFile myFile(path);
       if (myFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
            std::string text;
            for (int i = 0; i < db.size(); i++) {
                Client& client = db.getClient(i);
                if (!client.getBlocked()) {
                    text.append(std::to_string(client.getId())).append(",");
                    text.append(client.getName()).append(",");
                    text.append(client.getSex() == Sex::MALE ? "M" : "F").append(",");
                    text.append(std::to_string(client.getBDay())).append(",");
                    text.append(std::to_string(client.getBMonth())).append(",");
                    text.append(std::to_string(client.getBYear())).append("\n");
                }
            }
            text.erase(text.size()-1);
            myFile.write(text.c_str());
            myFile.close();
        }
    }
}

MainWindow::~MainWindow()
{
}
