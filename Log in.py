import os
import time
u_loaded = []
with open('C:\\Users\\minyg\\OneDrive\\Documents\\Visual\\user_list.txt','r') as file:
    for line in file:
        u_loaded.append(line.strip())

def clear():
    if os.name == 'nt':
        os.system('cls')
    else:
        os.system('clear')
u = u_loaded
# START OF CODE 
while True:
    clear()
    while True:
        user = input('Log in:').lower()
        if user in u:
            break
        else: print('Unknown User')
    clear()
    print('WELCOME USER')
    a=True
    while a == True:
        pas = input('Password:')
        if pas == '123':
            break
        else: print('Access Denied')
    print()
    print('Access Granted')
    time.sleep(1)
    clear()
    while True:
        flag = False
        clear()
        print('What would you like to me to do?')
        print('1 - Open Messages')
        print('2 - Write Message')
        print('3 - Set Up New User')
        print('4 - Log Out')
        while True:
            task= str(input('Task Number:'))
            #new
            if task== '1':
                print()
                print('Opening Messages...')
                time.sleep(0.5)
                with open('C:\\Users\\minyg\\OneDrive\\Documents\\Visual\\note.txt','r') as file:
                    mes = file.read()
                print(mes)
                print()
                if input('Type anything to return to menu:'): flag = True
                
            #new
            elif task== '2':
                clear()
                print('{Write a message. Press Enter when finished}')
                with open('C:\\Users\\minyg\\OneDrive\\Documents\\Visual\\note.txt', 'w') as file:
                    file.write(input())
                    print('Your message was saved!')
                    time.sleep(1)    
                break 
            #new
            elif task== '3':
                print()
                print('Type in the user you would like to register')
                z = input('New User:')
                u.append(z)
                with open('C:\\Users\\minyg\\OneDrive\\Documents\\Visual\\user_list.txt', 'w') as file:
                    for user in u:
                        file.write(user + '\n')
                
                print(f'User {z} registered successfully.')
                time.sleep(1)
                break
            #new
            elif task== '4':
                print()
                print('Successfully Logged Out')
                print()
                break
            
            else: print('Invalid option. Please choose 1, 2, or 3.')
    if task == '4':
        break
        if flag: True