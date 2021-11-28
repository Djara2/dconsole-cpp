import os
while(True):
    os.system("clear")
    print("1. dconsole.cpp (run)")
    print("2. dconsole.cpp (vim)")
    print("3. matrix.cpp (vim)")
    print("4. dconsole (compile)")
    selection = input("\nChoice?: ")
    if selection == "1":
        os.system("g++ -o dconsole dconsole.cpp")
        os.system("./dconsole")
    elif selection == "2":
        os.system("vim dconsole.cpp")
    elif selection == "3":
        os.system("vim matrix.cpp")
    elif selection == "4":
        os.system("g++ -o dconsole dconsole.cpp")
    elif selection == "quit" or selection == "exit":
        exit()
    stop = input("Press ENTER to continue ")

