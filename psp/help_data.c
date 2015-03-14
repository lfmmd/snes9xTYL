#include "psp.h"

#define HELP_TOTAL_ENTRIES 27

static char help_data[LANGUAGE_NUMBER][HELP_TOTAL_ENTRIES][1024]  __attribute__((aligned(16))) = {
	{//english
		"Select slot to use for loading and saving state.",
		"Load state from current slot\nCurrent game progress will be lost!",
		"Save state to current slot.",
		"Import savestate from another emulator.\nY's uosnes9x and zsnes should work (not always)",
		"Takes a jpeg snapshot from current game screen.\nIt will be used as game icon in browser.",
		"Reset the SNES.\nGame progress will be lost!",
		"Choose between 3 modes :\n-off : sound processor not emulated, incompatible with some games\n-emulated/no output : compatible mode, but no sound.\n-on : compatible mode with sound.",
		"Choose mixing frequency.\nHigher sounds better, but is slower.",
		"Choose the GFX engine :\n-Approx. software\n-Accurate software mode\nPSP Accelerated\nPSP accel.+accu.Soft. : mixed mode\nPSP accel.+approx.Soft. : mixed mode\nThe PSP hardware cannot handle all snes graphics operations.\nFor this the mixed modes have been created.\nThey provide an autoswitch to best rendering mode, depending on\ncurrent snes graphics requirements.\nUse approx. modes for speed and accurate mode for quality.",
		"Frameskip is used to boost speed\nFrameskip 0 means all snes frames are drawn\n1 is 1 frame skipped for 1 frame rendered\n2 is 2 frame skipped for 1 frame rendered...",
		"Show how much call to rendering function was needed to compute the screen\nThe lowest, the fastest. This is usefull to check the impact of hacks (below)\n",
		"Use SNESAdvance speedhacks if available in the database.\nOnly used at rom loading time.",
		"Ignore Fixed Colour Changes.\nSuch changes won't trigger the screen update process.\nGFX may be altered (gradient, ...)",
		"Ignore Windows clipping Changes.\nSuch changes won't trigger the screen update process.\nGFX may be altered (missing area, ...)",
		"Ignore Add/Sub modes Changes.\nSuch changes won't trigger the screen update process.\nGFX may be altered (pixels being opaque instead of transparent, ...)",
		"Ignore Palette writes Changes.\nSuch changes won't trigger the screen update process.\nGFX may be altered (wrong colours, ...)",
		"Fast mode 7.\nWith this hack some controls aren't done in mode 7.\nGFX may be altered (pixels being opaque instead of transparent, ...)",
		"OBJ On/Off.\nUse this to disactivate(Off) SPRITES drawing.",
		"BG0 On/Off.\nUse this to disactivate(Off) BACKGROUND 0 drawing.",
		"BG1 On/Off.\nUse this to disactivate(Off) BACKGROUND 1 drawing.",
		"BG2 On/Off.\nUse this to disactivate(Off) BACKGROUND 2 drawing.",
		"BG3 On/Off.\nUse this to disactivate(Off) BACKGROUND 3 drawing.",
		"No Transparency.\nUse this to force no transparency rendering.\nGFX may be altered (pixels being opaque instead of transparent, ...)",
		"Fast sprites.\nUse this to disactivate intra-sprites priorities handling.\nGFX may be altered",
		"Render PAL as NTSC.\nPAL games have 240 vertical lines, NTSC 224.\nMost PAL games are NTSC conversion and so the 16 more lines not used.\nEnabling this option will help removing the black border at bottom.",
		"Autosave timer.\nThis usefull feature will create a savestate for you every n minutes.\nn can be choosen between 1 to 10min.",
		"Autosave SRAM.\nThis option will save SRAM after each modification by the game.\nThis can cause big slowdowns in some games."
	},
	{//japanese TODO : translation
		"スロットを選んで、そこでステートをロードと保存できます。",
		"現在のスロットからステートをロード\n現在のゲーム情報が消えてしまうのでご注意。",
		"現在のスロットにステートを保存。",
		"ステートデータを他のエミューからロード\nYのuosnes9xとZSNESが大丈夫そうですが場合によって出来ません。",
		"現在のゲーム画面をJPEG画像に保存\nブラウザーにアイコンとして利用されます。",
		"SNESリセット\n現在のゲーム情報が消えてしまうのでご注意。",
		"三つのモードが選べる、\n-off : 音なし、音CPUなし, ゲームによって動かせない。\n-emulated/no output : 音なし、音CPU有り\n-on : 音有り、音CPU有り",
		"音の品質を選ぶ、\n高ければ高いほど、音が良いが、エミューが遅くなります。",
		"描画エンジンの選択\n-Approx. software\n-Accurate software mode\nPSP Accelerated\nPSP accel.+accu.Soft. : mixed mode\nPSP accel.+approx.Soft. : mixed mode\nPSPのハードウエアがすべてのスーファミの描画機能出来ないため、\nソフトウエアも使うMixedModeが存在するのです。\n自動的に描画目的によって\nベストな描画ルーチンを選択するですが、\nApproxモードが速度を優先、Accurateが本物と同じ描画を目指す。",
		"Snesの速度を目指すため、ある時に描画しないという選択も出来ます\n0の場合、すべてのフレームが描画\n1は１：１描画する（する、しないの切り替え）\n2は描画を１回する、２回しない...",
		"Show how much call to rendering function was needed to compute the screen\nThe lowest, the fastest. This is usefull to check the impact of hacks (below)\n",
		"Use SNESAdvance speedhacks if available in the database.\nOnly used at rom loading time.",
		"Ignore Fixed Colour Changes.\nSuch changes won't trigger the screen update process.\nGFX may be altered (gradient, ...)",
		"Ignore Windows clipping Changes.\nSuch changes won't trigger the screen update process.\nGFX may be altered (missing area, ...)",
		"Ignore Add/Sub modes Changes.\nSuch changes won't trigger the screen update process.\nGFX may be altered (pixels being opaque instead of transparent, ...)",
		"Ignore Palette writes Changes.\nSuch changes won't trigger the screen update process.\nGFX may be altered (wrong colours, ...)",
		"Fast mode 7.\nWith this hack some controls aren't done in mode 7.\nGFX may be altered (pixels being opaque instead of transparent, ...)",
		"OBJ On/Off.\nUse this to disactivate(Off) SPRITES drawing.",
		"BG0 On/Off.\nUse this to disactivate(Off) BACKGROUND 0 drawing.",
		"BG1 On/Off.\nUse this to disactivate(Off) BACKGROUND 1 drawing.",
		"BG2 On/Off.\nUse this to disactivate(Off) BACKGROUND 2 drawing.",
		"BG3 On/Off.\nUse this to disactivate(Off) BACKGROUND 3 drawing.",
		"No Transparency.\nUse this to force no transparency rendering.\nGFX may be altered (pixels being opaque instead of transparent, ...)",
		"Fast sprites.\nUse this to disactivate intra-sprites priorities handling.\nGFX may be altered",
		"Render PAL as NTSC.\nPAL games have 240 vertical lines, NTSC 224.\nMost PAL games are NTSC conversion and so the 16 more lines not used.\nEnabling this option will help removing the black border at bottom.",
		"Autosave timer.\nThis usefull feature will create a savestate for you every n minutes.\nn can be choosen between 1 to 10min.",
		"Autosave SRAM.\nThis option will save SRAM after each modification by the game.\nThis can cause big slowdowns in some games."
	},
	{//french TODO : translation		
	  "Selectionne le slot pour charger/sauvegarder (savestate)",
	  "Charger sauvegarde du slot courant\nLa partie en cours sera perdu!",
	  "Sauvegarder dans le slot courant.",
		"Importer une sauvegarde (savestate) d'un autre emulateur.\nuosnes9x et zsnes sont supportes.\n\nCependant l'import peut echouer et le jeu risque de se figer...",
		"Sauvegarder une capture ecran de la partie en cours.\nElle sera utilisee sur l'ecran de selection des ROMS.",
		"Reseter la SNES.\nLa partie en cours sera perdu!",
		"3 modes possibles :\n-off : son non-emule, incompatible avec certains jeux\n-emule/inaudible : mode compatible, pas de son.\n-on : mode compatible avec son (plut lent)",
		"Frequence de mixage du son : \nplus elle est haute, meilleur est la qualite\net plus lente est l'emulation.",		
		"Mode GFX :\n-Approx. software\n-Accurate software mode\nPSP Accelerated\nPSP accel.+accu.Soft. : mixed mode\nPSP accel.+approx.Soft. : mixed mode\nLa PSP ne peut pas gerer tous les modes graphiques de la SNES.\nPour cela les mixed modes ont ete crees.\nIls permettent une selection automatique du meilleur mode,\nen fonction du mode snes actif.\nLes modes approx. sont rapides et parfois loin de l'original\nles modes accurate sont fideles mais plus lent.",
		"Le frameskip est utilise pour accelerer l'emulation.\nA frameskip 0 toutes les images sont calculees et affichees\nA frameskip 1, 1 image est sautee pour une calculee\nA 2, 2 images sont sautees pour une calculee...",
		"Show how much call to rendering function was needed to compute the screen\nThe lowest, the fastest. This is usefull to check the impact of hacks (below)\n",
		"Use SNESAdvance speedhacks if available in the database.\nOnly used at rom loading time.",
		"Ignore Fixed Colour Changes.\nSuch changes won't trigger the screen update process.\nGFX may be altered (gradient, ...)",
		"Ignore Windows clipping Changes.\nSuch changes won't trigger the screen update process.\nGFX may be altered (missing area, ...)",
		"Ignore Add/Sub modes Changes.\nSuch changes won't trigger the screen update process.\nGFX may be altered (pixels being opaque instead of transparent, ...)",
		"Ignore Palette writes Changes.\nSuch changes won't trigger the screen update process.\nGFX may be altered (wrong colours, ...)",
		"Fast mode 7.\nWith this hack some controls aren't done in mode 7.\nGFX may be altered (pixels being opaque instead of transparent, ...)",
		"OBJ On/Off.\nUse this to disactivate(Off) SPRITES drawing.",
		"BG0 On/Off.\nUse this to disactivate(Off) BACKGROUND 0 drawing.",
		"BG1 On/Off.\nUse this to disactivate(Off) BACKGROUND 1 drawing.",
		"BG2 On/Off.\nUse this to disactivate(Off) BACKGROUND 2 drawing.",
		"BG3 On/Off.\nUse this to disactivate(Off) BACKGROUND 3 drawing.",
		"No Transparency.\nUse this to force no transparency rendering.\nGFX may be altered (pixels being opaque instead of transparent, ...)",
		"Fast sprites.\nUse this to disactivate intra-sprites priorities handling.\nGFX may be altered",
		"Render PAL as NTSC.\nPAL games have 240 vertical lines, NTSC 224.\nMost PAL games are NTSC conversion and so the 16 more lines not used.\nEnabling this option will help removing the black border at bottom.",
		"Autosave timer.\nThis usefull feature will create a savestate for you every n minutes.\nn can be choosen between 1 to 10min.",
		"Autosave SRAM.\nThis option will save SRAM after each modification by the game.\nThis can cause big slowdowns in some games."
	}
};
	
