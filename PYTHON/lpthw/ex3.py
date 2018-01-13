print("I will now count my chicken:")

print("Hens", 25 + 30 / 6) # 30.0py
print("Roosters", 100 - 25 * 3 % 4) # 97

print("Now I will count the eggs:")

print(3 + 2 + 1 - 5 + 4 % 2 -1 / 4 + 6) # 6.75

print("What is 3 + 2?", 3 + 2)
print("What is 5 - 7?", 5 - 7)

print("Oh, that's why it's False.")

print("How about some more.")

print("Is it greater?", 5 > -2) # True
print("Is it greater or equal?", 5 >= -2) # True
print("Is it less or equal?", 5 <= -2) # False

print(1 + 1)
print(1 * 2)
print(2 ** 2) # exponent
print(2 / 2)
print(2 // 3) # floor

# Arithmetic operators
# Comparison operators
# Logical operators
print(True and True)
print(True or False)
print(not True)

# Bitwise operators
'''
Operator	Meaning	Example
&	Bitwise AND	x& y = 0 (0000 0000)
|	Bitwise OR	x | y = 14 (0000 1110)
~	Bitwise NOT	~x = -11 (1111 0101)
^	Bitwise XOR	x ^ y = 14 (0000 1110)
>>	Bitwise right shift	x>> 2 = 2 (0000 0010)
<<	Bitwise left shift	x<< 2 = 40 (0010 1000)
'''

# Identity operators
'''
is and is not are the identity operators in Python. They are used to check if two values (or variables) are located on the same part of the memory.
'''
x = [1,2,3]
y = x
z = [1,2,3]
print('x is y', x is y) # True
print('x is z', x is z) # False

# Membership operators
'''
in and not in are the membership operators in Python. 
'''
print('1 in x', 1 in x)
print('"Hello" in x', 'Hello' in x)