**Chapter 7 - Basic Types**

* *The sizeof operator*

    - The *sizeof* operator allows a program to determine how much memory
    is required to store values of a particular type

    - The value of the expression
                *sizeof* ( *type-name* )
    is an unsigned integer representing the number of ***bytes*** required
    to store a value.
    
    - type of sizeof expression is implimentation-defined type called
    *size_t*, which is guaranteed to be an unsigned integer type. It
    is safest to cast a *sizeof* expression to *unsigned long* and
    print it with the %lu conversion.

