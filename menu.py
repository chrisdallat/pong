import sys
from PyQt6 import QtWidgets, uic

from ui_menu import ui_menu

class Menu(QtWidgets.QMainWindow, ui_menu):
    def __init__(self, *args, obj=None, **kwargs):
        super(Menu, self).__init__(*args, **kwargs)
        self.start = False
        self.setupUi(self)
        self.ui_menu = ui_menu()
        self.ui_menu.setupUi(self)
        self.ui_menu.start_button.clicked.connect(self.start_game)

    def start_game(self):
        self.set_players()
        self.set_powerups()
        self.set_ai_difficulty()
        self.set_points_limit()
        self.start = True
        #print(self.start)
        
    def set_players(self):
        self.players = self.ui_menu.players_combo.currentText()
        print("set_players() = " + self.players)

    def set_powerups(self):
        self.powerups = self.ui_menu.powerups_combo.currentText()
        print("set_powerups = " + self.powerups)

    def set_ai_difficulty(self):
        self.difficulty = self.ui_menu.difficulty_combo.currentText()
        print("set_ai_difficulty = " + self.difficulty)

    def set_points_limit(self):
        self.points = self.ui_menu.points_combo.currentText()
        print("set_points_limit = " + self.points)


