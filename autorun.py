import os
import pyautogui
import time
def cmd(command):
    pyautogui.hotkey('win','r')
    time.sleep(0.1)
    pyautogui.write('cmd')
    pyautogui.press('enter')
    time.sleep(2)
    pyautogui.write(command)
    pyautogui.press('enter')
def open_app(app):
    pyautogui.press('win')
    time.sleep(1)
    pyautogui.write(app)
    pyautogui.press('enter')


cmd('hello')