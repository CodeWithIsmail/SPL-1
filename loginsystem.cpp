#include<bits/stdc++.h>

using namespace std;

vector<string> comma_seperate( string s, char delimiter) {
    vector<string> tokens;
    stringstream ss(s);
    string token;
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

bool UserExist( string username) {
    ifstream file("users.txt");
    string line;
    while (getline(file, line)) {
        vector<string> parts = comma_seperate(line, ',');
        if (parts[0] == username) {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

void signUp() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;

    if (UserExist(username)) {
        cout << "Username already exists. Please choose another username.\n";
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    ofstream file("users.txt", ios::app);
    file << username << "," << password << "\n";
    file.close();

    cout << "Account created successfully!\n";
}

void login() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;

    if (!UserExist(username)) {
        cout << "Username doesn't exist.\n";
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");
    string line;
    bool found = false;
    while (getline(file, line)) {
        vector<string> parts = comma_seperate(line, ',');
        if (parts[0] == username && parts[1] == password) {
            found = true;
            break;
        }
    }
    file.close();

    if (found) {
        cout << "Login successful!\n";
    } else {
        cout << "Incorrect password.\n";
    }
}

int main() {
    int choice;
    do {
        cout << "Choose an option:\n";
        cout << "1. Sign Up\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                signUp();
                break;
            case 2:
                login();
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please enter again.\n";
        }
    } while (choice != 3);

    return 0;
}
