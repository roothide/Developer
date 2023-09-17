# File/Directory Mirror

there are some specific file/directory paths in jbroot, which we set as symlinks to the original rootfs, 
because there is no reason to create a separate copy in jbroot, and this simplifies maintenance of jailbreak app/daemon/tweak,
especially for bootstrap, since it uses jbroot as the default root through [libvroot](vroot.md), this method can replace the patching of the source code of each package.
(of cause under certain circumstances we can also replace it with a copy of the jailbroken version to meet our needs).

| path in jbroot |
| :-----|
| /dev |
| /private/preboot |
| /var/run/utmpx |
| /var/db/timezone |
| /var/containers |
| /private/var/mobile/Containers |
| /usr/share/misc/trace.codes |
| /usr/share/zoneinfo |
| /etc/hosts.equiv |
| /etc/hosts |
| /System/Library/CoreServices/SystemVersion.plist |

