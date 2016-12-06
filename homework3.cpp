/* Christian Tsvetanov Stanislavov
   F74234
   Define a class Set_string that stores integers in a dynamically allocated array of strings. In a set, the order of elements does not matter.
*/      

#include <iostream>
#include <cstdlib>

using namespace std;

class set_string
{
	public:
		set_string(); // default constructor
		set_string(const set_string& str); // copy constructor
		~set_string(); // destructor
		set_string& operator = (const set_string& str); // assignment operator 
		set_string return_value(set_string& value); // this functions completes e)
		set_string& operator << (const set_string& str);
		void add(char numb); // add function
		void remove(int remv); // remove function
		void print(); // printing functions 
		void contains();
		int size(); // storing the size of the array
	private:
		char* integers;
		int length;
		
};

set_string::set_string() // Default constructor 
{
	cout << "Default Constructor ! " << endl;
	length = 10;
	integers = new char[length];
	static const char alphanum[] =
        "0123456789";
        

    for (int i = 0; i < length; ++i) 
	{
        integers[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    integers[length] = 0;
}	
	


set_string::set_string(const set_string& str) // copy constructor 
{
	cout << "Copy Constructor ! " << endl;
	length = str.length;
	integers = new char[length];
	for(int i = 0 ; i < length; i++)
	{
		integers[i] = str.integers[i];
	}
	integers[length] = '\0'; 
}

set_string& set_string::operator << (const set_string& str)
{
	for(int i = 0; i < length;i++)
	{
		cout << integers[i] << endl;
	}
}

set_string& set_string::operator = (const set_string& str) // changing the assignment operator
{
	if(this != &str) // anti copying 
	{
		if(integers) // checking the memory state
		{
			delete [] integers; // deleting allocated memory	
			integers = 0; 
		}
		length = str.length; 
		integers = new char[length];
		for (int i = 0; i < length; i++ )
		{
			integers[i] = str.integers[i]; // copying string content
		}
		integers[length] = '\0';
	}
	return *this; // returing the current object
}

set_string::~set_string() // destructor 
{
	cout << "Destructor ! " << endl;
	if(integers)
	{
		delete[] integers;
		integers = 0;
	}
}

void set_string::add(char numb) // adding function 
{
	length = length + 1;
	char* bumb = new char[length]; // allocating the new dynamic memory 
	std::copy(this->integers, this->integers + length,bumb); // using std function to copy the content of the current object to the temporary one.
	bumb[length - 1] = numb;               
	delete[] integers; // deleting the allocated memory
	this->integers = bumb;	
}

void set_string::remove(int remv) // removing function
{
	length = length - 1; // decrementing 
	char* bumb = new char[length]; // allocating memory with temporary array 
	std::copy(this->integers, this-> integers + length, bumb );
	delete[] integers; // deleting allocated memory 
	this->integers = bumb;
}

void set_string::print() // printing function
{
	
	for(int i = 0; i < this->length ;i++)// enter every elemnt of the current object equal to the length
	{
		cout << integers[i] << endl;
	}
	cout << "end" << endl;
}

int set_string::size()
{
	return this->length; // returning the size of the array
}


set_string set_string::return_value(set_string& value)
{
	return value; // returining value to the demonstrate e)
}
int main()
{
	
	cout << "This programs impelents class String!" << endl;
	cout << "And demonstrates the three memory management functions!" << endl;
	cout << "\n" << endl;
	cout << "Initialization" << endl;
	set_string s;
	set_string t = s;
	s.print(); // calling functions
	cout << "End of first object!" << endl;
	t.print();
	cout << "End of second object!" << endl;
	cout << "\n" << endl;
	
	cout << "Assignment" << endl;
	
	set_string a;
	set_string b;
	a = b;
	a.print();
	cout << "End of first object!" << endl;
	b.print();
	cout << "End of second object!" << endl;
	cout << "\n" << endl;
	
	cout << "The fact that the copy constructor is invoked if an object is passed by value to a function " << endl;
	cout << "\n" << endl;
	set_string d;
    set_string f(d);
    d.print();
    f.print();
    cout << "\n" << endl;
    
    cout << "The fact that the copy constructor is not invoked when a parameter is passed by reference " << endl;
    cout << "\n" << endl;
    
	set_string k;
    set_string *l(&k); // pass by reference to demonstrate that the copy constructor is not invoked.
    k.print();
    l->print();
    cout << "\n" << endl;
    
    cout << "The fact that the copy constructor is used to copy a return value to the caller. " << endl;
    cout << "\n" << endl;
    
    set_string y;
    set_string n;
    y.return_value(n);
    cout << "\n" << endl;
    
    cout << "Add function. " << endl;
    cout << "\n" << endl;
	set_string adding;
	adding.print();
    adding.add(2);
    adding.add(1);
    adding.add(3);
    adding.print();
    cout << "\n" << endl;
    
    cout << "Removing function. " << endl;
    adding.remove(2);
    adding.print();
    cout << "\n" << endl;
    
    cout << "Array size : " << adding.size()
	 << endl;
    cout << "\n" << endl;
    
    cout << "Overloading the << operator : " << endl;
    cout << "\n" << endl;
    set_string overloading;
    overloading << overloading;
    cout << "\n" << endl;
    
return 0;
}
