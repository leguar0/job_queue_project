#include "JobQueue.hpp"
#include <algorithm>

size_t JobQueue::Size()
{
	return m_dequeJobs.size();
}

Job& JobQueue::FindJob(int nId)
{
	for (int i = 0; i < Size(); ++i)
	{
		if (m_dequeJobs[i].GetId() == nId)
			return m_dequeJobs[i];
	}

	JobNotFind jnf;
	throw jnf;
	
}

Job JobQueue::GetNextJob()
{	
	auto job = m_dequeJobs.begin();
	for (auto it = m_dequeJobs.begin() + 1; it != m_dequeJobs.end(); ++it)
	{
		if (
			it->GetPriority() > job->GetPriority() ||
			(it->GetPriority() == job->GetPriority() && it->GetSequenceNumber() < job->GetSequenceNumber())
			)
			job = it;
	}

	Job result = *job;
	m_dequeJobs.erase(job);

	return result;
}

void JobQueue::AddJob(const Job& rJob)
{
	m_dequeJobs.push_back(rJob);
}

void JobQueue::RemoveJob(int nId)
{
	auto it = std::find_if(m_dequeJobs.begin(), m_dequeJobs.end(),
		[nId](const Job& job) { return job.GetId() == nId; });

	if (it != m_dequeJobs.end())
		m_dequeJobs.erase(it);
}

void JobQueue::UpdateStatus(int nId, eStatusType nNewStatus)
{
	auto it = std::find_if(m_dequeJobs.begin(), m_dequeJobs.end(),
		[nId](const Job& job) { return job.GetId() == nId;  });

	if (it != m_dequeJobs.end())
		it->SetStatus(nNewStatus);
}
