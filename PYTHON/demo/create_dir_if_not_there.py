# create_dir_if_not_there.py
# Created: 24th December 2017

'''
Checks to see if a directory exists in the users desktop directory, if not then create it
'''

'''
learn point:
1. os.path.expanduser
2. os.path.makedirs
3. try ... except ...
'''

import os
MESSAGE = 'The directory already exists.'
TESTDIR = 'testdir'

try:
  desktop = os.path.join(os.path.expanduser("~"), 'Desktop')
  print(desktop)
  if not os.path.exists(os.path.join(desktop, TESTDIR)):
    os.makedirs(os.path.join(desktop, TESTDIR))
  else:
    print(MESSAGE)
except Exception as e:
  print(e)