@echo off

rem Define the hooks patch as $root/hooks over $root/.git/hooks so we can run our own hooks:
git config core.hooksPath hooks

if %ERRORLEVEL% neq 0 (
	pause
)

exit /B %ERRORLEVEL%
