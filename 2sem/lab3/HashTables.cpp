#include "HashTables.h"
#include <iostream>
MainHashTable::~MainHashTable()
{
    delete [] table;
}



void MainHashTable::insertEntry(int key, Booking value)
{
    if (float(loadness)/size >= 0.49)
        this->rehashing();
    int hash = getHash(key);
    int i = 0;
    while (table[hash].bookingCode != -1)
    {
        hash = getHash(key + i*i); i++;
    }
    table[hash].bookingCode = key;
    table[hash].booking = value;
    table[hash].deleted = false;
    loadness++;
}

bool MainHashTable::removeEntry(int key)
{
    int hash = getHash(key);
    for (int i = 0; ;i++)
    {
        if (table[hash].bookingCode == key)
        {
            table[hash].bookingCode = -1;
            table[hash].deleted = true;
            loadness--;
            return true;
        }
        else if (table[hash].bookingCode == -1 && table[hash].deleted == false)
            return false;
        
        hash = getHash(key + i*i);
    }
}

Booking* MainHashTable::findEntry(int key)
{
    int hash = getHash(key);
    for (int i = 0; ;i++)
    {
        if (table[hash].bookingCode == key)
        {
            return &table[hash].booking;
        }
        else if (table[hash].bookingCode == -1 && table[hash].deleted == false)
            return nullptr;
        
        hash = getHash(key + i*i);
    }
}

void MainHashTable::rehashing()
{
    MainField cont[loadness];
    for (int i = 0, j = 0; i < size; i++)
    {
        if (table[i].bookingCode != -1)
        {
            cont[j] = table[i];
            j++;
        }
    }

    size++;
    while(!prime(size))
        size++;

    delete [] table;
    table = new MainField[size];

    int l = loadness; this->loadness = 0;
    for (int i = 0; i < l; i++)
    {
        this->insertEntry(cont[i].bookingCode, cont[i].booking);
    }
}

int MainHashTable::getHash(int key)
{
    
    return key % size;
}

void MainHashTable::print()
{
    for (int i = 0; i < size; i++)
    {
        if (table[i].bookingCode != -1)
        {
            cout << i << " "
                      << table[i].bookingCode << " | "
                      << table[i].booking.mainGuestName + " | "
                      << table[i].booking.numberOfGuests << " | "
                      << table[i].booking.roomType + " | "
                      << table[i].booking.dateOfArrival.day << " | "
                      << table[i].booking.dateOfArrival.month + " | "
                      << table[i].booking.dateOfArrival.year << endl;
        }
        else
            cout << i << endl;
    }
}

AdditionalHashTable::~AdditionalHashTable()
{
    delete [] table;
}

void AdditionalHashTable::insertEntry(Date date, string guestName)
{
    if (float(loadness)/size >= 0.49)
        this->rehashing();
    int hash = getHash(hashDate(date));
    int i = 0;
    while (table[hash].dateOfArrival.day != 0 && !table[hash].isEqual(date))
    {
        hash = getHash(hashDate(date) + i*i); i++;
    }
    if (!table[hash].isEqual(date))
        loadness++;

    table[hash].dateOfArrival = date;
    table[hash].ListOfGuests.push_back(guestName);
    table[hash].deleted = false;
}

bool AdditionalHashTable::removeEntry(Date date, string name)
{
    int hash = getHash(hashDate(date));
    for (int i = 0; ;i++)
    {
        if (table[hash].isEqual(date))
        {
            if (table[hash].ListOfGuests.size() == 1)
            {
                table[hash].dateOfArrival.day = 0;
                table[hash].deleted = true;
                loadness--;
            }
            auto it = table[hash].ListOfGuests.begin();
            while (*it != name)
            {
                if (it == table[hash].ListOfGuests.end()) return false;
                it++;
            }
            table[hash].ListOfGuests.erase(it);
            return true;
        }
        else if (table[hash].dateOfArrival.day == 0 && table[hash].deleted == false)
            return false;
        
        hash = getHash(hashDate(date) + i*i);
    }
}

vector<string> AdditionalHashTable::findEntry(Date date)
{
    int hash = getHash(hashDate(date));
    for (int i = 0; i < size ;i++)
    {
        if (table[hash].isEqual(date))
        {
            return table[hash].ListOfGuests;
        }
        
        hash = getHash(hashDate(date) + i*i);
    }
}

void AdditionalHashTable::rehashing()
{
    AdditionalField cont[loadness];
    for (int i = 0, j = 0; i < size; i++)
    {
        if (table[i].dateOfArrival.day != 0)
        {
            cont[j] = table[i];
            j++;
        }
    }

    size++;
    while(!prime(size))
        size++;

    delete [] table;
    table = new AdditionalField[size];

    int l = loadness; this->loadness = 0;
    for (int i = 0; i < l; i++)
    {
        for (string & name : cont[i].ListOfGuests)
            this->insertEntry(cont[i].dateOfArrival, name);
    }
}



int AdditionalHashTable::getHash(int hashcode)
{
    return hashcode % size;
}

vector<string> AdditionalHashTable::allArrivalsAtThisDay(Date date)
{
    return findEntry(date);
}


int hashMonth(string month)
{
    string months[12] = {"january", "february", "march","april",
                         "may", "june", "july", "august",
                         "september", "october", "november", "december"};
    for (int i = 0; i < 12; i++)
    {
        if (month == months[i]) return i+1;
    }
    //std::cout << "Wrong month!\n";
    return 0;
}

int hashDate(Date date)
{
    return date.year + hashMonth(date.month)*10000 + date.day*1000000;
}

bool prime(int number)
{
    if (number % 2 == 0)
        return false;
    int i;
    for (i = 3; number >= i*i && number % i; i += 2);
    return i*i > number;
}
