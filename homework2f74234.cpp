/*
Christian Tsvetanov Stanislavov F74234
Implement a function generate_subsets , that generates all subsets
*/


#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> generate_subsets(string s) // defining  the function
{
    vector<string> store; // one vector to store the result
    vector<string> out_store; // and again a vector to store
    store.push_back(""); // this handles the empty string
    vector<string>::iterator storage; // declaring a iterator
    for(int i=0;i < s.size();i++) // for loop starting with the first charecter which stops at the last character
	{
        for(storage=store.begin() ; storage!=store.end() ; storage++) // using the iterator to define the begin and stops at the end
		{
                string tmp=*storage+s.substr(i,1); // a new string that is equal to iterator postion plus a single character which is defined by i'th position
                out_store.push_back(tmp); // putting the new substring to the  vector
        }
        store.push_back(s.substr(i,1)); // adding r character
        for(vector<string>::iterator storage2=out_store.begin();storage2!=out_store.end();storage2++) // declaring a second iterator
		{
            store.push_back(*storage2); // filling the first vector with the subsets
   		}
    out_store.clear(); // clearing the second vector
    }

    cout << endl;

	for (int i = 0; i < store.size(); i++) // for loop that prints and erase the duplicates
	{
		if(store[i] == store[i + 1])
		{
			store.erase(store.begin() + 1);
		}
	cout << " - " << store[i] << " - " << endl;
	}

    return store;
}

int main()
{
	string s;
	cout << "Generate all subsets! " << endl;
	cout << "Enter a string : " << endl;
	cin >> s;
	generate_subsets(s); // calling the function

	return 0;
}
