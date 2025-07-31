#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <grp.h>
#include <pwd.h>
#include <sys/types.h>

int main(void)
{
    char *username;
    struct passwd *pwd;
    struct group *grp;
    gid_t *groups;
    int ngroups;
    int i;

    username = getenv("FT_USER");
    if (username == NULL) {
        fprintf(stderr, "Error: FT_USER not set\\n");
        return 1;
    }

    pwd = getpwnam(username);
    if (pwd == NULL) {
        fprintf(stderr, "Error: User not found\\n");
        return 1;
    }

    ngroups = 0;
    if (getgrouplist(username, pwd->pw_gid, NULL, &ngroups) == -1) {
        groups = malloc(ngroups * sizeof(gid_t));
        if (groups == NULL) return 1;

        if (getgrouplist(username, pwd->pw_gid, groups, &ngroups) == -1) {
            free(groups);
            return 1;
        }

        for (i = 0; i < ngroups; i++) {
            grp = getgrgid(groups[i]);
            if (grp != NULL) {
                printf("%s", grp->gr_name);
                if (i < ngroups - 1) printf(",");
            }
        }
        printf("\\n");
        free(groups);
    }
    return 0;
}
