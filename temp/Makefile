#
# Replace OPENCV_DIR with your OpenCV base directory
# 
OPENCV_DIR	= /usr/include/opencv2
OBJS		= template_match.o
CC		= gcc
DEBUG		= -g
CFLAGS		= -c -I/usr/include/opencv -I"$(OPENCV_DIR)/core/include" \
				 -I"$(OPENCV_DIR)/ml/include" \
				 -I"$(OPENCV_DIR)/cv/include" \
				 -I"$(OPENCV_DIR)/highgui"
LFLAGS		= -L"$(OPENCV_DIR)\lib" -lopencv_core -lopencv_highgui -lopencv_ml

all: $(OBJS)
	$(CC) $(OBJS) $(LFLAGS) -o template_match

template_match.o: template_match.c
	$(CC) $(CFLAGS) template_match.c

clean:
	del *.o
