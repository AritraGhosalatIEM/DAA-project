TOTAL=30
numbers.dat:
	head -c $$((4*$(TOTAL))) /dev/urandom > numbers.dat
clean:
	rm numbers.dat
.PHONY:clean
