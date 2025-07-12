#include "Job.hpp"

unsigned int Job::ms_nNextSequenceNumber = 0;

Job::Job()
	: m_nId{-1}, m_strName{""}, m_nPriorityType{ePriorityType::PT_LOW}, m_nStatusType{eStatusType::ST_PENDING}
{
	++ms_nNextSequenceNumber;
	m_nSequenceNumber = ms_nNextSequenceNumber;
}

Job::Job(int nId, const std::string& strName, ePriorityType nPriorityType)
	: m_nId{nId}, m_strName{strName}, m_nPriorityType{nPriorityType}, m_nStatusType{eStatusType::ST_PENDING}
{
	++ms_nNextSequenceNumber;
	m_nSequenceNumber = ms_nNextSequenceNumber;
}

unsigned int Job::GetSequenceNumber()
{
	return m_nSequenceNumber;
}

int Job::GetId() const
{
	return m_nId;
}

const std::string& Job::GetName() const
{
	return m_strName;
}

ePriorityType Job::GetPriority() const
{
	return m_nPriorityType;
}

eStatusType Job::GetStatus() const
{
	return m_nStatusType;
}

void Job::SetStatus(eStatusType nStatusType)
{
	m_nStatusType = nStatusType;
}
