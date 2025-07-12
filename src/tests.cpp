#include "Job.hpp"
#include "JobQueue.hpp"
#include <gtest/gtest.h>

TEST(JobTest, SequenceNumberIncrements)
{
    Job job1(1, "Job1", ePriorityType::PT_LOW);
    Job job2(2, "Job2", ePriorityType::PT_MEDIUM);

    EXPECT_LT(job1.GetSequenceNumber(), job2.GetSequenceNumber());
}

TEST(JobTest, DefaultConstructorInitializesCorrectly)
{
    Job job;
    EXPECT_EQ(job.GetId(), -1);
    EXPECT_EQ(job.GetName(), "");
    EXPECT_EQ(job.GetPriority(), ePriorityType::PT_LOW);
    EXPECT_EQ(job.GetStatus(), eStatusType::ST_PENDING);
}

TEST(JobTest, SetStatusChangesStatus)
{
    Job job(1, "Example", ePriorityType::PT_HIGH);
    job.SetStatus(eStatusType::ST_RUNNING);

    EXPECT_EQ(job.GetStatus(), eStatusType::ST_RUNNING);
}

TEST(JobQueueTest, AddAndSize)
{
    JobQueue queue;
    EXPECT_EQ(queue.Size(), 0u);

    queue.AddJob(Job(1, "Task1", ePriorityType::PT_LOW));
    queue.AddJob(Job(2, "Task2", ePriorityType::PT_HIGH));

    EXPECT_EQ(queue.Size(), 2u);
}

TEST(JobQueueTest, RemoveJob)
{
    JobQueue queue;
    queue.AddJob(Job(1, "Task", ePriorityType::PT_LOW));
    queue.RemoveJob(1);

    EXPECT_EQ(queue.Size(), 0u);
}

TEST(JobQueueTest, RemoveJobNonExistingDoesNothing)
{
    JobQueue queue;
    queue.AddJob(Job(1, "Task", ePriorityType::PT_LOW));
    queue.RemoveJob(999);  // Nie istnieje

    EXPECT_EQ(queue.Size(), 1u);
}

TEST(JobQueueTest, UpdateStatus)
{
    JobQueue queue;
    queue.AddJob(Job(1, "UpdateTest", ePriorityType::PT_MEDIUM));
    queue.UpdateStatus(1, eStatusType::ST_COMPLETED);

    Job& job = queue.FindJob(1);
    EXPECT_EQ(job.GetStatus(), eStatusType::ST_COMPLETED);
}

TEST(JobQueueTest, FindJobThrowsWhenNotFound)
{
    JobQueue queue;

    EXPECT_THROW(queue.FindJob(999), JobNotFind);
}

TEST(JobQueueTest, GetNextJobReturnsHighestPriority)
{
    JobQueue queue;
    queue.AddJob(Job(1, "Low", ePriorityType::PT_LOW));
    queue.AddJob(Job(2, "Medium", ePriorityType::PT_MEDIUM));
    queue.AddJob(Job(3, "High", ePriorityType::PT_HIGH));

    Job next = queue.GetNextJob();
    EXPECT_EQ(next.GetId(), 3);  // High
}

TEST(JobQueueTest, GetNextJobSamePriorityReturnsOldest)
{
    JobQueue queue;
    Job job1(1, "First", ePriorityType::PT_MEDIUM);
    Job job2(2, "Second", ePriorityType::PT_MEDIUM);
    queue.AddJob(job2); // Dodany póŸniej
    queue.AddJob(job1); // Dodany wczeœniej, ale mniejszy sequence

    Job next = queue.GetNextJob();
    EXPECT_EQ(next.GetId(), job1.GetId());
}
