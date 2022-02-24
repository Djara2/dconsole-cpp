import sys
from rich.console import Console
CONSOLE = Console()
error_text = "\n[bold red]ERROR:[/] " + sys.argv[1]
CONSOLE.print(error_text)
exit()