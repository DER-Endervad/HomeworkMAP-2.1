#include <iostream>
#include <thread>
#include <Windows.h>

void clients(int& counter);
void operationists(int& counter);

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int counter = 0;
    std::thread t1(clients, std::ref(counter));
    std::thread t2(operationists, std::ref(counter));
    t1.join(); t2.join();
}

void clients(int& counter) {
    while(counter < 10) {
        Sleep(1000);
        counter++;
        std::cout << "Пришел клиент. Всего клиентов в очереди: " << counter << std::endl;
    }
    std::cout << "Очередь переполнена. Больше клиентов не принимаем." << std::endl;
}

void operationists(int& counter) {
    Sleep(2000);
    while (counter > 0) {
        Sleep(2000);
        counter--;
        std::cout << "Операция с клиентом завершено. Клиентов в очереди осталось: " << counter << std::endl;
    }
    std::cout << "Все операции с клиентами завершены. Рабочий день подошел к концу." << std::endl;
}
