@echo off
SET program="%1"
if %program% == "" goto err


echo Test1 >> out.txt
%program% input.txt 123 >> out.txt
if ERRORLEVEL 1 goto testFailed
if ERRORLEVEL 0 echo ...OK >> out.txt

echo Test2 >> out.txt
%program% "input2.txt" "123" >> out.txt
if ERRORLEVEL 1 goto testFailed
if ERRORLEVEL 0 echo ...OK >> out.txt

echo Test3 >> out.txt
%program% "input3.txt" "123" >> out.txt
if NOT ERRORLEVEL 1 goto testFailed
if ERRORLEVEL 0 echo ...OK >> out.txt

echo Test4 >> out.txt
%program% "input4.txt" "123" >> out.txt
if ERRORLEVEL 1 goto testFailed
if ERRORLEVEL 0 echo ...OK >> out.txt

echo Test5 >> out.txt
%program% "input56.txt" "123" >> out.txt
if NOT ERRORLEVEL 1 goto testFailed
if ERRORLEVEL 0 echo ...OK >> out.txt

echo Test6 >> out.txt
%program% "input.txt" >> out.txt
if NOT ERRORLEVEL 1 goto testFailed
if ERRORLEVEL 0 echo ...OK >> out.txt

echo OK
pause
exit /B

:testFailed
echo Testing failed
pause
exit /B

:err
echo Usage: test.bat <Path to program>