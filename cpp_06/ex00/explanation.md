### ✅ **CHARACTER INPUTS**

| Test  | Explanation                                                                                                   |
| ----- | ------------------------------------------------------------------------------------------------------------- |
| `"a"` | A printable ASCII character. Its ASCII code is 97. Can convert to int, float, double, and show `'a'` as char. |
| `"Z"` | Same: printable character, ASCII code 90. Output includes `'Z'`.                                              |
| `"!"` | Also printable, ASCII 33. All conversions valid.                                                              |

---

### ✅ **INTEGER INPUTS**

| Test     | Explanation                                                                                    |
| -------- | ---------------------------------------------------------------------------------------------- |
| `"0"`    | It's a number. Displayable as all types. Char is ASCII 0 = not printable → `"Non displayable"` |
| `"42"`   | A printable int. ASCII 42 = `'*'`.                                                             |
| `"-42"`  | A negative number. Cannot be converted to char (ASCII doesn’t allow negative) → `"impossible"` |
| `"+123"` | Same as 123. Printable char: ASCII 123 = `'{'`                                                 |

---

### ✅ **FLOAT LITERALS (ending with `f`)**

| Test      | Explanation                                                                                                                  |
| --------- | ---------------------------------------------------------------------------------------------------------------------------- |
| `"4.2f"`  | Valid float. Can convert to int (4), float (4.2f), double (4.2), char is `Non displayable` because ASCII 4 is not printable. |
| `"-4.2f"` | Same, but negative → `char: impossible`                                                                                      |
| `"+0.0f"` | Equivalent to 0 → `char: Non displayable`                                                                                    |
| `".5f"`   | Small float → `int: 0`, rest valid, char = not printable                                                                     |
| `"+.1f"`  | Also valid small float                                                                                                       |
| `"1.f"`   | Float with no digits after decimal — valid. Everything converts cleanly.                                                     |

---

### ✅ **DOUBLE LITERALS (no `f`)**

| Test     | Explanation                                    |
| -------- | ---------------------------------------------- |
| `"4.2"`  | Valid double. Same logic as float.             |
| `"-4.2"` | Negative → char = impossible                   |
| `"0.0"`  | Same as 0                                      |
| `".2"`   | Small double, all conversions fine except char |
| `"1."`   | 1 with implied decimal → works fine            |
| `"+.3"`  | Positive decimal, all outputs fine             |

---

### ✅ **PSEUDO-LITERALS**

| Test                           | Explanation                                                                         |
| ------------------------------ | ----------------------------------------------------------------------------------- |
| `"nan"`                        | Not a number. Can’t convert to int or char. `"nanf"`/`"nan"` used for float/double. |
| `"+inf"`, `"-inf"`             | Infinite values. `float: impossible` because `float` cast throws or loses meaning.  |
| `"nanf"`, `"+inff"`, `"-inff"` | Same as above, but explicitly typed as float. You handled them correctly.           |

---

### ❌ **INVALID INPUTS**

| Test                      | Why it's invalid                            |
| ------------------------- | ------------------------------------------- |
| `""`                      | Empty string → caught by validator          |
| `"abc"`                   | Not a number, not a char → invalid          |
| `"42abc"`, `"4.2ff"`      | Invalid suffixes                            |
| `"--42"`                  | Double negative → invalid syntax            |
| `"4.2.2"`                 | Multiple dots → invalid number              |
| `"999999999999999999999"` | Too big → causes overflow during conversion |

---

### ✅ **ASCII EDGE CASES FOR CHAR**

| Test    | Explanation                                              |
| ------- | -------------------------------------------------------- |
| `"31"`  | ASCII control char → not printable → `"Non displayable"` |
| `"32"`  | First printable char → `' '` (space)                     |
| `"126"` | ASCII `'~'`                                              |
| `"127"` | ASCII `DEL` → not printable                              |
| `"128"` | Beyond ASCII range → `"char: impossible"`                |

---

### ✅ **INT LIMITS**

| Test            | Explanation                                                                     |
| --------------- | ------------------------------------------------------------------------------- |
| `"2147483647"`  | Max 32-bit int. Float cannot represent it exactly → shows `"approx"`            |
| `"-2147483648"` | Min 32-bit int. **Can** be represented exactly in float → no `"approx"` needed. |

---

### ❌ **NON-PRINTABLE CHARACTER TEST**

| Test                 | Explanation                                                                                                                               |
| -------------------- | ----------------------------------------------------------------------------------------------------------------------------------------- |
| `""` (a second time) | This one likely came from trying to pass `"\x01"` or an empty `std::string(1, '\x01')`. Correctly rejected as `"non-printable character"` |
