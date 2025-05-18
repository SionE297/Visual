import os
import time

def clear():
    """Clear the console screen."""
    try:
        if os.name == 'nt':
            os.system('cls')
        else:
            os.system('clear')
    except Exception as e:
        print(f"Failed to clear the screen: {e}")

message = "Default message"
user = {
        'joness':'078',
        'sion':'123',
        'rhys':'123',
        'bob':'1',
}
admin_pass = 'qwerty'
reply = 'No Reply'
kill = False

def admin_controls():
    global message, reply, kill
    while True:
        clear()
        print('Admin Access')
        print()
        print('1 - Register New User')
        print('2 - View Message')
        print('3 - Change Message')
        print('4 - Delete Replies')
        print('5 - Delete User')
        print('6 - Extra Options')
        print('7 - Exit')
        choice = input('>>> ')
        
        if choice == '1':
            print('Register New User:')
            new_username = input('Username: ').lower()
            new_password = input('Password: ')
            user[new_username] = new_password
            print(f'Added {new_username} with password {new_password} as new login details')
            time.sleep(2)
        elif choice == '2':
            clear()
            print(f'Message: {message}')
            print()
            input('Press Enter to Exit')
        elif choice == '3':
            message = input('Enter new message: ')
            print('Message updated.')
            time.sleep(2)
        elif choice == '4':
            reply = 'No Reply'
            print('All Replies Deleted.')
            time.sleep(1)
        elif choice == '5':
            pop_user = input('Type the user you would like to delete:')
            try:
                user.pop(pop_user)
                print(f'Removed {pop_user} from the list of users.')
            except: print(f'{pop_user} was not in the user list.')
            time.sleep(4)
        elif choice == '6':
            print('/kill - Exit Program')
            time.sleep(4)
        elif choice == '7':
            break
        elif choice == '/kill':
            kill = True
            break
        else:
            print('Invalid choice. Please try again.')
            time.sleep(1)

def login():
    global kill
    while True:
        clear()
        print('Log in')
        time.sleep(0.3)

        username = input('Username: ').lower()
        password = input('Password: ')
        
        if username in user and password == user[username]:
            print('Access Granted')
            time.sleep(1)
            break
        elif username == 'admin' and password == admin_pass:
            admin_controls()
            if kill:
                break
            else:
                continue
        else:
            print('Access Denied')
            time.sleep(1)
        if kill:
            break

clear()
print('Write Your Message Here. Press Enter When Done:')
message = input()

while True:
    if kill:
        break
    clear()
    login()
    if kill:
        break
    clear()
    print('Message:')
    print()
    print(message)
    print()

    if reply == 'No Reply':
        reply = input('Leave a reply (optional): ').strip()
        if reply:
            print('Reply will show next time the message is opened.')
            time.sleep(3)
    else:
        print('Replies:')
        print()
        print(reply)
        new_reply = input('Leave a new reply (optional): ').strip()
        if new_reply:
            reply += "\n" + new_reply
            print('Reply will show next time the message is opened.')
            time.sleep(3)
