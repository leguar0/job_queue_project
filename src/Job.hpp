#ifndef JOB_HPP
#define JOB_HPP

#include <string>

enum class ePriorityType { PT_LOW, PT_MEDIUM, PT_HIGH };
enum class eStatusType { ST_PENDING, ST_RUNNING, ST_COMPLETED, ST_CANCELLED };

class Job
{
public:
	Job();
	Job(int nId, const std::string& strName, ePriorityType nPriorityType);

	unsigned int GetSequenceNumber();
	int GetId() const;
	const std::string& GetName() const;
	ePriorityType GetPriority() const;
	eStatusType GetStatus() const;

	void SetStatus(eStatusType nStatusType);

private:
	static unsigned int ms_nNextSequenceNumber;
	unsigned int m_nSequenceNumber;

	int m_nId;
	std::string m_strName;
	ePriorityType m_nPriorityType;
	eStatusType m_nStatusType;
};

#endif // !JOB_HPP
