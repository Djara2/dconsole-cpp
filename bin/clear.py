import platform
import os
OPERATING_SYSTEM = platform.system()
if OPERATING_SYSTEM == "Windows":
    os.system("cls")
else:
    os.system("clear")