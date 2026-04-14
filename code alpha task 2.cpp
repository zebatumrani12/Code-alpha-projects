#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Simple hash function (for learning purpose)
string hashPassword(string password) {
    int hash = 0;
    for (char c : password) {
        hash = hash * 31 + c;
    }
    return to_string(hash);
}

// Check if username already exists
bool userExists(string username) {
    ifstream file("users.txt");
    string u, p;

    while (file >> u >> p) {
        if (u == username) {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

// Registration Function
void registerUser() {
    string username, password;

    cout << "\n--- Registration ---\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (username.length() < 3 || password.length() < 4) {
        cout << "? Username or password too short!\n";
        return;
    }

    if (userExists(username)) {
        cout << "? Username already exists!\n";
        return;
    }

    ofstream file("users.txt", ios::app);
    file << username << " " << hashPassword(password) << endl;
    file.close();

    cout << "? Registration successful!\n";
}

// Login Function
void loginUser() {
    string username, password;

    cout << "\n--- Login ---\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");
    string u, p;
    string hashedPassword = hashPassword(password);

    while (file >> u >> p) {
        if (u == username && p == hashedPassword) {
            cout << "? Login successful! Welcome " << username << endl;
            file.close();
            return;
        }
    }

    file.close();
    cout << "? Invalid username or password!\n";
}

// Main Menu
int main() {
    int choice;

    do {
        cout << "\n===== LOGIN SYSTEM =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 3);

    return 0;
}

