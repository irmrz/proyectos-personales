from rich import print
from rich.console import Console
from rich.columns import Columns
from rich.text import Text
from password import *
import os

console = Console()

def main():
    text = Text("Welcome to the password generator!")
    text.stylize("reverse bold blue")
    columns = Columns([text], width=120, align='left')
    console.print(columns)

    console.print("How many characters do you want in your password?", style="b sky_blue2")
    console.print("The minimum is 5 characters and the maximum is 128.", style="b sky_blue2")
    user_input = read_user_input()
    result = password(user_input)
    console.print("Your password is:", style="b sky_blue2")
    console.print(Text(result), style="bold ")
    console.print("Your password has been copied to your clipboard!", style="b sky_blue2")
    pyperclip.copy(result)
    console.print("Copyright@ Ignacio Ramirez", style="grey15")

if __name__ == '__main__':
    main()