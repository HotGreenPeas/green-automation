from tkinter import *
import serial
from tkinter import * 
from tkinter.ttk import *

window = Tk()
window.title('Greenhouse Data')
window.geometry("500x500")
window.config(bg = "#C8E6C9")

title = Label(window, text = "Greenhouse Data" , font = ("Georgia", 18, "bold"), foreground = "#3F8060", background = "#C8E6C9")

title.pack(side = TOP, anchor = "nw")
temp = 0
m_level = ""
h_level = 0
degree = " °C"
photon = 0

def fahrenheit(var):
    temp = (var * 9/5) + 32
    temp = round(temp, 1)
    temperature.config  (text = "Temperature: " + str(temp) + " °F")
    fahrenheit_button["state"] = "disabled"
    celsius_button["state"] = "normal"
def f():
    fahrenheit(temp)

def celsius(var):
    temp = (var - 32) * 5/9
    temp = round(temp, 1)
    temperature.config(text = "Temperature: " + str(temp) + " °C")
    celsius_button["state"] = "disabled"
    fahrenheit_button["state"] = "normal"

def c():
    celsius(temp)
    
temperature = Label(window)
temperature.config(text ="Temperature: " + str(temp) +  " °C", font = ("Georgia", 14), foreground = "#3F8060", background = "#C8E6C9")
temperature.pack(side = TOP, pady = 20, anchor = "w")
moisture_level = Label(window, text = "Moisture Level:" + m_level, font = ("Georgia", 14), foreground = "#3F8060", background = "#C8E6C9")
moisture_level.pack(side = TOP, pady = 0, anchor = "w")

humidity_level = Label(window, text = "Humidity:" + str(h_level) + "", font = ("Georgia", 14), foreground = "#3F8060", background = "#C8E6C9")
humidity_level.pack(side = TOP, pady = 20, anchor = "w" )
sun = Label(window, text = "Sunlight: " + str(photon) + " photons", font = ("Georgia", 14), foreground = "#3F8060", background = "#C8E6C9")

sun.pack(side = TOP, pady = 0, anchor = "w")


ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)
    
def update():
    ser.reset_input_buffer()
    line = ser.readline().decode('utf-8').rstrip()
    data = line.split(",")
    
    
    if(data != ['']):
        temp = data[0]
        hum = data[1]
        moisture  = data[2]
        sunlight = data[3]
        
        fahrenheit = float(temp)
        fahrenheit = (fahrenheit * 9/5) + 32 
        temperature['text']= "Temperature: " + temp + " °C / " + str(round(fahrenheit,2)) + " °F"
        moisture_level['text'] = "Moisture: " + moisture
        sun['text'] = "Sunlight: " + sunlight + " photons"
        humidity_level['text'] = "Humidity: " + hum + " %"
    
 
    
    else:
        temp    =  "0"
        hum    =  "0"
        moisture    =  "0"
        sunlight    =  "0"
        
    
    window.after(100, update) # run itself again after 500 ms
    
    
# run first time
update()

window.mainloop()