# Reading Files
from sys import argv

script, filename = argv

txt = open(filename)

print("Here's your file %r:" % filename)
print(txt.read())

# print("Type the filename again:")
# file_again = input("> ")

# txt_again = open(file_again)

# print(txt_again.read())

txt.close()

# file object

txt = open(filename)
print('''
file closed: %s,
file mode: %s,
filename: %s,
''', (txt.closed, txt.mode, txt.name))

# file.close()
# file.write('Hello')
# file.read([count])
# file.tell() file.seek(offset[,from])
# os.rename() os.remove() os.mkdir() os.chdir() os.rmdir()