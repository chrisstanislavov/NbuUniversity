#include <iostream>

using namespace std;
/* 
Christian Tsvetanov Stanislavov F74234
Write a function that computes the average value of an array of floating-point data:
Double average(double* a, int size)
In the function, use a pointer variable, not an integer index, to traverse the array
Elements.

*/


double average(double* a, int size) // Passing the pointer as a paramter
{
	double result = 0; // double that result of all  array elements
	double final_result = 0; // stores the final result , the average sum
	for(int i = 0; i < size; i++)
	{
		result = result +  (*(a + i)); // variable that stores the result of all elemnts of the array, using the pointer 
		// as a array index	
	}
	final_result = result / size; // the average sum
	return final_result; // returning the result 
}

int main()
{
	cout << "Enter the size of the array : " << endl;
	int n; // integer that stores the size of the array
	cin >> n;
	double arr[n]; // declaring the array 
	for(int i = 0; i < n ; i++) // for loop that fills the array itself
	{
		cout << "Enter a number : ";
		cin >> arr[i];
	}
	double* arrPtr = arr; // declaring a pointer to the array
 	cout << average(arrPtr,n); // calling the function 
	


	return 0;
}

