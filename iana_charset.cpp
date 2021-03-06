// iana_charset.h
// Generated automatically by parse_iana_charsets.pl Thu Apr 10 03:09:39 2014
// DO NOT EDIT!!!

#include "gb-include.h"
#include "iana_charset.h"
#include "HashTableX.h"
#include "Conf.h"
#include "hash.h"
#include "GbMutex.h"
#include "ScopedLock.h"

typedef struct {
    const char *name;
    const char *mime;
    int16_t mib_enum;
    bool supported;
} IANACharset;

static const IANACharset s_charsets[] = {
	{"ANSI_X3.4-1968", "csASCII", 3, true},
	{"iso-ir-6", "csASCII", 3, true},
	{"ANSI_X3.4-1986", "csASCII", 3, true},
	{"ISO_646.irv:1991", "csASCII", 3, true},
	{"ASCII", "csASCII", 3, true},
	{"ISO646-US", "csASCII", 3, true},
	{"US-ASCII", "csASCII", 3, true},
	{"us", "csASCII", 3, true},
	{"IBM367", "csASCII", 3, true},
	{"cp367", "csASCII", 3, true},
	{"csASCII", "csASCII", 3, true},
	{"ISO_8859-1:1987", "csISOLatin1", 4, true},
	{"iso-ir-100", "csISOLatin1", 4, true},
	{"ISO_8859-1", "csISOLatin1", 4, true},
	{"ISO-8859-1", "csISOLatin1", 4, true},
	{"latin1", "csISOLatin1", 4, true},
	{"l1", "csISOLatin1", 4, true},
	{"IBM819", "csISOLatin1", 4, true},
	{"CP819", "csISOLatin1", 4, true},
	{"csISOLatin1", "csISOLatin1", 4, true},
	{"ISO_8859-2:1987", "csISOLatin2", 5, true},
	{"iso-ir-101", "csISOLatin2", 5, true},
	{"ISO_8859-2", "csISOLatin2", 5, true},
	{"ISO-8859-2", "csISOLatin2", 5, true},
	{"latin2", "csISOLatin2", 5, true},
	{"l2", "csISOLatin2", 5, true},
	{"csISOLatin2", "csISOLatin2", 5, true},
	{"ISO_8859-3:1988", "csISOLatin3", 6, true},
	{"iso-ir-109", "csISOLatin3", 6, true},
	{"ISO_8859-3", "csISOLatin3", 6, true},
	{"ISO-8859-3", "csISOLatin3", 6, true},
	{"latin3", "csISOLatin3", 6, true},
	{"l3", "csISOLatin3", 6, true},
	{"csISOLatin3", "csISOLatin3", 6, true},
	{"ISO_8859-4:1988", "csISOLatin4", 7, true},
	{"iso-ir-110", "csISOLatin4", 7, true},
	{"ISO_8859-4", "csISOLatin4", 7, true},
	{"ISO-8859-4", "csISOLatin4", 7, true},
	{"latin4", "csISOLatin4", 7, true},
	{"l4", "csISOLatin4", 7, true},
	{"csISOLatin4", "csISOLatin4", 7, true},
	{"ISO_8859-5:1988", "csISOLatinCyrillic", 8, true},
	{"iso-ir-144", "csISOLatinCyrillic", 8, true},
	{"ISO_8859-5", "csISOLatinCyrillic", 8, true},
	{"ISO-8859-5", "csISOLatinCyrillic", 8, true},
	{"cyrillic", "csISOLatinCyrillic", 8, true},
	{"csISOLatinCyrillic", "csISOLatinCyrillic", 8, true},
	{"ISO_8859-6:1987", "csISOLatinArabic", 9, true},
	{"iso-ir-127", "csISOLatinArabic", 9, true},
	{"ISO_8859-6", "csISOLatinArabic", 9, true},
	{"ISO-8859-6", "csISOLatinArabic", 9, true},
	{"ECMA-114", "csISOLatinArabic", 9, true},
	{"ASMO-708", "csISOLatinArabic", 9, true},
	{"arabic", "csISOLatinArabic", 9, true},
	{"csISOLatinArabic", "csISOLatinArabic", 9, true},
	{"ISO_8859-7:1987", "csISOLatinGreek", 10, true},
	{"iso-ir-126", "csISOLatinGreek", 10, true},
	{"ISO_8859-7", "csISOLatinGreek", 10, true},
	{"ISO-8859-7", "csISOLatinGreek", 10, true},
	{"ELOT_928", "csISOLatinGreek", 10, true},
	{"ECMA-118", "csISOLatinGreek", 10, true},
	{"greek", "csISOLatinGreek", 10, true},
	{"greek8", "csISOLatinGreek", 10, true},
	{"csISOLatinGreek", "csISOLatinGreek", 10, true},
	{"ISO_8859-8:1988", "csISOLatinHebrew", 11, true},
	{"iso-ir-138", "csISOLatinHebrew", 11, true},
	{"ISO_8859-8", "csISOLatinHebrew", 11, true},
	{"ISO-8859-8", "csISOLatinHebrew", 11, true},
	{"hebrew", "csISOLatinHebrew", 11, true},
	{"csISOLatinHebrew", "csISOLatinHebrew", 11, true},
	{"ISO_8859-9:1989", "csISOLatin5", 12, true},
	{"iso-ir-148", "csISOLatin5", 12, true},
	{"ISO_8859-9", "csISOLatin5", 12, true},
	{"ISO-8859-9", "csISOLatin5", 12, true},
	{"latin5", "csISOLatin5", 12, true},
	{"l5", "csISOLatin5", 12, true},
	{"csISOLatin5", "csISOLatin5", 12, true},
	{"ISO-8859-10", "ISO-8859-10", 13, true},
	{"iso-ir-157", "ISO-8859-10", 13, true},
	{"l6", "ISO-8859-10", 13, true},
	{"ISO_8859-10:1992", "ISO-8859-10", 13, true},
	{"csISOLatin6", "ISO-8859-10", 13, true},
	{"latin6", "ISO-8859-10", 13, true},
	{"ISO_6937-2-add", "ISO_6937-2-add", 14, false},
	{"iso-ir-142", "ISO_6937-2-add", 14, false},
	{"csISOTextComm", "ISO_6937-2-add", 14, false},
	{"JIS_X0201", "JIS_X0201", 15, true},
	{"X0201", "JIS_X0201", 15, true},
	{"csHalfWidthKatakana", "JIS_X0201", 15, true},
	{"JIS_Encoding", "JIS_Encoding", 16, false},
	{"csJISEncoding", "JIS_Encoding", 16, false},
	{"Shift_JIS", "Shift_JIS", 17, true},
	{"MS_Kanji", "Shift_JIS", 17, true},
	{"csShiftJIS", "Shift_JIS", 17, true},
	{"x-sjis", "Shift_JIS", 17, true},
	{"Extended_UNIX_Code_Packed_Format_for_Japanese", "EUC-JP", 18, true},
	{"csEUCPkdFmtJapanese", "EUC-JP", 18, true},
	{"EUC-JP", "EUC-JP", 18, true},
	{"Extended_UNIX_Code_Fixed_Width_for_Japanese", "Extended_UNIX_Code_Fixed_Width_for_Japanese", 19, false},
	{"csEUCFixWidJapanese", "Extended_UNIX_Code_Fixed_Width_for_Japanese", 19, false},
	{"BS_4730", "BS_4730", 20, false},
	{"iso-ir-4", "BS_4730", 20, false},
	{"ISO646-GB", "BS_4730", 20, false},
	{"gb", "BS_4730", 20, false},
	{"uk", "BS_4730", 20, false},
	{"csISO4UnitedKingdom", "BS_4730", 20, false},
	{"SEN_850200_C", "SEN_850200_C", 21, false},
	{"iso-ir-11", "SEN_850200_C", 21, false},
	{"ISO646-SE2", "SEN_850200_C", 21, false},
	{"se2", "SEN_850200_C", 21, false},
	{"csISO11SwedishForNames", "SEN_850200_C", 21, false},
	{"IT", "IT", 22, false},
	{"iso-ir-15", "IT", 22, false},
	{"ISO646-IT", "IT", 22, false},
	{"csISO15Italian", "IT", 22, false},
	{"ES", "ES", 23, false},
	{"iso-ir-17", "ES", 23, false},
	{"ISO646-ES", "ES", 23, false},
	{"csISO17Spanish", "ES", 23, false},
	{"DIN_66003", "DIN_66003", 24, false},
	{"iso-ir-21", "DIN_66003", 24, false},
	{"de", "DIN_66003", 24, false},
	{"ISO646-DE", "DIN_66003", 24, false},
	{"csISO21German", "DIN_66003", 24, false},
	{"NS_4551-1", "NS_4551-1", 25, false},
	{"iso-ir-60", "NS_4551-1", 25, false},
	{"ISO646-NO", "NS_4551-1", 25, false},
	{"no", "NS_4551-1", 25, false},
	{"csISO60DanishNorwegian", "NS_4551-1", 25, false},
	{"csISO60Norwegian1", "NS_4551-1", 25, false},
	{"NF_Z_62-010", "NF_Z_62-010", 26, false},
	{"iso-ir-69", "NF_Z_62-010", 26, false},
	{"ISO646-FR", "NF_Z_62-010", 26, false},
	{"fr", "NF_Z_62-010", 26, false},
	{"csISO69French", "NF_Z_62-010", 26, false},
	{"ISO-10646-UTF-1", "ISO-10646-UTF-1", 27, false},
	{"csISO10646UTF1", "ISO-10646-UTF-1", 27, false},
	{"ISO_646.basic:1983", "ISO_646.basic:1983", 28, false},
	{"ref", "ISO_646.basic:1983", 28, false},
	{"csISO646basic1983", "ISO_646.basic:1983", 28, false},
	{"INVARIANT", "INVARIANT", 29, false},
	{"csINVARIANT", "INVARIANT", 29, false},
	{"ISO_646.irv:1983", "ISO_646.irv:1983", 30, false},
	{"iso-ir-2", "ISO_646.irv:1983", 30, false},
	{"irv", "ISO_646.irv:1983", 30, false},
	{"csISO2IntlRefVersion", "ISO_646.irv:1983", 30, false},
	{"NATS-SEFI", "NATS-SEFI", 31, false},
	{"iso-ir-8-1", "NATS-SEFI", 31, false},
	{"csNATSSEFI", "NATS-SEFI", 31, false},
	{"NATS-SEFI-ADD", "NATS-SEFI-ADD", 32, false},
	{"iso-ir-8-2", "NATS-SEFI-ADD", 32, false},
	{"csNATSSEFIADD", "NATS-SEFI-ADD", 32, false},
	{"NATS-DANO", "NATS-DANO", 33, false},
	{"iso-ir-9-1", "NATS-DANO", 33, false},
	{"csNATSDANO", "NATS-DANO", 33, false},
	{"NATS-DANO-ADD", "NATS-DANO-ADD", 34, false},
	{"iso-ir-9-2", "NATS-DANO-ADD", 34, false},
	{"csNATSDANOADD", "NATS-DANO-ADD", 34, false},
	{"SEN_850200_B", "SEN_850200_B", 35, false},
	{"iso-ir-10", "SEN_850200_B", 35, false},
	{"FI", "SEN_850200_B", 35, false},
	{"ISO646-FI", "SEN_850200_B", 35, false},
	{"ISO646-SE", "SEN_850200_B", 35, false},
	{"se", "SEN_850200_B", 35, false},
	{"csISO10Swedish", "SEN_850200_B", 35, false},
	{"KS_C_5601-1987", "x-windows-949", 36, true},
	{"iso-ir-149", "x-windows-949", 36, true},
	{"KS_C_5601-1989", "x-windows-949", 36, true},
	{"KSC_5601", "x-windows-949", 36, true},
	{"korean", "x-windows-949", 36, true},
	{"csKSC56011987", "x-windows-949", 36, true},
	{"ISO-2022-KR", "ISO-2022-KR", 37, true},
	{"csISO2022KR", "ISO-2022-KR", 37, true},
	{"EUC-KR", "EUC-KR", 38, true},
	{"csEUCKR", "EUC-KR", 38, true},
	{"ISO-2022-JP", "ISO-2022-JP", 39, true},
	{"csISO2022JP", "ISO-2022-JP", 39, true},
	{"ISO-2022-JP-2", "ISO-2022-JP-2", 40, true},
	{"csISO2022JP2", "ISO-2022-JP-2", 40, true},
	{"JIS_C6220-1969-jp", "JIS_C6220-1969-jp", 41, false},
	{"JIS_C6220-1969", "JIS_C6220-1969-jp", 41, false},
	{"iso-ir-13", "JIS_C6220-1969-jp", 41, false},
	{"katakana", "JIS_C6220-1969-jp", 41, false},
	{"x0201-7", "JIS_C6220-1969-jp", 41, false},
	{"csISO13JISC6220jp", "JIS_C6220-1969-jp", 41, false},
	{"JIS_C6220-1969-ro", "JIS_C6220-1969-ro", 42, true},
	{"iso-ir-14", "JIS_C6220-1969-ro", 42, true},
	{"jp", "JIS_C6220-1969-ro", 42, true},
	{"ISO646-JP", "JIS_C6220-1969-ro", 42, true},
	{"csISO14JISC6220ro", "JIS_C6220-1969-ro", 42, true},
	{"PT", "PT", 43, false},
	{"iso-ir-16", "PT", 43, false},
	{"ISO646-PT", "PT", 43, false},
	{"csISO16Portuguese", "PT", 43, false},
	{"greek7-old", "greek7-old", 44, false},
	{"iso-ir-18", "greek7-old", 44, false},
	{"csISO18Greek7Old", "greek7-old", 44, false},
	{"latin-greek", "latin-greek", 45, false},
	{"iso-ir-19", "latin-greek", 45, false},
	{"csISO19LatinGreek", "latin-greek", 45, false},
	{"NF_Z_62-010_(1973)", "NF_Z_62-010_(1973)", 46, false},
	{"iso-ir-25", "NF_Z_62-010_(1973)", 46, false},
	{"ISO646-FR1", "NF_Z_62-010_(1973)", 46, false},
	{"csISO25French", "NF_Z_62-010_(1973)", 46, false},
	{"Latin-greek-1", "Latin-greek-1", 47, false},
	{"iso-ir-27", "Latin-greek-1", 47, false},
	{"csISO27LatinGreek1", "Latin-greek-1", 47, false},
	{"ISO_5427", "ISO_5427", 48, false},
	{"iso-ir-37", "ISO_5427", 48, false},
	{"csISO5427Cyrillic", "ISO_5427", 48, false},
	{"JIS_C6226-1978", "JIS_C6226-1978", 49, false},
	{"iso-ir-42", "JIS_C6226-1978", 49, false},
	{"csISO42JISC62261978", "JIS_C6226-1978", 49, false},
	{"BS_viewdata", "BS_viewdata", 50, false},
	{"iso-ir-47", "BS_viewdata", 50, false},
	{"csISO47BSViewdata", "BS_viewdata", 50, false},
	{"INIS", "INIS", 51, false},
	{"iso-ir-49", "INIS", 51, false},
	{"csISO49INIS", "INIS", 51, false},
	{"INIS-8", "INIS-8", 52, false},
	{"iso-ir-50", "INIS-8", 52, false},
	{"csISO50INIS8", "INIS-8", 52, false},
	{"INIS-cyrillic", "INIS-cyrillic", 53, false},
	{"iso-ir-51", "INIS-cyrillic", 53, false},
	{"csISO51INISCyrillic", "INIS-cyrillic", 53, false},
	{"ISO_5427:1981", "ISO_5427:1981", 54, false},
	{"iso-ir-54", "ISO_5427:1981", 54, false},
	{"ISO5427Cyrillic1981", "ISO_5427:1981", 54, false},
	{"ISO_5428:1980", "ISO_5428:1980", 55, false},
	{"iso-ir-55", "ISO_5428:1980", 55, false},
	{"csISO5428Greek", "ISO_5428:1980", 55, false},
	{"GB_1988-80", "GB_1988-80", 56, true},
	{"iso-ir-57", "GB_1988-80", 56, true},
	{"cn", "GB_1988-80", 56, true},
	{"ISO646-CN", "GB_1988-80", 56, true},
	{"csISO57GB1988", "GB_1988-80", 56, true},
	{"GB_2312-80", "GB_2312-80", 57, true},
	{"iso-ir-58", "GB_2312-80", 57, true},
	{"chinese", "GB_2312-80", 57, true},
	{"csISO58GB231280", "GB_2312-80", 57, true},
	{"NS_4551-2", "NS_4551-2", 58, false},
	{"ISO646-NO2", "NS_4551-2", 58, false},
	{"iso-ir-61", "NS_4551-2", 58, false},
	{"no2", "NS_4551-2", 58, false},
	{"csISO61Norwegian2", "NS_4551-2", 58, false},
	{"videotex-suppl", "videotex-suppl", 59, false},
	{"iso-ir-70", "videotex-suppl", 59, false},
	{"csISO70VideotexSupp1", "videotex-suppl", 59, false},
	{"PT2", "PT2", 60, false},
	{"iso-ir-84", "PT2", 60, false},
	{"ISO646-PT2", "PT2", 60, false},
	{"csISO84Portuguese2", "PT2", 60, false},
	{"ES2", "ES2", 61, false},
	{"iso-ir-85", "ES2", 61, false},
	{"ISO646-ES2", "ES2", 61, false},
	{"csISO85Spanish2", "ES2", 61, false},
	{"MSZ_7795.3", "MSZ_7795.3", 62, false},
	{"iso-ir-86", "MSZ_7795.3", 62, false},
	{"ISO646-HU", "MSZ_7795.3", 62, false},
	{"hu", "MSZ_7795.3", 62, false},
	{"csISO86Hungarian", "MSZ_7795.3", 62, false},
	{"JIS_C6226-1983", "JIS_C6226-1983", 63, true},
	{"iso-ir-87", "JIS_C6226-1983", 63, true},
	{"x0208", "JIS_C6226-1983", 63, true},
	{"JIS_X0208-1983", "JIS_C6226-1983", 63, true},
	{"csISO87JISX0208", "JIS_C6226-1983", 63, true},
	{"greek7", "greek7", 64, false},
	{"iso-ir-88", "greek7", 64, false},
	{"csISO88Greek7", "greek7", 64, false},
	{"ASMO_449", "ASMO_449", 65, false},
	{"ISO_9036", "ASMO_449", 65, false},
	{"arabic7", "ASMO_449", 65, false},
	{"iso-ir-89", "ASMO_449", 65, false},
	{"csISO89ASMO449", "ASMO_449", 65, false},
	{"iso-ir-90", "iso-ir-90", 66, false},
	{"csISO90", "iso-ir-90", 66, false},
	{"JIS_C6229-1984-a", "JIS_C6229-1984-a", 67, false},
	{"iso-ir-91", "JIS_C6229-1984-a", 67, false},
	{"jp-ocr-a", "JIS_C6229-1984-a", 67, false},
	{"csISO91JISC62291984a", "JIS_C6229-1984-a", 67, false},
	{"JIS_C6229-1984-b", "JIS_C6229-1984-b", 68, false},
	{"iso-ir-92", "JIS_C6229-1984-b", 68, false},
	{"ISO646-JP-OCR-B", "JIS_C6229-1984-b", 68, false},
	{"jp-ocr-b", "JIS_C6229-1984-b", 68, false},
	{"csISO92JISC62991984b", "JIS_C6229-1984-b", 68, false},
	{"JIS_C6229-1984-b-add", "JIS_C6229-1984-b-add", 69, false},
	{"iso-ir-93", "JIS_C6229-1984-b-add", 69, false},
	{"jp-ocr-b-add", "JIS_C6229-1984-b-add", 69, false},
	{"csISO93JIS62291984badd", "JIS_C6229-1984-b-add", 69, false},
	{"JIS_C6229-1984-hand", "JIS_C6229-1984-hand", 70, false},
	{"iso-ir-94", "JIS_C6229-1984-hand", 70, false},
	{"jp-ocr-hand", "JIS_C6229-1984-hand", 70, false},
	{"csISO94JIS62291984hand", "JIS_C6229-1984-hand", 70, false},
	{"JIS_C6229-1984-hand-add", "JIS_C6229-1984-hand-add", 71, false},
	{"iso-ir-95", "JIS_C6229-1984-hand-add", 71, false},
	{"jp-ocr-hand-add", "JIS_C6229-1984-hand-add", 71, false},
	{"csISO95JIS62291984handadd", "JIS_C6229-1984-hand-add", 71, false},
	{"JIS_C6229-1984-kana", "JIS_C6229-1984-kana", 72, false},
	{"iso-ir-96", "JIS_C6229-1984-kana", 72, false},
	{"csISO96JISC62291984kana", "JIS_C6229-1984-kana", 72, false},
	{"ISO_2033-1983", "ISO_2033-1983", 73, false},
	{"iso-ir-98", "ISO_2033-1983", 73, false},
	{"e13b", "ISO_2033-1983", 73, false},
	{"csISO2033", "ISO_2033-1983", 73, false},
	{"ANSI_X3.110-1983", "ANSI_X3.110-1983", 74, false},
	{"iso-ir-99", "ANSI_X3.110-1983", 74, false},
	{"CSA_T500-1983", "ANSI_X3.110-1983", 74, false},
	{"NAPLPS", "ANSI_X3.110-1983", 74, false},
	{"csISO99NAPLPS", "ANSI_X3.110-1983", 74, false},
	{"T.61-7bit", "T.61-7bit", 75, false},
	{"iso-ir-102", "T.61-7bit", 75, false},
	{"csISO102T617bit", "T.61-7bit", 75, false},
	{"T.61-8bit", "T.61-8bit", 76, false},
	{"T.61", "T.61-8bit", 76, false},
	{"iso-ir-103", "T.61-8bit", 76, false},
	{"csISO103T618bit", "T.61-8bit", 76, false},
	{"ECMA-cyrillic", "ECMA-cyrillic", 77, false},
	{"iso-ir-111", "ECMA-cyrillic", 77, false},
	{"KOI8-E", "ECMA-cyrillic", 77, false},
	{"csISO111ECMACyrillic", "ECMA-cyrillic", 77, false},
	{"CSA_Z243.4-1985-1", "CSA_Z243.4-1985-1", 78, false},
	{"iso-ir-121", "CSA_Z243.4-1985-1", 78, false},
	{"ISO646-CA", "CSA_Z243.4-1985-1", 78, false},
	{"csa7-1", "CSA_Z243.4-1985-1", 78, false},
	{"ca", "CSA_Z243.4-1985-1", 78, false},
	{"csISO121Canadian1", "CSA_Z243.4-1985-1", 78, false},
	{"CSA_Z243.4-1985-2", "CSA_Z243.4-1985-2", 79, false},
	{"iso-ir-122", "CSA_Z243.4-1985-2", 79, false},
	{"ISO646-CA2", "CSA_Z243.4-1985-2", 79, false},
	{"csa7-2", "CSA_Z243.4-1985-2", 79, false},
	{"csISO122Canadian2", "CSA_Z243.4-1985-2", 79, false},
	{"CSA_Z243.4-1985-gr", "CSA_Z243.4-1985-gr", 80, false},
	{"iso-ir-123", "CSA_Z243.4-1985-gr", 80, false},
	{"csISO123CSAZ24341985gr", "CSA_Z243.4-1985-gr", 80, false},
	{"ISO_8859-6-E", "ISO-8859-6-E", 81, false},
	{"csISO88596E", "ISO-8859-6-E", 81, false},
	{"ISO-8859-6-E", "ISO-8859-6-E", 81, false},
	{"ISO_8859-6-I", "ISO-8859-6-I", 82, false},
	{"csISO88596I", "ISO-8859-6-I", 82, false},
	{"ISO-8859-6-I", "ISO-8859-6-I", 82, false},
	{"T.101-G2", "T.101-G2", 83, false},
	{"iso-ir-128", "T.101-G2", 83, false},
	{"csISO128T101G2", "T.101-G2", 83, false},
	{"ISO_8859-8-E", "ISO-8859-8-E", 84, false},
	{"csISO88598E", "ISO-8859-8-E", 84, false},
	{"ISO-8859-8-E", "ISO-8859-8-E", 84, false},
	{"ISO_8859-8-I", "ISO-8859-8-I", 85, false},
	{"csISO88598I", "ISO-8859-8-I", 85, false},
	{"ISO-8859-8-I", "ISO-8859-8-I", 85, false},
	{"CSN_369103", "CSN_369103", 86, false},
	{"iso-ir-139", "CSN_369103", 86, false},
	{"csISO139CSN369103", "CSN_369103", 86, false},
	{"JUS_I.B1.002", "JUS_I.B1.002", 87, false},
	{"iso-ir-141", "JUS_I.B1.002", 87, false},
	{"ISO646-YU", "JUS_I.B1.002", 87, false},
	{"js", "JUS_I.B1.002", 87, false},
	{"yu", "JUS_I.B1.002", 87, false},
	{"csISO141JUSIB1002", "JUS_I.B1.002", 87, false},
	{"IEC_P27-1", "IEC_P27-1", 88, false},
	{"iso-ir-143", "IEC_P27-1", 88, false},
	{"csISO143IECP271", "IEC_P27-1", 88, false},
	{"JUS_I.B1.003-serb", "JUS_I.B1.003-serb", 89, false},
	{"iso-ir-146", "JUS_I.B1.003-serb", 89, false},
	{"serbian", "JUS_I.B1.003-serb", 89, false},
	{"csISO146Serbian", "JUS_I.B1.003-serb", 89, false},
	{"JUS_I.B1.003-mac", "JUS_I.B1.003-mac", 90, false},
	{"macedonian", "JUS_I.B1.003-mac", 90, false},
	{"iso-ir-147", "JUS_I.B1.003-mac", 90, false},
	{"csISO147Macedonian", "JUS_I.B1.003-mac", 90, false},
	{"greek-ccitt", "greek-ccitt", 91, false},
	{"iso-ir-150", "greek-ccitt", 91, false},
	{"csISO150", "greek-ccitt", 91, false},
	{"csISO150GreekCCITT", "greek-ccitt", 91, false},
	{"NC_NC00-10:81", "NC_NC00-10:81", 92, false},
	{"cuba", "NC_NC00-10:81", 92, false},
	{"iso-ir-151", "NC_NC00-10:81", 92, false},
	{"ISO646-CU", "NC_NC00-10:81", 92, false},
	{"csISO151Cuba", "NC_NC00-10:81", 92, false},
	{"ISO_6937-2-25", "ISO_6937-2-25", 93, false},
	{"iso-ir-152", "ISO_6937-2-25", 93, false},
	{"csISO6937Add", "ISO_6937-2-25", 93, false},
	{"GOST_19768-74", "GOST_19768-74", 94, false},
	{"ST_SEV_358-88", "GOST_19768-74", 94, false},
	{"iso-ir-153", "GOST_19768-74", 94, false},
	{"csISO153GOST1976874", "GOST_19768-74", 94, false},
	{"ISO_8859-supp", "ISO_8859-supp", 95, false},
	{"iso-ir-154", "ISO_8859-supp", 95, false},
	{"latin1-2-5", "ISO_8859-supp", 95, false},
	{"csISO8859Supp", "ISO_8859-supp", 95, false},
	{"ISO_10367-box", "ISO_10367-box", 96, false},
	{"iso-ir-155", "ISO_10367-box", 96, false},
	{"csISO10367Box", "ISO_10367-box", 96, false},
	{"latin-lap", "latin-lap", 97, false},
	{"lap", "latin-lap", 97, false},
	{"iso-ir-158", "latin-lap", 97, false},
	{"csISO158Lap", "latin-lap", 97, false},
	{"JIS_X0212-1990", "JIS_X0212-1990", 98, true},
	{"x0212", "JIS_X0212-1990", 98, true},
	{"iso-ir-159", "JIS_X0212-1990", 98, true},
	{"csISO159JISX02121990", "JIS_X0212-1990", 98, true},
	{"DS_2089", "DS_2089", 99, false},
	{"DS2089", "DS_2089", 99, false},
	{"ISO646-DK", "DS_2089", 99, false},
	{"dk", "DS_2089", 99, false},
	{"csISO646Danish", "DS_2089", 99, false},
	{"us-dk", "us-dk", 100, false},
	{"csUSDK", "us-dk", 100, false},
	{"dk-us", "dk-us", 101, false},
	{"csDKUS", "dk-us", 101, false},
	{"KSC5636", "KSC5636", 102, false},
	{"ISO646-KR", "KSC5636", 102, false},
	{"csKSC5636", "KSC5636", 102, false},
	{"UNICODE-1-1-UTF-7", "UNICODE-1-1-UTF-7", 103, true},
	{"csUnicode11UTF7", "UNICODE-1-1-UTF-7", 103, true},
	{"ISO-2022-CN", "ISO-2022-CN", 104, true},
	{"ISO-2022-CN-EXT", "ISO-2022-CN-EXT", 105, true},
	{"UTF-8", "UTF-8", 106, true},
	{"ISO-8859-13", "ISO-8859-13", 109, true},
	{"ISO-8859-14", "ISO-8859-14", 110, true},
	{"iso-ir-199", "ISO-8859-14", 110, true},
	{"ISO_8859-14:1998", "ISO-8859-14", 110, true},
	{"ISO_8859-14", "ISO-8859-14", 110, true},
	{"latin8", "ISO-8859-14", 110, true},
	{"iso-celtic", "ISO-8859-14", 110, true},
	{"l8", "ISO-8859-14", 110, true},
	{"ISO-8859-15", "ISO-8859-15", 111, true},
	{"ISO_8859-15", "ISO-8859-15", 111, true},
	{"Latin-9", "ISO-8859-15", 111, true},
	{"ISO-8859-16", "ISO-8859-16", 112, true},
	{"iso-ir-226", "ISO-8859-16", 112, true},
	{"ISO_8859-16:2001", "ISO-8859-16", 112, true},
	{"ISO_8859-16", "ISO-8859-16", 112, true},
	{"latin10", "ISO-8859-16", 112, true},
	{"l10", "ISO-8859-16", 112, true},
	{"GBK", "GBK", 113, true},
	{"CP936", "GBK", 113, true},
	{"MS936", "GBK", 113, true},
	{"windows-936", "GBK", 113, true},
	{"GB18030", "GB18030", 114, true},
	{"OSD_EBCDIC_DF04_15", "OSD_EBCDIC_DF04_15", 115, false},
	{"OSD_EBCDIC_DF03_IRV", "OSD_EBCDIC_DF03_IRV", 116, false},
	{"OSD_EBCDIC_DF04_1", "OSD_EBCDIC_DF04_1", 117, false},
	{"ISO-10646-UCS-2", "ISO-10646-UCS-2", 1000, true},
	{"csUnicode", "ISO-10646-UCS-2", 1000, true},
	{"ISO-10646-UCS-4", "ISO-10646-UCS-4", 1001, true},
	{"csUCS4", "ISO-10646-UCS-4", 1001, true},
	{"ISO-10646-UCS-Basic", "ISO-10646-UCS-Basic", 1002, false},
	{"csUnicodeASCII", "ISO-10646-UCS-Basic", 1002, false},
	{"ISO-10646-Unicode-Latin1", "ISO-10646-Unicode-Latin1", 1003, false},
	{"csUnicodeLatin1", "ISO-10646-Unicode-Latin1", 1003, false},
	{"ISO-10646", "ISO-10646-Unicode-Latin1", 1003, false},
	{"ISO-Unicode-IBM-1261", "ISO-Unicode-IBM-1261", 1005, false},
	{"csUnicodeIBM1261", "ISO-Unicode-IBM-1261", 1005, false},
	{"ISO-Unicode-IBM-1268", "ISO-Unicode-IBM-1268", 1006, false},
	{"csUnicodeIBM1268", "ISO-Unicode-IBM-1268", 1006, false},
	{"ISO-Unicode-IBM-1276", "ISO-Unicode-IBM-1276", 1007, false},
	{"csUnicodeIBM1276", "ISO-Unicode-IBM-1276", 1007, false},
	{"ISO-Unicode-IBM-1264", "ISO-Unicode-IBM-1264", 1008, false},
	{"csUnicodeIBM1264", "ISO-Unicode-IBM-1264", 1008, false},
	{"ISO-Unicode-IBM-1265", "ISO-Unicode-IBM-1265", 1009, false},
	{"csUnicodeIBM1265", "ISO-Unicode-IBM-1265", 1009, false},
	{"UNICODE-1-1", "UNICODE-1-1", 1010, true},
	{"csUnicode11", "UNICODE-1-1", 1010, true},
	{"SCSU", "SCSU", 1011, false},
	{"UTF-7", "UTF-7", 1012, true},
	{"UTF-16BE", "UTF-16BE", 1013, true},
	{"UTF-16LE", "UTF-16LE", 1014, true},
	{"UTF-16", "UTF-16", 1015, true},
	{"CESU-8", "CESU-8", 1016, false},
	{"csCESU-8", "CESU-8", 1016, false},
	{"UTF-32", "UTF-32", 1017, true},
	{"UTF-32BE", "UTF-32BE", 1018, true},
	{"UTF-32LE", "UTF-32LE", 1019, true},
	{"BOCU-1", "BOCU-1", 1020, false},
	{"csBOCU-1", "BOCU-1", 1020, false},
	{"ISO-8859-1-Windows-3.0-Latin-1", "ISO-8859-1-Windows-3.0-Latin-1", 2000, false},
	{"csWindows30Latin1", "ISO-8859-1-Windows-3.0-Latin-1", 2000, false},
	{"ISO-8859-1-Windows-3.1-Latin-1", "ISO-8859-1-Windows-3.1-Latin-1", 2001, false},
	{"csWindows31Latin1", "ISO-8859-1-Windows-3.1-Latin-1", 2001, false},
	{"ISO-8859-2-Windows-Latin-2", "ISO-8859-2-Windows-Latin-2", 2002, false},
	{"csWindows31Latin2", "ISO-8859-2-Windows-Latin-2", 2002, false},
	{"ISO-8859-9-Windows-Latin-5", "ISO-8859-9-Windows-Latin-5", 2003, false},
	{"csWindows31Latin5", "ISO-8859-9-Windows-Latin-5", 2003, false},
	{"hp-roman8", "hp-roman8", 2004, true},
	{"roman8", "hp-roman8", 2004, true},
	{"r8", "hp-roman8", 2004, true},
	{"csHPRoman8", "hp-roman8", 2004, true},
	{"Adobe-Standard-Encoding", "Adobe-Standard-Encoding", 2005, false},
	{"csAdobeStandardEncoding", "Adobe-Standard-Encoding", 2005, false},
	{"Ventura-US", "Ventura-US", 2006, false},
	{"csVenturaUS", "Ventura-US", 2006, false},
	{"Ventura-International", "Ventura-International", 2007, false},
	{"csVenturaInternational", "Ventura-International", 2007, false},
	{"DEC-MCS", "DEC-MCS", 2008, false},
	{"dec", "DEC-MCS", 2008, false},
	{"csDECMCS", "DEC-MCS", 2008, false},
	{"IBM850", "IBM850", 2009, true},
	{"cp850", "IBM850", 2009, true},
	{"850", "IBM850", 2009, true},
	{"csPC850Multilingual", "IBM850", 2009, true},
	{"IBM852", "IBM852", 2010, true},
	{"cp852", "IBM852", 2010, true},
	{"852", "IBM852", 2010, true},
	{"csPCp852", "IBM852", 2010, true},
	{"IBM437", "IBM437", 2011, true},
	{"cp437", "IBM437", 2011, true},
	{"437", "IBM437", 2011, true},
	{"csPC8CodePage437", "IBM437", 2011, true},
	{"PC8-Danish-Norwegian", "PC8-Danish-Norwegian", 2012, false},
	{"csPC8DanishNorwegian", "PC8-Danish-Norwegian", 2012, false},
	{"IBM862", "IBM862", 2013, true},
	{"cp862", "IBM862", 2013, true},
	{"862", "IBM862", 2013, true},
	{"csPC862LatinHebrew", "IBM862", 2013, true},
	{"PC8-Turkish", "PC8-Turkish", 2014, false},
	{"csPC8Turkish", "PC8-Turkish", 2014, false},
	{"IBM-Symbols", "IBM-Symbols", 2015, false},
	{"csIBMSymbols", "IBM-Symbols", 2015, false},
	{"IBM-Thai", "IBM-Thai", 2016, false},
	{"csIBMThai", "IBM-Thai", 2016, false},
	{"HP-Legal", "HP-Legal", 2017, false},
	{"csHPLegal", "HP-Legal", 2017, false},
	{"HP-Pi-font", "HP-Pi-font", 2018, false},
	{"csHPPiFont", "HP-Pi-font", 2018, false},
	{"HP-Math8", "HP-Math8", 2019, false},
	{"csHPMath8", "HP-Math8", 2019, false},
	{"Adobe-Symbol-Encoding", "Adobe-Symbol-Encoding", 2020, false},
	{"csHPPSMath", "Adobe-Symbol-Encoding", 2020, false},
	{"HP-DeskTop", "HP-DeskTop", 2021, false},
	{"csHPDesktop", "HP-DeskTop", 2021, false},
	{"Ventura-Math", "Ventura-Math", 2022, false},
	{"csVenturaMath", "Ventura-Math", 2022, false},
	{"Microsoft-Publishing", "Microsoft-Publishing", 2023, false},
	{"csMicrosoftPublishing", "Microsoft-Publishing", 2023, false},
	{"GB2312", "GB2312", 2025, true},
	{"csGB2312", "GB2312", 2025, true},
	{"Big5", "Big5", 2026, true},
	{"csBig5", "Big5", 2026, true},
	{"macintosh", "macintosh", 2027, true},
	{"mac", "macintosh", 2027, true},
	{"csMacintosh", "macintosh", 2027, true},
	{"IBM037", "IBM037", 2028, false},
	{"cp037", "IBM037", 2028, false},
	{"ebcdic-cp-us", "IBM037", 2028, false},
	{"ebcdic-cp-ca", "IBM037", 2028, false},
	{"ebcdic-cp-wt", "IBM037", 2028, false},
	{"ebcdic-cp-nl", "IBM037", 2028, false},
	{"csIBM037", "IBM037", 2028, false},
	{"IBM038", "IBM038", 2029, false},
	{"EBCDIC-INT", "IBM038", 2029, false},
	{"cp038", "IBM038", 2029, false},
	{"csIBM038", "IBM038", 2029, false},
	{"IBM273", "IBM273", 2030, false},
	{"CP273", "IBM273", 2030, false},
	{"csIBM273", "IBM273", 2030, false},
	{"IBM274", "IBM274", 2031, false},
	{"EBCDIC-BE", "IBM274", 2031, false},
	{"CP274", "IBM274", 2031, false},
	{"csIBM274", "IBM274", 2031, false},
	{"IBM275", "IBM275", 2032, false},
	{"EBCDIC-BR", "IBM275", 2032, false},
	{"cp275", "IBM275", 2032, false},
	{"csIBM275", "IBM275", 2032, false},
	{"IBM277", "IBM277", 2033, false},
	{"EBCDIC-CP-DK", "IBM277", 2033, false},
	{"EBCDIC-CP-NO", "IBM277", 2033, false},
	{"csIBM277", "IBM277", 2033, false},
	{"IBM278", "IBM278", 2034, false},
	{"CP278", "IBM278", 2034, false},
	{"ebcdic-cp-fi", "IBM278", 2034, false},
	{"ebcdic-cp-se", "IBM278", 2034, false},
	{"csIBM278", "IBM278", 2034, false},
	{"IBM280", "IBM280", 2035, false},
	{"CP280", "IBM280", 2035, false},
	{"ebcdic-cp-it", "IBM280", 2035, false},
	{"csIBM280", "IBM280", 2035, false},
	{"IBM281", "IBM281", 2036, false},
	{"EBCDIC-JP-E", "IBM281", 2036, false},
	{"cp281", "IBM281", 2036, false},
	{"csIBM281", "IBM281", 2036, false},
	{"IBM284", "IBM284", 2037, false},
	{"CP284", "IBM284", 2037, false},
	{"ebcdic-cp-es", "IBM284", 2037, false},
	{"csIBM284", "IBM284", 2037, false},
	{"IBM285", "IBM285", 2038, false},
	{"CP285", "IBM285", 2038, false},
	{"ebcdic-cp-gb", "IBM285", 2038, false},
	{"csIBM285", "IBM285", 2038, false},
	{"IBM290", "IBM290", 2039, false},
	{"cp290", "IBM290", 2039, false},
	{"EBCDIC-JP-kana", "IBM290", 2039, false},
	{"csIBM290", "IBM290", 2039, false},
	{"IBM297", "IBM297", 2040, false},
	{"cp297", "IBM297", 2040, false},
	{"ebcdic-cp-fr", "IBM297", 2040, false},
	{"csIBM297", "IBM297", 2040, false},
	{"IBM420", "IBM420", 2041, false},
	{"cp420", "IBM420", 2041, false},
	{"ebcdic-cp-ar1", "IBM420", 2041, false},
	{"csIBM420", "IBM420", 2041, false},
	{"IBM423", "IBM423", 2042, false},
	{"cp423", "IBM423", 2042, false},
	{"ebcdic-cp-gr", "IBM423", 2042, false},
	{"csIBM423", "IBM423", 2042, false},
	{"IBM424", "IBM424", 2043, false},
	{"cp424", "IBM424", 2043, false},
	{"ebcdic-cp-he", "IBM424", 2043, false},
	{"csIBM424", "IBM424", 2043, false},
	{"IBM500", "IBM500", 2044, false},
	{"CP500", "IBM500", 2044, false},
	{"ebcdic-cp-be", "IBM500", 2044, false},
	{"ebcdic-cp-ch", "IBM500", 2044, false},
	{"csIBM500", "IBM500", 2044, false},
	{"IBM851", "IBM851", 2045, false},
	{"cp851", "IBM851", 2045, false},
	{"851", "IBM851", 2045, false},
	{"csIBM851", "IBM851", 2045, false},
	{"IBM855", "IBM855", 2046, true},
	{"cp855", "IBM855", 2046, true},
	{"855", "IBM855", 2046, true},
	{"csIBM855", "IBM855", 2046, true},
	{"IBM857", "IBM857", 2047, true},
	{"cp857", "IBM857", 2047, true},
	{"857", "IBM857", 2047, true},
	{"csIBM857", "IBM857", 2047, true},
	{"IBM860", "IBM860", 2048, true},
	{"cp860", "IBM860", 2048, true},
	{"860", "IBM860", 2048, true},
	{"csIBM860", "IBM860", 2048, true},
	{"IBM861", "IBM861", 2049, true},
	{"cp861", "IBM861", 2049, true},
	{"861", "IBM861", 2049, true},
	{"cp-is", "IBM861", 2049, true},
	{"csIBM861", "IBM861", 2049, true},
	{"IBM863", "IBM863", 2050, true},
	{"cp863", "IBM863", 2050, true},
	{"863", "IBM863", 2050, true},
	{"csIBM863", "IBM863", 2050, true},
	{"IBM864", "IBM864", 2051, true},
	{"cp864", "IBM864", 2051, true},
	{"csIBM864", "IBM864", 2051, true},
	{"IBM865", "IBM865", 2052, true},
	{"cp865", "IBM865", 2052, true},
	{"865", "IBM865", 2052, true},
	{"csIBM865", "IBM865", 2052, true},
	{"IBM868", "IBM868", 2053, false},
	{"CP868", "IBM868", 2053, false},
	{"cp-ar", "IBM868", 2053, false},
	{"csIBM868", "IBM868", 2053, false},
	{"IBM869", "IBM869", 2054, true},
	{"cp869", "IBM869", 2054, true},
	{"869", "IBM869", 2054, true},
	{"cp-gr", "IBM869", 2054, true},
	{"csIBM869", "IBM869", 2054, true},
	{"IBM870", "IBM870", 2055, false},
	{"CP870", "IBM870", 2055, false},
	{"ebcdic-cp-roece", "IBM870", 2055, false},
	{"ebcdic-cp-yu", "IBM870", 2055, false},
	{"csIBM870", "IBM870", 2055, false},
	{"IBM871", "IBM871", 2056, false},
	{"CP871", "IBM871", 2056, false},
	{"ebcdic-cp-is", "IBM871", 2056, false},
	{"csIBM871", "IBM871", 2056, false},
	{"IBM880", "IBM880", 2057, false},
	{"cp880", "IBM880", 2057, false},
	{"EBCDIC-Cyrillic", "IBM880", 2057, false},
	{"csIBM880", "IBM880", 2057, false},
	{"IBM891", "IBM891", 2058, false},
	{"cp891", "IBM891", 2058, false},
	{"csIBM891", "IBM891", 2058, false},
	{"IBM903", "IBM903", 2059, false},
	{"cp903", "IBM903", 2059, false},
	{"csIBM903", "IBM903", 2059, false},
	{"IBM904", "IBM904", 2060, false},
	{"cp904", "IBM904", 2060, false},
	{"904", "IBM904", 2060, false},
	{"csIBBM904", "IBM904", 2060, false},
	{"IBM905", "IBM905", 2061, false},
	{"CP905", "IBM905", 2061, false},
	{"ebcdic-cp-tr", "IBM905", 2061, false},
	{"csIBM905", "IBM905", 2061, false},
	{"IBM918", "IBM918", 2062, false},
	{"CP918", "IBM918", 2062, false},
	{"ebcdic-cp-ar2", "IBM918", 2062, false},
	{"csIBM918", "IBM918", 2062, false},
	{"IBM1026", "IBM1026", 2063, false},
	{"CP1026", "IBM1026", 2063, false},
	{"csIBM1026", "IBM1026", 2063, false},
	{"EBCDIC-AT-DE", "EBCDIC-AT-DE", 2064, false},
	{"csIBMEBCDICATDE", "EBCDIC-AT-DE", 2064, false},
	{"EBCDIC-AT-DE-A", "EBCDIC-AT-DE-A", 2065, false},
	{"csEBCDICATDEA", "EBCDIC-AT-DE-A", 2065, false},
	{"EBCDIC-CA-FR", "EBCDIC-CA-FR", 2066, false},
	{"csEBCDICCAFR", "EBCDIC-CA-FR", 2066, false},
	{"EBCDIC-DK-NO", "EBCDIC-DK-NO", 2067, false},
	{"csEBCDICDKNO", "EBCDIC-DK-NO", 2067, false},
	{"EBCDIC-DK-NO-A", "EBCDIC-DK-NO-A", 2068, false},
	{"csEBCDICDKNOA", "EBCDIC-DK-NO-A", 2068, false},
	{"EBCDIC-FI-SE", "EBCDIC-FI-SE", 2069, false},
	{"csEBCDICFISE", "EBCDIC-FI-SE", 2069, false},
	{"EBCDIC-FI-SE-A", "EBCDIC-FI-SE-A", 2070, false},
	{"csEBCDICFISEA", "EBCDIC-FI-SE-A", 2070, false},
	{"EBCDIC-FR", "EBCDIC-FR", 2071, false},
	{"csEBCDICFR", "EBCDIC-FR", 2071, false},
	{"EBCDIC-IT", "EBCDIC-IT", 2072, false},
	{"csEBCDICIT", "EBCDIC-IT", 2072, false},
	{"EBCDIC-PT", "EBCDIC-PT", 2073, false},
	{"csEBCDICPT", "EBCDIC-PT", 2073, false},
	{"EBCDIC-ES", "EBCDIC-ES", 2074, false},
	{"csEBCDICES", "EBCDIC-ES", 2074, false},
	{"EBCDIC-ES-A", "EBCDIC-ES-A", 2075, false},
	{"csEBCDICESA", "EBCDIC-ES-A", 2075, false},
	{"EBCDIC-ES-S", "EBCDIC-ES-S", 2076, false},
	{"csEBCDICESS", "EBCDIC-ES-S", 2076, false},
	{"EBCDIC-UK", "EBCDIC-UK", 2077, false},
	{"csEBCDICUK", "EBCDIC-UK", 2077, false},
	{"EBCDIC-US", "EBCDIC-US", 2078, false},
	{"csEBCDICUS", "EBCDIC-US", 2078, false},
	{"UNKNOWN-8BIT", "UNKNOWN-8BIT", 2079, false},
	{"csUnknown8BiT", "UNKNOWN-8BIT", 2079, false},
	{"MNEMONIC", "MNEMONIC", 2080, false},
	{"csMnemonic", "MNEMONIC", 2080, false},
	{"MNEM", "MNEM", 2081, false},
	{"csMnem", "MNEM", 2081, false},
	{"VISCII", "VISCII", 2082, true},
	{"csVISCII", "VISCII", 2082, true},
	{"VIQR", "VIQR", 2083, false},
	{"csVIQR", "VIQR", 2083, false},
	{"KOI8-R", "KOI8-R", 2084, true},
	{"csKOI8R", "KOI8-R", 2084, true},
	{"HZ-GB-2312", "HZ-GB-2312", 2085, true},
	{"IBM866", "IBM866", 2086, true},
	{"cp866", "IBM866", 2086, true},
	{"866", "IBM866", 2086, true},
	{"csIBM866", "IBM866", 2086, true},
	{"IBM775", "IBM775", 2087, true},
	{"cp775", "IBM775", 2087, true},
	{"csPC775Baltic", "IBM775", 2087, true},
	{"KOI8-U", "KOI8-U", 2088, true},
	{"IBM00858", "IBM00858", 2089, false},
	{"CCSID00858", "IBM00858", 2089, false},
	{"CP00858", "IBM00858", 2089, false},
	{"PC-Multilingual-850+euro", "IBM00858", 2089, false},
	{"IBM00924", "IBM00924", 2090, false},
	{"CCSID00924", "IBM00924", 2090, false},
	{"CP00924", "IBM00924", 2090, false},
	{"ebcdic-Latin9--euro", "IBM00924", 2090, false},
	{"IBM01140", "IBM01140", 2091, false},
	{"CCSID01140", "IBM01140", 2091, false},
	{"CP01140", "IBM01140", 2091, false},
	{"ebcdic-us-37+euro", "IBM01140", 2091, false},
	{"IBM01141", "IBM01141", 2092, false},
	{"CCSID01141", "IBM01141", 2092, false},
	{"CP01141", "IBM01141", 2092, false},
	{"ebcdic-de-273+euro", "IBM01141", 2092, false},
	{"IBM01142", "IBM01142", 2093, false},
	{"CCSID01142", "IBM01142", 2093, false},
	{"CP01142", "IBM01142", 2093, false},
	{"ebcdic-dk-277+euro", "IBM01142", 2093, false},
	{"ebcdic-no-277+euro", "IBM01142", 2093, false},
	{"IBM01143", "IBM01143", 2094, false},
	{"CCSID01143", "IBM01143", 2094, false},
	{"CP01143", "IBM01143", 2094, false},
	{"ebcdic-fi-278+euro", "IBM01143", 2094, false},
	{"ebcdic-se-278+euro", "IBM01143", 2094, false},
	{"IBM01144", "IBM01144", 2095, false},
	{"CCSID01144", "IBM01144", 2095, false},
	{"CP01144", "IBM01144", 2095, false},
	{"ebcdic-it-280+euro", "IBM01144", 2095, false},
	{"IBM01145", "IBM01145", 2096, false},
	{"CCSID01145", "IBM01145", 2096, false},
	{"CP01145", "IBM01145", 2096, false},
	{"ebcdic-es-284+euro", "IBM01145", 2096, false},
	{"IBM01146", "IBM01146", 2097, false},
	{"CCSID01146", "IBM01146", 2097, false},
	{"CP01146", "IBM01146", 2097, false},
	{"ebcdic-gb-285+euro", "IBM01146", 2097, false},
	{"IBM01147", "IBM01147", 2098, false},
	{"CCSID01147", "IBM01147", 2098, false},
	{"CP01147", "IBM01147", 2098, false},
	{"ebcdic-fr-297+euro", "IBM01147", 2098, false},
	{"IBM01148", "IBM01148", 2099, false},
	{"CCSID01148", "IBM01148", 2099, false},
	{"CP01148", "IBM01148", 2099, false},
	{"ebcdic-international-500+euro", "IBM01148", 2099, false},
	{"IBM01149", "IBM01149", 2100, false},
	{"CCSID01149", "IBM01149", 2100, false},
	{"CP01149", "IBM01149", 2100, false},
	{"ebcdic-is-871+euro", "IBM01149", 2100, false},
	{"Big5-HKSCS", "Big5-HKSCS", 2101, true},
	{"IBM1047", "IBM1047", 2102, false},
	{"IBM-1047", "IBM1047", 2102, false},
	{"PTCP154", "PTCP154", 2103, false},
	{"csPTCP154", "PTCP154", 2103, false},
	{"PT154", "PTCP154", 2103, false},
	{"CP154", "PTCP154", 2103, false},
	{"Cyrillic-Asian", "PTCP154", 2103, false},
	{"Amiga-1251", "Amiga-1251", 2104, false},
	{"Ami1251", "Amiga-1251", 2104, false},
	{"Amiga1251", "Amiga-1251", 2104, false},
	{"Ami-1251", "Amiga-1251", 2104, false},
	{"KOI7-switched", "KOI7-switched", 2105, false},
	{"windows-1250", "windows-1250", 2250, true},
	{"windows-1251", "windows-1251", 2251, true},
	{"windows-1252", "windows-1252", 2252, true},
	{"windows-1253", "windows-1253", 2253, true},
	{"windows-1254", "windows-1254", 2254, true},
	{"windows-1255", "windows-1255", 2255, true},
	{"windows-1256", "windows-1256", 2256, true},
	{"windows-1257", "windows-1257", 2257, true},
	{"windows-1258", "windows-1258", 2258, true},
	{"TIS-620", "TIS-620", 2259, true},
	{"windows-874", "TIS-620", 2259, true}
};


static HashTableX s_table;
static bool       s_isInitialized = false;
static GbMutex    s_tableMutex;

void reset_iana_charset ( ) {
	ScopedLock sl(s_tableMutex);
	s_table.reset();
}

// Slightly modified from getTextEntity
int16_t get_iana_charset(const char *cs, int len)
{
	ScopedLock sl(s_tableMutex);
    if (!s_isInitialized){
	// set up the hash table
	if ( ! s_table.set ( 8,4,4096,NULL,0,false,"ianatbl") ) {
		log(LOG_WARN, "build: Could not init table of IANA Charsets.");
		return csUnknown;
	}
	// now add in all the charset entries
	int32_t n = (int32_t)sizeof(s_charsets) / (int32_t)sizeof(IANACharset);
	for ( int32_t i = 0 ; i < n ; i++ ) {
	    int64_t h = hash64Lower_a ( s_charsets[i].name, strlen(s_charsets[i].name) );
	    // store the charset index in the hash table as score
		if ( ! s_table.addTerm(h, i+1) ) {
			log(LOG_WARN, "build: add term failed");
			return csUnknown;
		}
	}
	s_isInitialized = true;
    }
    sl.unlock();
    int64_t h = hash64Lower_a ( cs , len );
    // get the entity index from table (stored in the score field)
    int32_t i = (int32_t) s_table.getScore(h);
    // return 0 if no match
    if ( i == 0 ) return csUnknown;
    // return the iso character
    return (int16_t)s_charsets[i-1].mib_enum;
}

const char *get_charset_str(int16_t cs)
{
    int s=0;
    int e=sizeof(s_charsets)/sizeof(IANACharset)-2;
    int i;
    if (cs < s_charsets[s].mib_enum) return NULL;
    if (cs > s_charsets[e].mib_enum) return NULL;
    
    // Binary search
    for(;;) {
	// Check endpoints
	if (cs == s_charsets[s].mib_enum) return s_charsets[s].mime;
	if (cs ==s_charsets[e].mib_enum) return s_charsets[e].mime;

	// check midpoint
	i = (s+e)/2;
	if (cs ==s_charsets[i].mib_enum) return s_charsets[i].mime;
	
	// end of search 
	if ((e-s)<3) return NULL;
	
	// reset either endpoint
	if (cs < s_charsets[i].mib_enum){e = i-1;continue;}
	if (cs > s_charsets[i].mib_enum){s = i+1;continue;}
    }
    
}

// is this charset supported?
bool supportedCharset(int16_t cs) {
    int s=0;
    int e=sizeof(s_charsets)/sizeof(IANACharset)-2;
    int i;
    if (cs < s_charsets[s].mib_enum) return false;
    if (cs > s_charsets[e].mib_enum) return false;
    
    // Binary search
    for(;;) {
	// Check endpoints
	if (cs == s_charsets[s].mib_enum) return s_charsets[s].supported;
	if (cs == s_charsets[e].mib_enum) return s_charsets[e].supported;

	// check midpoint
	i = (s+e)/2;
	if (cs ==s_charsets[i].mib_enum) return s_charsets[i].supported;
	
	// end of search 
	if ((e-s)<3) return false;
	
	// reset either endpoint
	if (cs < s_charsets[i].mib_enum){e = i-1;continue;}
	if (cs > s_charsets[i].mib_enum){s = i+1;continue;}
    }	
}


