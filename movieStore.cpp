
#include "movie_store.h"
#include "transaction_manager.h"
#include "customer_manager.h"
#include "inventory.h"
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
    movieFactory = new MovieFactory();
}

void MovieStore::readMovie(string filename) {
    ifstream file(filename);
    string line, type, director, title, actor;
    int stock, year, month;
    char mediaType;

    while (getline(file, line)) {
        stringstream ss(line);
        ss >> type >> mediaType >> stock;
        if (type == "F") {
            getline(ss, director, ',');
            getline(ss, title, ',');
            ss >> year;
            Movie* movie = movieFactory->createComedy(mediaType, stock, director, title, year);
            inventory->AddMovie("Comedy", movie);
        } else if (type == "D") {
            getline(ss, director, ',');
            getline(ss, title, ',');
            ss >> year;
            Movie* movie = movieFactory->createDrama(mediaType, stock, director, title, year);
            inventory->AddMovie("Drama", movie);
        } else if (type == "C") {
            getline(ss, director, ',');
            getline(ss, title, ',');
            getline(ss, actor, ' ');
            ss >> month >> year;
            Movie* movie = movieFactory->createClassics(mediaType, stock, director, title, actor, year, month);
            inventory->AddMovie("Classics", movie);
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
