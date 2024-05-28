
#include "movie_store.h"
#include "movieFactory.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

MovieStore::MovieStore() {
  inventory = new Inventory();
  customerManager = new CustomerManager();
  transactionManager = new TransactionManager();
}

void MovieStore::readMovie(string filename) {
  ifstream file(filename);

  while (!file.eof()) {
    string line;
    getline(file, line);
    stringstream ss(line);
    getline(ss, line, ',');
    char type = line[0];

    if (type == 'F') {
      string director, title;
      int stock, year;
      ss.ignore();
      ss >> stock;
      ss.ignore();
      getline(ss, director, ',');
      getline(ss, title, ',');
      ss >> year;
      Movie movie =
          MovieFactory::createComedy(MEDIA_TYPE, stock, director, title, year);
      inventory->AddMovie("F", movie);
    } else if (type == 'D') {
      string director, title;
      int stock, year;
      ss.ignore();
      ss >> stock;
      ss.ignore();
      getline(ss, director, ',');
      getline(ss, title, ',');
      ss >> year;
      Movie movie =
          MovieFactory::createDrama(MEDIA_TYPE, stock, director, title, year);
      inventory->AddMovie("D", movie);
    } else if (type == 'C') {
      getline(ss, line, ',');
      int stock = stoi(line);
      ss.get();
      getline(ss, line, ',');
      string director = line;
      ss.get();
      getline(ss, line, ',');
      string title = line;
      ss.get();
      stringstream actorStream;
      string actorPart;
      string actor;
      int month;
      int year;
      getline(ss, line, ' ');
      actor = line;
      getline(ss, line, ' ');
      actor += " " + line;
      getline(ss, line, ' ');
      month = stoi(line);
      getline(ss, line, ' ');
      year = stoi(line);
      Movie movie = MovieFactory::createClassics(MEDIA_TYPE, stock, director,
                                                 title, actor, year, month);
      inventory->AddMovie("C", movie);
    } else {
      cout << "Invalid movie type encountered: " << type << endl;
    }
  }
  file.close();
}

void MovieStore::readCustomer(string filename) {
  ifstream file(filename);
  string ID, lastName, firstName;

  while (file >> ID >> firstName >> lastName) {
    try {
      int id = stoi(ID);
      customerManager->addCustomer(id, firstName, lastName);
    } catch (const invalid_argument &e) {
      cerr << "Not a valid argument:" << e.what() << endl;
      continue;
    } catch (const out_of_range &e) {
      cerr << "Out of range: " << e.what() << endl;
      continue;
    }
  }
  file.close();
}

void MovieStore::readCommand(string filename) {
  ifstream file(filename);
  string line, commandType, movieType, mediaType;
  int customerID, year, month;
  string title, actor, director;

  while (getline(file, line)) {
    stringstream ss(line);
    ss >> commandType;

    if (commandType == "B" || commandType == "R") {
      ss >> customerID >> mediaType >> movieType;
      if (customerManager->isValid(customerID) && mediaType == "D") {
        if (movieType == "F") {
          getline(ss, title, ',');
          ss >> year;
          // Borrow or return logic for comedy
          if (inventory->FindMovie(movieType, title)) {
            if (commandType == "B") {
              Transaction t = inventory->Borrow(movieType, title, customerID);
              if (t.getID() != -1) {
                transactionManager->addTransaction(customerID, t);
              } else {
                cout << "Movie does not exist, or is out of stock!" << endl;
              }
            } else {
              Transaction t = inventory->Return(movieType, title, customerID);
              if (t.getID() != -1) {
                transactionManager->addTransaction(customerID, t);
              } else {
                cout << "Movie does not exist, or is out of stock!" << endl;
              }
            }
          }
        } else if (movieType == "D") {
          getline(ss, director, ',');
          getline(ss, title);
          // Borrow or return logic for drama
          if (inventory->FindMovie(movieType, title)) {
            if (commandType == "B") {
              Transaction t = inventory->Borrow(movieType, title, customerID);
              if (t.getID() != -1) {
                transactionManager->addTransaction(customerID, t);
              } else {
                cout << "Movie does not exist, or is out of stock!" << endl;
              }
            } else {
              Transaction t = inventory->Return(movieType, title, customerID);
              if (t.getID() != -1) {
                transactionManager->addTransaction(customerID, t);
              } else {
                cout << "Movie does not exist, or is out of stock!" << endl;
              }
            }
          }
        } else if (movieType == "C") {
          ss >> month >> year >> actor;
          // Borrow or return logic for classics
          getline(ss, line, ' ');
          actor += " " + line;
            if (commandType == "B") {
              Transaction t = inventory->BorrowClassics(actor, customerID);
              if (t.getID() != -1) {
                transactionManager->addTransaction(customerID, t);
              } else {
                cout << "Movie does not exist, or is out of stock!" << endl;
              }
            } else {
              Transaction t = inventory->ReturnClassics(actor, customerID);
              if (t.getID() != -1) {
                transactionManager->addTransaction(customerID, t);
              } else {
                cout << "Movie does not exist, or is out of stock!" << endl;
              }
            }
        } else {
          cout << "customer ID not valid: " << customerID << endl;
          ss.ignore();
        }
      }
    } else if (commandType == "I") {
      // Inventory display logic
      inventory->PrintInventory();
    } else if (commandType == "H") {
      ss >> customerID;
      // History display logic
      cout << transactionManager->printTransaction(customerID);
      
    } else {
      cout << "Invalid command encountered: " << commandType << endl;
      ss.ignore();
    }
  }
  file.close();
}

MovieStore::~MovieStore() {
  delete inventory;
  delete customerManager;
  delete transactionManager;
}