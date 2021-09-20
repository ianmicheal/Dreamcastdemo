TARGET = engine.elf
OBJS = main.o   \
			  point.o \
			 camera.o \
			   math.o \
			 system.o \
		      dreamcast.o \
		          model.o \
			    obj.o \
                texture_manager.o \
                            bmp.o \
                            map.o \
                         sphere.o \
                         entity.o \
                         player.o \
		      collision.o


INC_DIR = "include"

CFLAGS += -I $(INC_DIR) -fpermissive
OBJEXTRA = libGLdc.a

all: rm-elf $(TARGET)

include $(KOS_BASE)/Makefile.rules

clean:
	-rm -f 1ST_READ.BIN
	-rm -f IP.BIN
	-rm -f *.o

rm-elf:
	-rm -f $(TARGET) romdisk.*

$(TARGET): $(OBJS)
	$(KOS_CC) $(KOS_CFLAGS) $(KOS_LDFLAGS) -o $(TARGET) $(KOS_START) \
		$(OBJS) $(OBJEXTRA) -lm -lstdc++ -lkosutils $(KOS_LIBS) -fpermissive

run: $(TARGET)
	$(KOS_LOADER) $(TARGET)

dist:
	rm -f $(OBJS) romdisk.o romdisk.img
	$(KOS_STRIP) $(TARGET)
