# CIS-165 Lab 8

**Name:** Theo Douma  
**Section:** CIS-165-W099

## Initial Plans
**geometry.cpp:** I will define a constant `PI` set to `3.14159`, display the 4-option Geometry Calculator menu, and read the user's choice into an `int` variable. Using an `if-else if` structure, I will route the choice to prompt for the required `double` dimensions (`radius`, `length` and `width`, or `base` and `height`), check that no entered dimension is negative (`< 0.0`), calculate the `area` into a variable first, and print the labeled result. If the user selects 4, the program will quit immediately; if they enter a number outside 1–4, it will print an invalid choice error.

## Run Instructions
1. Go to onlinegdb.com and select **C++ 17** as the language.
2. Paste the code from `geometry.cpp` into the editor.
3. Click "Run" at the top, enter the menu choice and dimensions when prompted, and verify the output.

## Test Table
*(Note: Display precision uses default `cout` formatting.)*

| Program | Values used | Expected result | Actual output | Match |
| ----- | ----- | ----- | ----- | ----- |
| geometry.cpp (circle) | Choice 1, radius 2 | 12.5664 (from 12.56636) | Area of the circle: 12.5664 | Yes |
| geometry.cpp (rectangle) | Choice 2, length 3, width 4.5 | 13.5 | Area of the rectangle: 13.5 | Yes |
| geometry.cpp (triangle) | Choice 3, base 5, height 3 | 7.5 | Area of the triangle: 7.5 | Yes |
| geometry.cpp (quit) | Choice 4 | Ends without prompts or calculation | Program ending. | Yes |
| geometry.cpp (invalid low) | Choice 0 | Invalid-choice error | Error: Invalid choice. Please run the program again and enter a number from 1 to 4. | Yes |
| geometry.cpp (invalid high) | Choice 5 | Invalid-choice error | Error: Invalid choice. Please run the program again and enter a number from 1 to 4. | Yes |
| geometry.cpp (neg. radius) | Choice 1, radius -1 | Negative radius error | Error: Radius cannot be negative. | Yes |
| geometry.cpp (neg. length) | Choice 2, length -1, width 5 | Negative dimension error | Error: Length and width cannot be negative. | Yes |
| geometry.cpp (neg. width) | Choice 2, length 5, width -1 | Negative dimension error | Error: Length and width cannot be negative. | Yes |
| geometry.cpp (neg. base) | Choice 3, base -1, height 5 | Negative dimension error | Error: Base and height cannot be negative. | Yes |
| geometry.cpp (neg. height) | Choice 3, base 5, height -1 | Negative dimension error | Error: Base and height cannot be negative. | Yes |
| geometry.cpp (zero radius) | Choice 1, radius 0 | 0 | Area of the circle: 0 | Yes |
| geometry.cpp (additional valid) | Choice 2, length 10, width 2.5 | 25 | Area of the rectangle: 25 | Yes |

**Additional Test & Final Check Notes:**
* **Additional valid calculation:** Tested Choice 2 with `length = 10` and `width = 2.5` to verify that mixing an integer input with a decimal input in rectangle calculation accurately outputs `25`.
* **Final source check:** No temporary code changes were needed for testing because all test cases were entered via standard input (`cin`). The final `geometry.cpp` file was compiled and run again before the final commit.

## Explanations
* **Selection logic:** My `if / else if / else` statement checks the integer `choice` variable against `1`, `2`, `3`, and `4` in order. When a condition evaluates to true, only that specific block executes to prompt for that shape's dimensions and calculate its area, while the trailing `else` catches any numeric input outside 1 through 4.
* **Why `radius * radius` instead of `radius ^ 2`:** In C++, the `^` symbol is the bitwise XOR operator, not an exponent operator (and doesn't even work on `double` types). Multiplying `radius * radius` properly squares the floating-point value.
* **Why `0.5` instead of `1 / 2`:** In C++, `1 / 2` divides two integer literals, which performs integer division and truncates the decimal to `0`, making the triangle's area always `0`. Using `0.5` forces floating-point multiplication so the half value is preserved.
* **Checking negative dimensions, zero, and choice 4:** Immediately after reading the dimensions inside choices 1, 2, and 3, an `if` check tests whether any dimension is `< 0.0` (e.g., `base < 0.0 || height < 0.0`). Because the condition only rejects values strictly less than zero, `0` passes into the `else` branch and calculates an area of `0`. Choice 4 has its own `else if (choice == 4)` branch that prints a closing message and finishes `main` without prompting for any numbers.
