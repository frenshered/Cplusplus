// g++ test.cpp -o t.exe
#include <iostream>
#include <string>

const uint16_t N = 5;

const std::string names[N] = {"Serhiy", "Dmytro", "Mykola", "Oleg", "Pavlo"};
const std::string userNames[N] = {"ser", "dmt", "myk", "ol", "paha"};
const std::string passs[N] = {"3211", "1234", "4321", "4949", "0033"};
const uint16_t ages[N] = {17, 18, 23, 32, 40};

class User {
	public:
		User(std::string userName, std::string pass) {
			this -> pass = pass;
			this -> userName = userName;
		}
		void output() {
			std::cout << this -> userName << " " << this -> pass << std::endl;
		}

		std::string getUserName() {
			return this -> userName;
		}

		std::string getPass() {
			return this -> pass;
		}
		
	private:
		std::string pass;
		std::string userName;
};

class UserProfile : public User {
	public:
		UserProfile(std::string userName, std::string pass, std::string name, uint16_t age) : User(userName, pass) {
			this -> age = age;
			this -> name = name;
		}
		void output() {
			std::cout << "Name: " << this -> name << std::endl;
			std::cout << "Age: " << this -> age << std::endl;
			std::cout << "User name: " << this -> getUserName() << std::endl;
			std::cout << "Password: " << this -> getPass() << std::endl;
			std::cout << std::endl; 
 		}
	private:
		uint16_t age;
		std::string name;
};

void create(UserProfile* arr[]) 
{
	for (int i = 0; i < N; i++) {
		UserProfile* userProfile = new UserProfile(userNames[i], passs[i], names[i], ages[i]);
		arr[i] = userProfile;
	}
}

void read(UserProfile* arr[])
{
	uint16_t count = 1;
	for (int i = 0; i < N; i++) {
		std::cout << "User " << count << ":" << std::endl;
		arr[i] -> output();
		count++;
	}
}

int main(void) 
{
	UserProfile* arr[N];

	create(arr);
	read(arr);

	return 0;
}
