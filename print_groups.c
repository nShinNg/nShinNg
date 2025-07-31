#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <grp.h>
#include <pwd.h>
#include <string.h>

void print_groups(const char *user)
{
    struct passwd *pwd = getpwnam(user);
    if (pwd == NULL) {
        return;
    }
    
    gid_t groups[1024];
    int ngroups = 1024;
    
    if (getgrouplist(user, pwd->pw_gid, groups, &ngroups) == -1) {
        return;
    }
    
    int i = 0;
    while (i < ngroups)
    {
        struct group *grp = getgrgid(groups[i]);
        if (grp != NULL) {
            write(1, grp->gr_name, strlen(grp->gr_name));
            i++;
            if (i < ngroups) {
                write(1, ",", 1);
            }
        } else {
            i++;
        }
    }
    write(1, "\n", 1);
}

int main(void)
{
    const char *FT_USER = getenv("FT_USER");
    if (FT_USER == NULL) {
        return 1;
    }
    print_groups(FT_USER);
    return 0;
}