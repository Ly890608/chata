#pragma once

#define CHATA_STRINGIZING(x)    CHATA_STRINGIZING_EX(x)
#define CHATA_STRINGIZING_EX(x) #x

#define CHATA_CONCAT(x, y)      CHATA_CONCAT_EX(x, y)
#define CHATA_CONCAT_EX(x, y)   x ## y