import sys
from rich.console import Console
mode = sys.argv[1]
CONSOLE = Console()
if mode == "md":
	from rich.markdown import Markdown
	MD = Markdown(sys.argv[2])
	CONSOLE.print(MD)
elif mode == "normal":
	CONSOLE.print(sys.argv[2])
exit()