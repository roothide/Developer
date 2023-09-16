# update jailbreak apps/tweaks for roothide
 
 1. Update theos to the latest

    [https://github.com/theos/theos](https://github.com/theos/theos)

 3. Build package for roothide


    for those simple tweaks that don't use the file api to access jailbreak files, just

    ```make package THEOS_PACKAGE_SCHEME=roothide```




if you need to use the file apis to access jailbroken files in source code,

(or in a shell script, or store the file path in config files), please see:

- [the difference between rootide and rootless](roothide.md).

- [roothide sdk api and tools](interface.md).

