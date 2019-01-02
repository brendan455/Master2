#!usr/bin/env python3

import sys
import os
import random
from math import exp

#Functions definition
def initialisation_variable() :
	#Function which take every argument given by user using launch_simu_naive.py
	outputDirectoryName = str(sys.argv[1])
	outputFileNumber = int(sys.argv[2])
	prefixName = str(sys.argv[3])
	variableNumber = int(sys.argv[4])
	controlNumber = int(sys.argv[5])
	caseNumber = int(sys.argv[6])
	numberOfCausalSNP = int(sys.argv[7])
	validation = ""
	return (outputDirectoryName, outputFileNumber, prefixName, variableNumber, controlNumber, caseNumber, numberOfCausalSNP , validation)

def causal_logistic_regression_2():
	#This function use a logistic regression to generate causal epistasis pattern of 2 SNP
	#It return two list containing for one all cas pattern and for the other all controle pattern
	alpha = random.uniform(-1,1)
	beta1 = random.uniform(-1,1)
	beta2 = random.uniform(-1,1)
	beta12 = random.uniform(-1,1)
	pairs_of_solutions = [(0,0), (0,1), (0,2), (1,0), (1,1), (1,2), (2,0), (2,1), (2,2)]
	casList = []
	controlList = []
	for i in range(0, len(pairs_of_solutions)):
		z = alpha + beta1 * pairs_of_solutions[i][0] + beta2 * pairs_of_solutions[i][1] + beta12 * pairs_of_solutions[i][0] *pairs_of_solutions[i][1]
		pr = (1/(1 + exp(-z)))
		if (pr > 0.5):
			casList.append(pairs_of_solutions[i])
		elif (pr < 0.5):
			controlList.append(pairs_of_solutions[i])
		else:
			print("Error during logistic regression for 2 causal SNP")
			exit(1)
	return(casList, controlList)

def causal_logistic_regression_3():
	#This function use a logistic regression to generate causal epistasis pattern of 3 SNP
	#It return two list containing for one all cas pattern and for the other all controle pattern
	alpha = random.uniform(-1,1)
	beta1 = random.uniform(-1,1)
	beta2 = random.uniform(-1,1)
	beta3 = random.uniform(-1,1)
	beta12 = random.uniform(-1,1)
	beta13 = random.uniform(-1,1)
	beta23 = random.uniform(-1,1)
	beta123 = random.uniform(-1,1)
	pairs_of_solutions = [(0,0,0), (0,0,1), (0,0,2), (0,1,0), (0,1,1), (0,1,2), (0,2,0), (0,2,1), (0,2,2), (1,0,0), (1,0,1), (1,0,2), (1,1,0), (1,1,1), (1,1,2), (1,2,0), (1,2,1), (1,2,2), (2,0,0), (2,0,1), (2,0,2), (2,1,0), (2,1,1), (2,1,2), (2,2,0), (2,2,1), (2,2,2)]
	casList = []
	controlList = []
	for i in range(0, len(pairs_of_solutions)):
		z = alpha + beta1 * pairs_of_solutions[i][0] + beta2 * pairs_of_solutions[i][1] + beta3 * pairs_of_solutions[i][2] + beta12 * pairs_of_solutions[i][0] * pairs_of_solutions[i][1] + beta13 * pairs_of_solutions[i][0] * pairs_of_solutions[i][2] + beta23 * pairs_of_solutions[i][1] * pairs_of_solutions[i][2] + beta123 * pairs_of_solutions[i][0] * pairs_of_solutions[i][1] * pairs_of_solutions[i][2]
		pr = (1/(1 + exp(-z)))
		if (pr > 0.5):
			casList.append(pairs_of_solutions[i])
		elif (pr < 0.5):
			controlList.append(pairs_of_solutions[i])
		else:
			print("Error during logistic regression for 3 causal SNP")
			exit(1)
	return(casList, controlList)

#Display informations and ask for validation
outputDirectoryName, outputFileNumber, prefixName, variableNumber, controlNumber, caseNumber, numberOfCausalSNP , validation = initialisation_variable()
validation = str(input("\nYou enter these informations : \n- Output directory name : {0}\n- Number of files : {1}\n- Filename prefix : {2}\n- Number of variables : {3}\n- Number of controls : {4}\n- Number of cases : {5}\n- Number of causal SNP : {6}\n\nAll these informations are correct ? (Y/n)".format(outputDirectoryName, outputFileNumber, prefixName, variableNumber, controlNumber, caseNumber, numberOfCausalSNP , validation)))

while validation not in {'Y', 'y', 'Yes', 'yes', 'YES'} :
	if (validation in {'N', 'n', 'No', 'no', 'NO'}) :
		exit()
	else :
		validation = str(input("Answer in not correct. Please enter Y or n : "))

if not os.path.exists(outputDirectoryName):
	os.mkdir(outputDirectoryName)

#Generation of causal pattern
casList = []
controlList = []

while(len(casList)==0 or len(controlList)==0):
	if (numberOfCausalSNP == 2):
		casList, controlList = causal_logistic_regression_2()
	elif (numberOfCausalSNP == 3):
		casList, controlList = causal_logistic_regression_3()
	else:
		print("Error during extraction of list of cas and control")
		exit(3)

#File writting
for i in range(1, outputFileNumber + 1) :
	File = open('{0}/{1}_{2}_Genotype.txt'.format(outputDirectoryName, prefixName, i), 'a')
	Header = ""
	for j in range(1, (variableNumber - numberOfCausalSNP) + 1) :
		AddHeader = "N{0},".format(j)
		Header += AddHeader
	for j in range(1, numberOfCausalSNP + 1) :
		AddHeader = "X{0},".format(j)
		Header += AddHeader
	Header = Header[0: -1]
	File.write(Header + "\n")

	for j in range(1, controlNumber + caseNumber + 1) :
		Line = ""
		for k in range(1, variableNumber - numberOfCausalSNP + 1) :
			n = random.randint(0, 2)
			AddLine = "{0},".format(n)
			Line += AddLine
		if numberOfCausalSNP == 2:
			if (j <= caseNumber):
				n = random.choice(casList)
				AddLine = "{0},".format(n[0])
				Line += AddLine
				AddLine = "{0},".format(n[1])
				Line += AddLine
			else:
				n = random.choice(controlList)
				AddLine = "{0},".format(n[0])
				Line += AddLine
				AddLine = "{0},".format(n[1])
				Line += AddLine
		elif numberOfCausalSNP ==3:
			if (j <= caseNumber):
				n = random.choice(casList)
				AddLine = "{0},".format(n[0])
				Line += AddLine
				AddLine = "{0},".format(n[1])
				Line += AddLine
				AddLine = "{0},".format(n[2])
				Line += AddLine
			else:
				n = random.choice(controlList)
				AddLine = "{0},".format(n[0])
				Line += AddLine
				AddLine = "{0},".format(n[1])
				Line += AddLine
				AddLine = "{0},".format(n[2])
				Line += AddLine
		Line = Line[0: -1]
		File.write(Line + "\n")

	File.close()

	File = open('{0}/{1}_{2}_Phenotype.txt'.format(outputDirectoryName, prefixName, i), 'a')

	File.write("Class\n")
	for i in range(1, caseNumber + 1) :
		File.write("1\n")
	for i in range(1, controlNumber + 1) :
		File.write("0\n")

	File.close()
