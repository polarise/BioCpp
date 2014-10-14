#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include "Line.h"
#include "GTFRecord.h"
#include "Gene.h"

std::vector<std::string> split( std::string s, char delim )
{
	std::stringstream ss;
	std::vector<std::string> v;
	std::string t;

	ss << s;	
	
	while( std::getline( ss, t, delim ))
	{
		v.push_back( s );
	}
	
	return v;
}

int main( int argc, char **argv )
{
	std::fstream f;
	std::vector<std::string> v,u,w;
	f.open( argv[1], std::ios::in );
	
	if ( !f )
	{
		std::cerr << "Unable to open file!" << std::endl;
	}
	
	std::string s;
	
	
	std::map<std::string, Gene> genes;
	
	while ( getline( f, s, '\n' ))
	{
		if ( s[0] == '#' )
		{
			continue;
		}
		else
		{
			Line L( s );
			GTFRecord record( L );
			
			if ( record.feature.compare( "gene" ) == 0 )
			{
				Gene G( record );
				genes.insert( std::pair<std::string, Gene>( record.group["gene_id"], G ));
			}
		}
	}
	
	std::map<std::string, Gene>::iterator Iter = genes.begin();
	for ( Iter = genes.begin(); Iter != genes.end(); Iter++ )
	{
		( Iter->second ).print();
	}
//			else
//			{
//				continue;
//			}
//			

////			std::map<std::string, std::string>::iterator Iter = G.group.begin();
////			for ( Iter = record.group.begin(); Iter != record.group.end(); Iter++ )
////			{
////				std::cout << Iter->first << "|--|" << Iter->second << std::endl;
////			}
	
	/*
	Line L( "\"ldjsljdfksjdlkj\"" );
	s = L.lstrip( '"' );
	std::cout << s << std::endl;
	Line M( s );
	std::cout << M.rstrip( '"' ) << std::endl;
	 */
	/*
	while ( std::getline( f, s, '\n' ))
	{
		if ( s[0] == '#' )
		{
			continue;
		}
		else
		{
			Line L( s );
			L.split( '\t' );
			Line V( L.v[8] );
			V.split( ';' );
			std::cout <<  V.v[0] << "|" << V.v[1] << std::endl;
		}
	}*/
	
	f.close();
	
	return 0;
}
