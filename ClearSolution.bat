@echo current path : %cd%
@echo vs2015+
@echo ���������ļ���ɾ��vs��������ʱ�ļ�������cpp�������ļ���ʹ��ǰ�뿴�ļ����ݡ�
@echo set a=%cd%
@echo if not ("%a:Windows=%"=="%a%") ( msg %username% /time:3 "����ϵͳ�ļ��У�����ִ�У�3����Զ��˳���" & exit)
rem del /S/q *.exe
del /S/q *.db
del /S/q *.aps
del /S/q *.obj
del /S/q *.log
del /S/q *.pch
del /S/q *.pdb
del /S/q *.tlog
del /S/q *.lastbuildstate
del /S/q *.ilk
del /S/q *.idb
rd /s/q ipch
rem rd /S/s/q Debug
rem rd /s/q Release
for /f "delims=" %%I in ('dir /b/s/ad Release Debug') do echo "%%I"

for /f "delims=" %%s in ('dir /b/s/ad  tlog ipch') do rd /s/q "%%s"

@echo vs 2010-
del /S/q *.sdf
del /S/q/ah *.suo
( msg %username% /time:3 "�ļ��������~��3����Զ��˳���" & exit)