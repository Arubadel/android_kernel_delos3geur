/* Copyright (c) 2012, Code Aurora Forum. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/platform_device.h>
#ifdef CONFIG_ANDROID_PMEM
#include <linux/android_pmem.h>
#endif
#include <mach/board.h>

#include "board-msm7627a.h"

#define SND(desc, num) { .name = #desc, .id = num }
static struct snd_endpoint snd_endpoints_list[] = {
#if 1
	SND(HANDSET, 0),
	SND(HEADSET, 3),
	SND(SPEAKER, 6),
	SND(BT, 12),
	SND(VOICE_RECOGNITION, 24),
	SND(FM_DIGITAL_STEREO_HEADSET, 26),
	SND(FM_DIGITAL_SPEAKER_PHONE, 27),
	SND(STEREO_HEADSET_AND_SPEAKER, 31),
	SND(STEREO_HEADSET_3POLE, 34),
	SND(MP3_SPEAKER_PHONE, 35),
	SND(MP3_STEREO_HEADSET, 36),
	SND(BT_NSEC_OFF, 37),
	SND(HANDSET_VOIP, 38),
	SND(STEREO_HEADSET_VOIP, 39),
	SND(SPEAKER_VOIP, 40),
	SND(BT_VOIP, 41),
	SND(HANDSET_VOIP2, 42),
	SND(STEREO_HEADSET_VOIP2, 43),
	SND(SPEAKER_VOIP2, 44),
	SND(BT_VOIP2, 45),
	SND(FM_ANALOG_STEREO_HEADSET, 50),
	SND(FM_ANALOG_STEREO_HEADSET_CODEC, 51),
	SND(GSM_RCV, 52),
	SND(GSM_HEADSET, 53),
	SND(GSM_SPEAKER, 54),
	SND(GSM_BT, 55),
	SND(GSM_BT_NREC_OFF, 56),
	SND(GSM_HEADPHONE, 57),
	SND(HANDSET_EXTRA, 58),
	SND(SPEAKER_PHONE_EXTRA, 59),
	SND(HANDSET_LOOPBACK, 60),
	SND(HEADSET_LOOPBACK, 61),
	SND(SPEAKER_LOOPBACK, 62),
	SND(CAMCORDER_HEADSET, 63),
	SND(AUDIO_DOCK, 64),
	SND(CURRENT, 0x7FFFFFFE),
#else
	SND(HANDSET, 0),
	SND(MONO_HEADSET, 2),
	SND(HEADSET, 3),
	SND(SPEAKER, 6),
	SND(TTY_HEADSET, 8),
	SND(TTY_VCO, 9),
	SND(TTY_HCO, 10),
	SND(BT, 12),
	SND(IN_S_SADC_OUT_HANDSET, 16),
	SND(IN_S_SADC_OUT_SPEAKER_PHONE, 25),
	SND(FM_DIGITAL_STEREO_HEADSET, 26),
	SND(FM_DIGITAL_SPEAKER_PHONE, 27),
	SND(FM_DIGITAL_BT_A2DP_HEADSET, 28),
	SND(STEREO_HEADSET_AND_SPEAKER, 31),
	SND(CURRENT, 0x7FFFFFFE),
	SND(FM_ANALOG_STEREO_HEADSET, 35),
	SND(FM_ANALOG_STEREO_HEADSET_CODEC, 36),
#endif
};
#undef SND

static struct msm_snd_endpoints msm_device_snd_endpoints = {
	.endpoints = snd_endpoints_list,
	.num = sizeof(snd_endpoints_list) / sizeof(struct snd_endpoint)
};

struct platform_device msm_device_snd = {
	.name = "msm_snd",
	.id = -1,
	.dev    = {
		.platform_data = &msm_device_snd_endpoints
	},
};

#define DEC0_FORMAT ((1<<MSM_ADSP_CODEC_MP3)| \
	(1<<MSM_ADSP_CODEC_AAC)|(1<<MSM_ADSP_CODEC_WMA)| \
	(1<<MSM_ADSP_CODEC_WMAPRO)|(1<<MSM_ADSP_CODEC_AMRWB)| \
	(1<<MSM_ADSP_CODEC_AMRNB)|(1<<MSM_ADSP_CODEC_WAV)| \
	(1<<MSM_ADSP_CODEC_ADPCM)|(1<<MSM_ADSP_CODEC_YADPCM)| \
	(1<<MSM_ADSP_CODEC_EVRC)|(1<<MSM_ADSP_CODEC_QCELP)| \
	(1<<MSM_ADSP_CODEC_AC3))
#define DEC1_FORMAT ((1<<MSM_ADSP_CODEC_MP3)| \
	(1<<MSM_ADSP_CODEC_AAC)|(1<<MSM_ADSP_CODEC_WMA)| \
	(1<<MSM_ADSP_CODEC_WMAPRO)|(1<<MSM_ADSP_CODEC_AMRWB)| \
	(1<<MSM_ADSP_CODEC_AMRNB)|(1<<MSM_ADSP_CODEC_WAV)| \
	(1<<MSM_ADSP_CODEC_ADPCM)|(1<<MSM_ADSP_CODEC_YADPCM)| \
	(1<<MSM_ADSP_CODEC_EVRC)|(1<<MSM_ADSP_CODEC_QCELP))
#define DEC2_FORMAT ((1<<MSM_ADSP_CODEC_MP3)| \
	(1<<MSM_ADSP_CODEC_AAC)|(1<<MSM_ADSP_CODEC_WMA)| \
	(1<<MSM_ADSP_CODEC_WMAPRO)|(1<<MSM_ADSP_CODEC_AMRWB)| \
	(1<<MSM_ADSP_CODEC_AMRNB)|(1<<MSM_ADSP_CODEC_WAV)| \
	(1<<MSM_ADSP_CODEC_ADPCM)|(1<<MSM_ADSP_CODEC_YADPCM)| \
	(1<<MSM_ADSP_CODEC_EVRC)|(1<<MSM_ADSP_CODEC_QCELP))
#define DEC3_FORMAT ((1<<MSM_ADSP_CODEC_MP3)| \
	(1<<MSM_ADSP_CODEC_AAC)|(1<<MSM_ADSP_CODEC_WMA)| \
	(1<<MSM_ADSP_CODEC_WMAPRO)|(1<<MSM_ADSP_CODEC_AMRWB)| \
	(1<<MSM_ADSP_CODEC_AMRNB)|(1<<MSM_ADSP_CODEC_WAV)| \
	(1<<MSM_ADSP_CODEC_ADPCM)|(1<<MSM_ADSP_CODEC_YADPCM)| \
	(1<<MSM_ADSP_CODEC_EVRC)|(1<<MSM_ADSP_CODEC_QCELP))
#define DEC4_FORMAT (1<<MSM_ADSP_CODEC_MIDI)

static unsigned int dec_concurrency_table[] = {
	/* Audio LP */
	(DEC0_FORMAT|(1<<MSM_ADSP_MODE_TUNNEL)|(1<<MSM_ADSP_OP_DMA)), 0,
	0, 0, 0,

	/* Concurrency 1 */
	(DEC0_FORMAT|(1<<MSM_ADSP_MODE_TUNNEL)|(1<<MSM_ADSP_OP_DM)),
	(DEC1_FORMAT|(1<<MSM_ADSP_MODE_TUNNEL)|(1<<MSM_ADSP_OP_DM)),
	(DEC2_FORMAT|(1<<MSM_ADSP_MODE_TUNNEL)|(1<<MSM_ADSP_OP_DM)),
	(DEC3_FORMAT|(1<<MSM_ADSP_MODE_TUNNEL)|(1<<MSM_ADSP_OP_DM)),
	(DEC4_FORMAT),

	 /* Concurrency 2 */
	(DEC0_FORMAT|(1<<MSM_ADSP_MODE_TUNNEL)|(1<<MSM_ADSP_OP_DM)),
	(DEC1_FORMAT|(1<<MSM_ADSP_MODE_TUNNEL)|(1<<MSM_ADSP_OP_DM)),
	(DEC2_FORMAT|(1<<MSM_ADSP_MODE_TUNNEL)|(1<<MSM_ADSP_OP_DM)),
	(DEC3_FORMAT|(1<<MSM_ADSP_MODE_TUNNEL)|(1<<MSM_ADSP_OP_DM)),
	(DEC4_FORMAT),

	/* Concurrency 3 */
	(DEC0_FORMAT|(1<<MSM_ADSP_MODE_TUNNEL)|(1<<MSM_ADSP_OP_DM)),
	(DEC1_FORMAT|(1<<MSM_ADSP_MODE_TUNNEL)|(1<<MSM_ADSP_OP_DM)),
	(DEC2_FORMAT|(1<<MSM_ADSP_MODE_TUNNEL)|(1<<MSM_ADSP_OP_DM)),
	(DEC3_FORMAT|(1<<MSM_ADSP_MODE_NONTUNNEL)|(1<<MSM_ADSP_OP_DM)),
	(DEC4_FORMAT),

	/* Concurrency 4 */
	(DEC0_FORMAT|(1<<MSM_ADSP_MODE_TUNNEL)|(1<<MSM_ADSP_OP_DM)),
	(DEC1_FORMAT|(1<<MSM_ADSP_MODE_TUNNEL)|(1<<MSM_ADSP_OP_DM)),
	(DEC2_FORMAT|(1<<MSM_ADSP_MODE_NONTUNNEL)|(1<<MSM_ADSP_OP_DM)),
	(DEC3_FORMAT|(1<<MSM_ADSP_MODE_NONTUNNEL)|(1<<MSM_ADSP_OP_DM)),
	(DEC4_FORMAT),

	/* Concurrency 5 */
	(DEC0_FORMAT|(1<<MSM_ADSP_MODE_TUNNEL)|(1<<MSM_ADSP_OP_DM)),
	(DEC1_FORMAT|(1<<MSM_ADSP_MODE_NONTUNNEL)|(1<<MSM_ADSP_OP_DM)),
	(DEC2_FORMAT|(1<<MSM_ADSP_MODE_NONTUNNEL)|(1<<MSM_ADSP_OP_DM)),
	(DEC3_FORMAT|(1<<MSM_ADSP_MODE_NONTUNNEL)|(1<<MSM_ADSP_OP_DM)),
	(DEC4_FORMAT),

	/* Concurrency 6 */
	(DEC0_FORMAT|(1<<MSM_ADSP_MODE_TUNNEL)|
			(1<<MSM_ADSP_MODE_NONTUNNEL)|(1<<MSM_ADSP_OP_DM)),
	0, 0, 0, 0,

	/* Concurrency 7 */
	(DEC0_FORMAT|(1<<MSM_ADSP_MODE_NONTUNNEL)|(1<<MSM_ADSP_OP_DM)),
	(DEC1_FORMAT|(1<<MSM_ADSP_MODE_NONTUNNEL)|(1<<MSM_ADSP_OP_DM)),
	(DEC2_FORMAT|(1<<MSM_ADSP_MODE_NONTUNNEL)|(1<<MSM_ADSP_OP_DM)),
	(DEC3_FORMAT|(1<<MSM_ADSP_MODE_NONTUNNEL)|(1<<MSM_ADSP_OP_DM)),
	(DEC4_FORMAT),
};

#define DEC_INFO(name, queueid, decid, nr_codec) { .module_name = name, \
	.module_queueid = queueid, .module_decid = decid, \
	.nr_codec_support = nr_codec}

static struct msm_adspdec_info dec_info_list[] = {
	DEC_INFO("AUDPLAY0TASK", 13, 0, 11), /* AudPlay0BitStreamCtrlQueue */
	DEC_INFO("AUDPLAY1TASK", 14, 1, 11),  /* AudPlay1BitStreamCtrlQueue */
	DEC_INFO("AUDPLAY2TASK", 15, 2, 11),  /* AudPlay2BitStreamCtrlQueue */
	DEC_INFO("AUDPLAY3TASK", 16, 3, 11),  /* AudPlay3BitStreamCtrlQueue */
	DEC_INFO("AUDPLAY4TASK", 17, 4, 1),  /* AudPlay4BitStreamCtrlQueue */
};

static struct msm_adspdec_database msm_device_adspdec_database = {
	.num_dec = ARRAY_SIZE(dec_info_list),
	.num_concurrency_support = (ARRAY_SIZE(dec_concurrency_table) / \
					ARRAY_SIZE(dec_info_list)),
	.dec_concurrency_table = dec_concurrency_table,
	.dec_info_list = dec_info_list,
};

struct platform_device msm_device_adspdec = {
	.name = "msm_adspdec",
	.id = -1,
	.dev    = {
		.platform_data = &msm_device_adspdec_database
	},
};

#define SNDDEV_CAP_NONE 0x0
#define SNDDEV_CAP_RX 0x1 /* RX direction */
#define SNDDEV_CAP_TX 0x2 /* TX direction */
#define SNDDEV_CAP_VOICE 0x4 /* Support voice call */
#define SNDDEV_CAP_FM 0x10 /* Support FM radio */
#define SNDDEV_CAP_TTY 0x20 /* Support TTY */
#define CAD(desc, num, cap) { .name = #desc, .id = num, .capability = cap, }
static struct cad_endpoint cad_endpoints_list[] = {
#if 1
	/* VOICE CALL */
	CAD(NONE, 0, SNDDEV_CAP_NONE),
	CAD(HANDSET_RX, 1, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
	CAD(HANDSET_TX, 2, (SNDDEV_CAP_TX | SNDDEV_CAP_VOICE)),
	CAD(HEADSET_CALL_RX, 3, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
	CAD(HEADSET_CALL_TX, 4, (SNDDEV_CAP_TX | SNDDEV_CAP_VOICE)),
	CAD(SPEAKER_CALL_RX, 5, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
	CAD(SPEAKER_CALL_TX, 6, (SNDDEV_CAP_TX | SNDDEV_CAP_VOICE)),
	CAD(BT_CALL_RX, 7, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
	CAD(BT_CALL_TX, 8, (SNDDEV_CAP_TX | SNDDEV_CAP_VOICE)),
	CAD(BT_NREC_OFF_CALL_RX, 9, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
	CAD(BT_NREC_OFF_CALL_TX, 10, (SNDDEV_CAP_TX | SNDDEV_CAP_VOICE)),
	CAD(HANDSET_EXTRA_CALL_RX, 11, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
	CAD(HANDSET_EXTRA_CALL_TX, 12, (SNDDEV_CAP_TX | SNDDEV_CAP_VOICE)),
	CAD(SPEAKER_EXTRA_CALL_RX, 13, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
	CAD(SPEAKER_EXTRA_CALL_TX, 14, (SNDDEV_CAP_TX | SNDDEV_CAP_VOICE)),
	
	/* SOUND */
	CAD(HEADSET_AND_SPEAKER_RX, 21, (SNDDEV_CAP_RX)),
	CAD(MP3_HEADSET_3POLE_RX, 23, (SNDDEV_CAP_RX)),
	CAD(MP3_HEADSET_3POLE_TX, 24, (SNDDEV_CAP_TX)),
	CAD(MP3_SPEAKER_RX, 25, (SNDDEV_CAP_RX)),
	CAD(MP3_SPEAKER_TX, 26, (SNDDEV_CAP_TX)),
	CAD(MP3_HEADSET_RX, 27, (SNDDEV_CAP_RX)),
	CAD(MP3_HEADSET_TX, 28, (SNDDEV_CAP_TX)),

	/* AMR RECORDER */
	CAD(VOICE_RECORDER_HPH_RX, 31,(SNDDEV_CAP_RX)),
	CAD(VOICE_RECORDER_HPH_TX, 32,(SNDDEV_CAP_TX)),
	CAD(VOICE_RECORDER_SPK_RX, 33,(SNDDEV_CAP_RX)),
	CAD(VOICE_RECORDER_SPK_TX, 34,(SNDDEV_CAP_TX)),
	CAD(VOICE_RECOGNITION_RX, 35,(SNDDEV_CAP_RX)),
	CAD(VOICE_RECOGNITION_TX, 36,(SNDDEV_CAP_TX)),

	/* VOIP1 */
	CAD(HANDSET_VOIP_RX, 41, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
	CAD(HANDSET_VOIP_TX, 42, (SNDDEV_CAP_TX | SNDDEV_CAP_VOICE)),
	CAD(HEADSET_VOIP_RX, 43, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
	CAD(HEADSET_VOIP_TX, 44, (SNDDEV_CAP_TX | SNDDEV_CAP_VOICE)),
	CAD(SPEAKER_VOIP_RX, 45, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
	CAD(SPEAKER_VOIP_TX, 46, (SNDDEV_CAP_TX | SNDDEV_CAP_VOICE)),
	CAD(BT_VOIP_RX, 47, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
	CAD(BT_VOIP_TX, 48, (SNDDEV_CAP_TX | SNDDEV_CAP_VOICE)),

	/* VOIP2 */
	CAD(HANDSET_VOIP2_RX, 51, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
	CAD(HANDSET_VOIP2_TX, 52, (SNDDEV_CAP_TX | SNDDEV_CAP_VOICE)),
	CAD(HEADSET_VOIP2_RX, 53, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
	CAD(HEADSET_VOIP2_TX, 54, (SNDDEV_CAP_TX | SNDDEV_CAP_VOICE)),
	CAD(SPEAKER_VOIP2_RX, 55, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
	CAD(SPEAKER_VOIP2_TX, 56, (SNDDEV_CAP_TX | SNDDEV_CAP_VOICE)),
	CAD(BT_VOIP2_RX, 57, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
	CAD(BT_VOIP2_TX, 58, (SNDDEV_CAP_TX | SNDDEV_CAP_VOICE)),

	/* VOICE CALL2 */
	CAD(HANDSET_CALL2_RX, 61, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
	CAD(HANDSET_CALL2_TX, 62, (SNDDEV_CAP_TX | SNDDEV_CAP_VOICE)),
	CAD(HEADSET_CALL2_RX, 63, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
	CAD(HEADSET_CALL2_TX, 64, (SNDDEV_CAP_TX | SNDDEV_CAP_VOICE)),
	CAD(SPEAKER_CALL2_RX, 65, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
	CAD(SPEAKER_CALL2_TX, 66, (SNDDEV_CAP_TX | SNDDEV_CAP_VOICE)),
	CAD(BT_CALL2_RX, 67, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
	CAD(BT_CALL2_TX, 68, (SNDDEV_CAP_TX | SNDDEV_CAP_VOICE)),
	CAD(BT_NREC_OFF_CALL2_RX, 69, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
	CAD(BT_NREC_OFF_CALL2_TX, 70, (SNDDEV_CAP_TX | SNDDEV_CAP_VOICE)),
	CAD(HEADSET_3P_CALL2_RX, 71, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
	CAD(HEADSET_3P_CALL2_TX, 72, (SNDDEV_CAP_TX | SNDDEV_CAP_VOICE)),

	/* VT */
	CAD(HANDSET_VT_RX, 73, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
	CAD(HANDSET_VT_TX, 74, (SNDDEV_CAP_TX | SNDDEV_CAP_VOICE)),
	CAD(HEADSET_CALL_VT_RX, 75, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
	CAD(HEADSET_CALL_VT_TX, 76, (SNDDEV_CAP_TX | SNDDEV_CAP_VOICE)),
	CAD(SPEAKER_CALL_VT_RX, 77, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
	CAD(SPEAKER_CALL_VT_TX, 78, (SNDDEV_CAP_TX | SNDDEV_CAP_VOICE)),
	CAD(BT_CALL_VT_RX, 79, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
	CAD(BT_CALL_VT_TX, 80, (SNDDEV_CAP_TX | SNDDEV_CAP_VOICE)),

	/* LOOPBACK */
	CAD(HANDSET_LOOPBACK_RX, 81, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
	CAD(HANDSET_LOOPBACK_TX, 82, (SNDDEV_CAP_TX | SNDDEV_CAP_VOICE)),
	CAD(HEADSET_LOOPBACK_RX, 83, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
	CAD(HEADSET_LOOPBACK_TX, 84, (SNDDEV_CAP_TX | SNDDEV_CAP_VOICE)),
	CAD(SPEAKER_LOOPBACK_RX, 85, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
	CAD(SPEAKER_LOOPBACK_TX, 86, (SNDDEV_CAP_TX | SNDDEV_CAP_VOICE)),

	/* FM RADIO */
	CAD(FM_DIGITAL_STEREO_HEADSET, 91, (SNDDEV_CAP_FM | SNDDEV_CAP_RX)),
	CAD(FM_DIGITAL_SPEAKER_PHONE, 92, (SNDDEV_CAP_FM | SNDDEV_CAP_RX)),
	CAD(FM_ANALOG_STEREO_HEADSET, 93, (SNDDEV_CAP_FM | SNDDEV_CAP_RX)),
	CAD(FM_ANALOG_STEREO_HEADSET_CODEC, 94, (SNDDEV_CAP_FM | SNDDEV_CAP_RX)),

	/* AUDIO DOCK */
	CAD(AUDIO_DOCK_RX, 95, (SNDDEV_CAP_RX)),
	CAD(AUDIO_DOCK_TX, 96, (SNDDEV_CAP_TX)),
#else
	CAD(NONE, 0, SNDDEV_CAP_NONE),
	CAD(HANDSET_SPKR, 1, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
	CAD(HANDSET_MIC, 2, (SNDDEV_CAP_TX | SNDDEV_CAP_VOICE)),
	CAD(HEADSET_MIC, 3, (SNDDEV_CAP_TX | SNDDEV_CAP_VOICE)),
	CAD(HEADSET_SPKR_MONO, 4, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
	CAD(HEADSET_SPKR_STEREO, 5, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
	CAD(SPEAKER_PHONE_MIC, 6, (SNDDEV_CAP_TX | SNDDEV_CAP_VOICE)),
	CAD(SPEAKER_PHONE_MONO, 7, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
	CAD(SPEAKER_PHONE_STEREO, 8, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
	CAD(BT_SCO_MIC, 9, (SNDDEV_CAP_TX | SNDDEV_CAP_VOICE)),
	CAD(BT_SCO_SPKR, 10, (SNDDEV_CAP_TX | SNDDEV_CAP_VOICE)),
	CAD(BT_A2DP_SPKR, 11, (SNDDEV_CAP_RX | SNDDEV_CAP_VOICE)),
	CAD(TTY_HEADSET_MIC, 12, (SNDDEV_CAP_TX | \
			SNDDEV_CAP_VOICE | SNDDEV_CAP_TTY)),
	CAD(TTY_HEADSET_SPKR, 13, (SNDDEV_CAP_RX | \
			SNDDEV_CAP_VOICE | SNDDEV_CAP_TTY)),
	CAD(HEADSET_STEREO_PLUS_SPKR_MONO_RX, 19, (SNDDEV_CAP_TX | \
				SNDDEV_CAP_VOICE)),
	CAD(LP_FM_HEADSET_SPKR_STEREO_RX, 25, (SNDDEV_CAP_TX | SNDDEV_CAP_FM)),
	CAD(I2S_RX, 26, (SNDDEV_CAP_RX)),
	CAD(SPEAKER_PHONE_MIC_ENDFIRE, 45, (SNDDEV_CAP_TX | SNDDEV_CAP_VOICE)),
	CAD(HANDSET_MIC_ENDFIRE, 46, (SNDDEV_CAP_TX | SNDDEV_CAP_VOICE)),
	CAD(I2S_TX, 48, (SNDDEV_CAP_TX)),
	CAD(LP_FM_HEADSET_SPKR_STEREO_PLUS_HEADSET_SPKR_STEREO_RX, 57, \
			(SNDDEV_CAP_FM | SNDDEV_CAP_RX)),
	CAD(FM_DIGITAL_HEADSET_SPKR_STEREO, 65, \
			(SNDDEV_CAP_FM | SNDDEV_CAP_RX)),
	CAD(FM_DIGITAL_SPEAKER_PHONE_MONO, 67, \
			(SNDDEV_CAP_FM | SNDDEV_CAP_RX)),
	CAD(FM_DIGITAL_SPEAKER_PHONE_MIC, 68, \
			(SNDDEV_CAP_FM | SNDDEV_CAP_TX)),
	CAD(FM_DIGITAL_BT_A2DP_SPKR, 69, \
			(SNDDEV_CAP_FM | SNDDEV_CAP_RX)),
	CAD(MAX, 80, SNDDEV_CAP_NONE),
#endif
};
#undef CAD

static struct msm_cad_endpoints msm_device_cad_endpoints = {
	.endpoints = cad_endpoints_list,
	.num = sizeof(cad_endpoints_list) / sizeof(struct cad_endpoint)
};

struct platform_device msm_device_cad = {
	.name = "msm_cad",
	.id = -1,
	.dev    = {
		.platform_data = &msm_device_cad_endpoints
	},
};
