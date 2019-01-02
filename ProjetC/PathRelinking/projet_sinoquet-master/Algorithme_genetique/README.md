# Genetic algorithm for epistasis detection

This script is meant to be used by biologists, who want to search a pattern of epistasis (pattern of 2 or 3).  
It takes as an input a genotype file coming from a GWAS stydu, with every SNP coded 0|1|2.  


## Getting Started

First, you need to download the source from git:  
> git clone git@gitlab.univ-nantes.fr:AntoineLABEEUW/projet_sinoquet.git

And your're done !


### Prerequisites

To run it locally you need:  
- a GCC compiler
- BOOST 1.68.0, you can find it [here](https://www.boost.org/users/history/version_1_68_0.html)

you can install boost like this:  
>You need to have the sudo permissions  
Download the BOOST library  
Decompress the archive and go th the directory  
sudo ./bootstrap.sh  
sudo ./b2 install


### Installing

As said above, the only thing you need to do is downloading the source code and have BOOST.  
To use it, there is already some files meant to launch the script.  
**launch_genetic_algorithm** is the python script made to launch the algorithm. Change your paths for a use in your computer.  


## Running the tests

We have included 3 datasets for a test of our algorithm named *Simu_naive1, Simu_naive2, Simu_naive3*, and are already in the paths of launch_genetic_algorithm

## Parameters

You can find and change the parameters used by the algorithm under parameters.txt.
- number of individuals (i.e., solutions) in each population
- maximal number of iterations (i.e., successive populations)
- number of parents to be selected in current population
- probability that a child be subject to a mutation (0.00 to 1)
- maximal number of distinct best individuals in the last population
- number of wanted SNP (2 or 3)

Change only the numbers, not the letters before it !

## Built With

* C++
* python3
* BOOST library for c++