#pragma once

#define MU5_LIT_SYM_NAME "(literal)" /* name of a made-up symbol used during relocation to identify the data section where the literals are placed. */

#define MU5_REL_TYPE_FUNC 0 /* Relocation entry for a function call. */
#define MU5_REL_TYPE_VAR_BASE 1 /* Relocation entry for a global variable, base address for the module's globals. */
#define MU5_REL_TYPE_VAR_OFFSET 2 /* Relocation entry for a global variable, name offset from the base. */
#define MU5_REL_TYPE_DESC_LIT 3 /* Relocation entry for an embedded literal descriptor. The offset is to the address half of the descriptor. The addend is to be added to the segment base address. No symbol is associated with it */
#define MU5_REL_TYPE_16_BIT_VALUE 4 /* Relocation entry for a 16 bit literal, e.g. exported literals and V-Store addresses */

void import_module(char *filename);
void link_modules(char *filename);
