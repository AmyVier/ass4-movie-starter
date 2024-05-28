/**
 *  MovieFactory class - class used to create movies
 *
 * @author Amy Vier
 * @date 12 May 2024
 *
 * A movie has a director, title, release year, and stocks pertaining to their media types.
 * A movie has at lease one media type (DVD, blue-ray, etc.) with a corrosponding stock
 */

#include <string>
#include "comedy.h"
#include "classics.h"
#include "drama.h"

using namespace std;

class MovieFactory
{
public:
    static Movie createComedy(char mediaType, int stock, string director, string title, int releaseYear)
    {
        return Comedy(mediaType, stock, director, title, releaseYear);
    }

    static Movie createDrama(char mediaType, int stock, string director, string title, int releaseYear)
    {
        return Drama(mediaType, stock, director, title, releaseYear);
    }

    static Movie createClassics(char mediaType, int stock, string director, string title,
                                 string majorActor, int releaseYear, int releaseMonth)
    {
        return Classics(mediaType, stock, director, title, majorActor, releaseYear, releaseMonth);
    }
};