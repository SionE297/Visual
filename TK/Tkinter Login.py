import tkinter
import ctypes
import json
import os

# Enable high DPI awareness for roots to prevent scaling issues
try:
    ctypes.windll.shcore.SetProcessDpiAwareness(2)  # Use "2" for full DPI awareness (roots 10)
except:
    pass

# Get the directory of the current script


with open('C:\\Users\\minyg\\OneDrive\\Documents\\Visual\\TK\\Users.JSON', 'r') as file:
    user=json.load(file)
    
input_user=None
input_password=None
mode = tkinter.NORMAL
full_size=False #Oposite of boolen
message=None
count=0

def login():
    global message
    global count
    if count < 3:
        if user_entry.get().lower() in user and password_entry.get() == user[user_entry.get().lower()]:
            root.quit()
        else:
            message='Access Denied'
            output_label.config(text=message)
            count += 1
    else: root.quit()

def switch_state():
    global mode
    if mode == tkinter.DISABLED:
        mode = tkinter.NORMAL
    else:
        mode = tkinter.DISABLED
    user_entry.config(state=mode)


root = tkinter.Tk()
root.title("Login")
root.geometry('600x400')
root.configure(bg='#000000')

def full_screen():
    global full_size
    full_size=not full_size
    root.overrideredirect(full_size)

full_screen()

def center_window(window, width, height):
    # Get screen dimensions
    screen_width = window.winfo_screenwidth()
    screen_height = window.winfo_screenheight()
    
    # Calculate position
    x = (screen_width // 2) - (width // 2)
    y = (screen_height // 2) - (height // 2)
    
    # Set root geometry and position
    window.geometry(f'{width}x{height}+{x}+{y}')

center_window(root, 600, 400)

# Ensure the window stays visible in the taskbar
root.attributes('-topmost', True)  # Decides if this window can disapere

frame=tkinter.Frame(bg='#000000', pady=30)
frame.pack()

label = tkinter.Label(frame, fg='#20C20E', bg='#000000', text="Login", font=('arial rounded mt bold',30), pady=30)
label.grid(row=0, column=0, columnspan=3)
user_entry = tkinter.Entry(frame, font=('arial rounded mt bold',14), fg='#20C20E', bg='#454545', state=mode)
user_entry.grid(row=1, column=1, pady=10, padx=50)
password_entry = tkinter.Entry(frame, show='•', font=('arial rounded mt bold',14), fg='#20C20E', bg='#454545', state=mode)
password_entry.grid(row=2, column=1, pady=10, padx=50)
submit = tkinter.Button(frame, font=('arial rounded mt bold',10), fg='#20C20E', bg='#454545', text="Enter", command=login)
submit.grid(row=3, column=1, )

spacer=tkinter.Frame(bg='#000000', height=28)
spacer.pack()

message_frame=tkinter.Frame(bg='#000000', width=590, height=24,)
message_frame.pack_propagate(False)
message_frame.pack()
output_label = tkinter.Label(message_frame, fg='#ffffff', bg='#000000', text=message, font=('arial rounded mt bold',6))
output_label.pack(side='left')


root.mainloop()