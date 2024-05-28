#include "movie.h"
#include <iostream>
#include <string>

using namespace std;

ostream &operator<<(ostream &out, const Movie &movie) {
  // title director releaseTear stock
  out << movie.title << " " << movie.director << " " << movie.releaseYear << " "
      << movie.allStock.begin()->second->getRemained();
  return out;
}

Movie::Movie(char mediaType, int stock, string director, string title,
             int releaseYear) {
  this->director = director;
  this->title = title;
  this->releaseYear = releaseYear;

  // if media lready exists, add to stock, if not create new media
  if (allStock.find(mediaType) != allStock.end()) {
    allStock[mediaType]->addTostock(stock);
  } else if (mediaType == 'D') {

    Media *newDVD = MediaFactory::createDVD(stock);
    allStock.insert(make_pair(mediaType, newDVD));
  }
}

bool Movie::addTostock(char mediaType, int stock) {
  // if stock exists, add to stock
  if (allStock.find(mediaType) != allStock.end()) {
    allStock[mediaType]->addTostock(stock);
  }
  return true;
}

bool Movie::isInStock(char mediaType) {
  if (allStock.count(mediaType) && allStock[mediaType]->isInStock()) {
    return true;
  }

  return false;
}

string Movie::getTitle() { return this->title; }

int Movie::getYear() { return this->releaseYear; }

bool Movie::checkOut(char mediaType) {
  // do not check out is it does not exist
  if (allStock.count(mediaType) && allStock[mediaType]->isInStock()) {
    allStock[mediaType]->checkOut();
    return true;
  }

  return false;
}

bool Movie::returnMovie(char mediaType) {
  // do not return if media does not exist
  if (allStock.count(mediaType)) {
    allStock[mediaType]->returnMovie();
    return true;
  }

  return false;
}

string Movie::getActor() { return actor; }