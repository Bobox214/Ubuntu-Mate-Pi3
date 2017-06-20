# This requires the standard MegaPi firmware to be loaded on the MegaPi
from megapi import *
from time import sleep

bot = MegaPi()
bot.start('/dev/serial0')
while True:
    bot.digitalWrite(13,1);
    sleep(0.1)
    bot.digitalWrite(13,0);
    sleep(0.1)
