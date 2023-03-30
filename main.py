from PyQt6.QtWidgets import (
    QApplication, QWidget, QPushButton, QLabel, 
    QLineEdit, QVBoxLayout, QHBoxLayout, QGridLayout,
)
from PyQt6.QtCore import Qt
from PyQt6.QtGui import QIcon, QPixmap

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

    # TODO: some sort of while loop i guess
    compile_game()
    run_game()
    

if __name__ == "__main__":
    main()

