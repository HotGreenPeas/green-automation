import tkinter
from tkinter import * 
from tkinter.ttk import *
window = tkinter.Tk()       # creating the window object
window.title('Greenhouse Data')
window.geometry("500x500")
window.config(bg = "")

title = tkinter.ttk.Label(window, text = "Greenhouse Data" )

title.pack()

temp = 2.00
m_level = ""
h_level = 0
degree = " °C"


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
temperature.config(text ="Temperature: " + str(temp) +  " °C")
temperature.pack()
celsius_button = Button(window, text = "°C", state = "disabled",  command = c)
celsius_button.pack()
fahrenheit_button = Button(window, text = "°F", command = f)
fahrenheit_button.pack()
moisture_level = Label(window, text = "Moisture Level:" + str(m_level))
moisture_level.pack()
humidity_level = Label(window, text = "Humidity:" + str(h_level) + "")
humidity_level.pack()


# write your code here

window.mainloop()           # keeping the window until we close it