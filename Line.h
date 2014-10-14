#ifndef LINE_H
#define LINE_H

#include <string>
#include <vector>
#include <sstream>

std::string strip( std::string );
std::string lstrip( std::string, char );
std::string rstrip( std::string, char );

class Line
{
	public:
	// methods
		std::vector<std::string> split( char delim );
		std::string join( char sep );
		
	// attributes
		std::string s;
		std::vector<std::string> v;		

	// constructor
		Line( std::string s );
		
	// destructor
		~Line();
};

#endif // LINE_H
