Before reading this, you may also want to know [the difference between rootide and rootless](roothide.md).

# roothide Header
```
#include <roothide.h>
```
it has been included in theos, you can use it directly in c/c++/objc/swift-bridging-header. 
when you compile for rootful/rootless, all APIs in it will become empty stub functions for compatibility.

(if you use xcode, you can configure theos header and library paths in xcode, or you can download [roothide's devkit package](https://github.com/roothide/libroothide/releases/)).

# roothide API

  ## 1. jbroot

***this api is used to convert jbroot-based paths to rootfs-based paths for use by the system API.***

  ```
  /* for C language (auto cache) */
const char* jbroot(const char* path);

/ * for Objective-C */
NSString* jbroot(NSString* path);

/* for C++ language */
std::string jbroot(std::string path);
  ```

***examples***

C language:
<pre>
#include &lt;unistd.h&gt;
#include &lt;roothide.h&gt;

FILE* fp = fopen(<b>jbroot</b>("/var/jbconfig.test"), "w+");
fwrite(data, size, 1, fp);
fclose(fp);
</pre>

Objective-C language:
<pre>
#include &lt;Foundation/Foundation.h&gt;
#include &lt;roothide.h&gt;

NSString* filepath = <b>jbroot</b>("/var/jbconfig.plist");
NSMutableDictionary* dict = [NSMutableDictionary dictionaryWithContentsOfFile:file];
dict[@"testkey"] = @"testvalue";
[dict writeToFile:filepath atomically:YES];
</pre>

C++ language:
<pre>
#include &lt;string&gt;
#include &lt;fstream&gt;
#include &lt;roothide.h&gt;

std::fstream  testfile(<b>jbroot</b>("/var/test.config"), std::ios::out);
testfile.write(data, size);
testfile.close();
</pre>

exec command of bootstrap:
<pre>
#include &lt;unistd.h&gt;
#include &lt;spawn.h&gt;
#include &lt;roothide.h&gt;

pid_t pid;
char* args[] = {"/usr/bin/killall", "-9" "SpringBoard", NULL};
int ret = posix_spawn(&pid, <b>jbroot</b>(args[0]), NULL, NULL, args, NULL);
</pre>

  ## 2. rootfs
  
***this api is used to convert rootfs-based paths to jbroot-based paths, then store the converted path to config files for use with jbroot next time,
or use the converted path as an argument to call a command line tool in bootstrap.***

  ```
/* for C language (auto cache) */
const char* rootfs(const char* path);

/ * for Objective-C */
NSString* rootfs(NSString* path);

/* for C++ language */
std::string rootfs(std::string path);
```

***examples***

store paths to config file:
<pre>
#include &lt;unistd.h&gt;
#include &lt;Foundation/Foundation.h>
#include &lt;roothide.h&gt;

NSString* filepath = <b>jbroot</b>("/var/jbconfig.plist");
NSMutableDictionary* dict = [[NSMutableDictionary alloc] init];
dict[@"path"] = <b>rootfs</b>(filepath);
[dict writeToFile:filepath atomically:YES];

/* ..... */

// load the converted path from disk to use it with jbroot next time

NSMutableDictionary* dict = [NSMutableDictionary dictionaryWithContentsOfFile:file];
NSLog(@"saved path = %@ (path based on jbroot)", dict["path"]);

FILE* fp = fopen(<b>jbroot</b>(dict["path"].fileSystemRepresentation), "w+");
fwrite(data, size, 1, fp);
fclose(fp);
</pre>

call a command line tool of bootstrap:
<pre>
#include &lt;unistd.h&gt;
#include &lt;spawn.h&gt;
#include &lt;roothide.h&gt;

int execBootstrapBinary(char* binary, char** args)
{
    pid_t pid=0;
    int ret = posix_spawn(&pid, <b>jbroot</b>(args[0]), NULL, NULL, args, NULL);
    if(ret!=0) return ret;
    int status = -INT_MAX;
    waitpid(pid, &status, 0);
    return WEXITSTATUS(status);
}

//convert jbroot based path to rootfs based path
char* filepath = <b>jbroot</b>("/var/jbconfig.plist");
FILE* fp = fopen(filepath, "w+");
fwrite(data, size, 1, fp);
fclose(fp);

// convert rootfs based path to jbroot based path and exec rm -f
char* args = {"/usr/bin/rm", "-f", <b>rootfs</b>(filepath), NULL};
execBootstrapBinary(args);
</pre>

  ## 3. jbrand

  ***this API is used to get the random value of the current jailbreak state in system-wide.***
  ```
unsigned long long jbrand();
```
this value will not change until next time we jailbreak, for example we can use it to add to our xpc service name as a suffix, or for other cases.


# Mnemonic
|  API   | Input  | Output |
|  ----  | ----  | ----  |
|  jbroot  | a **jbroot**-based path  | a rootfs-based path  |
|  rootfs  | a **rootfs**-based path  | a jbroot-based path  |



# Command Line Tool

  jbroot/rootfs/jbrand also provided as command line tools for getting/converting paths in shell/scripts in some specific cases.

