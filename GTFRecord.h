#ifndef GTFRECORD_H
#define GTFRECORD_H

#include <string>
#include <map>
#include <vector>
#include "Line.h"

class GTFRecord
{
	public:
	// methods
	
	// attributes
		std::string seqname;
		std::string source;
		std::string feature;
		int start;
		int end;
		std::string score;
		std::string strand;
		std::string frame;
		std::map<std::string, std::string> group;
	
	// constructor
		GTFRecord( Line L );
	
	// destructor
		~GTFRecord();
};

#endif // GTFRECORD_H
