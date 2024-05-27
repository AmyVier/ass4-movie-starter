#include "movie_store.h"
#include <iostream>
#include <string>

using namespace std;

void test1()
{
  MovieStore test = MovieStore();
  test.readMovie("data4movies.txt");
  test.readCustomer("data4customers.txt");
}

int main()
{
  test1();
  cout << "Done." << endl;
}
