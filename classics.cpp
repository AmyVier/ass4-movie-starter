#include "classics.h"
#include <string>

using namespace std;

bool Classics::operator<(const Classics &other) const {
  if (this->releaseYear < other.releaseYear) {
    return true;
  } else if ((this->releaseYear == other.releaseYear) &&
             (this->releaseMonth < other.releaseMonth)) {
    return true;
  } else if ((this->releaseYear == other.releaseYear) &&
             (this->releaseMonth == other.releaseMonth) &&
             (this->majorActor < other.majorActor)) {
    return true;
  } else {
    return false;
  }
}

bool Classics::operator>(const Classics &other) const {
  if (this->releaseYear > other.releaseYear) {
    return true;
  } else if ((this->releaseYear == other.releaseYear) &&
             (this->releaseMonth > other.releaseMonth)) {
    return true;
  } else if ((this->releaseYear == other.releaseYear) &&
             (this->releaseMonth == other.releaseMonth) &&
             (this->majorActor > other.majorActor)) {
    return true;
  } else {
    return false;
  }
}

bool Classics::operator==(const Classics &other) const {
  if ((this->releaseYear == other.releaseYear) &&
      (this->releaseMonth == other.releaseMonth) &&
      (this->majorActor > other.majorActor)) {
    return true;
  } else {
    return false;
  }
}