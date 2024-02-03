#include <iostream>
#include <string>

struct Account {
    std::string username;
    std::string password;
};

Account accounts[10]; 
int kolvoAkkov = 0;    

void addAkkov() {
    std::cout << "Vvedite imya: ";
    std::cin >> accounts[kolvoAkkov].username;
    std::cout << "Vvedite password: ";
    std::cin >> accounts[kolvoAkkov].password;
    kolvoAkkov++;
    std::cout << "Gotovo, accout dobavlen" << std::endl;
}

void updateAkkov() {
    std::string username;
    std::cout << "Enter username to update: ";
    std::cin >> username;
    for (int i = 0; i < kolvoAkkov; i++) {
        if (accounts[i].username == username) {
            std::cout << "Enter new username: ";
            std::cin >> accounts[i].username;
            std::cout << "Enter new password: ";
            std::cin >> accounts[i].password;
            std::cout << "Account updated successfully." << std::endl;
            return;
        }
    }
    std::cout << "Account not found." << std::endl;
}
void deleteAkkov() {
    std::string username;
    std::cout << "Enter username to delete: ";
    std::cin >> username;
    for (int i = 0; i < kolvoAkkov; i++) {
        if (accounts[i].username == username) {
            for (int j = i; j < kolvoAkkov - 1; j++) {
                accounts[j] = accounts[j + 1];
            }
            kolvoAkkov--;
            std::cout << "Account deleted! " << std::endl;
            return;
        }
    }
    std::cout << "Account ne nayden" << std::endl;
}



void pokazAkkov() {
    for (int i = 0; i < kolvoAkkov; i++) {
        std::cout << "Username: " << accounts[i].username << ", Password: " << accounts[i].password << std::endl;
    }
}

int main() {
    void (*funcptr[])(void) = { addAkkov, deleteAkkov, updateAkkov, pokazAkkov };

    while (1) {
        std::cout << "1) Add account" << std::endl;
        std::cout << "2) Delete account" << std::endl;
        std::cout << "3) Update account" << std::endl;
        std::cout << "4) Print all accounts" << std::endl;
        std::cout << "5) Exit :(" << std::endl;

        int vibor;

        std::cin >> vibor;
        if (vibor == 5) exit();
        if (vibor < 1 || vibor > 4) {
            std::cout << "Vy vveli nepravilnoe znachenie!" << std::endl;
            continue;
        }
        (*funcptr[vibor - 1])();
    }

    return 0;
}