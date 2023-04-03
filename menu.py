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
        #self.start_button.clicked.connect(self.close)

    def start_game(self):
        self.set_players()
        self.set_powerups()
        self.set_ai_difficulty()
        self.set_points_limit()
        self.start = True
        compile_game()
        run_game(self.get_players(), self.get_powerups(), self.get_ai_difficulty(), self.get_points_limit())
        self.close()

    def get_players(self):
        return self.players

    def set_players(self):
        self.players = self.players_combo.currentText()
    
    def get_powerups(self):
        return self.powerups

    def set_powerups(self):
        self.powerups = self.powerups_combo.currentText()

    def get_ai_difficulty(self):
        return self.difficulty

    def set_ai_difficulty(self):
        self.difficulty = self.difficulty_combo.currentText()

    def get_points_limit(self):
        return self.points

    def set_points_limit(self):
        self.points = self.points_combo.currentText()


