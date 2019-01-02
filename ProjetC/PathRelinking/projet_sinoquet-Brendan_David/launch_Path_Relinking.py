#!usr/bin/env python3

import os


PathRelinkingFolder ="./PathRelinking/source/main.cpp"
outputDirectory = "/ESULTS"
iteration_number = 5

if not os.path.exists(outputDirectory):
	os.mkdir(outputDirectory)

for i in range(1, iteration_number+1):
    outputFile = "results_{0}.txt".format(i)
    os.system("./pathRelinking {0}".format(outputFile))
