import argparse

parser = argparse.ArgumentParser()

parser.add_argument("square", type=int,
                    help="display a square of a given number")
parser.add_argument("--verbose", "-v", action="store_true",
                    help="increate output verbosity")

args = parser.parse_args()
answer = args.square**2

if args.verbose:
    print("the square of {} equals {}".format(args.square, answer))
else:
    print(answer)

  