import curses
stdscr = curses.initscr()
curses.noecho()
curses.cbreak()
stdscr.keypad(1)

import serial
import time
ser = serial.Serial('/dev/ttyACM0', 115200, timeout=1)
ser.flush()

ser.write(b"SET_SPEED\n")
ser.write(b"400\n")

while True:
    inp = chr(stdscr.getch()).lower()
    if inp == "w":
        ser.write(b"FORWARD\n")
    if inp == "s":
        ser.write(b"BACKWARD\n")
    if inp == "a":
        ser.write(b"LEFT\n")
    if inp == "d":
        ser.write(b"RIGHT\n")
    if inp == "b":
        ser.write(b"STOP\n")
    line = ser.readline().decode('utf-8').rstrip()
    print(line)
    time.sleep(0.001)