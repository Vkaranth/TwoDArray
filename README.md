Assignment-
Write classes  and  some main to test  it, that will implement a   two dimensional array of a parametric type (template) as follows:
a.	The classes may be instantiated for numeric or non-numeric type (e.g. Numeric2DArray<double>, NonNumeric2DArray<string>). 
b.	The class implementation will be  done by holding 2D  array (**data) and not by using vector<vector>> 
c.	The Numeric2DArray will also hold as member the max value that may be entered (an int). The class will verify all the time that the max value is not exceeded and will throw an exception if it is exceeded.
d.	The following constructors will be supported:
a.	Constructor that gets row size, column size and an optional value for all indices (default value is    0   for numeric types). The constructor of a    numeric type will also get an optional max value parameter (the default is 1000);
b.	Copy constructor assignment operators and destructors
c.	Constructor that gets 2D array (and sizes)
e.	Write << operator. – cout 
f.	Write +=  and + operators for the numeric matrix class
g.	Write prefix and postfix increment (x++  and  ++x) for the numeric matrix class (will add one to all indices)
h.	Operator (row, column) for accessing an item – use () operator to return item at row x and col y
i.	Operator == and !=. 
j.	Operator [][] to enable access using m[i][j]

