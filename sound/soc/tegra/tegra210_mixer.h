/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * tegra210_mixer.h - Definitions for Tegra210 MIXER driver
 *
 * Copyright (c) 2021, NVIDIA CORPORATION.  All rights reserved.
 *
 */

#ifndef __TEGRA210_MIXER_H__
#define __TEGRA210_MIXER_H__

/* XBAR_RX related MIXER offsets */
#define TEGRA210_MIXER_RX1_SOFT_RESET	0x04
#define TEGRA210_MIXER_RX1_STATUS	0x10
#define TEGRA210_MIXER_RX1_CIF_CTRL	0x24
#define TEGRA210_MIXER_RX1_CTRL		0x28
#define TEGRA210_MIXER_RX1_PEAK_CTRL	0x2c
#define TEGRA210_MIXER_RX1_SAMPLE_COUNT	0x30

/* XBAR_TX related MIXER offsets */
#define TEGRA210_MIXER_TX1_ENABLE	0x280
#define TEGRA210_MIXER_TX1_SOFT_RESET	0x284
#define TEGRA210_MIXER_TX1_STATUS	0x290
#define TEGRA210_MIXER_TX1_INT_STATUS	0x294
#define TEGRA210_MIXER_TX1_INT_MASK	0x298
#define TEGRA210_MIXER_TX1_INT_SET	0x29c
#define TEGRA210_MIXER_TX1_INT_CLEAR	0x2a0
#define TEGRA210_MIXER_TX1_CIF_CTRL	0x2a4
#define TEGRA210_MIXER_TX1_ADDER_CONFIG	0x2a8

/* MIXER related offsets */
#define TEGRA210_MIXER_ENABLE			0x400
#define TEGRA210_MIXER_SOFT_RESET		0x404
#define TEGRA210_MIXER_CG			0x408
#define TEGRA210_MIXER_STATUS			0x410
#define TEGRA210_MIXER_INT_STATUS		0x414
#define TEGRA210_MIXER_GAIN_CFG_RAM_CTRL	0x42c
#define TEGRA210_MIXER_GAIN_CFG_RAM_DATA	0x430
#define TEGRA210_MIXER_PEAKM_RAM_CTRL		0x434
#define TEGRA210_MIXER_PEAKM_RAM_DATA		0x438
#define TEGRA210_MIXER_CTRL			0x43c

#define TEGRA210_MIXER_TX2_ADDER_CONFIG	(TEGRA210_MIXER_TX1_ADDER_CONFIG + TEGRA210_MIXER_REG_STRIDE)
#define TEGRA210_MIXER_TX3_ADDER_CONFIG	(TEGRA210_MIXER_TX2_ADDER_CONFIG + TEGRA210_MIXER_REG_STRIDE)
#define TEGRA210_MIXER_TX4_ADDER_CONFIG	(TEGRA210_MIXER_TX3_ADDER_CONFIG + TEGRA210_MIXER_REG_STRIDE)
#define TEGRA210_MIXER_TX5_ADDER_CONFIG	(TEGRA210_MIXER_TX4_ADDER_CONFIG + TEGRA210_MIXER_REG_STRIDE)

#define TEGRA210_MIXER_TX2_ENABLE	(TEGRA210_MIXER_TX1_ENABLE + TEGRA210_MIXER_REG_STRIDE)
#define TEGRA210_MIXER_TX3_ENABLE	(TEGRA210_MIXER_TX2_ENABLE + TEGRA210_MIXER_REG_STRIDE)
#define TEGRA210_MIXER_TX4_ENABLE	(TEGRA210_MIXER_TX3_ENABLE + TEGRA210_MIXER_REG_STRIDE)
#define TEGRA210_MIXER_TX5_ENABLE	(TEGRA210_MIXER_TX4_ENABLE + TEGRA210_MIXER_REG_STRIDE)

/* Fields in TEGRA210_MIXER_ENABLE */
#define TEGRA210_MIXER_ENABLE_SHIFT	0
#define TEGRA210_MIXER_ENABLE_MASK	(1 << TEGRA210_MIXER_ENABLE_SHIFT)
#define TEGRA210_MIXER_EN		(1 << TEGRA210_MIXER_ENABLE_SHIFT)

/* Fields in TEGRA210_MIXER_GAIN_CFG_RAM_CTRL */
#define TEGRA210_MIXER_GAIN_CFG_RAM_ADDR_0		0x0
#define TEGRA210_MIXER_GAIN_CFG_RAM_ADDR_STRIDE		0x10

#define TEGRA210_MIXER_GAIN_CFG_RAM_RW_SHIFT		14
#define TEGRA210_MIXER_GAIN_CFG_RAM_RW_MASK		(1 << TEGRA210_MIXER_GAIN_CFG_RAM_RW_SHIFT)
#define TEGRA210_MIXER_GAIN_CFG_RAM_RW_WRITE		(1 << TEGRA210_MIXER_GAIN_CFG_RAM_RW_SHIFT)

#define TEGRA210_MIXER_GAIN_CFG_RAM_ADDR_INIT_EN_SHIFT	13
#define TEGRA210_MIXER_GAIN_CFG_RAM_ADDR_INIT_EN_MASK	(1 << TEGRA210_MIXER_GAIN_CFG_RAM_ADDR_INIT_EN_SHIFT)
#define TEGRA210_MIXER_GAIN_CFG_RAM_ADDR_INIT_EN	(1 << TEGRA210_MIXER_GAIN_CFG_RAM_ADDR_INIT_EN_SHIFT)

#define TEGRA210_MIXER_GAIN_CFG_RAM_SEQ_ACCESS_EN_SHIFT	12
#define TEGRA210_MIXER_GAIN_CFG_RAM_SEQ_ACCESS_EN_MASK	(1 << TEGRA210_MIXER_GAIN_CFG_RAM_SEQ_ACCESS_EN_SHIFT)
#define TEGRA210_MIXER_GAIN_CFG_RAM_SEQ_ACCESS_EN	(1 << TEGRA210_MIXER_GAIN_CFG_RAM_SEQ_ACCESS_EN_SHIFT)

#define TEGRA210_MIXER_GAIN_CFG_RAM_ADDR_SHIFT		0
#define TEGRA210_MIXER_GAIN_CFG_RAM_ADDR_MASK		(0x1ff << TEGRA210_MIXER_GAIN_CFG_RAM_ADDR_SHIFT)

#define TEGRA210_MIXER_REG_STRIDE	0x40
#define TEGRA210_MIXER_RX_MAX		10
#define TEGRA210_MIXER_RX_LIMIT		(TEGRA210_MIXER_RX_MAX * TEGRA210_MIXER_REG_STRIDE)
#define TEGRA210_MIXER_TX_MAX		5
#define TEGRA210_MIXER_TX_LIMIT		(TEGRA210_MIXER_RX_LIMIT + (TEGRA210_MIXER_TX_MAX * TEGRA210_MIXER_REG_STRIDE))

#define REG_CFG_DONE_TRIGGER	0xf
#define VAL_CFG_DONE_TRIGGER	0x1

#define NUM_GAIN_POLY_COEFFS 9
#define NUM_DURATION_PARMS 4

struct tegra210_mixer_gain_params {
	int poly_coeff[NUM_GAIN_POLY_COEFFS];
	int gain_value;
	int duration[NUM_DURATION_PARMS];
};

struct tegra210_mixer {
	int gain_value[TEGRA210_MIXER_RX_MAX];
	struct regmap *regmap;
};

#endif
