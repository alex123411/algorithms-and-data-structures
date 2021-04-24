#pragma once


#include <vector>
#include <string>

using namespace std;
using std::vector;

struct Date
{
    int day = 0;
    string month;
    int year;
};

struct Booking
{
    string mainGuestName;
    int numberOfGuests;
    string roomType;
    Date dateOfArrival;
};

struct MainField
{
    int bookingCode = -1;
    Booking booking;
    bool deleted = false;
};

struct AdditionalField
{
    Date dateOfArrival;
    vector<string> ListOfGuests;
    bool deleted = false;

    bool isEqual(Date date)
    {
        if (date.day == dateOfArrival.day &&
            date.month == dateOfArrival.month &&
            date.year == dateOfArrival.year)
            return true;
        
        return false;
    }
};

class MainHashTable
{
    MainField* table;
    int size;
    int loadness = 0;

 public:
    MainHashTable(): size(7) {table = new MainField[size];}
    ~MainHashTable();

    void insertEntry(int key, Booking value);
    bool removeEntry(int key);
    Booking* findEntry(int key);
    void rehashing();
    int getHash(int key);
    void print();
    //int keyHashCode(int key);
};

class AdditionalHashTable
{
    AdditionalField* table;
    int size;
    int loadness = 0;

 public:
    AdditionalHashTable(): size(7) {table = new AdditionalField[size];}
    ~AdditionalHashTable();

    void insertEntry(Date date, string guestName);
    bool removeEntry(Date date, string name);
    vector<string> findEntry(Date date);
    void rehashing();
    int getHash(int hashCode);
    vector<string> allArrivalsAtThisDay(Date date);
};

int hashDate(Date date);
int hashMonth(string month);
bool prime(int number);
