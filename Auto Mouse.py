import tkinter as tk
import sys
import pyautogui
import random
import keyboard

pyautogui.FAILSAFE = False
active = False

def close_program():
    sys.exit()

def toggle_active():
    global active
    active = not active
    print(f'Active state toggled to: {active}')

# Create a popup window
root = tk.Tk()
root.title("Auto Mouse")

# Remove window decorations
root.overrideredirect(True)

# Set window size and position
width = 106
height = 40
x = 0   # X-coordinate of the window's position
y = 970  # Y-coordinate of the window's position
root.geometry(f"{width}x{height}+{x}+{y}")

# Add a button to close the script
close_button = tk.Button(root, text="Close Script", command=close_program)
close_button.pack(pady=0)

# Register hotkeys before the Tkinter main loop
keyboard.add_hotkey('win+shift+q', close_program)
keyboard.add_hotkey('win+shift+m', toggle_active)

# Function to update the mouse movement based on the active state
def update_mouse_movement():
    if active:
        x = random.randint(100, 2000)
        y = random.randint(100, 1000)
        pyautogui.moveTo(x, y, 0.5)
    # Call this function again after 100ms
    root.after(100, update_mouse_movement)

# Start updating mouse movement
update_mouse_movement()

# Keep the window open and responsive
root.mainloop()
