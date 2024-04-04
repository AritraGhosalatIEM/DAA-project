CC=gcc
TOTAL=100000
SAMPLES=10
LOW=100
JUMP=500
MAX=10000
TESTS=10
numbers.dat:
	head -c $$((4*$(TOTAL))) /dev/urandom > numbers.dat
speed.pdf: code/graph.py data
	code/graph.py
%.out:code/test.c code/sorts/%.c
	$(CC) $^ -o $@
data/stamp: $(shell ls code/sorts/ | sed 's/\.c/\.out/')
	-mkdir data
	i=$(SAMPLES);while [ $$i -gt 0 ];do\
	  	make numbers.dat;\
		for exeutable in *.out;do\
			./$$exeutable $(LOW) $(MAX) $(JUMP) $(TESTS) >> data/$$exeutable.csv;\
		done;\
		i=$$((i-1));\
	done;
	touch data/stamp
ticks.pdf:data/stamp
	code/graph.py $(LOW) $(MAX) $(JUMP) $(TESTS)
report.pdf:latex/main.tex latex/template.tex ticks.pdf
	xelatex latex/main.tex
	mv main.pdf report.pdf
clear:clean
	-rm -r data
	-rm ticks.pdf
	-rm report.pdf
clean:
	-rm numbers.dat
	-rm *.out
	-rm main.log main.aux main.out
.PHONY:clean clear numbers.dat
