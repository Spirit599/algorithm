import os
import sys
import time

os.system("find . -name '*.exe' | xargs rm -vr")

message = time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())
message = " \"" + message + "\" "

repository = " git@github.com:Spirit599/algorithm.git "
branch = " master "
if len(sys.argv) >= 2:
	message = sys.argv[1]

os.system("git add .")
os.system("git status")
os.system("git commit -m" + message)
os.system("git push" + repository + branch)

os.system('pause')
