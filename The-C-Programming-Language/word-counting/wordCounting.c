#include <stdio.h>

enum CharacterHandler {
    SPACE = ' ',
    NEW_LINE = '\n',
    TAB = '\t',
};

#define IN 1
#define OUT 0

int main() {
    int c, nl, nw, nc, state;
    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        ++nc;
        switch (c) {
            case SPACE:
            case NEW_LINE:
            case TAB:
                state = OUT;
                if (c == NEW_LINE)
                    ++nl;
                break;
            default:
                if (state == OUT) {
                    state = IN;
                    ++nw;
                }
                break;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);

    return 0;
}

