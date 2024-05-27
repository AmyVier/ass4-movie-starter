#include <string>
#include "mediaFactory.h"
#include "dvd.h"

static DVD MediaFactory::createDVD(int stock) {
	DVD dvd = DVD(stock);
	return dvd;
}