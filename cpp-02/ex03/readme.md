# General ressources & definitions

- [Determine if a point is inside a triangle](https://www.youtube.com/watch?v=kkucCUlyIUE) (french | video)
- [The Coplien canonical class](https://eric.univ-lyon2.fr/ricco/cours/cours/au_coeur_de_la_prg_objet_cpp.pdf) (french)

# The Coplien canonical class

The Coplien canonical form is standard to respect when creating classes. For a class to be canonical, the following methods must be defined : 

```cpp
	class Class
		public:
			Class(void); // default constructor
			// or :
			Class(int i = 3); // default constructor
			Class(const Class&); // copy constuctor
			~Class(void); // destructor
			Class &operator=(const T&); // assignement operator
```

## The default constructor
The default constructor takes no arguments or for which each arguments has a default value.
Default constructors allow the user to eliminate unexpected behaviors ; in the absence of a default constructor, compilers will attempt to provide one. Depending on the environement, the values within the class will be initialized to 0 or left empty ; I'm sure you can see how that could be an issue. 

## Copy constructor
