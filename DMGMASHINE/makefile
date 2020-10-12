#All variable.
PROJ_NAME = main
CC = @arm-none-eabi-gcc
OBJECT_COPY = @arm-none-eabi-objcopy
SRC = src/
CMSIS_DIR = CMSIS/
OUT_DIR = out/
SCRIPT_DIR = script/

CFLAG = -mcpu=cortex-m3	\
		-I CMSIS/						\
		-I inc/							\
		-mthumb							\
		-Wl,--gc-sections		\
		-MMD								\
		-T $(SCRIPT_DIR)stm32_flash.ld

OBJECT = $(patsubst src/%.c,out/%.o,$(wildcard src/*.c))	\
$(patsubst CMSIS/%.c,out/%.o,$(wildcard CMSIS/*.c))				\
$(patsubst CMSIS/%.s,out/%.o,$(wildcard CMSIS/*.s))

.PHONY: load erase loadbootloader clean hex

$(OUT_DIR)$(PROJ_NAME).elf: $(OBJECT)
	$(CC) $(CFLAG) -o $(OUT_DIR)$(PROJ_NAME).elf $(OBJECT)
	$(OBJECT_COPY) -Oihex $(OUT_DIR)$(PROJ_NAME).elf $(OUT_DIR)$(PROJ_NAME).hex

$(OUT_DIR)%.o: $(SRC)%.c
	$(CC) $(CFLAG) -c  $< -o $@

$(OUT_DIR)%.o: $(CMSIS_DIR)%.c
	$(CC) $(CFLAG) -c  $< -o $@

$(OUT_DIR)%.o: $(CMSIS_DIR)%.s
	$(CC) $(CFLAG) -c  $< -o $@

sinclude $(OUT_DIR)*.d

erase: $(SCRIPT_DIR)/erase.jlink
	@JLinkExe -device stm32f103c8 -si swd -speed 4000 $(SCRIPT_DIR)erase.jlink

load: $(OUT_DIR)$(PROJ_NAME).elf
	@JLinkExe -device stm32f103c8 -si swd -speed 4000 $(SCRIPT_DIR)load.jlink

loadbootloader: $(SCRIPT_DIR)bootloader.bin
	@JLinkExe -device stm32f103c8 -si swd -speed 4000 $(SCRIPT_DIR)loadbootloader.jlink

clean:
	@-rm -f $(OUT_DIR)*.hex $(OUT_DIR)*.o $(OUT_DIR)*.bin $(OUT_DIR)*.elf $(OUT_DIR)*.d
