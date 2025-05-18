import keyboard

print("Press 'q' to quit.")

# Function to print the key pressed
def on_key_event(event):
    print(f"Key pressed: {event.name}")
    if event.name == 'q':
        print("You pressed 'q'. Exiting...")
        keyboard.unhook_all()  # Stop listening for key presses

# Listen for all key presses
keyboard.on_press(on_key_event)

# Wait until 'q' is pressed to exit
keyboard.wait('q')
