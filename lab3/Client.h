#include <iostream>


enum class Sex { MALE, FEMALE };


class Client {
public:
    Client();
    Client(std::string name, Sex sex);

    void addHabit(std::string habit);

    int getAge();

    void display();
    // Accessors and setters
    void setId(int in);

    int getId();

    std::string getName();

    void setName(std::string in);

    Sex getSex();

    void setSex(Sex in);

    int getBDay();

    void setBDay(int in);

    int getBMonth();

    void setBMonth(int in);

    int getBYear();

    void setBYear(int in);

    int getHeight();

    void setHeight(int in);

    int getWeight();

    void setWeight(int in);

    int getChildrenAmount();

    void setChildrenAmount(int in);

    std::string getStatus();

    void setStatus(std::string in);

    std::string getHabits();

    void setHabits(std::string in);

    std::string getHobbies();

    void setHobbies(std::string in);

    std::string getDescription();

    void setDescription(std::string in);

    int getZodiacId();

    void setZodiacId(int in);

    int getRelationshipId();

    void setRelationshipId(int in);

    int getNationalityId();

    void setNationalityId(int in);

    std::string getAddress();

    void setAddress(std::string in);

    std::string getPhone();

    void setPhone(std::string in);

    int getPassport();

    void setPassport(int in);

    std::string getPartnerInfo();

    void setPartnerInfo(std::string in);

    void setBlocked(bool in);

    bool getBlocked();

    std::string toString();
private:
    int id{};
    std::string name;
    Sex sex{};
    int b_day{};
    int b_month{};
    int b_year{};
    int height{};
    int weight{};
    int children_amount{};
    std::string status;
    std::string habits;
    std::string hobbies;
    std::string description;
    int zodiac_id{};
    int relationship_id{};
    int nationality_id{};
    std::string address;
    std::string phone;
    int passport{};
    std::string partner_info;
    bool blocked;
};
