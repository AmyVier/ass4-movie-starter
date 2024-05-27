
#include "movie_store.h"
#include "transaction_manager.h"
#include "customer_manager.h"
#include "inventory.h"
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
    string line, type, director, title, actor;
    int stock, year, month;
    char mediaType;

    while (getline(file, line)) {
        stringstream ss(line);
        ss >> type >> mediaType >> stock;
        if (type == "F" || type == "D") {
            getline(ss, director, ',');
            getline(ss, title, ',');
            ss >> year;
            if (type == "F") {
                // Add comedy
               inventory->AddMovie("Comedy", new Comedy(mediaType, stock, director, title, year));
            } else {
                // Add drama
                inventory->AddMovie("Drama", new Drama(mediaType, stock, director, title, year));
            }
        } else if (type == "C") {
            getline(ss, director, ',');
            getline(ss, title, ',');
            getline(ss, actor, ' ');
            ss >> month >> year;
            // Add classic
            inventory->AddMovie("Classics", new Classics(mediaType, stock, director, title, actor, year, month));
        } else {
            cout << "Invalid movie type encountered: " << type << endl;
        }
    }
    file.close();
}

void MovieStore::readCustomer(string filename) {
    ifstream file(filename);
    string line, lastName, firstName;
    int ID;

    while (getline(file, line)) {
        stringstream ss(line);
        ss >> ID >> lastName >> firstName;
        // Add customer logic
        customerManager->addCustomer(ID, firstName, lastName);
    }
    file.close();
}

void MovieStore::readCommand(string filename) {
    ifstream file(filename);
    string line, commandType, movieType;
    int customerID, year, month;
    string title, actor, director;

    while (getline(file, line)) {
        stringstream ss(line);
        ss >> commandType;
        if (commandType == "B" || commandType == "R") {
            ss >> customerID >> movieType;
            if (movieType == "F") {
                getline(ss, title, ',');
                ss >> year;
                // Borrow or return logic for comedy
            } else if (movieType == "D") {
                getline(ss, director, ',');
                getline(ss, title);
                // Borrow or return logic for drama
            } else if (movieType == "C") {
                ss >> month >> year >> actor;
                // Borrow or return logic for classics
            }
        } else if (commandType == "I") {
            // Inventory display logic
            inventory->printInventory();
        } else if (commandType == "H") {
            ss >> customerID;
            // History display logic
            cout << transactionManager->printTransaction(customerID);
        } else {
            cout << "Invalid command encountered: " << commandType << endl;
        }
    }
    file.close();
}

MovieStore::~MovieStore() {
    delete inventory;
    delete customerManager;
    delete transactionManager;
}
