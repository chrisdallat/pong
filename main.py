from PyQt6.QtWidgets import QApplication
from menu import Menu

import sys
import subprocess

def compile_game():
    output_text = None
    args = ["./build.sh", "--gen", "pong"]
    result = subprocess.run(args, stdout=subprocess.PIPE)
    print(result.stdout.decode())

def run_game():
    output_text = None
    #TODO: add different args here for settings later
    args = ["./build/pong", "game"]
    result = subprocess.run(args, stdout=subprocess.PIPE)
    print(result.stdout.decode())

def main():
    app = QApplication(sys.argv)
    app.setStyleSheet("""
        QLineEdit:focus {
            background-color: "grey";
        }
        QPushButton {
            font-size:16px;
        }
        QPushButton:hover { 
            background-color: "grey";
        }
        QPushButton:focus { 
            background-color: "grey";
        }
    """)

    print("Welcome to Pong Setup!")

    menu = Menu()
    menu.show() 
    if(menu.start == True):
        print("start == true")
        menu.hide()
        compile_game()
        run_game()
    # TODO: some sort of while loop i guess

    sys.exit(app.exec())

if __name__ == "__main__":
    main()

