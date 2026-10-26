# Task 2 — Choose the Data Types

**Name:** Nanditha S  
**Register Number:** 192412467

## 1. Data Type Selection

| Data item | C data type | Reason |
| --- | --- | --- |
| Previous reading | `meter_t` (`unsigned short`) | Stores a 16-bit meter reading from 0 to 65535 on the target system. |
| Current reading | `meter_t` (`unsigned short`) | Uses the same range as the previous reading. |
| Household number | `unsigned int` | Can represent at least 800,000 household IDs on standard-conforming systems. |
| Category | `char` or `enum` | Represents a category code or named tariff category. |
| Units consumed | `unsigned int` | Stores non-negative consumption values, including rollover. |
| Energy charge | `long` | Stores monetary amounts in paise, subject to range checks. |
| Fixed charge | `long` | Stores the fixed fee as integer paise. |
| Total bill | `long` | Adds the energy and fixed charges without floating-point rounding. |
| Total district revenue | `long long` | Provides a wider integer range for accumulated revenue. |

## 2. Sizes and Ranges

The exact sizes depend on the compiler and system. Use `sizeof`, `limits.h`, and `float.h` to check them.

| Type | Typical size | Range or precision |
|---|---:|---|
| `char` | 1 byte | At least −127 to 127 if signed |
| `short` | 2 bytes | At least −32767 to 32767 |
| `unsigned short` | 2 bytes | 0 to 65535 on a 16-bit implementation |
| `int` | 4 bytes | At least −32767 to 32767 |
| `unsigned int` | 4 bytes | At least 0 to 65535 |
| `long` | 4 or 8 bytes | At least −2147483647 to 2147483647 |
| `long long` | 8 bytes | At least −9223372036854775807 to 9223372036854775807 |
| `float` | Usually 4 bytes | About 6–7 decimal digits of precision |
| `double` | Usually 8 bytes | About 15–16 decimal digits of precision |

A district may contain 800,000 households, so a 16-bit signed `short` is insufficient for household IDs. An `unsigned int` is suitable for IDs on conforming implementations because its minimum guaranteed maximum is 65535? **Correction:** C guarantees only 65535 for `unsigned int`, so the actual implementation must be checked. A typical 32-bit `unsigned int` supports up to 4294967295, which is sufficient for 800,000 IDs.

The district revenue type must also be checked against the maximum possible accumulated bill.

## 3. Why Money Should Be Stored as Integer Paise

Floating-point types such as `float` cannot represent many decimal fractions exactly. Repeated additions can accumulate rounding errors.

For example, 4,000 bills of ₹0.10 should total exactly ₹400.00. With integer paise, each bill is 10 paise, and:

4000 × 10 = 40000 paise = ₹400.00.

Integer paise avoids binary floating-point rounding during addition. Before calculating, ensure the selected integer type cannot overflow.

## 4. Meter Rollover

The meter is a 16-bit unsigned counter with values from 0 to 65535. After 65535, it returns to 0.

For example:

- Previous reading = 65400
- Current reading = 120
- Units consumed = 256

The result is 256 because unsigned 16-bit arithmetic wraps modulo 65536. The calculation is:

120 − 65400 = −65280

−65280 modulo 65536 = 256.

The C program below uses a cast to `meter_t` to obtain this result without `if-else`.

## 5. Alternative: Storing Money as `double`

If money is stored as `double` rupees, the program can calculate the energy and fixed charges in rupees, then round the final amount to two decimal places for billing.

However, binary floating-point values may not represent decimal currency values exactly. Rounding should be applied at the appropriate billing boundary, and totals can still accumulate small errors.

- Integer paise: addition takes O(1) time and uses a fixed amount of memory.
- `double` rupees: addition also takes O(1) time and usually uses 8 bytes.
- Integer paise is preferred for exact currency calculations, provided overflow is prevented.

The exact rounding error from adding n bills depends on the values, order of addition, and floating-point implementation. It may accumulate or partially cancel.

## Conclusion

Use integer types for meter readings and money stored in paise. Select wider integer types for large totals, check actual type sizes and limits on the target compiler, and handle rollover with unsigned arithmetic. This reduces precision errors and improves reliability.
