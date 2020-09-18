// g++ class.cpp -o cl.exe

#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

const uint16_t SIZE = 5;

class User {
	public:
		void init(uint16_t userAge, std::string userName) 
		{
			name = userName;
			age = userAge;
		}
		void read() {
			std::cout << name << " " << age << std::endl;
		}
	private:
		uint16_t age;
		std::string name;
};

void readVector(uint16_t size, User* arr) 
{
	std::cout << "Read vector" << std::endl;

	for (int i = 0; i < size; i++)
	{
		arr[i].read();
	}
}

int main() 
{
	std::string names[SIZE] = {"Serhiy", "Dmytro", "Mykola", "Oleg", "Pavlo"};
	uint16_t ages[SIZE] = {19, 23, 21, 20, 17};
	// std::vector<User> users;
	User users[SIZE];

	User* user = new User;

	for (int i = 0; i < SIZE; i++)
	{
		user -> init(ages[i], names[i]);
		// users.push_back(*user);
		users[i] = *user;
	}
	
	readVector(SIZE, users);

	delete user;

	return 0;
}