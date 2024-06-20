//Movie Ticket Booking System
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const int NUM_ROWS = 5;
const int NUM_COLS = 10;

// Function to display the seating arrangement
void displaySeatingArrangement(const vector<vector<char>>& seats) {
    cout << "  ";
    for (int j = 0; j < NUM_COLS; ++j) {
        cout << setw(2) << j + 1 << " ";
    }
    cout << endl;

    for (int i = 0; i < NUM_ROWS; ++i) {
        cout << static_cast<char>('A' + i) << " ";
        for (int j = 0; j < NUM_COLS; ++j) {
            cout << seats[i][j] << "  ";
        }
        cout << endl;
    }
}

// Function to book seats
double bookSeats(vector<vector<char>>& seats) {
    int row, col;
    double totalCost = 0;

    while (true) {
        cout << "Enter row and column number (e.g., A 1) to book a seat (or '0 0' to finish booking): ";
        char rowChar;
        cin >> rowChar;
        if (rowChar == '0') break;

        cin >> col;
        row = rowChar - 'A';
        col--;

        if (row < 0 || row >= NUM_ROWS || col < 0 || col >= NUM_COLS) {
            cout << "Invalid seat selection. Please try again." << endl;
            continue;
        }

        if (seats[row][col] == 'X') {
            cout << "Seat already booked. Please select another seat." << endl;
            continue;
        }

        seats[row][col] = 'X';
        totalCost += 10.0; // Assuming each ticket costs $10
    }

    return totalCost;
}

int main() {
    vector<vector<char>> seats(NUM_ROWS, vector<char>(NUM_COLS, '-'));

    cout << "Welcome to the Movie Ticket Booking System!" << endl;

    char choice;
    do {
        cout << "\nMenu:\n"
             << "1. View Seating Arrangement\n"
             << "2. Book Seats\n"
             << "3. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                cout << "\nSeating Arrangement:\n";
                displaySeatingArrangement(seats);
                break;
            case '2':
                cout << "\nBooking Seats:\n";
                double totalCost = bookSeats(seats);
                cout << "Total Cost: $" << totalCost << endl;
                break;
            case '3':
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != '3');

    return 0;
}
