import RPi.GPIO as GPIO
import sys
board_type = sys.argv[-1]

GPIO.setmode(GPIO.BCM)                              # initialise RPi.GPIO

# set up ports 23 for input pulled-up high
GPIO.setup(23, GPIO.IN, pull_up_down=GPIO.PUD_UP)       

if board_type == "m":
    print "These are the connections you must make on the Multiface for this test:"
    print "GPIO 23 --- 3 in BUFFERS"
    print "GPIO 22 --- 6 in BUFFERS"
    print "BUFFER DIRECTION SETTINGS 3, pin 2 --- 6 in top header (next to leds)"
    print "jumper on BUFFER DIRECTION SETTINGS 'IN' 6"

else:
    print "These are the connections you must make on the Gertboard for this test:"
    print "GP23 in J2 --- B3 in J3"
    print "GP22 in J2 --- B6 in J3"
    print "U3-out-B3 pin 1 --- BUF6 in top header"
    print "jumper on U4-in-B6"
raw_input("When ready hit enter.\n")

button_press = 1                           # set intial values for variables
previous_status = ''

try:
	while button_press>0:
        	status_list = GPIO.input(23) 
        	if status_list:
			print "waiting"
           	 #status_list = "1"
        	else:
			print "pressed"
           	 #status_list = "0" 
                    # dump current status values in a variable
        #current_status = ''.join((status_list[0],status_list[1]))
                    # if that variable not same as last time 
       # if current_status != previous_status:
          #  print current_status                             # print the results 
                    # update status variable for next comparison
           # previous_status = current_status
           # button_press += 1                   # increment button_press counter

except KeyboardInterrupt:          # trap a CTRL+C keyboard interrupt
    GPIO.cleanup()                 # resets all GPIO ports
GPIO.cleanup()                     # on exit, reset  GPIO ports used by program
