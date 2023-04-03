import sys
import os
import subprocess

def compile_game():
    if(os.path.exists("./build/pong")):
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