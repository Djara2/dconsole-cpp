import os
print("1. dconsole.cpp (run)")
print("2. dconsole.cpp (vim)")
print("3. matrix.cpp (vim)")
selection = input("Choice?: ")
if selection == "1":
    os.system("g++ -o dconsole dconsole.cpp")
    os.system("./dconsole")
elif selection == "2":
    os.system("vim dconsole.cpp")
elif selection == "3":
    os.system("vim matrix.cpp")

