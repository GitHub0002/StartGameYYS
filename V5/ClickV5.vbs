Set objWsh = CreateObject("WScript.Shell")
objWsh.Run("V5.exe")
Wsctipt.Sleep 1000
objwsh.SendKeys "{LEFT}"
'objWsh.AppActivate "V5.exe"
