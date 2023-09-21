# update jailbreak apps/tweaks for roothide
 
 1. Update your theos to the this

    ```git clone --recursive https://github.com/roothide/theos.git ```
    
    this theos is always automatically updated to latest with the upstream.

 3. Build package for roothide


    for those simple tweaks that don't use the file api to access jailbreak files, just

    ```make package``` with ```THEOS_PACKAGE_SCHEME=roothide```


if you need to use the file apis to access jailbreak files in source code,

(or in shell scripts, or store the file path in config files), please see:

- [the difference between rootide and rootless](roothide.md).

- [entitlements and data sharing via files](entitlements.md).
  
- [roothide's sdk api and tools](interface.md).


# get support

- roothide discord server: https://discord.gg/scqCkumAYp

- theos dev discord server: https://discord.gg/z4RTnrcbKW

- procursus discord server: https://discord.gg/QJDrrAJPDY
