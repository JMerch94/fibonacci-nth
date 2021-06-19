#include <iostream>
using namespace std;
#include <chrono>
using namespace std::chrono;
#include <fstream>
#include <istream>
int F[51];
#define Size 50

// Calculate the nth Fibonacci number using recursion
int recursion(int n)
{

   if (n <= 1)
      return n;

   return recursion(n - 1) + recursion(n - 2);
}

// Calculate the nth Fibonacci number using memoization
int memoization(int n)
{
   if (F[n] != -1)
   {
      return F[n];
   }
   F[n] = memoization(n - 1) + memoization(n - 2);
   return F[n];
}

// Write results to CSV
void updateLog(int nth, int memoizationDuration, int recursiveDuration, int difference)
{
   fstream fout;

   fout.open("log.csv", ios::out | ios::app);

   fout << nth << ", "
        << memoizationDuration << ", "
        << recursiveDuration << ", "
        << difference
        << "\n";
}

int main()
{
   int number;
   cout << "Provide the nth Fibonacci Number to calculate: ";
   cin >> number;
   int n = number;

   // Measures recursive() execution time
   auto recursiveStart = high_resolution_clock::now();
   cout << "\nRecursion" << endl;
   printf("Fibonacci Number: %d\n", recursion(n));
   auto recursiveStop = high_resolution_clock::now();
   auto recursiveDuration = duration_cast<microseconds>(recursiveStop - recursiveStart);
   cout << recursiveDuration.count() << " microseconds\n"
        << endl;

   // Measures memoization() execution time
   for (int i = 0; i < 51; i++)
   {
      F[i] = -1;
   }
   F[0] = 0;
   F[1] = 1;
   auto memoizationStart = high_resolution_clock::now();
   cout << "Memoization" << endl;
   printf("Fibonacci Number: %d\n", memoization(n));
   auto memoizationStop = high_resolution_clock::now();
   auto memoizationDuration = duration_cast<microseconds>(memoizationStop - memoizationStart);
   cout << memoizationDuration.count() << " microseconds\n\n"
        << endl;

   // Displays the execution time results
   int difference;
   cout << n << "th Fibonacci\nExecution Times:" << endl;
   if (memoizationDuration.count() < recursiveDuration.count())
   {
      difference = recursiveDuration.count() - memoizationDuration.count();
      cout << "The Memoization() function was " << difference << " milliseconds faster than Recursive().\n"
           << endl;
   }
   else if (memoizationDuration.count() > recursiveDuration.count())
   {
      difference = memoizationDuration.count() - recursiveDuration.count();
      cout << "The Recursive() function was " << difference << " milliseconds faster than Memoization().\n"
           << endl;
   }
   else
   {
      return 0;
   }

   updateLog(n, memoizationDuration.count(), recursiveDuration.count(), difference);

   return 0;
}