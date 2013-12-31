CC = sdcc
FLAGS =  -mmcs51 --model-small 
#FILENAME  == project.c
FILENAME = source
MAKEHEX = packihx
SRC = src

#sdcc -mmcs51 --model-small hw.c

all: project.hex
	cp $(FILENAME).hex  project.hex

project.hex: $(FILENAME).ihx
	$(MAKEHEX) $(FILENAME).ihx >> ./$(FILENAME).hex

$(FILENAME).ihx:
	$(CC) $(FLAGS) $(SRC)/$(FILENAME).c

.PHONY: clean

clean:
	-rm *.hex *.ihx


rebuild:
	-rm *.hex *.ihx *.mem *.bin *.lst *.cdb *.asm *.lk *.map *.omf *.rel
	make
