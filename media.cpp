#include "media.h"
#include <string>

using namespace std;

bool Media::addTostock(int stk)
{
  stock += stk;
  return true;
}
bool Media::isInStock()
{
  return (stock != 0);
}
bool Media::checkOut()
{
  if (stock == 0)
    return false;
  stock--;
  return true;
}
bool Media::returnMovie()
{
  stock++;
  return true;
}