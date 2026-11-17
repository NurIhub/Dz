
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

void createArray(int*& ptr, int size)
{
    ptr = new int[size];
}

void fillArray(int* ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        ptr[i] = std::rand() % 100;
    }
}

void printArray(int* ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << ptr[i] << " ";
    }
    std::cout << std::endl;
}

void deleteArray(int*& ptr)
{
    delete[] ptr;
    ptr = nullptr;
}

void addElement(int*& ptr, int& size, int element)
{
    int* newPtr = new int[size + 1];

    for (int i = 0; i < size; i++)
    {
        newPtr[i] = ptr[i];
    }

    newPtr[size] = element;

    delete[] ptr;

    ptr = newPtr;
    size++;
}

void insertElement(int*& ptr, int& size, int index, int element)
{
    if (index < 0 || index > size)
    {
        std::wcout << L"Неверный индекс!" << std::endl;
        return;
    }

    int* newPtr = new int[size + 1];

    for (int i = 0; i < index; i++)
    {
        newPtr[i] = ptr[i];
    }

    newPtr[index] = element;

    for (int i = index; i < size; i++)
    {
        newPtr[i + 1] = ptr[i];
    }

    delete[] ptr;

    ptr = newPtr;
    size++;
}

void removeElement(int*& ptr, int& size, int index)
{
    if (index < 0 || index >= size)
    {
        std::wcout << L"Неверный индекс!" << std::endl;
        return;
    }

    int* newPtr = new int[size - 1];

    for (int i = 0; i < index; i++)
    {
        newPtr[i] = ptr[i];
    }

    for (int i = index + 1; i < size; i++)
    {
        newPtr[i - 1] = ptr[i];
    }

    delete[] ptr;

    ptr = newPtr;
    size--;
}

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    std::srand(std::time(0));

    int size = 5;
    int* ptr = nullptr;

    std::wcout << L"Создание массива:" << std::endl;

    createArray(ptr, size);
    fillArray(ptr, size);
    printArray(ptr, size);

    std::wcout << std::endl << L"Добавление элемента в конец:" << std::endl;

    addElement(ptr, size, 777);
    printArray(ptr, size);

    std::wcout << std::endl << L"Вставка элемента по индексу 2:" << std::endl;

    insertElement(ptr, size, 2, 555);
    printArray(ptr, size);

    std::wcout << std::endl << L"Удаление элемента по индексу 3:" << std::endl;

    removeElement(ptr, size, 3);
    printArray(ptr, size);

    std::wcout << std::endl << L"Удаление массива:" << std::endl;

    deleteArray(ptr);

    std::wcout << L"Память освобождена!" << std::endl;

    return 0;
}
