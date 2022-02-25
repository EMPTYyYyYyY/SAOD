#include <chrono>
#include <iostream>
#include <ctime>
#include <iomanip>

void insertionSort(int*, int); // прототип функции сортировки вставками

using namespace std;
int main(int argc, char* argv[])
{
    srand(time(NULL));
    cout << "Enter size mass: ";
    int A; // длинна массива
    cin >> A;
    
    int* sorted_array = new int[A]; // одномерный динамический массив
    for (int counter = 0; counter < A; counter++)
    {
        sorted_array[counter] = rand() % 100; // заполняем массив случайными числами // вывод массива на экран
    }
    cout << " " << endl;
    auto start_time = std::chrono::steady_clock::now();
    insertionSort(sorted_array, A); // вызов функции сортировки вставками
    auto end_time = std::chrono::steady_clock::now();
    for (int counter = 0; counter < A; counter++)
    {
        cout << setw(2) << sorted_array[counter] << "  "; // печать отсортированного массива
    }
    cout << " " << endl;
    auto elapsed_ns = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    std::cout << elapsed_ns.count() << " milliseconds" << endl;
    system("pause");
    return 0;
}

void insertionSort(int* arrayPtr, int length) // сортировка вставками
{
    int temp, // временная переменная для хранения значения элемента сортируемого массива
        item; // индекс предыдущего элемента
    for (int counter = 1; counter < length; counter++)
    {
        temp = arrayPtr[counter]; // инициализируем временную переменную текущим значением элемента массива
        item = counter - 1; // запоминаем индекс предыдущего элемента массива
        while (item >= 0 && arrayPtr[item] > temp) // пока индекс не равен 0 и предыдущий элемент массива больше текущего
        {
            arrayPtr[item + 1] = arrayPtr[item]; // перестановка элементов массива
            arrayPtr[item] = temp;
            item--;
        }
    }
}