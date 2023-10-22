#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QLineEdit>
#include <QTextEdit>
#include <QComboBox>

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void displayAll();
    void displayBoys();
    void displayGirls();
    void client();
    void setBirth();
    void addClient();
    void blockUnblockClient();
    void loadFile();
    void saveFile();
private:
    QLineEdit *inputIdField;
    QLineEdit *inputDayField;
    QLineEdit *inputMonthField;
    QLineEdit *inputYearField;
    QTextEdit *outputField;
    QLineEdit *inputName;
    QComboBox *inputSex;
};
#endif // MAINWINDOW_H
