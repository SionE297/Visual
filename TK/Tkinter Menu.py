import customtkinter
import ctypes

# Enable high DPI awareness for roots to prevent scaling issues
try:
    ctypes.windll.shcore.SetProcessDpiAwareness(2)  # Use "2" for full DPI awareness (Windows 10+)
except:
    pass

bg0 = '#2e2e2e'
fg0 = '#ffffff'
highlight_color = '#1e90ff'  # Use a blue highlight color for selected options

# Function to center the window
def center_window(window, width, height):
    screen_width = window.winfo_screenwidth()
    screen_height = window.winfo_screenheight()
    x = (screen_width // 2) - (width // 2)
    y = (screen_height // 2) - (height // 2)
    window.geometry(f'{width}x{height}+{x}+{y}')

# Function to create the main menu
def open_menu():
    menu = customtkinter.CTk()
    menu.title("Options")
    center_window(menu, 800, 500)
    customtkinter.set_appearance_mode("dark")
    customtkinter.set_default_color_theme("dark-blue")

    # Main frame
    menu_frame = customtkinter.CTkFrame(master=menu, fg_color=bg0, corner_radius=10, width=400)
    menu_frame.pack(pady=40)

    # Options
    options = []
    for text in ["Option 1", "Option 2", "Option 3", "Option 4"]:
        option = customtkinter.CTkLabel(menu_frame, text_color=fg0, font=('arial rounded mt bold', 20), text=text)
        option.pack(pady=10, padx=20)
        options.append(option)

    # Keep track of current option
    current_option = 0

    # Update option color
    def highlight_option(option_index):
        for i, option in enumerate(options):
            if i == option_index:
                option.configure(text_color='#000000', fg_color=highlight_color)
            else:
                option.configure(text_color=fg0, fg_color=bg0)

    # Set initial highlight
    highlight_option(current_option)

    # Define what happens when "Enter" is pressed
    def press():
        nonlocal current_option
        menu.destroy()
        if current_option == 0:
            open_opt0()

    # Event handling for up/down keys
    def on_key_press(event):
        nonlocal current_option
        if event.keysym == 'Up':
            current_option = (current_option - 1) % len(options)
        elif event.keysym == 'Down':
            current_option = (current_option + 1) % len(options)
        highlight_option(current_option)
        if event.keysym == 'Return':
            press()

    # Bind arrow keys and Enter to window
    menu.bind("<Up>", on_key_press)
    menu.bind("<Down>", on_key_press)
    menu.bind("<Return>", on_key_press)

    menu.mainloop()

# Function to create the opt0 window
def open_opt0():
    opt0 = customtkinter.CTk()
    opt0.title("Messages")
    center_window(opt0, 400, 200)

    # Message label
    message_label = customtkinter.CTkLabel(opt0, text="This is Option 1", font=('arial rounded mt bold', 20), text_color=fg0)
    message_label.pack(pady=20)

    # Button to go back to menu
    back_button = customtkinter.CTkButton(opt0, text="Back to Menu", fg_color=highlight_color, text_color='#ffffff', command=lambda: [opt0.destroy(), open_menu()])
    back_button.pack(pady=10)

    opt0.mainloop()

# Start by opening the menu
open_menu()
