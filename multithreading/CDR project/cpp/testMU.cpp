#include "mu_test.h"
#include "CDRManager.h"
#include "Parser.h"
#include "CDR.h"
#include "SafeHash.h"
#include "Operator.h"
#include "Subscriber.h"

#define SIZEOFHASH 7
#define NUMBEROFMUTEXES 5
#define SIZE 3
#define NUMBEROFPARSERS 2

#include "HasherForSize_t.h"

UNIT(CDR_test)
	SafeHash<size_t,Operator,HasherForSize_t> shOp = SafeHash<size_t,Operator,HasherForSize_t> (SIZEOFHASH,NUMBEROFMUTEXES);
   	SafeHash<size_t,Subscriber,HasherForSize_t> shSub = SafeHash<size_t,Subscriber,HasherForSize_t> (SIZEOFHASH,NUMBEROFMUTEXES);
	HasherForSize_t func;
    CDRManager<size_t,Operator,Subscriber,HasherForSize_t> cdrm(shOp,shSub,func);

	std::vector<std::string> nameOfFiles;
	nameOfFiles.push_back("f0.txt");
	nameOfFiles.push_back("f1.txt");
	

	std::vector<Parser*> parser;

		std::vector<CDR*> cdrVector1;
		Parser *tempParser1=new Parser(nameOfFiles[0]);
		cdrVector1=tempParser1->parse();
		cdrm.addCDRsOfVector(cdrVector1);
	
/*
		std::vector<CDR*> cdrVector2;
		Parser *tempParser2=new Parser(nameOfFiles[1]);
		cdrVector2=tempParser2->parse();
		cdrm.addCDRsOfVector(cdrVector2);
*/	

END_UNIT

TEST_SUITE(CDR Tests)
    TEST(CDR_test)
END_SUITE
