


import tkinter as tk
import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
temp_lst = []
hum_lst = []
moisture_lst = []
sun_lst = []
data1 = {'seconds': [0,1,2,3,4,5,6,7,8,9,10],
         'temperature': temp_lst
         }
df1 = pd.DataFrame(data1)

data2 = {'seconds': [0,1,2,3,4,5,6,7,8,9,10],
         'humidity': hum_lst
         }  
df2 = pd.DataFrame(data2)

data3 = {'seconds': [0,1,2,3,4,5,6,7,8,9,10],
         'moisture': moisture_lst
         }
df3 = pd.DataFrame(data3)

window = tk.Tk()



figure2 = plt.Figure(figsize=(5, 4), dpi=100)
ax2 = figure2.add_subplot(111)
line2 = FigureCanvasTkAgg(figure2, window)
line2.get_tk_widget().pack(side=tk.LEFT, fill=tk.BOTH)
df1 = df1[['seconds', 'temperature']].groupby('seconds').sum()
df1.plot(kind='line', legend=True, ax=ax2, color='r', marker='o', fontsize=10)
ax2.set_title('Temperature')

figure3 = plt.Figure(figsize=(5, 4), dpi=100)
ax2 = figure3.add_subplot(111)
line2 = FigureCanvasTkAgg(figure3, window)
line2.get_tk_widget().pack(side=tk.LEFT, fill=tk.BOTH)
df2 = df2[['seconds', 'humidity']].groupby('seconds').sum()
df2.plot(kind='line', legend=True, ax=ax2, color='r', marker='o', fontsize=10)
ax2.set_title('Humidity')

figure4 = plt.Figure(figsize=(5, 4), dpi=100)
ax2 = figure4.add_subplot(111)
line2 = FigureCanvasTkAgg(figure4, window)
line2.get_tk_widget().pack(side=tk.LEFT, fill=tk.BOTH)
df3 = df3[['seconds', 'moisture']].groupby('year').sum()
df3.plot(kind='line', legend=True, ax=ax2, color='r', marker='o', fontsize=10)
ax2.set_title('Year Vs. Unemployment Rate')

window.mainloop()
