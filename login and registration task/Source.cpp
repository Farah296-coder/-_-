#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void registeration() {
    string username, password;
    cout << "Enter a username: " << endl;
    cin >> username;

    ifstream infile("database2.txt");
    string storedUsername, storedPassword;
    while (infile >> storedUsername >> storedPassword) {
        if (storedUsername == username) {
            cout << "Username already exists. Please try another one.\n";
            return;
        }
    }
    infile.close();

    cout << "Enter a password: " << endl;
    cin >> password;

    ofstream outfile("database2.txt", ios::app);
    outfile << username << " " << password << endl;
    outfile.close();

    cout << "Registration successful!!" << endl;
}
void login() {
    string username, password;
    cout << "Enter a username: " << endl;
    cin >> username;
    cout << "Enter a password: " << endl;
    cin >> password;
    ifstream infile("database2.txt");
    string storedUsername, storedPassword;
    bool loginsuccess = false;
    while (infile >> storedUsername >> storedPassword) {

        if (storedUsername == username && storedPassword == password) {
            loginsuccess = true;
            break;
        }

    }
    infile.close();

    if (loginsuccess) {
        cout << "Login successful!!" << endl;
    }
    else {
        cout << "Login failed!! Incorrect username or password...." << endl;
    }



}






int main() {
    while (true) {
        int x;
        cout << "1)Register\n2)Login\n3)Exit\nChoose an option: ";
        cin >> x;

        switch (x) {
        case 1:
            registeration();
            break;
        case 2:
            login();
            break;
        case 3:
            return 0;
        default:
            cout << "Invalid option....Please try again\n";
        }


    }
}