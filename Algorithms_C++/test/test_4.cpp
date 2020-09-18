// g++ test_4.cpp -o t4.exe
#include <iostream>
#include <string>
#include <initializer_list>

class User
{
	public:
		User() 
		{
			this->name = "";
			this->age = 0;
			this->size = 0;
		}
		User( std::string name, int age, int size )
		{
			this->name = name;
			this->age = age;
			this->size = size;
		}
		~User()
		{
			delete [] this->secret;
		}
		template<typename T>
		T getData( std::string data ) 
		{
			if ( data == "name" )
			{
				// return this->name;
				return 0;
			}
			else if ( data == "age" )
			{
				return this->age;
			}
			else if ( data == "size" )
			{
				return this->size;
			}
			else 
			{
				return -1;
			}
		}
		int* getArray() 
		{
			return this->secret;
		}
		void initialSecret( std::initializer_list<int> args )
		{
			int i = 0;
			for ( auto a : args )
			{
				this->secret[i] = a;
				i++;
			}
		}
		void output()
		{
			for ( int i = 0; i < this->size; i++ )
			{
				std::cout << this->secret[i] << " ";
			}
		}
	private:
		std::string name;
		int age;
		int size;
		int* secret = new int[size];
};

int main(int argc, char const *argv[])
{
	User* user = new User( "serhiy", 17, 2 );

	std::cout << user->getData<int>( "size" ) << std::endl;;
	user->initialSecret( {2, 4} );
	user->output();
	
	return 0;
}