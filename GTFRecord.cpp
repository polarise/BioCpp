#include "GTFRecord.h"

GTFRecord::GTFRecord( Line L )
{
	L.split( '\t' );
	seqname = L.v[0];
	source = L.v[1];
	feature = L.v[2];
	start = std::stoi( L.v[3] );
	end = std::stoi( L.v[4] );
	score = L.v[5];
	strand = L.v[6];
	frame = L.v[7];
	
	Line G( L.v[8] );
	G.split( ' ' );	
	
	std::vector<std::string>::iterator Iter = G.v.begin();
	int i = 0;
	std::string key, value;
	for (Iter = G.v.begin(); Iter != G.v.end(); Iter++ )
	{
		if ( i % 2 == 0 ) // keys
		{
			key = *Iter;
			i++;
			continue;
		}
		else // values
		{
			value = rstrip( rstrip( lstrip( *Iter, '"' ), ';' ), '"' );
			i++;
		}
		group[key] = value;
//		group.insert( std::pair<std::string, std::string>( key, value ));
	}
}

GTFRecord::~GTFRecord()
{}
