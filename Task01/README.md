Nanditha S 192412467 
Task 1: Identify the inputs, outputs, constants, rules, and assumptions of the electricity billing problem.
# Task 1 — Understand the Problem and Identify the Data

## 1. Problem Analysis

The electricity billing system must calculate accurate bills for households. The existing spreadsheet produces errors due to floating-point rounding, meter rollover, and tariff values repeated in multiple places. The solution must calculate bills exactly to the nearest paise and support up to 800,000 households.

## 2. Inputs and Outputs

| Data item | Description and justification |
| --- | --- |
| Previous reading | Earlier meter value, needed to calculate consumption. |
| Current reading | Latest meter value, needed to calculate consumption. |
| Household number | Identifies each customer uniquely; must support a large number of households. |
| Category | Identifies the applicable tariff category. |
| Units consumed | Difference between readings, adjusted for meter rollover. |
| Energy charge | Cost calculated from units and tariff rates. |
| Fixed charge | Constant fee charged to the household. |
| Total bill | Sum of energy charge and fixed charge, stored in paise. |

## 3. Constants

Values that remain unchanged during a program run should be defined centrally:

- Maximum meter reading: 65535.
- Meter range: 0–65535.
- First slab limit: 100 units.
- Second slab limit: 200 units.
- Rate for the first slab: 0 paise per unit.
- Rate for the second slab: 225 paise per unit.
- Rate above 200 units: 450 paise per unit.
- Fixed charge: 5000 paise.

Centralized constants allow tariff revisions to be made in one place, reducing inconsistent calculations.

## 4. Negative, Fractional and Large Values

- **Negative values:** Meter readings and consumption cannot be negative. A negative difference caused by rollover must be handled correctly. A bill must never be negative.
- **Fractional values:** Money may contain fractional rupees, such as ₹162.50. Store it as integer paise (16250) to avoid floating-point rounding errors.
- **Large values:** Household numbers, total readings, and accumulated revenue may become large when processing 800,000 households. Suitable integer types must be selected to prevent overflow.

## 5. Rules for a Correct Bill

1. Units consumed must be calculated correctly, including meter rollover.
2. The first 100 units are free.
3. Units 101–200 are charged at 225 paise per unit.
4. Units above 200 are charged at 450 paise per unit.
5. The fixed charge is 5000 paise.
6. Total bill = energy charge + fixed charge.
7. The total bill must be non-negative.
8. All monetary calculations must be accurate to the nearest paise.

## 6. Assumptions

- The meter is a 16-bit unsigned counter with values from 0 to 65535.
- At most one rollover occurs between consecutive readings.
- The tariff slabs are cumulative.
- The fixed charge applies to every household.
- Tariff rates remain constant during a single program run.
- Each household has a unique identification number.

## 7. Alternative Concept: Text Versus Integer Readings

A meter reading could be stored as a character string, such as "01530", instead of an integer such as 1530. The string preserves leading zeros, but it must be converted into an integer before arithmetic can be performed.

### Time Complexity

Let d represent the number of digits in a reading.

- **Text representation:** Converting a string to an integer takes O(d) time. Comparing two strings can take O(d) time in the worst case.
- **Integer representation:** Comparing integer readings takes O(1) time. Subtraction and rollover arithmetic also take O(1) time for a fixed-width integer type.

### Space Complexity

- **Text representation:** A reading with d digits typically requires d + 1 bytes, including the null terminator.
- **Integer representation:** A fixed-width integer requires a constant amount of memory, O(1), regardless of the number of digits represented within its range.

Integer representation is more suitable for this billing system because it simplifies arithmetic, uses fixed memory, and avoids repeated text conversion.

## Conclusion

The billing system should use appropriate integer types for meter readings and store money as integer paise. Centralized tariff constants, correct rollover handling, and validation rules ensure accurate bills and support future expansion to district-level processing.
