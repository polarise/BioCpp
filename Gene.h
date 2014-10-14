#ifndef GENE_H
#define GENE_H

#include <string>
#include <map>
#include "GTFRecord.h"

class Gene
{
	public:
	// methods
		void print( void );
	// members
		std::string gene_id;
		std::string seqname;
		std::string source;
		int start;
		int end;
		std::string strand;
		std::map<std::string, std::string> transcripts;
	
	// constructor
		Gene( GTFRecord record );
	
	// destructor
		~Gene();
};

#endif // GENE_H
