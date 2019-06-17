#ifndef MEDIATAG_H
#define MEDIATAG_H

#include<QMap>

const char AENC[]= "AENC";        //   [#sec4.20 Audio encryption]
const char APIC[]= "APIC";        //   [#sec4.15 Attached picture]
const char COMM[]= "COMM";        //   [#sec4.11 Comments]
const char COMR[]= "COMR";        //   [#sec4.25 Commercial frame]
const char ENCR[]= "ENCR";        //   [#sec4.26 Encryption method registration]
const char EQUA[]= "EQUA";        //   [#sec4.13 Equalization]
const char ETCO[]= "ETCO";        //   [#sec4.6 Event timing codes]
const char GEOB[]= "GEOB";        //   [#sec4.16 General encapsulated object]
const char GRID[]= "GRID";        //   [#sec4.27 Group identification registration]
const char IPLS[]= "IPLS";        //   [#sec4.4 Involved people list]
const char LINK[]= "LINK";        //   [#sec4.21 Linked information]
const char MCDI[]= "MCDI";        //   [#sec4.5 Music CD identifier]
const char MLLT[]= "MLLT";        //   [#sec4.7 MPEG location lookup table]
const char OWNE[]= "OWNE";        //   [#sec4.24 Ownership frame]
const char PRIV[]= "PRIV";        //   [#sec4.28 Private frame]
const char PCNT[]= "PCNT";        //   [#sec4.17 Play counter]
const char POPM[]= "POPM";        //   [#sec4.18 Popularimeter]
const char POSS[]= "POSS";        //   [#sec4.22 Position synchronisation frame]
const char RBUF[]= "RBUF";        //   [#sec4.19 Recommended buffer size]
const char RVAD[]= "RVAD";        //   [#sec4.12 Relative volume adjustment]
const char RVRB[]= "RVRB";        //   [#sec4.14 Reverb]
const char SYLT[]= "SYLT";        //   [#sec4.10 Synchronized lyric/text]
const char SYTC[]= "SYTC";        //   [#sec4.8 Synchronized tempo codes]
const char TALB[]= "TALB";        //   [#TALB Album/Movie/Show title]
const char TBPM[]= "TBPM";        //   [#TBPM BPM (beats per minute)]
const char TCOM[]= "TCOM";        //   [#TCOM Composer]
const char TCON[]= "TCON";        //   [#TCON Content type]
const char TCOP[]= "TCOP";        //   [#TCOP Copyright message]
const char TDAT[]= "TDAT";        //   [#TDAT Date]
const char TDLY[]= "TDLY";        //   [#TDLY Playlist delay]
const char TENC[]= "TENC";        //   [#TENC Encoded by]
const char TEXT[]= "TEXT";        //   [#TEXT Lyricist/Text writer]
const char TFLT[]= "TFLT";        //   [#TFLT File type]
const char TIME[]= "TIME";        //   [#TIME Time]
const char TIT1[]= "TIT1";        //   [#TIT1 Content group description]
const char TIT2[]= "TIT2";        //   [#TIT2 Title/songname/content description]
const char TIT3[]= "TIT3";        //   [#TIT3 Subtitle/Description refinement]
const char TKEY[]= "TKEY";        //   [#TKEY Initial key]
const char TLAN[]= "TLAN";        //   [#TLAN Language(s)]
const char TLEN[]= "TLEN";        //   [#TLEN Length]
const char TMED[]= "TMED";        //   [#TMED Media type]
const char TOAL[]= "TOAL";        //   [#TOAL Original album/movie/show title]
const char TOFN[]= "TOFN";        //   [#TOFN Original filename]
const char TOLY[]= "TOLY";        //   [#TOLY Original lyricist(s)/text writer(s)]
const char TOPE[]= "TOPE";        //   [#TOPE Original artist(s)/performer(s)]
const char TORY[]= "TORY";        //   [#TORY Original release year]
const char TOWN[]= "TOWN";        //   [#TOWN File owner/licensee]
const char TPE1[]= "TPE1";        //   [#TPE1 Lead performer(s)/Soloist(s)]
const char TPE2[]= "TPE2";        //   [#TPE2 Band/orchestra/accompaniment]
const char TPE3[]= "TPE3";        //   [#TPE3 Conductor/performer refinement]
const char TPE4[]= "TPE4";        //   [#TPE4 Interpreted, remixed, or otherwise modified by]
const char TPOS[]= "TPOS";        //   [#TPOS Part of a set]
const char TPUB[]= "TPUB";        //   [#TPUB Publisher]
const char TRCK[]= "TRCK";        //   [#TRCK Track number/Position in set]
const char TRDA[]= "TRDA";        //   [#TRDA Recording dates]
const char TRSN[]= "TRSN";        //   [#TRSN Internet radio station name]
const char TRSO[]= "TRSO";        //   [#TRSO Internet radio station owner]
const char TSIZ[]= "TSIZ";        //   [#TSIZ Size]
const char TSRC[]= "TSRC";        //   [#TSRC ISRC (international standard recording code)]
const char TSSE[]= "TSSE";        //   [#TSEE Software/Hardware and settings used for encoding]
const char TYER[]= "TYER";        //   [#TYER Year]
const char TXXX[]= "TXXX";        //   [#TXXX User defined text information frame]
const char UFID[]= "UFID";        //   [#sec4.1 Unique file identifier]
const char USER[]= "USER";        //   [#sec4.23 Terms of use]
const char USLT[]= "USLT";        //   [#sec4.9 Unsychronized lyric/text transcription]
const char WCOM[]= "WCOM";        //   [#WCOM Commercial information]
const char WCOP[]= "WCOP";        //   [#WCOP Copyright/Legal information]
const char WOAF[]= "WOAF";        //   [#WOAF Official audio file webpage]
const char WOAR[]= "WOAR";        //   [#WOAR Official artist/performer webpage]
const char WOAS[]= "WOAS";        //   [#WOAS Official audio source webpage]
const char WORS[]= "WORS";        //   [#WORS Official internet radio station homepage]
const char WPAY[]= "WPAY";        //   [#WPAY Payment]
const char WPUB[]= "WPUB";        //   [#WPUB Publishers official webpage]
const char WXXX[]= "WXXX";        //   [#WXXX User defined URL link frame]

struct ID3V2_header
{
    char header[3]; /*必须为“ID3”否则认为标签不存在*/
    char version;   /*版本号ID3V2.3 就记录3*/
    char revision;  /*副版本号此版本记录为0*/
    char flag;      /*标志字节，只使用高三位，其它位为0 */
    char size[4];   /*标签大小*/
};

struct ID3V2_TagFrame
{
    char id[4];    /*用四个字符标识一个帧，说明其内容，稍后有常用的标识对照表*/
    char size[4];  /*帧内容的大小，不包括帧头，不得小于1*/
    char flags[2]; /*存放标志，只定义了6 位，稍后详细解说*/
};
const int id3V1DataL = 128;
const int id3TagL = 3;
const int id3TitleL = 30;
const int id3ArtistL = 30;
const int id3albumL = 30;
const int id3YearL = 4;
const int id3CommentL = 28;
const int GONE = 1;
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

struct AudioMediaInfo
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

#endif // MEDIATAG_H
