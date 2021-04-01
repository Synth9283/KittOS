target = kittos
isoDir = kernel/iso/boot
boot = $(isoDir)/boot.o
kernel = $(isoDir)/$(target).o
bin = $(isoDir)/$(target).bin
iso = $(isoDir)/$(target).iso
src = $(wildcard kernel/src/*.c)
obj = $(src:.c=.o)
linker = $(isoDir)/linker.ld
compiler = gcc
compilerFlags = -m32 -std=c99 -ffreestanding -O2 -Wall -Wextra -fstack-protector 

all: $(iso)

$(iso): $(bin)
	grub-mkrescue kernel/iso -o $^

$(bin): $(boot) $(kernel) $(obj)
	$(compiler) -T $(linker) $(compilerFlags) -nostdlib $^ -o $@

$(boot): $(isoDir)/boot.asm
	nasm -f elf32 $^ -o $@

$(kernel): main.c
	$(compiler) -c $^ $(compilerFlags) -o $@

%.o: %.c
	$(compiler) -c $(compilerFlags) $^ -o $@

clean:
	rm -rfv kernel/src/*.o $(boot) $(kernel) $(bin) $(iso)
