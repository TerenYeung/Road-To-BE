# Variables and Names

cars = 100
space_in_a_car = 4
drivers = 30
passengers = 90
cars_not_driven = cars - drivers
cars_driven = drivers
carpool_capacity = cars * space_in_a_car
average_passengers_per_car = passengers / cars_driven

print("There are", cars, "cars available.")
print("There are only", drivers, "drivers avaiable.")
print("There will be", cars_not_driven, "empty cars today.")
print("We can transport", carpool_capacity, "people today.")
print("We have", passengers, "to carpool today.")
print("We need to put about", average_passengers_per_car, "in each car.")

a, b, c = 1, 2, 'Hello World'
print(a)
print(b)
print(c)

## Standard Data Types
'''
Numbers
String
List
Tuple
Dictionary
'''

### Numbers
# Python supports four different numerical types: int, long, float, complex
var1 = 1
var2 = 100

### Strings
str = 'Hello World!'
print(str[0])
print(str[2:5])
print(str[2:])
print(str * 2)
print(str + 'TEST')

### Lists
list = ['abcd', 786, 2.23, 'john', 70.2]
print(list)
print(list[1:3])
print(list * 2)

### Tuples
'''
The main differences between lists and tuples are: Lists are enclosed in brackets ( [ ] ) and their elements and size can be changed, while tuples are enclosed in parentheses ( ( ) ) and cannot be updated.

Tuples can be thought of as read-only lists
'''

list2 = ('abcd', 786, 2.23, 'john', 70.2, 'tuple')
print('tuple', list2)
# list2[0] = 'Hello'
print('write tuple', list2)

#### Dictionary
'''
Python's dictionaries are kind of hash table type and and consist of key-value pairs. 
'''

tinydict = {
  'name': 'john',
  'age': 28
}
tinydict['career'] = 'programer'
print(tinydict)

