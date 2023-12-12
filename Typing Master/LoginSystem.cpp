#include"AllHeaderFile.h"

vector<string> comma_seperate( string s, char delimiter)
{
    vector<string> tokens;
    stringstream ss(s);
    string token;
    while (getline(ss, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

bool UserExist( string username)
{
    ifstream file("users.txt");
    string line;
    while (getline(file, line))
    {
        vector<string> parts = comma_seperate(line, ',');
        if (parts[0] == username)
        {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

void signUp()
{
       system("cls");
        moveCursor(47,4);
    cout<<"  --------------------------\n";
    cout<<"\t\t\t\t\t\t |     TYPING TUTOR       |\n";
    cout<<"\t\t\t\t\t\t --------------------------\n\n\n";
    string username, password;
    moveCursor(40,10);
    cout << "Enter username: ";
    cin >> username;

    if (UserExist(username))
    {
        moveCursor(40,15);
        cout << "Username already exists. Please choose another username.\n";
      Sleep(700);
      signUp();
    }
    moveCursor(40,12);
    cout << "Enter password: ";
    cin >> password;

    ofstream file("users.txt", ios::app);
    file << username << "," << password << "\n";
    file.close();
    moveCursor(40,15);
    Sleep(800);
    cout << "Account created successfully!\n";

}

void login()
{
    system("cls");
     moveCursor(47,4);
    cout<<"  --------------------------\n";
    cout<<"\t\t\t\t\t\t |     TYPING TUTOR       |\n";
    cout<<"\t\t\t\t\t\t --------------------------\n\n\n";
    string username, password;
    moveCursor(40,10);
    cout << "Enter username: ";
    cin >> username;

    if (!UserExist(username))
    {
        moveCursor(40,14);
          cout << "No user found. Try again\n";
          Sleep(700);
        login();
    }
    moveCursor(40,12);
    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");
    string line;
    bool found = false;
    while (getline(file, line))
    {
        vector<string> parts = comma_seperate(line, ',');
        if (parts[0] == username && parts[1] == password)
        {
            found = true;
            break;
        }
    }
    file.close();
    moveCursor(40,15);
    Sleep(800);
    if (found)
    {
        cout << "Login successful!\n";
           Sleep(700);
    }
    else
    {
        cout << "Incorrect password. Try again\n";
           Sleep(700);
        login();
    }
}

void loginsystem()
{
    system("color FD");
    system("cls");
    moveCursor(47,4);
    cout<<"Software Project Lab 1\n";
    moveCursor(50,6);
    cout<<"TYPING MASTER";
    moveCursor(40,8);
    cout<<"An interactive typing tutor and typing game";
    moveCursor(50,12);
    cout<<"Welcome!";
     moveCursor(40,14);
     cout<<"Login with your account. If you don't have an account, Sign Up first!";

    moveCursor(48,17);
    cout << "Choose option:\n";
    moveCursor(48,19);
    cout << "1. Sign Up\n";
    moveCursor(48,21);
    cout << "2. Login\n";
    moveCursor(40,23);

    char ch=getche();

    if(ch=='1')
        signUp();
    else if(ch=='2')
        login();
    else
    {
        cout<<"Wrong Input. Try again";
        loginsystem();
    }
}


