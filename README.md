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

## 🏆 The Day 5 Challenge: "The Real-Time Analytics Engine"

### 📜 The Scenario
You are building a high-performance system for a stock trading platform. The system receives a stream of "Price Updates" (Strings) that are often messy. You need to sanitize them, calculate statistics, and notify a set of specialized **"Alert Bots"** (Subscribers) about the new average price—all while ensuring the system doesn't crash or leak memory.

---

### 🏗 The Architecture Requirements

#### 1. Data Sanitization (Day 2)
* **Input:** Start with a `std::vector<std::string>` of raw price data (e.g., `"150.50"`, `"ERROR"`, `"200.00"`, `"9999.99"`).
* **Process:** Use **Ranges** and **Lambdas** to:
    * Convert strings to `double` using `try-catch` and `std::stod`.
    * Clamp outliers (e.g., cap everything at `5000.0`).
    * Remove invalid entries or "zero" values using `std::erase_if`.

#### 2. Smart Ownership (Day 1 & 3)
* **Lifecycle:** Store your `AlertBot` objects in `main` using `std::shared_ptr`.
* **Observation:** The `AnalyticsEngine` (Publisher) must store these bots as `std::weak_ptr`. 
* **Goal:** Ensure that if a bot is disconnected (destroyed), the engine doesn't keep it alive or crash when trying to reach it.

#### 3. Threaded Execution (Day 4)
* **Parallelism:** When a new batch of data is processed, the `AnalyticsEngine` must notify all bots in parallel using `std::jthread`.
* **Feedback:** Each bot should print its unique ID and the new calculated average.

#### 4. The "Safety" Twist
* **Console Integrity:** Use a `static inline std::mutex` in the `AlertBot` class to ensure console output isn't scrambled.
* **Atomic Accounting:** Use a `std::atomic<int>` to count exactly how many bots successfully logged the update across all threads.
* **The Killer Feature:** One of your bots must be "temporary" (created in a small `{}` scope in `main`). Prove that your engine handles its sudden "death" mid-run by using the `.lock()` pattern safely.

---

### 🧪 Expected Output Example
```text
[Engine]: Processing 5 new price signals...
[Engine]: Sanitization complete. New Market Average: 175.25
[Bot 1] Received Update: 175.25
[Bot 2] Received Update: 175.25
[Engine]: Successfully notified 2 active bots. (1 bot was found to be expired).

---

## 🛠 Tech Stack
* **Language:** C++20 / C++23
* **Compiler:** GCC 11+ / Clang 13+ / MSVC 19.29+
* **Build System:** CMake 3.20+