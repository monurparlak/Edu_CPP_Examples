/*
Question #48
Difficulty: 2
Source: CPP Quiz

Question:
According to the C++23 standard, what is the output of this program?

My Answer:
✅ Output: Undefined Behavior (no guaranteed output)

Reason:
- `x` is a `std::string` in `main()`’s stack frame.
- Two `std::async` calls are launched with `std::launch::async`, meaning each lambda
  will execute in its own thread.
- Both lambdas capture `x` by reference and write to it concurrently without
  synchronization.
- Concurrent modification of a `std::string` without proper synchronization is a
  **data race**, which under the C++ memory model results in *undefined behavior*.
- Possible outcomes include:
  - `"x"` (if `std::cout` runs before either thread writes),
  - `"y"` or `"z"` (if one write finishes before print),
  - corrupted output, crash, or anything else.
- Additionally, neither `std::future` returned by `std::async` is stored or `.get()` called,
  so the main thread does not wait for the async tasks to finish before printing.
- This means the `std::cout << x;` in `main` may execute before, during, or after the writes.

If Wrong:
If you think `"x"`, `"y"`, or `"z"` is guaranteed, you are assuming a specific thread scheduling
and ignoring the C++ data race rules. The standard explicitly says the result of a data race
is undefined behavior.

Reference:
C++23 §6.9.2 [intro.multithread] — data races and undefined behavior
C++23 §33.10.5.1 [futures.async] — asynchronous task launch semantics
*/

#include <iostream>
#include <string>
#include <future>

int main() {
  std::string x = "x";

  std::async(std::launch::async, [&x]() {
    x = "y";
  });
  std::async(std::launch::async, [&x]() {
    x = "z";
  });

  std::cout << x;
}
