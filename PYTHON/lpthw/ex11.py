age = input('How old are you?')
height = input('How tal are you?')
weight = input('How much do you weight?')

print("So, you're %s old, %s tall and %s heavy." % (age, height, weight))

'''
Input fom Keyboard
The input Function
Input via keyboard There are hardly any programs without any input. Input can come in various ways, for example from a database, another computer, mouse clicks and movements or from the internet.
'''

name = input("What's your name? ")
print(f"Nice to meet you {name}")
print("Nice to meet you %s" % name)
print("NIce to meet you {}".format(name))

# python -m pydoc input