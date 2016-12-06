
#include<iostream>
#include<ctime>
#include<cmath>
#include<iomanip>
#include<cstdlib>



using namespace std;

int main()
{
   double nDarts = 1;
   cout << "\nThis program determines the hits of a darts."<< endl;
   while(nDarts > 0)
   {
      cout << "\nHow many darts do you want to throw?" << endl;
      cin  >> nDarts;
      if (nDarts > 0)
      {
         srand(time(NULL)); //Sets seed value for the random numbers
         int hit = 0;
         for(int i = 0; i < nDarts; ++i)
         {
            double xValue = static_cast<double>(rand())/RAND_MAX; //generates a random value of x and y
            double yValue = static_cast<double>(rand())/RAND_MAX;
            //checks if the x and y values are inside a circle
            if (((xValue * xValue) + (yValue * yValue)) <= 1)
            {
              ++hit;
            }
         }
          cout << "\nThere were "<< hit <<" hits." << endl;
          cout << "\nTip of the Day : If you enter 0 the program closes." <<endl;
       }
   }
   return 0;

}
