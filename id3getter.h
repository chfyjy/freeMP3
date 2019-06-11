#ifndef ID3GETTER_H
#define ID3GETTER_H

enum AudioType
{
    A_MP3,
    A_M4A,
    A_MP4,
};

struct id3_v2_header
{
  char id3[4];//必须为“ID3”否则认为标签不存在
  char ver_major;//版本号
  char ver_minor;//副版本号
  char flags;//标志字节，只使用高三位，其它位为0
  unsigned int size;//标签大小
};

struct id3_v2_frame_header
{
  char id[4];//帧标识
  unsigned int size;//帧内容的大小
  unsigned short flags;//帧标志
};

struct id3_v2_frame_contents
{
  unsigned char id[4];
  unsigned int size;
  unsigned char *contents;
};

class AudioInfo
{

}

class ID3Getter
{
public:
    ID3Getter();
private:
    AudioType type;
};

#endif // ID3GETTER_H
