import tkinter as tk
import sys

def close_program():
    sys.exit()

# Create a popup window
root = tk.Tk()
root.title("Script Running")

# Set window size
root.geometry("200x100")

# Add a label to indicate the script is running
label = tk.Label(root, text="The script is running.")
label.pack(pady=10)

# Add a button to close the script
close_button = tk.Button(root, text="Close Script", command=close_program)
close_button.pack(pady=10)

# Keep the window open
root.mainloop()
