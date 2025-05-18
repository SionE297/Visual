import os
def clear():
    os.system('cls')
def xor_encrypt_decrypt(message, key):
    encrypted_message = ''.join(chr(ord(c) ^ ord(key[i % len(key)])) for i, c in enumerate(message))
    return encrypted_message

clear()
while True:
    original_message = input('Original Message:')
    encryption_key = "key"
    encrypted_message = xor_encrypt_decrypt(original_message, encryption_key)
    print("Encrypted Message:", encrypted_message)  # Save this output securely