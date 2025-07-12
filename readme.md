# JobQueue

## Overview

`JobQueue` is a lightweight C++ library implementing a prioritized job queue system.  
It manages tasks (`Job`) with unique IDs, priorities, statuses, and sequence numbers, allowing adding, removing, updating, and retrieving jobs according to priority and insertion order.

---

## Features

- **Job** class with:
  - Unique ID
  - Name
  - Priority levels (`LOW`, `MEDIUM`, `HIGH`)
  - Status states (`PENDING`, `RUNNING`, `COMPLETED`, `CANCELLED`)
  - Auto-incremented sequence number for ordering

- **JobQueue** class supporting:
  - Adding jobs
  - Removing jobs by ID
  - Updating job status by ID
  - Retrieving the next job with highest priority, breaking ties by earliest sequence number
  - Finding jobs by ID (throws exception if not found)

---

## Technologies Used

- Modern **C++** (C++11 and above)
- **CMake** for building and managing the project
- **GoogleTest** for unit testing

---

## Building the Project

### Prerequisites

- C++ compiler supporting C++11 or newer (e.g., GCC, Clang, MSVC)
- CMake 3.10 or higher
- GoogleTest (can be fetched automatically via CMake)

### Steps

```bash
git clone <repo-url>
cd JobQueue
mkdir build && cd build
cmake ..
cmake --build .
ctest
