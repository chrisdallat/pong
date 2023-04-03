import sys
import os
import subprocess

def compile_game():
    if(os.path.exists("./build/pong") == False):
        output_text = None
        args = ["./build.sh", "--gen", "pong"]
        result = subprocess.run(args, stdout=subprocess.PIPE)
        print(result.stdout.decode())
    
def run_game(players, powerups, difficulty, points):
    output_text = None
    #TODO: add different args here for settings later
    args = ["./build/pong", players, powerups, difficulty, points]
    result = subprocess.run(args, stdout=subprocess.PIPE)
    print(result.stdout.decode())