# Modern C++ Bootcamp

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
* **Lambdas:** Writing anonymous functions for concise, in-place logic.
* **Capture Clauses:** Mastering capture by value `[=]` vs. capture by reference `[&]`.
* **std::ranges (C++20):** Operating on entire containers instead of iterator pairs.
* **Projections:** Simplifying algorithms with member pointers (e.g., `&Student::grade`). (Todo)
* **Data Sanitization:** Robust string-to-number conversion using `try-catch` and `std::stod`.

### Assignment: The String Sanitizer & Stats
* **Filter & Convert:** Transform a `std::vector<std::string>` (with "ERROR" noise) into a clean `std::vector<double>`.
* **Clamping:** Use `std::ranges::replace_if` to cap values at 100.0.
* **Outlier Removal:** Use C++20 `std::erase_if` to strip values below 10.0.
* **Reduction:** Calculate the dataset average using `std::accumulate`.

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