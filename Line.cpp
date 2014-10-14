#include "Line.h"

std::string strip( std::string s )
{
	char c;
	int length;
	// get the length of the string
	length = s.length();
	// go to the end
	c = s[s.length() - 1];
	
	// if the terminal character is '\n' then remove it
	if ( c == '\n' )
	{
		s = s.substr( 0, length - 1 );
		return s;
	}
	else
	{
		return s;
	}
}

std::string lstrip( std::string s, char lchar )
{	
	// perhaps it could be recursive e.g. return lstrip( s.substr( 1, s.length());
	if ( s[0] == lchar )
	{
		s = s.substr( 1, s.length() - 1 );
		return s;
	}
	else
	{
		return s;
	}
}

std::string rstrip( std::string s, char rchar )
{
	if ( s[s.length()-1] == rchar )
	{
		s = s.substr( 0, s.length() - 1 );
		return s;
	}
	else
	{
		return s;
	}
}

// Line class methods
Line::Line( std::string s ) : s( s )
{}

Line::~Line()
{}

std::vector<std::string> Line::split( char delim )
{
	std::stringstream ss;
	std::string t;
	
	ss << s;
	
	while ( std::getline( ss, t, delim ))
	{
		v.push_back( t );
	}
	
	return v;
}

std::string Line::join( char sep )
{
	std::stringstream ss;
	std::vector<std::string>::iterator Iter;
	
	for ( Iter = v.begin(); Iter != v.end(); Iter++ )
	{
		ss << *Iter << sep;
	}
	
	ss >> s;
	
	return s;
}
