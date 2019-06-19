#ifndef MEDIATAG_H
#define MEDIATAG_H

#include<QMap>
const QMap<QString, int> idMap = {
{"AENC", 0},       //   [#sec4.20 Audio encryption]
{"APIC", 1},       //   [#sec4.15 Attached picture]
{"COMM", 2},       //   [#sec4.11 Comments]
{"COMR", 3},       //   [#sec4.25 Commercial frame]
{"ENCR", 4},       //   [#sec4.26 Encryption method registration]
{"EQUA", 5},       //   [#sec4.13 Equalization]
{"ETCO", 6},       //   [#sec4.6 Event timing codes]
{"GEOB", 7},       //   [#sec4.16 General encapsulated object]
{"GRID", 8},       //   [#sec4.27 Group identification registration]
{"IPLS", 9},       //   [#sec4.4 Involved people list]
{"LINK", 10},      //   [#sec4.21 Linked information]
{"MCDI", 11},      //   [#sec4.5 Music CD identifier]
{"MLLT", 12},      //   [#sec4.7 MPEG location lookup table]
{"OWNE", 13},      //   [#sec4.24 Ownership frame]
{"PRIV", 14},      //   [#sec4.28 Private frame]
{"PCNT", 15},      //   [#sec4.17 Play counter]
{"POPM", 16},      //   [#sec4.18 Popularimeter]
{"POSS", 17},      //   [#sec4.22 Position synchronisation frame]
{"RBUF", 18},      //   [#sec4.19 Recommended buffer size]
{"RVAD", 19},      //   [#sec4.12 Relative volume adjustment]
{"RVRB", 20},      //   [#sec4.14 Reverb]
{"SYLT", 21},      //   [#sec4.10 Synchronized lyric/text]
{"SYTC", 22},      //   [#sec4.8 Synchronized tempo codes]
{"TALB", 23},      //   [#TALB Album/Movie/Show title]
{"TBPM", 24},      //   [#TBPM BPM (beats per minute)]
{"TCOM", 25},      //   [#TCOM Composer]
{"TCON", 26},      //   [#TCON Content type]
{"TCOP", 27},      //   [#TCOP Copyright message]
{"TDAT", 28},      //   [#TDAT Date]
{"TDLY", 29},      //   [#TDLY Playlist delay]
{"TENC", 30},      //   [#TENC Encoded by]
{"TEXT", 31},      //   [#TEXT Lyricist/Text writer]
{"TFLT", 32},      //   [#TFLT File type]
{"TIME", 33},      //   [#TIME Time]
{"TIT1", 34},      //   [#TIT1 Content group description]
{"TIT2", 35},      //   [#TIT2 Title/songname/content description]
{"TIT3", 36},      //   [#TIT3 Subtitle/Description refinement]
{"TKEY", 37},      //   [#TKEY Initial key]
{"TLAN", 38},      //   [#TLAN Language(s)]
{"TLEN", 39},      //   [#TLEN Length]
{"TMED", 40},      //   [#TMED Media type]
{"TOAL", 41},      //   [#TOAL Original album/movie/show title]
{"TOFN", 42},      //   [#TOFN Original filename]
{"TOLY", 43},      //   [#TOLY Original lyricist(s)/text writer(s)]
{"TOPE", 44},      //   [#TOPE Original artist(s)/performer(s)]
{"TORY", 45},      //   [#TORY Original release year]
{"TOWN", 46},      //   [#TOWN File owner/licensee]
{"TPE1", 47},      //   [#TPE1 Lead performer(s)/Soloist(s)]
{"TPE2", 48},      //   [#TPE2 Band/orchestra/accompaniment]
{"TPE3", 49},      //   [#TPE3 Conductor/performer refinement]
{"TPE4", 50},      //   [#TPE4 Interpreted, remixed, or otherwise modified by]
{"TPOS", 51},      //   [#TPOS Part of a set]
{"TPUB", 52},      //   [#TPUB Publisher]
{"TRCK", 53},      //   [#TRCK Track number/Position in set]
{"TRDA", 54},      //   [#TRDA Recording dates]
{"TRSN", 55},      //   [#TRSN Internet radio station name]
{"TRSO", 56},      //   [#TRSO Internet radio station owner]
{"TSIZ", 57},      //   [#TSIZ Size]
{"TSRC", 58},      //   [#TSRC ISRC (international standard recording code)]
{"TSSE", 59},      //   [#TSEE Software/Hardware and settings used for encoding]
{"TYER", 60},      //   [#TYER Year]
{"TXXX", 61},      //   [#TXXX User defined text information frame]
{"UFID", 62},      //   [#sec4.1 Unique file identifier]
{"USER", 63},      //   [#sec4.23 Terms of use]
{"USLT", 64},      //   [#sec4.9 Unsychronized lyric/text transcription]
{"WCOM", 65},      //   [#WCOM Commercial information]
{"WCOP", 66},      //   [#WCOP Copyright/Legal information]
{"WOAF", 67},      //   [#WOAF Official audio file webpage]
{"WOAR", 68},      //   [#WOAR Official artist/performer webpage]
{"WOAS", 69},      //   [#WOAS Official audio source webpage]
{"WORS", 70},      //   [#WORS Official internet radio station homepage]
{"WPAY", 71},      //   [#WPAY Payment]
{"WPUB", 72},      //   [#WPUB Publishers official webpage]
{"WXXX", 73},      //   [#WXXX User defined URL link frame]
};
const int GONE = 1;
const int ID3V2_headerL = 10;
const int ID3V2_headerheaderL = 3;
const int ID3V2_headersizeL = 4;
const char ID3[] = "ID3";
struct ID3V2_header
{
    char header[ID3V2_headerheaderL]; /*必须为“ID3”否则认为标签不存在*/
    char version[GONE];   /*版本号ID3V2.3 就记录3*/
    char revision[GONE];  /*副版本号此版本记录为0*/
    char flag[GONE];      /*标志字节，只使用高三位，其它位为0 不作处理*/
    char size[ID3V2_headersizeL];   /*标签大小*/
};

const int ID3V2_TagFrameL = 10;
const int ID3V2_TagFrameidL = 4;
const int ID3V2_TagFramesizeL = 4;
const int ID3V2_TagFrameflagsL = 2;
struct ID3V2_TagFrame
{
    char id[ID3V2_TagFrameidL];    /*用四个字符标识一个帧，说明其内容，稍后有常用的标识对照表*/
    char size[ID3V2_TagFramesizeL];  /*帧内容的大小，不包括帧头，不得小于1*/
    char flags[ID3V2_TagFrameflagsL]; /*存放标志，只定义了6 位 char的高3位*/
    unsigned tag_volit  : 1;/*标志*/
    unsigned file_volit : 1;/*标志*/
    unsigned readonly   : 1;/*标志*/
    unsigned packed     : 1;/*标志*/
    unsigned encrypted  : 1;/*标志*/
    unsigned grouped    : 1;/*标志*/
    size_t isize;
};
const int id3V1DataL = 128;
const int id3TagL = 3;
const int id3TitleL = 30;
const int id3ArtistL = 30;
const int id3albumL = 30;
const int id3YearL = 4;
const int id3CommentL = 28;
const char id3v1Tag[] = "TAG";
struct ID3V1_header
{
    char header[id3TagL];          /*标签头必须是"TAG"否则认为没有标签*/
    char title[id3TitleL];          /*标题*/
    char artist[id3ArtistL];         /*作者*/
    char album[id3albumL];          /*专集*/
    char year[id3YearL];            /*出品年代*/
    char comment[id3CommentL];        /*备注*/
    char reserve[GONE];            /*保留*/
    unsigned char track[GONE];              /*音轨*/
    unsigned char genre[GONE];              /*类型*/
};

struct AudioInfo
{
    QString title;
    QString artist;
    QString album;
    QString year;
    int track;
    QString genre;
};

const QMap<int, QString> genreMap = {
{0,"Blues"                      },
{1,"ClassicRock"                },
{2,"Country"                    },
{3,"Dance"                      },
{4,"Disco"                      },
{5,"Funk"                       },
{6,"Grunge"                     },
{7,"Hip-Hop"                    },
{8,"Jazz"                       },
{9,"Metal"                      },
{10,"NewAge"                    },
{11,"Oldies"                    },
{12,"Other"                     },
{13,"Pop"                       },
{14,"R&B"                       },
{15,"Rap"                       },
{16,"Reggae"                    },
{17,"Rock"                      },
{18,"Techno"                    },
{19,"Industrial"                },
{20,"Alternative"               },
{21,"Ska"                       },
{22,"DeathMetal"                },
{23,"Pranks"                    },
{24,"Soundtrack"                },
{25,"Euro-Techno"               },
{26,"Ambient"                   },
{27,"Trip-Hop"                  },
{28,"Vocal"                     },
{29,"Jazz+Funk"                 },
{30,"Fusion"                    },
{31,"Trance"                    },
{32,"Classical"                 },
{33,"Instrumental"              },
{34,"Acid"                      },
{35,"House"                     },
{36,"Game"                      },
{37,"SoundClip"                 },
{38,"Gospel"                    },
{39,"Noise"                     },
{40,"AlternRock"                },
{41,"Bass"                      },
{42,"Soul"                      },
{43,"Punk"                      },
{44,"Space"                     },
{45,"Meditative"                },
{46,"InstrumentalPop"           },
{47,"InstrumentalRock"          },
{48,"Ethnic"                    },
{49,"Gothic"                    },
{50,"Darkwave"                  },
{51,"Techno-Industrial"         },
{52,"Electronic"                },
{53,"Pop-Folk"                  },
{54,"Eurodance"                 },
{55,"Dream"                     },
{56,"SouthernRock"              },
{57,"Comedy"                    },
{58,"Cult"                      },
{59,"Gangsta"                   },
{60,"Top40"                     },
{61,"ChristianRap"              },
{62,"Pop/Funk"                  },
{63,"Jungle"                    },
{64,"NativeAmerican"            },
{65,"Cabaret"                   },
{66,"NewWave"                   },
{67,"Psychadelic"               },
{68,"Rave"                      },
{69,"Showtunes"                 },
{70,"Trailer"                   },
{71,"Lo-Fi"                     },
{72,"Tribal"                    },
{73,"AcidPunk"                  },
{74,"AcidJazz"                  },
{75,"Polka"                     },
{76,"Retro"                     },
{77,"Musical"                   },
{78,"Rock&Roll"                 },
{79,"HardRock"                  },
/* Extended genres */
{80,"Folk"                      },
{81,"Folk-Rock"                 },
{82,"NationalFolk"              },
{83,"Swing"                     },
{84,"FastFusion"                },
{85,"Bebob"                     },
{86,"Latin"                     },
{87,"Revival"                   },
{88,"Celtic"                    },
{89,"Bluegrass"                 },
{90,"Avantgarde"                },
{91,"GothicRock"                },
{92,"ProgessiveRock"            },
{93,"PsychedelicRock"           },
{94,"SymphonicRock"             },
{95,"SlowRock"                  },
{96,"BigBand"                   },
{97,"Chorus"                    },
{98,"EasyListening"             },
{99,"Acoustic"                  },
{100,"Humour"                   },
{101,"Speech"                   },
{102,"Chanson"                  },
{103,"Opera"                    },
{104,"ChamberMusic"             },
{105,"Sonata"                   },
{106,"Symphony"                 },
{107,"BootyBass"                },
{108,"Primus"                   },
{109,"PornGroove"               },
{110,"Satire"                   },
{111,"SlowJam"                  },
{112,"Club"                     },
{113,"Tango"                    },
{114,"Samba"                    },
{115,"Folklore"                 },
{116,"Ballad"                   },
{117,"PowerBallad"              },
{118,"RhythmicSoul"             },
{119,"Freestyle"                },
{120,"Duet"                     },
{121,"PunkRock"                 },
{122,"DrumSolo"                 },
{123,"Acapella"                 },
{124,"Euro-House"               },
{125,"DanceHall"                },
{126,"Goa"                      },
{127,"Drum&Bass"                },
{128,"Club-House"               },
{129,"Hardcore"                 },
{130,"Terror"                   },
{131,"Indie"                    },
{132,"BritPop"                  },
{133,"Negerpunk"                },
{134,"PolskPunk"                },
{135,"Beat"                     },
{136,"ChristianGangstaRap"      },
{137,"HeavyMetal"               },
{138,"BlackMetal"               },
{139,"Crossover"                },
{140,"ContemporaryChristian"    },
{141,"ChristianRock"            },
{142,"Merengue"                 },
{143,"Salsa"                    },
{144,"TrashMetal"               },
{145,"Anime"                    },
{146,"JPop"                     },
{147,"Synthpop"                 }
};

int getBit(char src, int bnum) ;


#endif // MEDIATAG_H
