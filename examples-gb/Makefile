SHELL=C:/Windows/System32/cmd.exe
CC	= sdcc -mz80

BINS	= galaxy.sms


all:	$(BINS)

%.rel:	%.c
	$(CC) -c --std-sdcc99 $<

%.sms:	%.ihx
	ihx2sms $< $@

galaxy.ihx:	galaxy.rel
	$(CC) --data-loc 0xC000 galaxy.rel ../SMSlib/SMSlib.rel

clean:
	rm -f *.ihx *.lk *.lst *.map *.noi *.rel *.sym *.asm *.sms
