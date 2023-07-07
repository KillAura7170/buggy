#include <openssl/md5.h>
#include <openssl/sha.h>
#include <sys/utsname.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(_WIN32)
    #define PLATFORM_NAME "windows" // Windows
#elif defined(_WIN64)
    #define PLATFORM_NAME "windows" // Windows
#elif defined(__CYGWIN__) && !defined(_WIN32)
    #define PLATFORM_NAME "windows" // Windows (Cygwin POSIX under Microsoft Window)
#elif defined(__ANDROID__)
    #define PLATFORM_NAME "android" // Android (implies Linux, so it must come first)
#elif defined(__linux__)
    #define PLATFORM_NAME "linux" // Debian, Ubuntu, Gentoo, Fedora, openSUSE, RedHat, Centos and other
#elif defined(__unix__) || !defined(__APPLE__) && defined(__MACH__)
    #include <sys/param.h>
    #if defined(BSD)
        #define PLATFORM_NAME "bsd" // FreeBSD, NetBSD, OpenBSD, DragonFly BSD
    #endif
#elif defined(__hpux)
    #define PLATFORM_NAME "hp-ux" // HP-UX
#elif defined(_AIX)
    #define PLATFORM_NAME "aix" // IBM AIX
#elif defined(__APPLE__) && defined(__MACH__) // Apple OSX and iOS (Darwin)
    #include <TargetConditionals.h>
    #if TARGET_IPHONE_SIMULATOR == 1
        #define PLATFORM_NAME "ios" // Apple iOS
    #elif TARGET_OS_IPHONE == 1
        #define PLATFORM_NAME "ios" // Apple iOS
    #elif TARGET_OS_MAC == 1
        #define PLATFORM_NAME "osx" // Apple OSX
    #endif
#elif defined(__sun) && defined(__SVR4)
    #define PLATFORM_NAME "solaris" // Oracle Solaris, Open Indiana
#else
    #define PLATFORM_NAME NULL
#endif

// Return a name of platform, if determined, otherwise - an empty string
const char *get_platform_name() {
    return (PLATFORM_NAME == NULL) ? "" : PLATFORM_NAME;
}

void main() {
    unsigned char *OS = get_platform_name();
    unsigned char input[4096];


    if (OS == "linux") {
    	while(OS == "linux") {	
        	printf("[/]: ");
		scanf("%c", input);
	
		if(input == "cpu_info") {
			 FILE *cpuinfo = fopen("/proc/cpuinfo", "rb");
   			 char *arg = 0;
   			 size_t size = 0;
   			 while(getdelim(&arg, &size, 0, cpuinfo) != -1)
   			 {
      				puts(arg);
   			 }
   			 free(arg);
   			 fclose(cpuinfo);
		}

		if (input == "os_info") {
			printf("%c", OS);
		}
    	}
    }

	//Linux Stuff
   // puts(get_platform_name());
	//End of Linux Stuff

    unsigned char sha512_digest[SHA512_DIGEST_LENGTH];
    unsigned char buffer[500];
    int i;

    printf("Enter String to encrypt with sha512 (500 MAX): ");
    gets(buffer);

    SHA512(buffer, strlen(buffer), sha512_digest);
    
    for (i = 0; i < SHA512_DIGEST_LENGTH; i++) {
        printf("%02x", sha512_digest[i]);
    }
    printf("\n");
}
