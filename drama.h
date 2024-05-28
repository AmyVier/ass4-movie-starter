#ifndef DRAMA_H
#define DRAMA_H

#include <string>
#include "movie.h"
#include "media.h"
#include "dvd.h"
#include <map>

using namespace std;

class Drama : public Movie
{
public:
	Drama(char mediaType, int stock, string director, string title,
				int releaseYear) : Movie(mediaType, stock, director, title, releaseYear){};

	bool operator<(const Drama &) const;
	bool operator>(const Drama &) const;
	bool operator==(const Drama &) const;
};

#endif