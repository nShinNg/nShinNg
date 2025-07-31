#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <grp.h>
#include <pwd.h>
void print_groups(void)
{
    char *username = getenv("FT_USER");
    struct passwd *pwd; gid_t *groups; int ngroups = 0, i = 0;
    if (!username || !(pwd = getpwnam(username))) return;
    getgrouplist(username, pwd->pw_gid, NULL, &ngroups);
    if (!(groups = malloc(ngroups * sizeof(gid_t)))) return;
    getgrouplist(username, pwd->pw_gid, groups, &ngroups);
    while (i < ngroups) {
        struct group *grp = getgrgid(groups[i]);
        if (grp) printf("%s%s", grp->gr_name, (i++ < ngroups - 1) ? "," : "");
    }
    printf("\n"); free(groups);
}
int main(void)
{
    print_groups();
    return (0);
}
