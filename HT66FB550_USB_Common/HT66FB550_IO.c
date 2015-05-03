#include "HT66FB550.h"
#include "HT66FB550_MCU.h"
#include "HT66FB550_IO.h"
#include "HT66FB550_typedef.h"

//io direction buf
char port_A_config,port_B_config,port_C_config,port_D_config,port_E_config;
//io data buf
char port_A_data,port_B_data,port_C_data,port_D_data,port_E_data;
//io pull-high buf
char port_A_pull_high,port_B_pull_high,port_C_pull_high,port_D_pull_high,port_E_pull_high;

void HT66FB550_IO_INIT(void)
{
	HT66FB550_IO_DIR(HT66FB550_MCU_IO_PA,HT66FB550_MCU_IO_PINALL,HT66FB550_MCU_IO_OUTPUT);
	HT66FB550_IO_DIR(HT66FB550_MCU_IO_PB,HT66FB550_MCU_IO_PINALL,HT66FB550_MCU_IO_OUTPUT);
	HT66FB550_IO_DIR(HT66FB550_MCU_IO_PC,HT66FB550_MCU_IO_PINALL,HT66FB550_MCU_IO_OUTPUT);
	HT66FB550_IO_DIR(HT66FB550_MCU_IO_PD,HT66FB550_MCU_IO_PINALL,HT66FB550_MCU_IO_OUTPUT);
	HT66FB550_IO_DIR(HT66FB550_MCU_IO_PE,HT66FB550_MCU_IO_PINALL,HT66FB550_MCU_IO_OUTPUT);
	HT66FB550_IO_Data(HT66FB550_MCU_IO_PA,HT66FB550_MCU_IO_PINALL,0x00);
	HT66FB550_IO_Data(HT66FB550_MCU_IO_PB,HT66FB550_MCU_IO_PINALL,0x00);
	HT66FB550_IO_Data(HT66FB550_MCU_IO_PC,HT66FB550_MCU_IO_PINALL,0x00);
	HT66FB550_IO_Data(HT66FB550_MCU_IO_PD,HT66FB550_MCU_IO_PINALL,0x00);
	HT66FB550_IO_Data(HT66FB550_MCU_IO_PE,HT66FB550_MCU_IO_PINALL,0x00);
    //set ADC pin to IO pin here
    _acer0 = 0;
    _acer1 = 0;
    
}

void HT66FB550_IO_DIR(char port, char pin, char direction)
{
	char filter=0x01;
	filter = filter << pin;
	switch(port)
	{
		case HT66FB550_MCU_IO_PA:
			switch(pin)
			{
				case HT66FB550_MCU_IO_PINALL:
					port_A_config = direction;
					break;
				default:
					port_A_config = port_A_config & (!filter);
					port_A_config = port_A_config | (filter & direction);
					break;
			}
			_pac = port_A_config;
			break;
		case HT66FB550_MCU_IO_PB:
			switch(pin)
			{
				case HT66FB550_MCU_IO_PINALL:
					port_B_config = direction;
					break;
				default:
					port_B_config = port_B_config & (!filter);
					port_B_config = port_B_config | (filter & direction);
					break;
			}
			_pbc = port_B_config;
			break;
		case HT66FB550_MCU_IO_PC:
			switch(pin)
			{
				case HT66FB550_MCU_IO_PINALL:
					port_C_config = direction;
					break;
				default:
					port_C_config = port_C_config & (!filter);
					port_C_config = port_C_config | (filter & direction);
					break;
			}
			_pcc = port_C_config;
			break;
		case HT66FB550_MCU_IO_PD:
			switch(pin)
			{
				case HT66FB550_MCU_IO_PINALL:
					port_D_config = direction;
					break;
				default:
					port_D_config = port_D_config & (!filter);
					port_D_config = port_D_config | (filter & direction);
					break;
			}
			_pdc = port_D_config;
			break;
		case HT66FB550_MCU_IO_PE:
			switch(pin)
			{
				case HT66FB550_MCU_IO_PINALL:
					port_E_config = direction;
					break;
				default:
					port_E_config = port_E_config & (!filter);
					port_E_config = port_E_config | (filter & direction);
					break;
			}
			_pec = port_E_config;
			break;
	}	
}

void HT66FB550_IO_Data(char port, char pin, char data)
{
	char filter=0x01;
	filter = filter << pin;
	switch(port)
	{
		case HT66FB550_MCU_IO_PA:
			switch(pin)
			{
				case HT66FB550_MCU_IO_PINALL:
					port_A_data = data;
					break;
				default:
					port_A_data = port_A_data & (!filter);
					port_A_data = port_A_data | (filter & data);
					break;
			}
			_pa = port_A_data;
			break;
		case HT66FB550_MCU_IO_PB:
			switch(pin)
			{
				case HT66FB550_MCU_IO_PINALL:
					port_B_data = data;
					break;
				default:
					port_B_data = port_B_data & (!filter);
					port_B_data = port_B_data | (filter & data);
					break;
			}
			_pb = port_B_data;
			break;
		case HT66FB550_MCU_IO_PC:
			switch(pin)
			{
				case HT66FB550_MCU_IO_PINALL:
					port_C_data = data;
					break;
				default:
					port_C_data = port_C_data & (!filter);
					port_C_data = port_C_data | (filter & data);
					break;
			}
			_pc = port_C_data;
			break;
		case HT66FB550_MCU_IO_PD:
			switch(pin)
			{
				case HT66FB550_MCU_IO_PINALL:
					port_D_data = data;
					break;
				default:
					port_D_data = port_D_data & (!filter);
					port_D_data = port_D_data | (filter & data);
					break;
			}
			_pd = port_D_data;
			break;
		case HT66FB550_MCU_IO_PE:
			switch(pin)
			{
				case HT66FB550_MCU_IO_PINALL:
					port_E_data = data;
					break;
				default:
					port_E_data = port_E_data & (!filter);
					port_E_data = port_E_data | (filter & data);
					break;
			}
			_pe = port_E_data;
			break;
	}		
}

void HT66FB550_IO_Pull_High(char port, char pin, char data)
{
	char filter=0x01;
	filter = filter << pin;
	switch(port)
	{
		case HT66FB550_MCU_IO_PA:
			switch(pin==HT66FB550_MCU_IO_PINALL)
			{
				case HT66FB550_MCU_IO_PINALL:
					port_A_pull_high = data;
					break;
				default:
					port_A_pull_high = port_A_pull_high & (!filter);
					port_A_pull_high = port_A_pull_high | (filter & data);
					break;
			}
			_pa = port_A_pull_high;
			break;
		case HT66FB550_MCU_IO_PB:
			switch(pin==HT66FB550_MCU_IO_PINALL)
			{
				case HT66FB550_MCU_IO_PINALL:
					port_B_pull_high = data;
					break;
				default:
					port_B_pull_high = port_B_pull_high & (!filter);
					port_B_pull_high = port_B_pull_high | (filter & data);
					break;
			}
			_pb = port_B_pull_high;
			break;
		case HT66FB550_MCU_IO_PC:
			switch(pin==HT66FB550_MCU_IO_PINALL)
			{
				case HT66FB550_MCU_IO_PINALL:
					port_C_pull_high = data;
					break;
				default:
					port_C_pull_high = port_C_pull_high & (!filter);
					port_C_pull_high = port_C_pull_high | (filter & data);
					break;
			}
			_pc = port_C_pull_high;
			break;
		case HT66FB550_MCU_IO_PD:
			switch(pin==HT66FB550_MCU_IO_PINALL)
			{
				case HT66FB550_MCU_IO_PINALL:
					port_D_pull_high = data;
					break;
				default:
					port_D_pull_high = port_D_pull_high & (!filter);
					port_D_pull_high = port_D_pull_high | (filter & data);
					break;
			}
			_pd = port_D_pull_high;
			break;
		case HT66FB550_MCU_IO_PE:
			switch(pin==HT66FB550_MCU_IO_PINALL)
			{
				case HT66FB550_MCU_IO_PINALL:
					port_E_pull_high = data;
					break;
				default:
					port_E_pull_high = port_E_pull_high & (!filter);
					port_E_pull_high = port_E_pull_high | (filter & data);
					break;
			}
			_pe = port_E_pull_high;
			break;
	}			
}

void HT66FB550_IO_High_Current(char port, char data)
{
	switch(port)
	{
		case HT66FB550_MCU_IO_PA:
			switch(data)
			{
				case HT66FB550_MCU_IO_DATA_SET:
					_paoi = 0xff;
					break;
				case HT66FB550_MCU_IO_DATA_CLEAR:
				default:
					_paoi = 0x00;
					break;
			}
			break;
		case HT66FB550_MCU_IO_PB:
			switch(data)
			{
				case HT66FB550_MCU_IO_DATA_SET:
					_pbhi = 1;
					_pbli = 1;
					break;
				case HT66FB550_MCU_IO_DATA_CLEAR:
				default:
					_pbhi = 0;
					_pbli = 0;
					break;
			}
		case HT66FB550_MCU_IO_PC:
			switch(data)
			{
				case HT66FB550_MCU_IO_DATA_SET:
					_pchi = 1;
					_pcli = 1;
					break;
				case HT66FB550_MCU_IO_DATA_CLEAR:
				default:
					_pchi = 0;
					_pcli = 0;
					break;
			}
		case HT66FB550_MCU_IO_PD:
			switch(data)
			{
				case HT66FB550_MCU_IO_DATA_SET:
					_pdhi = 1;
					_pdli = 1;
					break;
				case HT66FB550_MCU_IO_DATA_CLEAR:
				default:
					_pdhi = 0;
					_pdli = 0;
					break;
			}
		case HT66FB550_MCU_IO_PE:
			switch(data)
			{
				case HT66FB550_MCU_IO_DATA_SET:
					_pehi = 1;
					_peli = 1;
					break;
				case HT66FB550_MCU_IO_DATA_CLEAR:
				default:
					_pehi = 0;
					_peli = 0;
					break;
			}
	}			
}

void HT66FB550_IO_Slew_Rate(void)
{
    
}
void HT66FB550_IO_Port_A_Output_Power_Control(char pin, char power_source)
{
	
}