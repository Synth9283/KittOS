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
compilerFlags = -m32 -std=c99 -ffreestanding -O2 -Wall -Wextra

all: $(iso)

$(iso): $(bin)
	grub-mkrescue kernel/iso -o $^

$(bin): $(boot) $(kernel)
	$(compiler) -T $(linker) $(compilerFlags) -nostdlib $^ -o $@

$(boot): $(isoDir)/boot.s
	i686-elf-as $^ -o $@

$(kernel): main.c $(obj)
	$(compiler) -c $^ $(compilerFlags) -T $(linker) -o $@

%.o: %.c
	$(compiler) -c $(compilerFlags) $^ -o $@

clean:
	rm -rfv kernel/src/*.o $(boot) $(kernel) $(bin) $(iso)
