rem @echo off
SET program="lab1-2.exe"
if %program% == "" goto err

echo Test1
%program% 0 0 0 > out.txt
if ERRORLEVEL 1 goto testFailed
fc.exe "out.txt" "Reference/reference1.txt"
if ERRORLEVEL 1 goto testFailed

echo Test2
%program% > out.txt
if ERRORLEVEL 1 goto testFailed
fc.exe "out.txt" "Reference/reference2.txt"
if ERRORLEVEL 1 goto testFailed

echo Test3
%program% 1 2 3 > out.txt
if ERRORLEVEL 1 goto testFailed
fc.exe "out.txt" "Reference/reference3.txt"
if ERRORLEVEL 1 goto testFailed

echo Test4
%program% a 2 3 > out.txt
fc.exe "out.txt" "Reference/reference4.txt"
if ERRORLEVEL 1 goto testFailed

echo Test5
%program% 2 5 3 > out.txt
fc.exe "out.txt" "Reference/reference5.txt"
if ERRORLEVEL 1 goto testFailed

echo Test6
%program% 2 -9 5 > out.txt
fc.exe "out.txt" "Reference/reference6.txt"
if ERRORLEVEL 1 goto testFailed

echo Test7
%program% 2 4 2 > out.txt
fc.exe "out.txt" "Reference/reference7.txt"
if ERRORLEVEL 1 goto testFailed


echo OK
exit /B

:noFile
echo file is missing
exit /B

:testFailed
echo Testing failed
exit /B

:err
echo Usage: test.bat <Path to program>;