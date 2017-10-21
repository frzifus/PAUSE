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

#include <stdio.h>      /* printf */
#include <locale.h>     /* setlocale */
#include <string.h>     /* strcmp */

int main() {
  const char DE[] = "de_DE.utf8";
  char *locale = setlocale(LC_ALL, "");

  if (strcmp(locale, DE)) {
    printf("Drücken Sie eine beliebige Taste . . . ");
  } else {
    printf("Press any key to continue . . . ");
  }
  getchar();
  return 0;
}
