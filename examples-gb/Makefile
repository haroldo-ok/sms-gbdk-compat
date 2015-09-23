SHELL=C:/Windows/System32/cmd.exe
CC	= sdcc -mz80 -I../include/gb -I../SMSlib/src

BINS	= galaxy.gg


all:	$(BINS)

%.rel:	%.c
	$(CC) -c --std-sdcc99 $<

%.gg:	%.ihx
	ihx2sms $< $@

galaxy.ihx:	galaxy.rel ../lib/gb/gb.rel
	$(CC) --data-loc 0xC000 $< gb.rel ../SMSlib/SMSlib_GG.rel

clean:
	rm -f *.ihx *.lk *.lst *.map *.noi *.rel *.sym *.asm *.sms
