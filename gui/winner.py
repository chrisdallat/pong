import sys
from PyQt6 import QtWidgets, uic
from PyQt6 import QtCore

from run import *

class Winner(QtWidgets.QMainWindow):

    def __init__(self):
        super(Winner, self).__init__()
        uic.loadUi("gui/winner.ui", self)
        self.main_menu_button.clicked.connect(self.hide)

    def winner_menu(self, winner):
        if(winner == 0):
            self.winner_text.setText("")
            self.player_number.setText("QUIT")
        else:
            self.winner_text.setText("THE WINNER IS")
            self.player_number.setText(str(winner))
