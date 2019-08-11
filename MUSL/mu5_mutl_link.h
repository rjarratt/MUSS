#pragma once

#define MU5_LIT_SYM_NAME "(literal)" /* name of a made-up symbol used during relocation to identify the data section where the literals are placed. */

#define MU5_REL_TYPE_FUNC 0 /* Relocation entry for a function call. */
#define MU5_REL_TYPE_VAR 1 /* Relocation entry for a global variable. */
#define MU5_REL_TYPE_DESC_LIT 2 /* Relocation entry for an embedded literal descriptor. The offset is to the address half of the descriptor. The addend is to be added to the segment base address. No symbol is associated with it */

void import_module(char *filename);
void link_modules(char *filename);
