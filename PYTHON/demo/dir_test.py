# dir_test.property
# Created: 24th December 2017

'''
Tests to see if the directory testdir exists, if not it will create the directory for you
'''

'''
learn point:
1. __future__
2. sys module
'''

from __future__ import print_function
'''
Python为了确保你能顺利过渡到新版本，特别提供了__future__模块，让你在旧的版本中试验新版本的一些特性。

__futrun__  provide the functionality to use new feturen in the old version
'''

import os
import sys

def main():
  if sys.version_info.major >= 3:
    input_func = input
  else:
    input_func = raw_input
  
  CheckDir = input("Enter the name of the directory to check: ")
  print()

  if os.path.exists(CheckDir):
    print("The directory exists")
  else:
    print("No directory found for " + CheckDir)
    print()
    os.makedirs(CheckDir)
    print("Directory created for " + CheckDir)

if __name__ == '__main__':
  main()