**Name:** Nanditha S   **Reg.no:**192412467
# Task 04 – Use Macros Safely

## 1. Objective
To implement macros for repeated calculations and analyse macro expansion, common pitfalls, and alternatives using static inline functions.

## 2. Preprocessor Expansion
Macros are processed by the C preprocessor before compilation. The preprocessor replaces each macro invocation with its corresponding expanded expression.

The command `gcc -E main.c` displays the preprocessed source code. For a shorter output, use:

`gcc -E -P main.c`

For example:

`SQUARE(a + 1)` expands to `((a + 1) * (a + 1))`.

The parentheses preserve the intended order of operations.

## 3. Why Parentheses Are Necessary
An unsafe macro such as `#define SQUARE(x) x*x` expands `SQUARE(a + 1)` into `a + 1*a + 1`. For `a = 4`, this evaluates to 9 instead of 25.

The corrected macro is:

`#define SQUARE(x) ((x) * (x))`

The outer parentheses protect the complete expression, while the inner parentheses protect the argument.

## 4. Repeated Evaluation in MAX
A macro such as `#define MAX(a, b) ((a) > (b) ? (a) : (b))` may evaluate an argument more than once.

For example, `MAX(i++, j)` can increment `i` twice if the first argument is selected, because `i++` appears in both the comparison and the selected result.

This can cause unexpected side effects. Passing expressions without side effects, or using a function, avoids this problem.

## 5. When a Function Is Better
A function is generally preferable when arguments have side effects, type checking is important, or the calculation is complex. A function evaluates each argument once and follows normal C language rules.

## 6. Static Inline Functions
The program uses `static inline` functions for square and maximum calculations. These functions provide type checking and avoid repeated evaluation of their parameters.

The compiler may inline a function or generate a normal function call; the `inline` keyword does not guarantee inlining.

## 7. Time and Space Complexity
Both the macro expressions and these simple functions perform a constant amount of work, so each calculation takes O(1) time.

A macro expands at each use, potentially increasing generated code size when used many times. A normal function can share one implementation, reducing duplicated code but introducing call overhead. An inline function may reduce call overhead, although its actual code generation depends on compiler decisions.

If a macro is used k times, its expanded code can be duplicated k times. The actual size depends on the expression and compiler optimisation.

## 8. Result
Fully parenthesised macros were implemented for rupees-to-paise conversion, squaring, and finding the maximum. The analysis demonstrates why unsafe macro definitions can produce incorrect results or repeated side effects, and explains when static inline functions are a safer alternative.
