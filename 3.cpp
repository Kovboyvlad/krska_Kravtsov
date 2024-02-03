#include <iostream>
#include <ctime>
void pokaz(int** mas, int strok, int stolb) {
    for (int i = 0; i < strok; i++) {
        for (int j = 0; j < stolb; j++) {
            std::cout << mas[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void zapolnenie(int** mas, int strok, int stolb) {
    for (int i = 0; i < strok; i++) {
        for (int j = 0; j < stolb; j++) {
            mas[i][j] = rand() % 70 + 1;
        }
    }
}

int SummaDiagonali(int** mas, int strok, int stolb) {
    int sum = 0;
    for (int i = 0; i < strok; i++) {
        sum += mas[i][stolb - i - 1];
    }
    return sum;
}


int main() {
    srand(time(0));
    int n;
    std::cout << "VVedite razmer massiva n*n: n = ";
    std::cin >> n;
    int** mas = new int*[n];
    for (int i = 0; i < n; i++) {
        mas[i] = new int[n];
    }

    zapolnenie(mas, n, n);
    std::cout << "Matritsa: " << std::endl;
    pokaz(mas, n, n);
    std::cout << "Summa elementov: " << SummaDiagonali(mas, n, n) << std::endl;

    for (int i = 0; i < n; i++) {
        delete[] mas[i];
    }
    delete[] mas;

    return 0;
}

