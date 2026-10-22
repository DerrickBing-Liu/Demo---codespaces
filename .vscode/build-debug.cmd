@echo off
rem Configure + build the Debug target with MSVC.
rem Invoked by the "cmake: build debug" VS Code task; also runnable by hand.
rem
rem vcvars64.bat takes ~45s on this machine, which stalls every F5, so its
rem resulting environment is captured once into build\msvc-env.txt and replayed
rem on later runs. Delete that file after a Visual Studio update to refresh it.
setlocal

set "VS=C:\Program Files\Microsoft Visual Studio\18\Professional"
set "VCVARS=%VS%\VC\Auxiliary\Build\vcvars64.bat"
set "CMAKE=%VS%\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe"
set "SRC=%~dp0.."
set "BUILD=%SRC%\build\debug"
set "ENVCACHE=%SRC%\build\msvc-env.txt"

if not exist "%VCVARS%" (
    echo ERROR: vcvars64.bat not found at "%VCVARS%"
    exit /b 1
)
if not exist "%CMAKE%" (
    echo ERROR: cmake.exe not found at "%CMAKE%"
    exit /b 1
)

if exist "%ENVCACHE%" goto :loadenv

echo Initializing the MSVC environment - one-time, takes about a minute ...
if not exist "%SRC%\build" mkdir "%SRC%\build"
rem vcvars64.bat calls vswhere.exe unqualified; put its folder on PATH to keep it quiet.
set "PATH=%ProgramFiles(x86)%\Microsoft Visual Studio\Installer;%PATH%"
call "%VCVARS%" >nul
if %errorlevel% neq 0 (
    echo ERROR: failed to initialize the MSVC environment
    exit /b 1
)
set > "%ENVCACHE%.tmp"
rem Drop cmd's pseudo-variables ^(lines starting with =^), which are not assignable.
findstr /v /b "=" "%ENVCACHE%.tmp" > "%ENVCACHE%"
del "%ENVCACHE%.tmp"
goto :configure

:loadenv
for /f "usebackq delims=" %%L in ("%ENVCACHE%") do set "%%L"

:configure
rem Configure only when there is no generated build system yet.
rem Ninja re-runs CMake by itself when CMakeLists.txt changes, so this stays correct.
rem Each check compares with neq 0 rather than using "if errorlevel 1": cmake reports a
rem failed build as -1, and "if errorlevel 1" is a >= test that would call that success.
rem The checks stay outside any parenthesized block so %errorlevel% is not expanded early.
if exist "%BUILD%\build.ninja" goto :build

echo Configuring %BUILD% ...
"%CMAKE%" -S "%SRC%" -B "%BUILD%" -G Ninja -DCMAKE_BUILD_TYPE=Debug
if %errorlevel% neq 0 exit /b 1

:build
"%CMAKE%" --build "%BUILD%"
if %errorlevel% neq 0 exit /b 1

exit /b 0
