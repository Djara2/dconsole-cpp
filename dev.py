import os
import sys
from get_os import *
"""
print(sys.platform)
if(sys.platform == "win32"):
    WINDOWS = True
else:
    WINDOWS = False
"""
OPERATING_SYSTEM = GET_OS()
while(True):
    
    if OPERATING_SYSTEM == "Windows":
        os.system("cls")
    else:
        os.system("clear")
    print("0. dconsole.cpp (run - Windows)")
    print("1. dconsole.cpp (run+compile - Linux)")
    print("2. dconsole.cpp (vim)")
    print("3. matrix.cpp (vim)")
    print("4. dconsole (compile - Linux)")
    print("5. dconsole (compile - Windows SHAREABLE) [make sure you do it on Windows]")
    print("6. dconsole (compile - Windows LOCAL ONLY) [make sure you do it on Windows]")
    print("7. EDIT IN SUBLIME TEXT")
    print("8. AUTOCOMPILER (for programs in bin folder)")
    print("9. exit")
    selection = input("\nChoice?: ")
    if selection == "0":
        os.system("dcwin")
    elif selection == "1":
        os.system("g++ -o dconsole dconsole.cpp")
        os.system("./dconsole")
    elif selection == "2":
        os.system("vim dconsole.cpp")
    elif selection == "3":
        os.system("vim matrix.cpp")
    elif selection == "4":
        os.system("g++ -o dconsole dconsole.cpp")
    elif selection == "5":
        os.system("g++ dconsole.cpp -o dcwin.exe -static-libgcc -static-libstdc++")
    elif selection == "6":
        os.system("g++ dconsole.cpp -o dcwin.exe")
    elif selection == "7":
        os.system("subl dconsole.cpp")
    elif selection == "8":
        if OPERATING_SYSTEM == "Windows":
            os.system("bin/autocompiler.exe")
        else:
            os.system("cd bin")
            os.system("./bin/autocompiler")
    elif selection == "9":
        exit()
    elif selection == "quit" or selection == "exit":
        exit()
    else:
        pass
    stop = input("Press ENTER to continue ")

