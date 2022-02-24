from random import *
import sys
import os
from rich.console import Console
import pyclip
CONSOLE = Console()
mode = sys.argv[1]
return_value = ""
try:
	lower_bound = int(sys.argv[2])
	upper_bound = int(sys.argv[3])
except:
	os.system("python3 error.py \"Invalid parameters - Defaulting to range [0, 10]\"")
	lower_bound = 0
	upper_bound = 10

if mode == "randint":
	return_value = randint(lower_bound, upper_bound)

elif mode == "randword":
	for x in range(0, randint(lower_bound, upper_bound)):
		return_value += chr(randint(ord('a'), ord('z')))


CONSOLE.print("\n[green]Output:[/] {}".format(return_value))
if mode == "randword":
	copy = input("\nCopy result to clipboard?: ")
	if copy == "y" or copy == "Y":
		pyclip.copy(return_value)
exit()