//without the following line, we cannot function as users
#include <iostream>

/*
what else can we #include?
you can find an exhaustive list here: http://en.cppreference.com/w/cpp/header

here are some common ones
<ctime>
<math>
<string>
<vector>
<list>
<random>
<istream>
<ostream>

*/


//now you've seen 2 types of comments - we're using them
//try cntrl - / 

//we also need to include namespace
using namespace std;


// otherwise our lines all have to read
// std::cout<< etc


//this is where all of our program will be housed (for now)
// in main()
int main() {

// these aree declarations
int intVariable;
float floatVariable;

//these we are going to let a user assign a value to
int fromUserOne, fromUserTwo;
// this is called a comma separated list

// these are assignments
intVariable = 4;
floatVariable = 5.25;

// or you can combine them
int intVariableTwo = 6;
float floatVariableTwo = 10.50;

// this is a terminal out
cout << "This is a terminal out\n\n\n\n\n\n\n";

// notice every line ends with a ;

// you can output variables by name
cout << "intVariable is equal to\t\t\t " << intVariable << endl;
cout << "floatVariable is equal to\t\t\t " << floatVariable << endl <<  "\a";
// run the code here by hitting play above
// notice something about line 3 of the output?

// notice that the endls give you an escape char like \n
// those are escape characters
//there's a list in your Session Two Module

}