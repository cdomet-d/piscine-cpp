# Templates in C++98

Templates in C++98 (and subsequent versions) are snippets of codes that enables generic programming, meaning that you can do a lot with just one "model" function.

You can make make:

- function templates,
- class templates,
- member functions templates.

Some templates can be specialized with multiple arguments or default arguments.

The syntax is as follows:

# Template syntax

## Function Templates

```cpp
	template <typename T>

	// T stands for a given datatype (int, double...)

	T max(T x, T y) {
		return (x > y) ? x : y;
	}
```

`max(x, y)` can now be used for any datatype that will support the operation made by the function, provided that you cast it when using:

```cpp
	int res = max<int>(10, 8);
```

## Class Templates

Class templates allow the user to create a class that can work with different datatypes. A prime example of this is `std::vector`, that can be with any datatypes:

```cpp
	template <class T>

	class vector
	{
		public:
			void push_back(const T& x);
			T& at(size_t index);

		private:
			T* array;
			size_t size;
			// etc...
	}
```

Once that's done, one can initialize any type of vector:

```cpp
	vector<int> iVec;
	vector<double> dVec;
	vector<std::string> sVec;
	vector<vector<std::string>> 2dSVec;
	// etc...
```

## Multiple arguments Templates

It is possible to declate templates with multiple arguments, be it class templates or function templates. The syntax is as follows :

```cpp
	template <class T, class U>

	class A 
	{
	public:
		A()
		~A()
	private:
		T x;
		U y;
};
```
## Default arguments

When creating a template for which a case is most common, it's possible to declare a default argument:

```cpp
	template <typename T = int>

	// T stands for a given datatype (int, double...)

	T max(T x, T y) {
		return (x > y) ? x : y;
	}
```

That way, passing arguments to the functions will be by default treated as intergers, while still allowing the user to specify another type should the need arise.

# Great! But what happens at compiler level when using templates ? 
