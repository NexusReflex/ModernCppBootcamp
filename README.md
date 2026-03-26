# 🚀 Modern C++ Bootcamp

This repository tracks the progression from "Classic C++" to **Modern C++ (C++20/23)**, focusing on safety, performance, and expressive syntax.

---

## 📅 Day 1: RAII & Resource Management
### Topics
* **The Problem with Raw Resources:** Managing file handles (`FILE*`) manually is error-prone and leads to leaks if a function returns early or throws an exception.
* **RAII (Resource Acquisition Is Initialization):** The core C++ philosophy where an object's constructor acquires a resource and its destructor releases it.
* **Deterministic Cleanup:** Understanding that in C++, the destructor is guaranteed to run the moment an object goes out of scope.

### Assignment: The SafeFile Wrapper
* Create a `SafeFile` class that encapsulates a `FILE*`.
* **Constructor:** Open the file using `fopen`.
* **Destructor:** Automatically close the file using `fclose`.
* **Member Functions:** Implement a `write()` method to wrap `fprintf` or `fputs` and a `write_formatted()` function that uses a `std::unique_ptr<char[]> buffer` to write a formatted string.
* **Goal:** Demonstrate that even if the program logic is complex, the file handle is never leaked.

---

## 📅 Day 2: Functional C++, Lambdas & Ranges
### Topics
* **Lambdas & Captures:** Writing anonymous functions with `[&]` and `[=]` for in-place logic.
* **Modern Algorithms:** Mastering `std::find_if`, `std::count_if`, and `std::copy_if` with `std::back_inserter`.
* **C++20 Ranges:** Transitioning from `.begin()/.end()` to passing entire containers to `std::ranges::sort`.
* **Exception Handling:** Using `try-catch` with `std::stod` to sanitize "dirty" string data.

### Assignment A: String Sanitizer & Statistics
* **Filter & Convert:** Use `std::for_each` and `std::stod` to extract numbers from messy log strings.
* **Data Processing:** Implement "Clamping" (capping values between 0 and 100) and outlier removal using `std::erase_if`.
* **Numeric Reduction:** Compute averages using `std::accumulate` (noting the importance of `0.0` to avoid integer truncation).

### Assignment B: Student Grade Processor
* **Advanced Sorting:** Sort custom `Student` structs in both ascending and descending order.
* **Searching:** Find the first "Top Student" (> 90.0) and extract a list of "Failed Students" (<= 50.0).
---

## 📅 Day 3: Shared Ownership & The Observer Pattern
### Topics
* **Shared Ownership:** Managing resources with `std::shared_ptr` reference counting.
* **Weak Observation:** Using `std::weak_ptr` to reference objects without extending their lifetime (preventing memory leaks from circular dependencies).
* **The "Lock" Pattern:** Safely converting `weak_ptr` to `shared_ptr` before access to ensure the object still exists.
* **Encapsulation:** Using `private` members and `const` getters to protect object integrity.
* **Virtual Destructors:** Ensuring safe cleanup in polymorphic class hierarchies.

### Assignment: The Priority Message Dispatcher
* **The Subscriber:** A base class with a `virtual` destructor and a `const` message handler.
* **The Publisher:** A system holding a `std::vector<std::weak_ptr<Subscriber>>`.
* **Priority Sorting:** Sorting subscribers via `std::ranges::sort` based on a priority integer.
* **Life-Cycle Test:** Verify that the Publisher automatically "skips" subscribers that have been destroyed in local scopes.

---

## 📅 Day 4: Concurrency & Thread Safety (Preview)
### Topics
* **Modern Threading:** Using `std::jthread` (C++20) for auto-joining background tasks.
* **Data Races:** Identifying why concurrent writes to shared resources (like `std::cout`) cause corruption.
* **Mutual Exclusion:** Protecting "Critical Sections" using `std::mutex` and `std::lock_guard`.
* **Atomics:** Thread-safe counters using `std::atomic<T>`.

### Assignment: The Parallel Dispatcher
* **Threaded Notification:** Update `Publisher` to notify each `Subscriber` on a separate thread.
* **Atomic Counters:** Track successful deliveries across threads with `std::atomic<int>`.
* **Mutex Protection:** Prevent console output "scrambling" during simultaneous subscriber updates.

---

## 🛠 Tech Stack
* **Language:** C++20 / C++23
* **Compiler:** GCC 11+ / Clang 13+ / MSVC 19.29+
* **Build System:** CMake 3.20+