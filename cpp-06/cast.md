# Typecasting in C++

Typecasting (or typeconversion) in C++ is the process of converting one data type to another. The values of objects are stored in memory as a sequence of bits, and the data type of an object instruct the compiler on how to interpret said bits into meaningful data.

It allows for flexible manipulation of data types.

Casting in C++ can be done explicitly and implicitely.

## Implicit type conversion

This type of casting, also called automatic type conversion or coercion, is performed automatically by the compiler when a specific type of data is expected, but another type is supplied, such as in the following example :

```c
#include <stdio.h>

int multiply(int x, int y) {
	return x * y;
}

int main(void) {
	double x = 5.0;
	double y = 10.0;

	// passing double to multiply expecting is an automatic type conversion
	printf("%d\n", multiply(x, y));
}

```

Here's the full list of cases in which coercion can happen:

- when initialising a variable with a value of a different type (such as `int i = 5.0`),
- when returning a value that differs from the return type,
- when using operands of different types with certain binary operators,
- when using a non boolean value in an if-statement,
- when passing an argument to a function expecting a different type,

Please note that implicit type conversion can result in data loss. It is sometime intended, but it can lead to discreet and very annoying bugs. In C++, implicit conversion can also bypass some safety mechanisms, leading to an increased risk of errors; finally, using unnecessary type conversion may lead to poorer performance due to extra data copying.

Always think twice before using implicit type conversion, prefer explicit casts to make your intent clear !

## Explicit type conversion

This type of casting is perfomed manually by the developper. In C++, you may cast as you would in C, (`(int)double`), but the language also implements **four** casting operators (called *named cast operators*) with the following syntax :

```cpp
	type_cast<data_type>(x)
```

The operators are as follows:

- `static_cast`, commonly used for converting between related types (ie. `int` and `double`). It can also be used to upcast and downcast within inheritance hierarchies, if certainty exists. It the safest cast, as it performs compile-time checking for correctness; it also does not incur runtime overhead
- `dynamic_cast`, used for safe [downcasting](#downcasting) in inheritance hierarchies for polymorphic classes.
- `const_cast` is used to add or remove the [const](#const) or [volatile](#volatile) qualifier from variables. It should be used with caution, as dereferencing a true `const` object leads to undefined behavior.
  - `const_cast` is mostly used when interfacing with legacy code or APIs that don't use const appropriately.
- `reinterpret_cast` is used when low level conversions are needed (ie, when interfacing with hardware and generally in low-level programming.) It is a powerful (and hence, dangerous) tool that can convert pointers to incompatible types, allowing type punning (ie. allowing binary values to be interpreted as a different type), allowing access to underlying byte representation. Incorrect usage of reinterpret casting can lead to undefined behaviors, since it allows the binary representation of a type to be interpreted as another without checking for compatibility. 
	- it is used in [data serialization](#data-serialization).

As often in C++, those cast operators were created to insure more safety than the typical C operation. In a way, reinterpret casting is the closest thing to C-type casting; the other three types were created to limit that use to the cases where it is truly needed, providing safer alternatives for regular uses. 

## Upcasting and downcasting

Upcasting and downcasting are operation performed in the context of inheritance.

### Upcasting

_see also generalization or widening conversion_

The process of converting a reference of a child class to a reference of its parent class.

- It's implicitly performed by the compiler
- It's always safe (the child object is guaranteed to have all the properties of its parent).
- It allows access to the parent class members but limits access to child-specific members

### Downcasting

_see also, specialization or narrowing conversion_

The process of converting a reference of a superclass to a reference of its subclass.

- It must be done explicitly using casting operators,
- It can be unsafe and may lead to runtime errors if not performed correctly,
- It allows access to both parent and child class members.

## Const & volatiles qualifiers

### const

The const qualifier indicates that a variable's value cannot be changed after initialization.

- Once initialized, a const variable cannot be modified.
- Attempts to modify const variables result in compilation errors.
- Compilers can optimize code using const variables, potentially improving performance.

| Aspect        | const                      | volatile                             |
| ------------- | -------------------------- | ------------------------------------ |
| Purpose       | Prevent modification       | Ensure memory access                 |
| Optimization  | Allows optimization        | Prevents certain optimizations       |
| Use case      | Constants, immutable data  | Hardware registers, shared variables |
| Thread safety | Not inherently thread-safe | Provides some thread visibility      |

### volatile

The volatile qualifier tells the compiler:

- that a variable's value may change unexpectedly, outside the normal flow of the program (ie. that the variable might be modified by code that is not near it.).
- to not optimize the variable.

It is often used in embedded systems where everything is quite critical. More [here](https://www.embedded.com/introduction-to-the-volatile-keyword/).

- Every read or write to a volatile variable is done directly from/to memory, not from CPU cache.
- Compiler optimizations that might affect the variable's value are prevented.
- In multi-threaded environments, changes to volatile variables are immediately visible to all threads.

## Data serialization (and deserialization)
Data serialization is defined as the process of converting complex data objects in simpler byte sequences in order to preserve their structure and value in an easily storable and transmittable format. Deserialization, as expected, is described as the reverse process. 

Data serialization result in serialized data, pretty straighforwardly. Serialized data is usually stored in convetionnal format (ie, JSON, XML).

Data serialization is pretty important for the following reasons :
- Most importantly, it saves the data in a way that allows it to be recreated later, even in a different environments.
- Allows optimal and efficient data storage, especially when working on large scale objects.
	- As a result, data transfer is faster and suffers less latency.
- Allows interoperability and seamless data exhanges across services, networks and application, in a way that makes sense for each of those.
	- This also permits more flexibility and independance as serialized data can be shared between different languages and platforms.

More about [data serialization](https://www.confluent.io/learn/data-serialization/) and also on [Wikipedia](https://en.wikipedia.org/wiki/Serialization).
