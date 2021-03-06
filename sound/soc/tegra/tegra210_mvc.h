/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * tegra210_mvc.h - Definitions for Tegra210 MVC driver
 *
 * Copyright (c) 2021 NVIDIA CORPORATION.  All rights reserved.
 *
 */

#ifndef __TEGRA210_MVC_H__
#define __TEGRA210_MVC_H__

/*
 * MVC_RX registers are with respect to XBAR.
 * The data comes from XBAR to MVC.
 */
#define TEGRA210_MVC_RX_STATUS			0x0c
#define TEGRA210_MVC_RX_INT_STATUS		0x10
#define TEGRA210_MVC_RX_INT_MASK		0x14
#define TEGRA210_MVC_RX_INT_SET			0x18
#define TEGRA210_MVC_RX_INT_CLEAR		0x1c
#define TEGRA210_MVC_RX_CIF_CTRL		0x20

/*
 * MVC_TX registers are with respect to XBAR.
 * The data goes out of MVC.
 */
#define TEGRA210_MVC_TX_STATUS			0x4c
#define TEGRA210_MVC_TX_INT_STATUS		0x50
#define TEGRA210_MVC_TX_INT_MASK		0x54
#define TEGRA210_MVC_TX_INT_SET			0x58
#define TEGRA210_MVC_TX_INT_CLEAR		0x5c
#define TEGRA210_MVC_TX_CIF_CTRL		0x60

/* Register offsets from TEGRA210_MVC*_BASE */
#define TEGRA210_MVC_ENABLE			0x80
#define TEGRA210_MVC_SOFT_RESET			0x84
#define TEGRA210_MVC_CG				0x88
#define TEGRA210_MVC_STATUS			0x90
#define TEGRA210_MVC_INT_STATUS			0x94
#define TEGRA210_MVC_CTRL			0xa8
#define TEGRA210_MVC_SWITCH			0xac
#define TEGRA210_MVC_INIT_VOL			0xb0
#define TEGRA210_MVC_TARGET_VOL			0xd0
#define TEGRA210_MVC_DURATION			0xf0
#define TEGRA210_MVC_DURATION_INV		0xf4
#define TEGRA210_MVC_POLY_N1			0xf8
#define TEGRA210_MVC_POLY_N2			0xfc
#define TEGRA210_MVC_PEAK_CTRL			0x100
#define TEGRA210_MVC_CFG_RAM_CTRL		0x104
#define TEGRA210_MVC_CFG_RAM_DATA		0x108
#define TEGRA210_MVC_PEAK_VALUE			0x10c
#define TEGRA210_MVC_CONFIG_ERR_TYPE		0x12c

/* Fields in TEGRA210_MVC_ENABLE */
#define TEGRA210_MVC_EN_SHIFT			0
#define TEGRA210_MVC_EN				(1 << TEGRA210_MVC_EN_SHIFT)

#define TEGRA210_MVC_MUTE_SHIFT			8
#define TEGRA210_MUTE_MASK_EN			0xff
#define TEGRA210_MVC_MUTE_MASK			(TEGRA210_MUTE_MASK_EN << TEGRA210_MVC_MUTE_SHIFT)
#define TEGRA210_MVC_MUTE_EN			(TEGRA210_MUTE_MASK_EN << TEGRA210_MVC_MUTE_SHIFT)

#define TEGRA210_MVC_PER_CHAN_CTRL_EN_SHIFT	30
#define TEGRA210_MVC_PER_CHAN_CTRL_EN_MASK	(1 << TEGRA210_MVC_PER_CHAN_CTRL_EN_SHIFT)
#define TEGRA210_MVC_PER_CHAN_CTRL_EN		(1 << TEGRA210_MVC_PER_CHAN_CTRL_EN_SHIFT)

#define TEGRA210_MVC_CURVE_TYPE_SHIFT		1
#define TEGRA210_MVC_CURVE_TYPE_MASK		(1 << TEGRA210_MVC_CURVE_TYPE_SHIFT)

#define TEGRA210_MVC_VOLUME_SWITCH_SHIFT	2
#define TEGRA210_MVC_VOLUME_SWITCH_MASK		(1 << TEGRA210_MVC_VOLUME_SWITCH_SHIFT)
#define TEGRA210_MVC_VOLUME_SWITCH_TRIGGER	(1 << TEGRA210_MVC_VOLUME_SWITCH_SHIFT)
#define TEGRA210_MVC_CTRL_DEFAULT	0x40000003

#define TEGRA210_MVC_INIT_VOL_DEFAULT_POLY	0x01000000
#define TEGRA210_MVC_INIT_VOL_DEFAULT_LINEAR	0x00000000

/* Fields in TEGRA210_MVC ram ctrl */
#define TEGRA210_MVC_CFG_RAM_CTRL_RW_SHIFT		14
#define TEGRA210_MVC_CFG_RAM_CTRL_RW_WRITE		(1 << TEGRA210_MVC_CFG_RAM_CTRL_RW_SHIFT)

#define TEGRA210_MVC_CFG_RAM_CTRL_ADDR_INIT_EN_SHIFT	13
#define TEGRA210_MVC_CFG_RAM_CTRL_ADDR_INIT_EN		(1 << TEGRA210_MVC_CFG_RAM_CTRL_ADDR_INIT_EN_SHIFT)

#define TEGRA210_MVC_CFG_RAM_CTRL_SEQ_ACCESS_EN_SHIFT	12
#define TEGRA210_MVC_CFG_RAM_CTRL_SEQ_ACCESS_EN		(1 << TEGRA210_MVC_CFG_RAM_CTRL_SEQ_ACCESS_EN_SHIFT)

#define TEGRA210_MVC_CFG_RAM_CTRL_ADDR_SHIFT		0
#define TEGRA210_MVC_CFG_RAM_CTRL_ADDR_MASK		(0x1ff << TEGRA210_MVC_CFG_RAM_CTRL_ADDR_SHIFT)

#define REG_SIZE 4
#define TEGRA210_MVC_MAX_CHAN_COUNT 8
#define TEGRA210_MVC_REG_OFFSET(reg, i) (reg + (REG_SIZE * i))

#define NUM_GAIN_POLY_COEFFS 9

enum {
	CURVE_POLY,
	CURVE_LINEAR,
};

struct tegra210_mvc_gain_params {
	int poly_coeff[NUM_GAIN_POLY_COEFFS];
	int poly_n1;
	int poly_n2;
	int duration;
	int duration_inv;
};

struct tegra210_mvc {
	int volume[TEGRA210_MVC_MAX_CHAN_COUNT];
	unsigned int curve_type;
	unsigned int ctrl_value;
	struct regmap *regmap;
};

#endif
