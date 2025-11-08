# Student Grading System (v0.2 / v0.25)

## Overview
This project is a continuation of version **v0.1**.  
It implements a student grading program that calculates final results based on homework and exam grades.  
Version **v0.2** adds code refactoring, exception handling, performance measurement, and automated test file generation.

---

## Features
### 🔹 Version v0.2
- Code reorganized into multiple `.h` and `.cpp` files.
- Added **exception handling** for file operations and data access.
- Added **random student data generator** to create large input files:
  - 10,000  
  - 100,000  
  - 1,000,000  
  - 10,000,000 records.
- Students are divided into:
  - **Failed** (<5.0)
  - **Passed** (≥5.0)
- Results are saved into two separate files:
  - `failed.txt`
  - `passed.txt`
- Program execution time is measured for:
  - File reading
  - Sorting
  - Splitting
  - Output writing

### 🔹 Version v0.25
- Same logic as v0.2 but using:
  - `std::list`
  - `std::deque`
- Performance comparison for:
  - `std::vector`
  - `std::list`
  - `std::deque`
