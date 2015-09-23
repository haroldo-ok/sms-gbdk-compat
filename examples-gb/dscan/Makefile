SHELL=C:/Windows/System32/cmd.exe
CC	= sdcc -mz80 -I../../include/gb -I../../SMSlib/src

BINS	= dscan.gg


all:	$(BINS)

%.rel:	%.c
	$(CC) -c --std-sdcc99 $< -o $@

%.gg:	%.ihx
	ihx2sms $< $@

dscan.ihx:	dscan.rel bkg.rel fore.rel ../../lib/gb/gb.rel
	$(CC) --data-loc 0xC000 $^ ../../SMSlib/SMSlib_GG.rel

clean:
	rm -f *.ihx *.lk *.lst *.map *.noi *.rel *.sym *.asm *.sms
