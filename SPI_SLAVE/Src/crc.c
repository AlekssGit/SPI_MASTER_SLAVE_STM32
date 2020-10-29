#include "crc.h"

int crc_calc(uint8_t *buff, uint8_t size)
{
	int tmp, tmp2, flag;

	tmp = 0xFFFF;

	for (int i = 0; i < size; i++)
	{
		tmp = tmp ^ buff[i];

		for (int j = 1; j <= 8; j++)
		{
			flag = tmp & 0x0001;
			tmp >>= 1;

			if (flag)
				tmp ^= 0xA001;
		}
	}

	tmp2 = tmp >> 8;
	tmp = (tmp << 8) | tmp2;
	tmp &= 0xFFFF;

	return tmp;
}
