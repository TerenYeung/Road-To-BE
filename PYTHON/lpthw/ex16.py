from sys import argv

script, filename = argv

print("We're going to erase %r." % filename)
print("If you dont't want that, hit CTRL-C.")
print("If you do want that, hit RETUREN.")

input("?")

print("Opening the file...")
target = open(filename, 'w+')
# 'w'	open for writing, truncating the file first
print("Truncating the file. Goodbye!")
# target.truncate()
print("Now the file content is: {}".format(target.read()))

print("Now I'm going to ask you for three lines.")

line1 = input("line 1: ")
line2 = input("line 2: ")
line3 = input("line 3: ")

print("I'm going to write these to the file.")

# target.write(line1)
# target.write("\n")
# target.write(line2)
# target.write("\n")
# target.write(line3)
# target.write("\n")
target.write("%s\n%s\n%s\b\n" % (line1, line2, line3))


print("And finally, we close it.")
target.close()

target2 = open(filename, 'r')
print("Now the file content is: %r" % target2.read())