// g++ test_1.cpp -o t1.exe
#include <iostream>
#include <string>

class User
{
public:
    User()
    {
        this -> name = "";
        this -> age = 0;
    }

    User(std::string name, int age, int size)
    {
        this -> name = name;
        this -> age = age;
        this -> size = size;
    }

    ~User()
    {
        delete [] this -> arr;
    }

    std::string getName()
    {
        return this -> name;
    }

    int getAge()
    {
        return this -> age;
    }

    int* getArr()
    {
        return this -> arr;
    }

    int getArrSize()
    {
        return this -> size;
    }

    void printData()
    {
        std::cout << this -> name << " " << this -> age << " Addres this array: " << this -> arr << std::endl;
    }
private:
    std::string name;
    int age;
    int size;
    int* arr = new int[size];
};

void filling(User* user)
{
    for (int i= 0; i < user -> getArrSize(); i++)
    {
        user -> getArr()[i] = i;
    }
}

void printArr(User* user)
{
    for (int i = 0; i < user -> getArrSize(); i++)
    {
        std::cout << user -> getArr()[i] << "\t" << std::endl;
    }
}

int main()
{
    User* user = new User("Serhiy", 17, 3);
    std::cout << user -> getName() << std::endl;
    std::cout << user -> getAge() << std::endl;
    std::cout << user -> getArr() << std::endl;
    user -> printData();

    filling(user);
    printArr(user);

    return 0;
}

