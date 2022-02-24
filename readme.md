# Extensions
- there is now a folder called "bin" -- here is where all the extensions go. Any executable that is placed here can be ran by dconsole. To execute, just enter the file name, preceeded by one ! character. For example, to run an executable "helloWorld", you would enter !helloWorld. Ensure that you have .exe and regular executable for this to work on Linux and Windows. 

# Graphics 
- Graphics handling has changed. 
- The old graphics.py program is still there, but it would not make sense to use it. 
- Within the bin folder, use "graphics.py" (different from one in main folder)
- Within the main folder, use "graphics2.py"
	- Graphics2.py just takes parameters and prints using the rich library based on those parameters. 
	- **grahics2.py CLI arguments**
		- argv[1] = mode
			- **mode can be either "md" or "normal"**
				- **md** → stands for Markdown. Anything in argv[2] will be interpreted as Markdown for rendering.
				- **normal** → printing occurs as normal, using syntax from Python's rich library.
		- argv[2] = what gets printed