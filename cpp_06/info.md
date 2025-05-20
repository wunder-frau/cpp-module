# 🧾 **C++ Casts Cheat Sheet**

| Cast Type             | Use Case / Purpose                          | Works With          | Throws?           | Safe?                                 | Typical Use Cases |
| --------------------- | ------------------------------------------- | ------------------- | ----------------- | ------------------------------------- | ----------------- |
| 🔹 `static_cast`      | Compile-time type conversion                | Related types       | ❌ No             | ✅ Yes (if types are compatible)      |                   |
| 🔹 `dynamic_cast`     | Safe downcasting in polymorphism            | Class hierarchies   | ⚠️ Yes (for refs) | ✅ Runtime-checked                    |                   |
| 🔹 `const_cast`       | Add/remove `const` or `volatile` qualifiers | Same types          | ❌ No             | ⚠️ Risky (if used incorrectly)        |                   |
| 🔹 `reinterpret_cast` | Bitwise reinterpretation of memory          | Any pointer/integer | ❌ No             | ❌ Unsafe (very low-level, dangerous) |                   |

---

## 🔍 `static_cast`

- **Most commonly used**
- Converts between types **at compile-time**
- Used for numeric conversions, upcasting, explicit constructors

```cpp
double d = 3.14;
int i = static_cast<int>(d);  // 3

Base* b = static_cast<Base*>(derivedPtr);  // Upcast
```

✅ Use when types are **known to be safely convertible**

---

## 🔍 `dynamic_cast`

- Used for **downcasting** (Base → Derived) in polymorphic class hierarchies
- Requires the base class to have a **virtual function** (like a virtual destructor)
- Returns:

  - `nullptr` on failure (when using pointers)
  - **Throws** `std::bad_cast` on failure (when using references)

```cpp
Base* b = new Derived();
Derived* d = dynamic_cast<Derived*>(b);  // returns nullptr if wrong
```

✅ Use to safely check object type at **runtime**

---

## 🔍 `const_cast`

- Adds or removes `const` or `volatile`
- Used to call non-const methods on const objects (⚠️ risky)
- ⚠️ **UB** if you modify a truly `const` object

```cpp
const int* ptr = getConstInt();
int* modifiable = const_cast<int*>(ptr);  // ⚠️ don't write to it unless you're sure
```

🚫 Avoid unless you **know the object wasn't originally const**

---

## 🔍 `reinterpret_cast`

- Reinterprets memory layout of one type as another
- Used for **low-level hacks**, pointer-to-int, int-to-pointer, etc.

```cpp
int* p = new int(42);
char* bytes = reinterpret_cast<char*>(p);
```

⚠️ **Dangerous**: breaks type safety, may cause crashes or UB

---

## ✅ Summary: When to Use Each

| Scenario                     | Recommended Cast   |
| ---------------------------- | ------------------ |
| Converting `double` to `int` | `static_cast`      |
| Downcasting in inheritance   | `dynamic_cast`     |
| Temporarily removing `const` | `const_cast`       |
| Accessing raw memory         | `reinterpret_cast` |

---
