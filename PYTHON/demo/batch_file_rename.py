'''
# 功能
批量重命名目录下的文件后缀

# 基本思路
1. 读取某个目录下的所有文件
2. 然后根据在命令行的输入的目录、old ext 和 new ext 批量修改文件后缀

# 学习点
1. 了解 os 和 argparse 模块的使用
2. 了解 __name__ == '__main__' 的含义
'''

# batch_file_rename.property
# Created: 23rd December 2017

'''
This will batch rename a group of files in a given directory,
once you pass the current and new extensions
'''

__practiser__ = 'Teren Yeung'

import os
import argparse

def batch_rename(work_dir, old_ext, new_ext):
  '''
  This will batch rename a group of files in a given derectory,
    once you pass the current and new extensions
  '''
  for filename in os.listdir(work_dir):
    # Get the file extension
    split_file = os.path.splitext(filename)
    file_ext = split_file[1]
    # Start of the logic to check the file extensions, if old_ext = file_ext
    if file_ext == old_ext:
      # Returns changed name of the file with new extension
      new_file = split_file[0] + new_ext
      os.rename(
        os.path.join(work_dir, filename),
        os.path.join(work_dir, new_file)
      )

def get_parser():
  parser = argparse.ArgumentParser(description="change extension of files in a working directory")
  parser.add_argument(
    'work_dir', metavar="WORK_DIR",
    type=str, nargs=1, help="the directory where to change extension"
    )
  parser.add_argument(
    'old_ext', metavar="OLD_EXT",
    type=str, nargs=1, help="old extension"
  )
  parser.add_argument(
    'new_ext', metavar="NEW_EXT",
    type=str, nargs=1, help="new extension"
  )
  return parser

def main():
  '''
  This will be called if the script is directly invoked.
  '''
  # adding command line argument
  parser = get_parser()
  args = vars(parser.parse_args())
  print(args)

  batch_rename(args['work_dir'][0], args['old_ext'][0], args['new_ext'][0])

if __name__ == "__main__":
  main()