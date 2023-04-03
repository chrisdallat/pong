from PyQt6.QtWidgets import QApplication
from menu import Menu
from run import *

import sys

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

    menu = Menu()
    menu.show()
    print("Welcome to Pong!")

    app.exec()
    print("Exited Game!")

if __name__ == "__main__":
    main()

