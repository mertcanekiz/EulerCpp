#!/usr/bin/python3

import os
import sys
import subprocess

path = sys.argv[1]
name, ext = os.path.splitext(path)
options = ['g++',
           '-O3',
           'src/' + path,
           '-o', f'./bin/{name}',
           '-lgmp']
subprocess.call(options)
subprocess.call([f'./bin/{name}'])
