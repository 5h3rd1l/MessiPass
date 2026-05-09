#include "MessiPass.h"
#include <iostream>
#include <fstream>
#include <conio.h> // for getch() and system("cls")
#include <iomanip> // for setw and left
using namespace std;

void PasswordManager::verify()
{
    asciiArt();
    string user, pass;
    cout << "Enter Username: ";
    cin >> user;
    cout << "Enter Password: ";
    cin >> pass;

    if (user == adminUser && pass == adminPass)
    {
        run();
    }
    else
    {
        cout << "Wrong username or password!\n";
        getch();
    }
}

void PasswordManager::asciiArt()
{
    cout << "  __  __           _   ___            \n";
    cout << " |  \\/  |___ _____(_) | _ \\__ _ ______\n";
    cout << " | |\\/| / -_|_-<_-< | |  _/ _` (_-<_-<\n";
    cout << " |_|  |_\\___/__/__/_| |_| \\__,_/__/__/\n";
    cout << "                (by f4n7um & 5h3rd1l)\n";
}

void PasswordManager::run()
{
    system("cls");
    asciiArt();
    int choice;
    cout << "1. Save New Password\n";
    cout << "2. View Saved Passwords\n";
    cout << "3. Check if Password is Secure\n";
    cout << "4. Show help page\n";

    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        savePassword();
        break;
    case 2:
        viewPasswords();
        break;
    case 3:
        checkPasswordStrength();
        break;
    case 4:
        HelpPage();
        break;
    default:
        cout << "Invalid choice!\n";
        getch();
        run();
    }
}

void PasswordManager::savePassword()
{
    system("cls");
    asciiArt();
    string website, username, password;
    cout << "Enter website: ";
    cin >> website;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    ofstream outFile(filename, ios::app);
    if (outFile.is_open())
    {
        outFile << encrypt(website) << " "
                << encrypt(username) << " "
                << encrypt(password) << endl;
        outFile.close();
        cout << "Password saved successfully!" << getch();
        run();
    }
    else
    {
        cout << "Failed to open file!\n";
    }
}

string PasswordManager::encrypt(const string &data)
{
    string encrypted = data;
    for (char &c : encrypted)
    {
        c += 5;
    }
    return encrypted;
}

void PasswordManager::viewPasswords()
{
    system("cls");
    asciiArt();
    string user, pass;
    cout << "Enter vault username: ";
    cin >> user;
    cout << "Enter vault password: ";
    cin >> pass;

    if (user == vaultUser && pass == vaultPass)
    {
        system("cls");
        asciiArt();
        ifstream inFile(filename);
        if (inFile.is_open())
        {
            string website, username, password;
            cout << left << setw(20) << "Website"
                 << setw(20) << "Username"
                 << setw(20) << "Password" << endl;

            while (inFile >> website >> username >> password)
            {
                cout << left << setw(20) << decrypt(website)
                     << setw(20) << decrypt(username)
                     << setw(20) << decrypt(password) << endl;
            }
            cout << "Press enter to go back" << getch();
            inFile.close();
        }
        else
        {
            cout << "No saved passwords found.\n";
        }
        getch();
        run();
    }
    else
    {
        cout << "Invalid admin credentials!\n";
        getch();
        run();
    }
}

string PasswordManager::decrypt(const string &data)
{
    string decrypted = data;
    for (char &c : decrypted)
    {
        c -= 5;
    }
    return decrypted;
}

void PasswordManager::checkPasswordStrength()
{
    system("cls");
    asciiArt();
    string password;
    cout << "Enter password to check: ";
    cin >> password;

    bool hasUpper = false, hasLower = false, hasSpecial = false;
    int length = password.length();

    for (char c : password)
    {
        if (isupper(c))
            hasUpper = true;
        if (islower(c))
            hasLower = true;
        if (ispunct(c))
            hasSpecial = true;
    }

    cout << "\nPassword Strength Check:\n";

    if (length >= 8)
        cout << "- Length is OK\n";
    else
        cout << "- Password should be at least 8 characters long\n";

    if (hasUpper)
        cout << "- Has uppercase letter\n";
    else
        cout << "- Add at least one uppercase letter\n";

    if (hasLower)
        cout << "- Has lowercase letter\n";
    else
        cout << "- Add at least one lowercase letter\n";

    if (hasSpecial)
        cout << "- Has special character\n";
    else
        cout << "- Add at least one special character (like @, #, !, etc.)\n";

    if (length >= 8 && hasUpper && hasLower && hasSpecial)
        cout << "\nYour password is strong.\n";
    else
        cout << "\nYour password is weak.\n";

    cout << "\nPress any key to return to main menu...";
    getch();
    run();
}

void PasswordManager::HelpPage()
{
    system("cls");
    asciiArt();
    cout << "-----------------------------------------------------------------------------\n";
    cout << "        Developed by Fatima Razzaq (241563) and Rubas Ali (241503)\n\n";
    cout << "- This is our end-semester OOP project - a Secure Password Vault that safely\n";
    cout << "  stores your passwords in an encrypted format inside a local text file.\n\n";

    cout << "- To save a new password or access your stored passwords, please enter your\n";
    cout << "  admin credentials.\n";
    cout << "- Once logged in, you can Save New Passwords or View your Saved Passwords or Check your Password Strength\n\n";
    cout << "-----------------------------------------------------------------------------\n";
    cout << "Press enter to go back\n"
         << getch();
    run();
}
