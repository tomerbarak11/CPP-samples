#include "RecordFactory.h"
#include "StreamStringLoader.h"
#include "RecordParser.h"

RecordFactory::RecordFactory(IStringLoader *a_ssl,IParser *a_rp)
:m_ssl(a_ssl)
,m_rp(a_rp)
{
}
