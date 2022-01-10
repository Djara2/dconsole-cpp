import os

while(True):
    os.system("clear")
    print("0. dconsole.cpp (run - Windows)")
    print("1. dconsole.cpp (run+compile - Linux)")
    print("2. dconsole.cpp (vim)")
    print("3. matrix.cpp (vim)")
    print("4. dconsole (compile - Linux)")
    print("5. dconsole (compile - Windows) [make sure you do it on Windows]")
    print("6. exit")
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
        exit()
    elif selection == "quit" or selection == "exit":
        exit()
    else:
        pass
    stop = input("Press ENTER to continue ")

