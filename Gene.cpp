#include "Gene.h"
#include <string>
#include <iostream>

Gene::Gene( GTFRecord record )
{
	gene_id = record.group["gene_id"];
	seqname = record.seqname;
	source = record.source;
	start = record.start;
	end = record.end;
	strand = record.strand;
}

Gene::~Gene()
{}

void Gene::print( void )
{
	std::cout << "This is gene " << gene_id << " (" << seqname << ":" << start << "-" << end << ":" << strand << ")." << std::endl;
}
