@echo off
setlocal enabledelayedexpansion

set "file=devices.txt"
set "count=0"

REM 读取设备列表文件
for /f "tokens=1,2,3" %%a in (%file%) do (
    set /a count+=1
    set "id[!count!]=%%a"
    set "name[!count!]=%%b"
    set "ip[!count!]=%%c"
)

REM 列出设备信息
echo ID   Device Name   Address
for /l %%i in (1,1,%count%) do (
    echo !id[%%i]!    !name[%%i]!   !ip[%%i]!
)

REM 用户选择设备ID
set /p "choice=Enter device ID or type 'exit' to quit: "
if /i "%choice%" equ "exit" exit /b 0

REM 执行SSH连接
if %choice% geq 1 if %choice% leq %count% (
    set "sshCmd=ssh root@!ip[%choice%]!"
    powershell.exe -Command "!sshCmd!"
) else (
    echo Please enter a valid device ID.
)

exit /b 0
