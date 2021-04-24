#include "HashTables.h"
using namespace std;
#include <iostream>

int example()
{
    int max = 10000;
    MainHashTable extable;
    Booking newbooking;

    newbooking.mainGuestName = "Albert Einstein";
    newbooking.numberOfGuests = 3;
    newbooking.roomType = "Luxury";
    newbooking.dateOfArrival.day = 7;
    newbooking.dateOfArrival.month = "april";
    newbooking.dateOfArrival.year = 2002;
    extable.insertEntry(max+=3,newbooking);
    //new
    newbooking.mainGuestName = "Van Gog";
    newbooking.numberOfGuests = 2;
    newbooking.roomType = "Economy";
    newbooking.dateOfArrival.day = 3;
    newbooking.dateOfArrival.month = "may";
    newbooking.dateOfArrival.year = 2002;
    extable.insertEntry(max+=3,newbooking);
    //new
    newbooking.mainGuestName = "Leonardo da Vinci";
    newbooking.numberOfGuests = 1;
    newbooking.roomType = "Luxury";
    newbooking.dateOfArrival.day = 21;
    newbooking.dateOfArrival.month = "march";
    newbooking.dateOfArrival.year = 2002;
    extable.insertEntry(max+=3,newbooking);
    //new
    newbooking.mainGuestName = "Mikilandgelo";
    newbooking.numberOfGuests = 2;
    newbooking.roomType = "Normal";
    newbooking.dateOfArrival.day = 11;
    newbooking.dateOfArrival.month = "october";
    newbooking.dateOfArrival.year = 2002;
    extable.insertEntry(max+=3,newbooking);
    cout << "\n\n---------------------------------------------\n";
    extable.print();
    cout << "---------------------------------------------\n\n";
}

int main()
{
    int max = 10000;
    bool Quit = false;
    char choice;
    MainHashTable BookingTable;
    AdditionalHashTable DateTable;
    while (1)
    {
        cout << "1)Add to table\n"
             << "2)Remove from table\n"
             << "3)Get all guests in date\n"
             << "4)Get customer`s booking by code\n"
             << "5)Show table\n"
             << "6)exit\n"
             << "7)Example\n";
        cin >> choice;
        if (choice == '1')
        {
            char input[255];
            Booking newBooking;
            cout << "\n\n---------------------------------------------\n";
            cout << "Enter information:\n"
                 << "Main guest name:\t";
            if (cin.peek() == '\n') cin.get();
            cin.getline(input, 255); newBooking.mainGuestName = input;
            cout << "Number of guests:\t";
            cin >> newBooking.numberOfGuests;
            cin.get();
            cout << "Room type:\t";
            cin.getline(input, 255); newBooking.roomType = input;
            cout << "Year:\t"; 
            cin >> newBooking.dateOfArrival.year;
            cin.get();
            cout << "Month(word):\t";
            cin.getline(input, 255); newBooking.dateOfArrival.month = input;
            cout << "Day:\t"; 
            cin >> newBooking.dateOfArrival.day;
            cin.get();
            BookingTable.insertEntry(max+=3, newBooking);
            DateTable.insertEntry(newBooking.dateOfArrival, newBooking.mainGuestName);
            cout << "Code of booking: " << max << endl;
            cout << "---------------------------------------------\n\n";
        }
        
        else if (choice == '2')
        {
            cout << "\n\n---------------------------------------------\n"
                 << "Enter booking code: ";
            int code;
            cin >> code;
            cin.get();
            auto res = BookingTable.findEntry(code);
            if (res != nullptr)
                DateTable.removeEntry(res->dateOfArrival, res->mainGuestName);
            if (BookingTable.removeEntry(code))
            {
                cout << "Booking has been removed\n";
            }
            else
            {
                cout << "This code doesn`t exist\n";
            }
            cout << "---------------------------------------------\n\n";
        }
        else if (choice == '3')
        {
            Date date; char input[255];
            cout << "\n\n---------------------------------------------\n";
            cout << "Enter date:\n";
            if (cin.peek() == '\n') cin.get();
            cout << "Year:\t"; 
            cin >> date.year;
            cin.get();
            cout << "Month (word):\t";
            cin.getline(input, 255); date.month = input;
            cout << "Day:\t"; 
            cin >> date.day;
            cin.get();
            auto list = DateTable.allArrivalsAtThisDay(date);
            for (string & name : list)
            {
                cout << "Name:" << name + " " << endl;
            }
            cout << "\n---------------------------------------------\n\n";
        }
        else if (choice == '4')
        {
            int code;
            cout << "\n\n---------------------------------------------\n";
            cout << "Enter code:\t";
            cin >> code;
            Booking* booking = BookingTable.findEntry(code);
            if (booking != nullptr)
            {
                cout << booking->mainGuestName + "\t"
                    << booking->numberOfGuests << "\t"
                    << booking->roomType + "\t"
                    << booking->dateOfArrival.day << "."
                    << booking->dateOfArrival.month + "."
                    << booking->dateOfArrival.year;
            }
            else
            {
                cout << "This code doesn`t exist\n";
            }
            cout << "\n---------------------------------------------\n\n";
        }
        else if (choice == '5')
        {
            cout << "\n\n---------------------------------------------\n";
            BookingTable.print();
            cout << "---------------------------------------------\n\n";
        }
        else if (choice == '6')
        {
            exit(1);
        }else if (choice == '7')
        {
            Booking newbooking;
            newbooking.mainGuestName = "Albert Einstein";
    newbooking.numberOfGuests = 3;
    newbooking.roomType = "Luxury";
    newbooking.dateOfArrival.day = 7;
    newbooking.dateOfArrival.month = "april";
    newbooking.dateOfArrival.year = 2002;
    BookingTable.insertEntry(max+=3,newbooking);
    DateTable.insertEntry(newbooking.dateOfArrival, newbooking.mainGuestName);
    //new
    newbooking.mainGuestName = "Van Gog";
    newbooking.numberOfGuests = 2;
    newbooking.roomType = "Economy";
    newbooking.dateOfArrival.day = 3;
    newbooking.dateOfArrival.month = "may";
    newbooking.dateOfArrival.year = 2002;
    BookingTable.insertEntry(max+=3,newbooking);
    DateTable.insertEntry(newbooking.dateOfArrival, newbooking.mainGuestName);
    //new
    newbooking.mainGuestName = "Leonardo da Vinci";
    newbooking.numberOfGuests = 1;
    newbooking.roomType = "Luxury";
    newbooking.dateOfArrival.day = 21;
    newbooking.dateOfArrival.month = "march";
    newbooking.dateOfArrival.year = 2002;
    BookingTable.insertEntry(max+=3,newbooking);
    DateTable.insertEntry(newbooking.dateOfArrival, newbooking.mainGuestName);
    //new
    newbooking.mainGuestName = "Mikilandgelo";
    newbooking.numberOfGuests = 2;
    newbooking.roomType = "Normal";
    newbooking.dateOfArrival.day = 11;
    newbooking.dateOfArrival.month = "october";
    newbooking.dateOfArrival.year = 2002;
    BookingTable.insertEntry(max+=3,newbooking);
    DateTable.insertEntry(newbooking.dateOfArrival, newbooking.mainGuestName);
        }
    }
    
}