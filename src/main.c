/**
 * This file is part of PAUSE.
 *
 * PAUSE is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the frzifus, either version 3 of the License.
 *
 * PAUSE is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * see <http://www.gnu.org/licenses/>.
 **/

#include <locale.h> /* setlocale */
#include <stdio.h>  /* printf */
#include <string.h> /* strcmp */
#ifdef __unix__
#include <termios.h>
void one_char_buffer_ioctl() {
    struct termios info;
    tcgetattr(0, &info);
    info.c_lflag &= ~ICANON;
    info.c_cc[VMIN] = 1;
    info.c_cc[VTIME] = 0;
    tcsetattr(0, TCSANOW, &info);
}
#else
void one_char_buffer_ioctl() { /* not unix, so no action needed here */
}
#endif  // __unix__

int main() {
    one_char_buffer_ioctl();

    const char DE[] = "de_DE.utf8";
    char *locale = setlocale(LC_ALL, "");

    if (strcmp(locale, DE)) {
        printf("Dr\u00FCcken Sie eine beliebige Taste . . . ");
    } else {
        printf("Press any key to continue . . . ");
    }
    getchar();
    return 0;
}
