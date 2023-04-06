import sys

sys.path.append("./gui/")
from menu import Menu
from winner import Winner
from run import *

from PyQt6.QtWidgets import QApplication

def main():
    
    print("Welcome to Pong!")

    app = QApplication(sys.argv)
    
    menu = Menu()
    menu.show()

    app.exec()
    print("Exited Game!")

if __name__ == "__main__":
    main()

