import sys
from PyQt6 import QtWidgets, uic
from PyQt6 import QtCore

from run import *

class Menu(QtWidgets.QMainWindow):

    start = False

    def __init__(self):
        super(Menu, self).__init__()
        uic.loadUi('menu.ui', self)

        self.start_button.clicked.connect(self.start_game)
        self.start_button.clicked.connect(self.close)

    def start_game(self):
        self.set_players()
        self.set_powerups()
        self.set_ai_difficulty()
        self.set_points_limit()
        self.start = True
        compile_game()
        run_game()

    def get_players(self):
        return self.players

    def set_players(self):
        self.players = self.players_combo.currentText()
        print("set_players() = " + self.players)
    
    def get_powerups(self):
        return self.powerups

    def set_powerups(self):
        self.powerups = self.powerups_combo.currentText()
        print("set_powerups = " + self.powerups)

    def get_ai_difficulty(self):
        print(self.difficulty)
        return self.difficulty

    def set_ai_difficulty(self):
        self.difficulty = self.difficulty_combo.currentText()
        print("set_ai_difficulty = " + self.difficulty)

    def get_points_limit(self):
        return self.points

    def set_points_limit(self):
        self.points = self.points_combo.currentText()
        print("set_points_limit = " + self.points)


