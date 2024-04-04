#!/bin/python
LOW=100
JUMP=500
TESTS=10
MAX=10000
from matplotlib.pyplot import plot,legend,title,xlabel,ylabel,xticks,savefig
from matplotlib.style import use
from numpy import array
from os import listdir
from sys import argv
LOW=int(argv[1]);MAX=int(argv[2]);JUMP=int(argv[3]);TESTS=int(argv[4])
numbers=range(LOW,MAX,JUMP)
use('seaborn-v0_8')
for datapath in listdir('data'):
    with open(f'data/{datapath}','r') as datafile:
        data=array([int(i) for i in datafile.readline().split(',')[:-1]])
        linecount=1;
        for line in datafile:
            data+=array([int(i) for i in line.split(',')[:-1]])
            linecount+=1
        data//=linecount
        plot(*numbers,data,label=f'{datapath[:-8]} sort')
title('Speed')
xlabel('Numbers sorted')
xticks(numbers,rotation=75)
ylabel(f'Average clock ticks for {TESTS} runs')
legend()
savefig('ticks.pdf')
