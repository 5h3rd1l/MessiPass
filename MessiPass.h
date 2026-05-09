#ifndef MESSIPASS_H
#define MESSIPASS_H
#include <string>
using namespace std;

class PasswordManager
{
private:
    const string filename = "D:\\Projects\\Sem 2\\OOP\\passwords.txt";
    const string vaultUser = "vault123";
    const string vaultPass = "vault123";
    const string adminUser = "admin";
    const string adminPass = "admin";

    string encrypt(const string &data);
    string decrypt(const string &data);

public:
    void savePassword();
    void viewPasswords();
    void checkPasswordStrength();
    void run();
    void HelpPage();
    void asciiArt();
    void verify();
};

#endif
