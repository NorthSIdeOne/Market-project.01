all:
	gcc main1.c -o market
clean:
	rm market
build:
	./market date1.txt date2.txt cerinte.txt rezultate.txt
