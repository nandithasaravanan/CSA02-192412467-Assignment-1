**Name**:Nanditha S **Reg.no.**:192412467
# Task 03 – Define the Constants

## 1. Objective
To define electricity tariff values and limits as constants so that tariff revisions can be made easily in one place.

## 2. Analysis of Constants

### `#define`, `const`, and `enum`

- **`#define`:** Defines symbolic constants through the C preprocessor. It is suitable for fixed tariff values and slab limits.
- **`const`:** Declares a variable whose value cannot be modified after initialization. It supports type checking and scope rules.
- **`enum`:** Defines named integer constants. It is suitable for related integral values, such as status codes or menu options.

### Difference Between `#define` and `const`

| Feature | `#define` | `const` |
| --- | --- | --- |
| Type checking | No type checking | Supports type checking |
| Scope | No normal C block scope; applies from its definition until `#undef` or the end of the source file | Follows C variable scope rules |
| Debugging | May not appear as a variable in the debugger | Can be visible in the debugger |
| Memory | Does not itself allocate storage | May require storage, depending on usage and compiler |
| Modification | Replacing the macro definition changes its value | Cannot be modified through the const-qualified object |

## 3. Naming Conventions
Constants are written in uppercase letters, with words separated by underscores. For example, `SLAB1_UNITS`, `RATE2_PAISE`, and `FIXED_CHARGE_PAISE`. Meaningful names improve readability and maintainability.

## 4. Tariff Calculation
The program uses the following tariff structure:

- First 100 units: free.
- Units 101–200: 225 paise per unit.
- Units above 200: 450 paise per unit.
- Fixed charge: 5000 paise (₹50).

The bill is calculated in paise to avoid floating-point rounding errors. The program adds charges for each slab using the defined macros.

## 5. Effect of Changing the Tariff
When `RATE2_PAISE` changes from 225 to 230, the revised rate is applied wherever that macro is used. This avoids manually changing multiple calculations.

For the given test inputs, the bills become:

| Units | Original bill (₹) | Revised bill (₹) |
| --- | --- | --- |
| 0 | 50.00 | 50.00 |
| 100 | 50.00 | 50.00 |
| 150 | 162.50 | 165.00 |
| 200 | 275.00 | 280.00 |
| 350 | 950.00 | 960.00 |

## 6. Alternative Concept and Complexity Analysis
Using `const` variables instead of `#define` provides type checking and normal scope rules. An `enum` is appropriate for named integer constants but is less suitable for expressing tariff values with different units or types.

For this program, `#define` is a reasonable choice because the tariff values are fixed compile-time constants and the faculty-provided code already uses macros. Macros themselves do not allocate storage, whereas a `const` object may require storage depending on how it is used and compiled.

Changing the constant type does not inherently change the algorithm's running time. The program processes a fixed number of test cases, so its overall time complexity is **O(1)** for this fixed test array.

## 7. Result
The electricity billing program calculates bills using named tariff constants. Changing `RATE2_PAISE` in one place updates the relevant slab calculations consistently.
