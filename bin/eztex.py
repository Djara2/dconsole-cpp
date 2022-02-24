import pyclip
from rich.markdown import Markdown
from rich.console import Console
import os
from get_os import *

OPERATING_SYSTEM = GET_OS()
print(OPERATING_SYSTEM)
CONSOLE = Console()
HEADER = Markdown("# EZtex")
exit_keys = ["ex", "exit", "quit", "stop", "q"]
userInput = None
user_input_list = []
return_string = ""
out = ""

continue_looping = True
while continue_looping:
    user_input_list = []
    return_string = ""
    CONSOLE.print(HEADER)
    CONSOLE.print("[green]Enter HELP or H for help.[/green]\n")
    userInput = input("> ")
    if userInput in exit_keys:
        exit()
    if not len(user_input_list) == 0 or not len(user_input_list) == 1:
        user_input_list = userInput.split()
        for x in range(0, len(user_input_list)):
            if user_input_list[x] == "frac":
                return_string += "\\frac{" + user_input_list[x+1] + "}{" + user_input_list[x+2] + "} "
            else:
                if user_input_list[x-1] != "frac" and user_input_list[x-2] != "frac":
                    return_string += "{} ".format(user_input_list[x])
        return_string = "${}$".format(return_string[0:len(return_string)-1])
        print(return_string)

    else:
        CONSOLE.print("[orange]Input is too short. Please enter more arguments.[/orange]\n")
    
    userInput = input("\nHit ENTER to continue... ")
    pyclip.copy(return_string)
    if OPERATING_SYSTEM == "Windows":
        os.system("cls")
    else:
        os.system("clear")

    

    

