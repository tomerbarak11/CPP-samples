#ifndef _RECORDFACTORY_H_
#define _RECORDFACTORY_H_

#include "IStringLoader.h"
#include "IParser.h"
#include "Record.h"

class RecordFactory
{
	public:
		RecordFactory(IStringLoader *a_ssl,IParser *a_rp);
		const Record get();
	private:
		Record m_record;
		IStringLoader* m_ssl;
		IParser* m_rp;
};

#endif
