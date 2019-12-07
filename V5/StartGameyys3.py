#coding=utf-8

import win32api
import win32con

import time
#程序多开器启动
#win32api.WinExec("cmd /c G:\v5chengxuduokaiqi_itmop.com\V5\V5.exe",1)
win32api.ShellExecute(0, 'open', r'F:\v5chengxuduokaiqi_itmop.com\V5\V5.exe', '','',1)
win32api.keybd_event(13,0,0,0)

print(time.ctime())
time.sleep( 1 )
print(time.ctime())

win32api.keybd_event(13,0,win32con.KEYEVENTF_KEYUP,0)




