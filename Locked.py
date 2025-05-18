import os
import time

# Load user list from file
u_loaded = []
with open('C:\\Users\\minyg\\OneDrive\\Documents\\Visual\\user_list.txt', 'r') as file:
    for line in file:
        u_loaded.append(line.strip())

def clear():
    """Clear the console screen."""
    if os.name == 'nt':
        os.system('cls')
    else:
        os.system('clear')

u = u_loaded

# Start of the code
while True:
    clear()
    while True:
        user = input('Log in:').lower()
        if user in u:
            break
        else:
            print('Unknown User')
    
    clear()
    print('WELCOME USER')
    
    while True:
        pas = input('Password:')
        if pas == '123':
            break
        else:
            print('Access Denied')
    
    print('\nAccess Granted')
    time.sleep(1)
    
    while True:
        clear()
        print('What would you like to do?')
        print('1 - Open Messages')
        print('2 - Write Message')
        print('3 - Set Up New User')
        print('4 - Log Out')

        task = input('Task Number:').strip()

        if task == '1':
            clear()
            print('Opening Messages...')
            time.sleep(0.5)
            try:
                with open('C:\\Users\\minyg\\OneDrive\\Documents\\Visual\\note.txt', 'r') as file:
                    mes = file.read()
            except FileNotFoundError:
                mes = 'File not found.'
            print(mes)
            input('Press Enter to return to menu')  # Wait for user input
        elif task == '2':
            clear()
            print('Write a message. Press Enter when finished:')
            message = input()
            with open('C:\\Users\\minyg\\OneDrive\\Documents\\Visual\\note.txt', 'w') as file:
                file.write(message)
            print('Your message was saved!')
            time.sleep(1)
        elif task == '3':
            clear()
            print('Type in the user you would like to register:')
            new_user = input('New User:').strip()
            if new_user not in u:
                u.append(new_user)
                with open('C:\\Users\\minyg\\OneDrive\\Documents\\Visual\\user_list.txt', 'w') as file:
                    for user in u:
                        file.write(user + '\n')
                print(f'User {new_user} registered successfully.')
                time.sleep(0.5)
            else:
                print('User already exists.')
            time.sleep(0.5)
        elif task == '4':
            print('Successfully Logged Out')
            break
        else:
            print('Invalid option. Please choose 1, 2, 3, or 4.')
        
        if task == '4':
            break
    if task == '4':
        break
