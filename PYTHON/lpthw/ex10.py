tabby_cat = "\tI'm tabbed in."
persian_cat = "I'm split\non a line."
backslash_cat = "I'm \\ a \\ cat."

fat_cat = """
I'll do a list:
\t* Cat food
\t* Fishies
\t* Catnip\n\t* Grass
"""

print(tabby_cat)
print(persian_cat)
print(backslash_cat)
print(fat_cat)

# list1 = ["/", "-", "|", "\\", "|"]
# while True:
#   for i in list1:
#     print("%s\r" %i)

# 格式化字符串
print("I'm %s. I'm %d years old" % ("Teren", 25))

print("I'm %(name)s. I'm %(age)d years old" % {'name': 'Teren', 'age': 99})

print("%s" % 5)