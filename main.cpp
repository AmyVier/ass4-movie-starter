#include "movie_store.h"
#include <iostream>
#include <string>

using namespace std;

void test1()
{
  MovieStore test = MovieStore();
  test.readMovie("data5movies.txt");
  std::cout << "movie input complete! " << endl;
  test.readCustomer("data4customers.txt");
  std::cout << "customer input complete! " << endl;
  test.readCommand("data5commands.txt");
  std::cout << "command input complete! " << endl;
}

int main()
{
  test1();
  cout << "Done." << endl;
}