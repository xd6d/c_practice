#include "Client.h"

using namespace std;

Client::Client() {}

Client::Client(string name, Sex sex) : name(name), sex(sex) {}

void Client::addHabit(string habit) {
    habits += "\n" + habit;
}

int Client::getAge() {
    time_t t = time(0);
    tm *now = localtime(&t);
    int age = now->tm_year + 1900 - b_year;
    int delta = 0;
    if (now->tm_mon + 1 < b_month)
        delta = -1;
    if (now->tm_mon == b_month && now->tm_mday < b_day)
        delta = -1;
    return age + delta;
}

void Client::display() {
    cout << "Client: " << getName() << " with id " << getId() << endl;
    cout << "Sex: " << (getSex() == Sex::MALE ? "Male" : "Female") << endl;
    cout << endl;
}

void Client::setId(int in) {
    id = in;
}

int Client::getId() {
    return id;
}

string Client::getName() {
    return name;
}

void Client::setName(string in) {
    name = in;
}

Sex Client::getSex() {
    return sex;
}

void Client::setSex(Sex in) {
    sex = in;
}

int Client::getBDay() {
    return b_day;
}

void Client::setBDay(int in) {
    b_day = in;
}

int Client::getBMonth() {
    return b_month;
}

void Client::setBMonth(int in) {
    b_month = in;
}

int Client::getBYear() {
    return b_year;
}

void Client::setBYear(int in) {
    b_year = in;
}

int Client::getHeight() {
    return height;
}

void Client::setHeight(int in) {
    height = in;
}

int Client::getWeight() {
    return weight;
}

void Client::setWeight(int in) {
    weight = in;
}

int Client::getChildrenAmount() {
    return children_amount;
}

void Client::setChildrenAmount(int in) {
    children_amount = in;
}

string Client::getStatus() {
    return status;
}

void Client::setStatus(string in) {
    status = in;
}

string Client::getHabits() {
    return habits;
}

void Client::setHabits(string in) {
    habits = in;
}

string Client::getHobbies() {
    return hobbies;
}

void Client::setHobbies(string in) {
    hobbies = in;
}

string Client::getDescription() {
    return description;
}

void Client::setDescription(string in) {
    description = in;
}

int Client::getZodiacId() {
    return zodiac_id;
}

void Client::setZodiacId(int in) {
    zodiac_id = in;
}

int Client::getRelationshipId() {
    return relationship_id;
}

void Client::setRelationshipId(int in) {
    relationship_id = in;
}

int Client::getNationalityId() {
    return nationality_id;
}

void Client::setNationalityId(int in) {
    nationality_id = in;
}

string Client::getAddress() {
    return address;
}

void Client::setAddress(string in) {
    address = in;
}

string Client::getPhone() {
    return phone;
}

void Client::setPhone(string in) {
    phone = in;
}

int Client::getPassport() {
    return passport;
}

void Client::setPassport(int in) {
    passport = in;
}

string Client::getPartnerInfo() {
    return partner_info;
}

void Client::setPartnerInfo(string in) {
    partner_info = in;
}

void Client::setBlocked(bool in) {
    blocked = in;
}

bool Client::getBlocked() {
    return blocked;
}

std::string Client::toString() {
    std::string str;
    str.append("Client: ").append(getName()).append(" with id ").append(to_string(getId())).append("\n")
    .append("Sex: ").append(getSex() == Sex::MALE ? "Male" : "Female").append("\n").append("\n");
    return str;
}