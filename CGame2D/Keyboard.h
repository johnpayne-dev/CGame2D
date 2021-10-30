#pragma once
#include <SDL2/SDL.h>
#include <stdbool.h>

typedef enum cgKey
{
	cgKeyUnknown = 0,
	cgKeyA = 4, cgKeyB = 5, cgKeyC = 6,
	cgKeyD = 7, cgKeyE = 8, cgKeyF = 9,
	cgKeyG = 10, cgKeyH = 11, cgKeyI = 12, cgKeyJ = 13, cgKeyK = 14,
	cgKeyL = 15, cgKeyM = 16, cgKeyN = 17, cgKeyO = 18, cgKeyP = 19,
	cgKeyQ = 20, cgKeyR = 21, cgKeyS = 22, cgKeyT = 23, cgKeyU = 24,
	cgKeyV = 25, cgKeyW = 26, cgKeyX = 27, cgKeyY = 28, cgKeyZ = 29,
	cgKey1 = 30, cgKey2 = 31, cgKey3 = 32, cgKey4 = 33, cgKey5 = 34,
	cgKey6 = 35, cgKey7 = 36, cgKey8 = 37, cgKey9 = 38, cgKey0 = 39,
	
	cgKeyReturn = 40, cgKeyEscape = 41, cgKeyBackspace = 42,
	cgKeyTab = 43, cgKeySpace = 44,

	cgKeyMinus = 45, cgKeyEquals = 46, cgKeyLeftBracket = 47,
	cgKeyRightBracket = 48, cgKeyBackslash = 49, cgKeyNonushash = 50,
	cgKeySemicolon = 51, cgKeyApostrophe = 52, cgKeyGrave = 53,
	cgKeyComma = 54, cgKeyPeriod = 55, cgKeySlash = 56,

	cgKeyCapsLock = 57,

	cgKeyF1 = 58, cgKeyF2 = 59, cgKeyF3 = 60, cgKeyF4 = 61,
	cgKeyF5 = 62, cgKeyF6 = 63, cgKeyF7 = 64, cgKeyF8 = 65,
	cgKeyF9 = 66, cgKeyF10 = 67, cgKeyF11 = 68, cgKeyF12 = 69,

	cgKeyPrintScreen = 70, cgKeyScrollLock = 71, cgKeyPause = 72,
	cgKeyInsert = 73, cgKeyHome = 74, cgKeyPageUp = 75, cgKeyDelete = 76,
	cgKeyEnd = 77, cgKeyPageDown = 78, cgKeyRight = 79, cgKeyLeft = 80,
	cgKeyDown = 81, cgKeyUp = 82,

	cgKeyNumLockClear = 83, cgKeyKPDivide = 84, cgKeyKPMultiply = 85,
	cgKeyKPMinus = 86, cgKeyKPPlus = 87, cgKeyKPEnter = 88,
	cgKeyKP1 = 89, cgKeyKP2 = 90, cgKeyKP3 = 91, cgKeyKP4 = 92,
	cgKeyKP5 = 93, cgKeyKP6 = 94, cgKeyKP7 = 95, cgKeyKP8 = 96,
	cgKeyKP9 = 97, cgKeyKP0 = 98, cgKeyKPPeriod = 99,

	cgKeyNonusBackslash = 100, cgKeyApplication = 101, cgKeyPower = 102,
	cgKeyKPEquals = 103, cgKeyF13 = 104, cgKeyF14 = 105, cgKeyF15 = 106,
	cgKeyF16 = 107, cgKeyF17 = 108, cgKeyF18 = 109, cgKeyF19 = 110,
	cgKeyF20 = 111, cgKeyF21 = 112, cgKeyF22 = 113, cgKeyF23 = 114,
	cgKeyF24 = 115, cgKeyExecute = 116, cgKeyHelp = 117, cgKeyMenu = 118,
	cgKeySelect = 119, cgKeyStop = 120, cgKeyAgain = 121,
	cgKeyUndo = 122, cgKeyCut = 123, cgKeyCopy = 124, cgKeyPaste = 125,
	cgKeyFind = 126, cgKeyMute = 127, cgKeyVolumeUp = 128,
	cgKeyVolumeDown = 129, cgKeyKPComma = 133, cgKeyKPEqualsAS400 = 134,

	cgKeyInternational1 = 135, cgKeyInternational2 = 136,
	cgKeyInternational3 = 137, cgKeyInternational4 = 138,
	cgKeyInternational5 = 139, cgKeyInternational6 = 140,
	cgKeyInternational7 = 141, cgKeyInternational8 = 142,
	cgKeyInternational9 = 143,
	cgKeyLang1 = 144, cgKeyLang2 = 145, cgKeyLang3 = 146,
	cgKeyLang4 = 147, cgKeyLang5 = 148, cgKeyLang6 = 149,
	cgKeyLang7 = 150, cgKeyLang8 = 151, cgKeyLang9 = 152,

	cgKeyAlterase = 153, cgKeySysReq = 154, cgKeyCancel = 155,
	cgKeyClear = 156, cgKeyPrior = 157, cgKeyReturn2 = 158,
	cgKeySeparator = 159, cgKeyOut = 160, cgKeyOper = 161,
	cgKeyClearAgain = 162, cgKeyCrsel = 163, cgKeyExsel = 164,

	cgKeyKP00 = 176, cgKeyKP000 = 177, cgKeyThousandsSeparator = 178,
	cgKeyDecimalSeparator = 179, cgKeyCurrencyUnit = 180,
	cgKeyCurrencySubunit = 181, cgKeyKPLeftParen = 182,
	cgKeyKPRightParen = 183, cgKeyKPLeftBrace = 184, cgKeyKPRightBrace = 185,
	cgKeyKPTab = 186, cgKeyKPBackspace = 187, cgKeyKPA = 188,
	cgKeyKPB = 189, cgKeyKPC = 190, cgKeyKPD = 191, cgKeyKPE = 192,
	cgKeyKPF = 193, cgKeyKPXor = 194, cgKeyKPPower = 195,
	cgKeyKPPercent = 196, cgKeyKPLess = 197, cgKeyKPGreater = 198,
	cgKeyKPAmpersand = 199, cgKeyKPDBLAmpersand = 200,
	cgKeyKPVerticalBar = 201, cgKeyKPDBLVerticalBar = 202,
	cgKeyKPColor = 203, cgKeyKPHash = 204, cgKeyKPSpace = 205,
	cgKeyKPAt = 206, cgKeyKPExclam = 207, cgKeyKPMemStore = 208,
	cgKeyKPMemRecall = 209, cgKeyKPMemClear = 210, cgKeyKPMemAdd = 211,
	cgKeyKPMemSubtract = 212, cgKeyKPMemMultiply = 213,
	cgKeyKPMemDivide = 214, cgKeyKPPlusMinus = 215, cgKeyKPClear = 216,
	cgKeyKPClearEntry = 217, cgKeyKPBinary = 218, cgKeyKPOctal = 219,
	cgKeyKPDecimal = 220, cgKeyKPHexadecimal = 221,

	cgKeyLCtrl = 224, cgKeyLShift = 225, cgKeyLAlt = 226,
	cgKeyLGui = 227, cgKeyRCtrl = 228, cgKeyRShift = 229,
	cgKeyRAlt = 230, cgKeyRGui = 231, cgKeyMode = 257,

	cgKeyAudioNext = 258, cgKeyAudioPrev = 259, cgKeyAudioStop = 260,
	cgKeyAudioPlay = 261, cgKeyAudioMute = 262, cgKeyMediaSelect = 263,
	cgKeyWWW = 264, cgKeyMail = 265, cgKeyCalculator = 266,
	cgKeyComputer = 267, cgKeyACSearch = 268, cgKeyACHome = 269,
	cgKeyACBack = 270, cgKeyACForward = 271, cgKeyACStop = 272,
	cgKeyACRefresh = 273, cgKeyACBookmarks = 274,

	cgKeyBrightnessDown = 275, cgKeyBrightnessUp = 276,
	cgKeyDisplaySwitch = 277, cgKeyKBDIllumToggle = 278,
	cgKeyKBDIllumDown = 279, cgKeyKBDIllumUp = 280, cgKeyEject = 281,
	cgKeySleep = 282, cgKeyApp1 = 283, cgKeyApp2 = 284,
	cgKeyAudioRewind = 285, cgKeyAudioFastForward = 286,

	cgKeyCount = 512
} cgKey;

void cgKeyboardInitialize(void);

bool cgKeyboardKeyRepeatEnabled(void);

bool cgKeyboardOnScreenSupport(void);

bool cgKeyboardTextInputEnabled(void);

bool cgKeyboardIsKeyPressed(cgKey key);

void cgKeyboardSetKeyRepeat(bool enable);

void cgKeyboardSetTextInput(bool enable);
