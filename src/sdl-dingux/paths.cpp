
// Paths module
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include "burner.h"

char szAppHomePath[MAX_PATH] = "./.fba";			// ~/.fba
char szAppSavePath[MAX_PATH] = "./.fba/saves";		// ~/.fba/saves

void BurnPathsInit()
{
#ifndef WIN32
	char *home = getenv("HOME");
	if(home) sprintf(szAppHomePath, "%s/.fba", home);
	mkdir(szAppHomePath, 0777);
	if(!errno) {
		getcwd(szAppHomePath, MAX_PATH);
		strcat(szAppHomePath, "/.fba");
		mkdir(szAppHomePath, 0777);
	}

	sprintf(szAppSavePath, "%s/saves", szAppHomePath);
	mkdir(szAppSavePath, 0777);
#else
	getcwd(szAppHomePath, MAX_PATH);
	strcat(szAppHomePath, "/.fba");
	mkdir(szAppHomePath);

	sprintf(szAppSavePath, "%s/saves", szAppHomePath);
	mkdir(szAppSavePath);
#endif
}
