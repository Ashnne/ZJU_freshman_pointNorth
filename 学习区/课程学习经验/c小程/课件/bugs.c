#include <stdio.h>

char b1[]="   \\";
char b2[]="    '-.__.-'";
char b3[]="    /oo |--.--,--,--.";
char b4[]="    \\_.-'._i__i__i_.'";
char b5[]="         \"\"\"\"\"\"\"\"\"";  

void draw_bug1()
{
	printf("%s\n",b1);
	printf("%s\n",b2);
	printf("%s\n",b3);
	printf("%s\n",b4);
	printf("%s\n",b5);
}

void draw_bug2()
{
	printf("\n");
	printf("           .-.\n");
    printf("          o   \\     .-.\n");
    printf("             .----.'   \\\n");
    printf("           .'o)  / `.   o\n");
    printf("          /         |\n");
    printf("          \\_)       /-.\n");
    printf("            '_.`    \\  \\\n");
    printf("             `.      |  \\\n");
    printf("              |       \\ |\n");
    printf("          .--/`-.     / /\n");
    printf("        .'.-/`-. `.  .\\|\n");
    printf("       /.' /`._ `-    '-.\n");
    printf("  ____(|__/`-..`-   '-._ \\\n");
    printf("  |`------.'-._ `      ||\\ \\\n");
    printf("  || #   /-.   `   /   || \\|\n");
    printf("  ||   #/   `--'  /  /_::_|)__\n");
    printf("  `|____|-._.-`  /  ||`--------`\n");
    printf("       \\-.___.` | / || #      |\n");
    printf("        \\       | | ||   #  # |\n");
    printf("        /`.___.'\\ |.`|________|\n");
    printf("        | /`.__.'|'.`\n");
    printf("      __/ \\    __/ \\\n");
    printf("     /__.-.)  /__.-.)\n");
	printf("\n");
}

int main()
{
	char ch;
	draw_bug1();
	printf("继续吗？输入 y 继续，其他字符退出\n");
	ch = getchar();
	if( ch=='y' || ch=='Y' )
		draw_bug2();
		
	return 0;
}


