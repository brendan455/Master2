#!usr/bin/env python3

import os

#Genetic alorithm can be run by three differents way:
#To choose your method you just have to uncomment parameters for your method and comment the other
#################1 - You want to run it on one file one time

# pathToGenotypesFile = "/home/damien/Bureau/C/Sinoquet/Simu_naive3/Naif3_1_Genotype.txt"
# pathToPhenotypesFile = "/home/damien/Bureau/C/Sinoquet/Simu_naive3/Naif3_1_Phenotype.txt"
# outputDirectory = "RESULTS"
# outputFile = "results.txt"
#
# if not os.path.exists(outputDirectory):
# 	os.mkdir(outputDirectory)
#
# os.system("./Genetic_alorithm {0} {1} ./{2}/{3}".format(pathToGenotypesFile, pathToPhenotypesFile, outputDirectory, outputFile))


################2 - You want to run it on on file many time


pathToGenotypesFile = "/home/damien/Bureau/C/Sinoquet/Simu_naive3/Naif3_1_Genotype.txt"
pathToPhenotypesFile = "/home/damien/Bureau/C/Sinoquet/Simu_naive3/Naif3_1_Phenotype.txt"
outputDirectory = "RESULTS"
iteration_number = 5

if not os.path.exists(outputDirectory):
	os.mkdir(outputDirectory)

for i in range(1, iteration_number+1):
    outputFile = "results_{0}.txt".format(i)
    os.system("./Genetic_alorithm {0} {1} ./{2}/{3}".format(pathToGenotypesFile, pathToPhenotypesFile, outputDirectory, outputFile))

#################3 - you want to run it on all file in a directory one time

# pathToDirectory = "/home/damien/Bureau/C/Sinoquet/Simu_naive3/"
# filePrefix ="Naif3"
# outputDirectory = "RESULTS"
# outputFile = "results.txt"
#
# if not os.path.exists(outputDirectory):
# 	os.mkdir(outputDirectory)
# i = 0
# for root, dirs, files in os.walk(pathToDirectory):
#     for filename in files:
#         i+=1
# i = int(i/2)
#
# for j in range(1, i+1):
#     outputFile = "results_{0}.txt".format(j)
#     os.system("./Genetic_alorithm {0}/{1}_{2}_Genotype.txt {0}/{1}_{2}_Phenotype.txt ./{3}/{4}".format(pathToDirectory, filePrefix, j, outputDirectory, outputFile))
