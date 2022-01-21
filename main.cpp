#include <iostream>
#include <random>
#include <fstream>
#include <time.h>
#include <cstring>

//Программа создает таблицу которую можно использовать как генератор паролей, секретом является путь(фигура, линии, слово), символы лежащие на этом пути и будут паролем.

int main(){
    unsigned int m = 50; //стандартный размер таблицы

    char* seed = new char[30]; // код генерации

    time_t now = time(0); //реальное время
    char* dt = ctime(&now);

    char name[30] = {"table"};  //имя выходного файла

    std::cout << "seed: ";
    std::cin.getline(seed, 30, '\n');
    std::cout << std::endl;

    //переобразование строки в число
    int temp = 0 ;
    for(int i = 0; i < strlen(seed); i++){
        temp += (int)seed[i];
    }

    srand(temp);

    std::cout << "size: ";
    std::cin >> m;
    std:: cout << std::endl;

    const unsigned int n = m;

    //создание массива таблицы
    char** mass = new char* [n];
    std::ofstream fout;
    for (int i = 0; i < n; i++)
        mass[i] = new char[n];

    //заполнение таблицы символами
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n  ; j++){
            mass[i][j] = 33 +  rand() % (126 - 33 + 1);
           //std::cout << rand() % 126  << " ";  
        }
        //std::cout << std::endl;
    }

    std::cout << "Name File: ";
    std::cin >> name;
    std::cout << std::endl;
    std::cout << "OK " << std::endl;
    fout.open(name);

    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < n; j++){
           //std::cout << mass[i][j] << " ";
            fout << mass[i][j] << " ";
        }
        //std::cout << std::endl;
        fout << std::endl;
    }
    fout << std::endl;
    fout << "Seed: " << seed << "   Time: " << dt <<std::endl;


    fout.close();

    for(int i = 0; i < n - 1; i++)
        delete [] mass[i];


    return 0;
}
