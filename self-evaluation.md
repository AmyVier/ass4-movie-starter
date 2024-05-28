# Self-Evaluation

## Name(s): 

Out of 25 points. Use output.txt created using 
`./create-output.sh > output.txt 2>&1` for guidance.

Complete all questions with "Q:"

Q: Does the program compile and run to completion: Yes

- If the program does not compile or gives a segmentation error when run, 
the maximum possible grade is 50%. No need to continue with the rest of self-evaluation

Q: All public functions have been implemented: 0

- -2 for each functionality not implemented

For each command, state Full, Partial or None to indicate 
if it has been fully, partially or not implemented at all.
Explain any partial implementations.

Inventory: Partial
History: Partial
Borrow: Partial
Return: Partial


Q: -1 for each compilation warning, min -3: 0

- Check under *1. Compiles without warnings*
- If the warning message is addressed in README.md, including how the programmer tried to address it, no deductions

Q: -1 for each clang-tidy warning, min -3: 0

- Check under *3. clang-tidy warnings*
- If the warning message is addressed in README.md, including how the programmer tried to address it, no deductions

Q: -1 for each clang-format warning, min -3: 0

- Check under *4. clang-format does not find any formatting issues*


Q: -2 for any detected memory leak: -2

- Check under *5. No memory leaks using g++*
- Check under *6. No memory leaks using valgrind*

Q: Do the tests sufficiently test the code: -2

- -1 for each large block of code not executed
- -2 for each function that is never called when testing
- Check under *7. Tests have full code coverage* paying attention to *The lines below were never executed*

Q: Are all functions in .h and .cpp file documents (min -3): 0

- -1 for each function not documented

## Location of error message or functionality

State the file and function where the information can be found

invalid command code: movie_store.cpp - readCommands()

invalid movie type: movie_store.cpp - readMovies()

invalid customer ID: movie_store.cpp - readCustomers()
 
invalid movie: Inventory.cpp - FindMovie()

factory classes: movieFactory.h, mediaFactory.h

hashtable: hashtable.cpp - only used for maintaining hash functions used in customer_manager.cpp

container used for comedy movies: in inventory.h

function for sorting comedy movies: inventory.cpp - sort()

function where comedy movies are sorted: inventory.cpp - sort()

functions called when retrieving a comedy movie based on title and year: movies.h - ostream<<

functions called for retrieving and printing customer history: transaction_manager.h

container used for customer history:in transaction_manager.h

functions called when borrowing a movie: Inventory.cpp -Borrow()

explain borrowing a movie that does not exist: the borrow function will check if the movie exists or not. if not it will generate a null transaction to the MovieStore object to check.

explain borrowing a movie that has 0 stock: the borrow function will perform an action to borrow a movie, before the process of deducting stock, it will check if there's any remaining, and return false if not.

explain returning a movie that customer has not checked out: the borrow function will perform an action to borrow a movie, before the process of adding stock, it will check if there's any being borrowed.


any static_cast or dynamic_cast used: static cast being used for movie factories and media factories to instantiate objects.

Q: Total points: ADD_ALL_POINTS (max 25)
