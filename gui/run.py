import sys
import os
import subprocess

from winner import Winner

def compile_game():
    if(os.path.exists("./build/pong") == False):
        args = ["./build.sh", "--gen", "pong"]
        result = subprocess.run(args, stdout=subprocess.PIPE)
        print("----- compiled game successfully -----")
    
def run_game(players, powerups, difficulty, points):
    args = ["./build/pong", players, powerups, difficulty, points]
    result = subprocess.run(args, stdout=subprocess.PIPE)
    return result.returncode


