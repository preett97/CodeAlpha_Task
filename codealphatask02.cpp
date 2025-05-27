#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void registerUser() {
    string username, password;
    cout << "\n=== User Registration ===\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;
    file.close();

    cout << "Registration successful! User saved.\n";
}

void loginUser() {
    string username, password, fileUser, filePass;
    bool found = false;

    cout << "\n=== User Login ===\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");
    while (file >> fileUser >> filePass) {
        if (fileUser == username && filePass == password) {
            found = true;
            break;
    }
    }
    file.close();

    if (found)
        cout << "Login successful! Welcome, " << username << "!\n";
    else
        cout << "Login failed. Invalid username or password.\n";
}

int main() {
    int choice;
    do {
        cout << "\n=== Login & Registration System ===\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
            registerUser();
        else if (choice == 2)
           loginUser();
        else if (choice == 3)
        cout << "Exiting... Goodbye!\n";
        else
        cout << "Invalid choice. Try again.\n";

    } while (choice != 3);

    return 0;
}

