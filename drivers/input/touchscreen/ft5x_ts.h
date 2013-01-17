/*
 * drivers/input/touchscreen/ft5x_ts.h
 *
 * (C) Copyright 2007-2012
 * Allwinner Technology Co., Ltd. <www.allwinnertech.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef __LINUX_FT5X_TS_H__
#define __LINUX_FT5X_TS_H__

// gpio base address
#define CONFIG_FT5X0X_MULTITOUCH     (1)
#define CALIBRATION  (1)
#define UPGRADE   (5)
/*#define IOCTL_SETXNORMAL  _IOR(I2C_MAJOR, (10), char *)
#define IOCTL_SETYNORMAL  _IOR(I2C_MAJOR, (11), char *)
#define IOCTL_SETXINVERT  _IOR(I2C_MAJOR, (12), char *)
#define IOCTL_SETYINVERT  _IOR(I2C_MAJOR, (13), char *)
#define IOCTL_SETXYNORMAL _IOR(I2C_MAJOR, (14), char *)
#define IOCTL_SETXYSWAP   _IOR(I2C_MAJOR, (15), char *)*/
#define IOCTL_SETXNORMAL  (10)
#define IOCTL_SETYNORMAL  (11)
#define IOCTL_SETXINVERT  (12)
#define IOCTL_SETYINVERT  (13)
#define IOCTL_SETXYNORMAL (14)
#define IOCTL_SETXYSWAP   (15)
#define IOCTL_SETXMAX	   (16)
#define IOCTL_SETYMAX  	   (17)
#define IOCTL_GETXDEF     (18)
#define IOCTL_GETYDEF     (19)

#define FT5X_SCALE_HACK 1 /* The device shows at 1024x600 or something similar even after rotation */
#ifdef FT5X_SCALE_HACK

#define IOCTL_FT5X_SETSCALE (20)
#define IOCTL_SETXSCALE	   (21)
#define IOCTL_SETYSCALE	   (22)

#endif


//#define CALIBRATION _IO(CALIBRATION_FLAG,0)
//#define UPDRAGE _IO(UPDRAGE_FLAG,0)
#define I2C_MINORS 	256
#define I2C_MAJOR 	125
                                
#undef  AW_GPIO_INT_API_ENABLE
//#define AW_FPGA_SIM
#ifdef AW_FPGA_SIM
#endif

#define AW_GPIO_API_ENABLE
//#undef CONFIG_HAS_EARLYSUSPEND
//#define CONFIG_HAS_EARLYSUSPEND
struct ft5x_ts_platform_data{
	u16	intr;		/* irq number	*/
};

enum ft5x_ts_regs {
	FT5X0X_REG_PMODE	= 0xA5,	/* Power Consume Mode		*/	
};

//FT5X0X_REG_PMODE
#define PMODE_ACTIVE        0x00
#define PMODE_MONITOR       0x01
#define PMODE_STANDBY       0x02
#define PMODE_HIBERNATE     0x03


#ifndef ABS_MT_TOUCH_MAJOR
    #define ABS_MT_TOUCH_MAJOR	0x30	/* touching ellipse */
    #define ABS_MT_TOUCH_MINOR	0x31	/* (omit if circular) */
    #define ABS_MT_WIDTH_MAJOR	0x32	/* approaching ellipse */
    #define ABS_MT_WIDTH_MINOR	0x33	/* (omit if circular) */
    #define ABS_MT_ORIENTATION	0x34	/* Ellipse orientation */
    #define ABS_MT_POSITION_X	0x35	/* Center X ellipse position */
    #define ABS_MT_POSITION_Y	0x36	/* Center Y ellipse position */
    #define ABS_MT_TOOL_TYPE	0x37	/* Type of touching device */
    #define ABS_MT_BLOB_ID		0x38	/* Group set of pkts as blob */
#endif /* ABS_MT_TOUCH_MAJOR */



#define FOR_TSLIB_TEST
//#define PRINT_INT_INFO
//#define PRINT_POINT_INFO
//#define DEBUG
//#define TOUCH_KEY_SUPPORT
#ifdef TOUCH_KEY_SUPPORT
//#define TOUCH_KEY_LIGHT_SUPPORT
//#define TOUCH_KEY_FOR_EVB13
//#define TOUCH_KEY_FOR_ANGDA
#ifdef TOUCH_KEY_FOR_ANGDA
#define TOUCH_KEY_X_LIMIT	(60000)
#define TOUCH_KEY_NUMBER	(4)
#endif
#ifdef TOUCH_KEY_FOR_EVB13
#define TOUCH_KEY_LOWER_X_LIMIT	(848)
#define TOUCH_KEY_HIGHER_X_LIMIT	(852)
#define TOUCH_KEY_NUMBER	(5)
#endif
#endif

//#define CONFIG_SUPPORT_FTS_CTP_UPG

struct i2c_dev{
struct list_head list;
struct i2c_adapter *adap;
struct device *dev;
};

static struct class *i2c_dev_class;
static LIST_HEAD (i2c_dev_list);
static DEFINE_SPINLOCK(i2c_dev_list_lock);

#define FT5X_NAME		"ft5x_ts"
#define CHARDEV_NAME    "aw_i2c_ts"

#endif

