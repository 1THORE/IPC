# IPC

a utility to quickly get public ipv4 from [AmazonAWS Checkip](https://checkip.amazonaws.com)

## Project background:
I needed a utility that doesnt rely on `curl.exe` from `C:\Windows\System32`.

>This is a batch script that I was using that did the same thing.
```batch
@echo off
curl https://checkip.amazonaws.com/ > "%appdata%\ip.dat"
type "%appdata%\ip.dat"
```
I want to remove batch from my projects because honestly batch files are fucking ugly.
