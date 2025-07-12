#ifndef JOBQUEUE_HPP
#define JOBQUEUE_HPP

#include "Job.hpp"
#include <deque>
#include <exception>

struct JobNotFind : std::exception
{
};

class JobQueue
{
public:
	size_t Size();
	Job& FindJob(int nId);
	Job GetNextJob();

	void AddJob(const Job& rJob);
	void RemoveJob(int nId);
	void UpdateStatus(int nId, eStatusType nNewStatus);

private:
	std::deque<Job> m_dequeJobs;
};

#endif // !JOBQUEUE_HPP
